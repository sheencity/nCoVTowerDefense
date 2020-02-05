// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/nCoVTDController.h"
#include "GameFramework/Pawn.h"

#include "Public/nCovTDPawn.h"

void AnCoVTDController::OnPossess(APawn* pPawn)
{
	Super::OnPossess(pPawn);
	mCovTDPawn = Cast<AnCovTDPawn>(pPawn);
}

void AnCoVTDController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AnCoVTDController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AnCoVTDController::MoveRight);
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AnCoVTDController::CameraZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &AnCoVTDController::CameraZoomOut);
}

void AnCoVTDController::MoveForward(float pValue)
{
	if (mCovTDPawn && pValue != 0) {
		float forwardValue = mCovTDPawn->GetActorLocation().X + pValue * mSpeed;
		mCovTDPawn->SetActorLocation(FVector(forwardValue, mCovTDPawn->GetActorLocation().Y, mCovTDPawn->GetActorLocation().Z));
	}
}

void AnCoVTDController::MoveRight(float pValue)
{
	if (mCovTDPawn && pValue != 0) {
		float rightValue = mCovTDPawn->GetActorLocation().Y + pValue * mSpeed;
		mCovTDPawn->SetActorLocation(FVector(mCovTDPawn->GetActorLocation().X, rightValue, mCovTDPawn->GetActorLocation().Z));
	}
}

void AnCoVTDController::CameraZoomIn()
{
	if (mCovTDPawn) {
		mCovTDPawn->CameraZoomIn();
	}
}

void AnCoVTDController::CameraZoomOut()
{
	if (mCovTDPawn) {
		mCovTDPawn->CameraZoomOut();
	}
}

