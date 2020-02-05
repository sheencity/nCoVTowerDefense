// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "nCoVTDController.generated.h"

/**
 * 
 */
UCLASS()
class NCOVTOWERDEFENSE_API AnCoVTDController : public APlayerController
{
	GENERATED_BODY()

		virtual void OnPossess(APawn* pPawn) override;

protected:
	UPROPERTY(EditAnywhere)
		float mSpeed = 15.0f;

	virtual void SetupInputComponent() override;

private:
	class AnCovTDPawn* mCovTDPawn;
};
