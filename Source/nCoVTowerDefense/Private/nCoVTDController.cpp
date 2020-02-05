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
}


