// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/nCoVTDController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

#include "Public/nCovTDPawn.h"
#include "Towers/PreviewTower.h"
#include "Towers/BaseTower.h"

AnCoVTDController::AnCoVTDController()
{
	bShowMouseCursor = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AnCoVTDController::OnPossess(APawn* pPawn)
{
	Super::OnPossess(pPawn);
	mCovTDPawn = Cast<AnCovTDPawn>(pPawn);
	CreatePreviewTower();
}

void AnCoVTDController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Place", IE_Pressed, this, &AnCoVTDController::PlaceTower);
	InputComponent->BindAction("Place", IE_Released, this, &AnCoVTDController::PlaceTower);
}

void AnCoVTDController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);
	UpdatePreviewLocation();
}

void AnCoVTDController::PlaceTower()
{
	if (!isPlacing&& PreviewTower) {
		PreviewTower->Destroy();
		PreviewTower = nullptr;

		FHitResult traceHitResult;
		if (GetHitResultUnderCursor(ECC_Visibility, true, traceHitResult)) {
			FVector cursorFV = FVector(traceHitResult.Location.X, traceHitResult.Location.Y,0);
			GetWorld()->SpawnActor<ABaseTower>(TowerClass, cursorFV, FRotator::ZeroRotator);			
		}
	}
}

void AnCoVTDController::CreatePreviewTower()
{
	FHitResult traceHitResult;
	GetHitResultUnderCursor(ECC_Visibility, true, traceHitResult);
	PreviewTower = GetWorld()->SpawnActor<APreviewTower>(PreviewTowerClass, traceHitResult.Location, FRotator::ZeroRotator);
}

void AnCoVTDController::CanclePlace()
{
	if (PreviewTower) {
		PreviewTower->Destroy();
		PreviewTower = nullptr;
	}
}

void AnCoVTDController::UpdatePreviewLocation()
{
	if (PreviewTower)
	{
		FHitResult traceHitResult;
		GetHitResultUnderCursor(ECC_Visibility, true, traceHitResult);
		if(traceHitResult.bBlockingHit)
		PreviewTower->SetActorLocation(FVector(traceHitResult.Location.X,traceHitResult.Location.Y,0));
	}
}


