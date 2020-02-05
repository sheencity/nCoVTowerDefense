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
		AnCoVTDController();

		virtual void OnPossess(APawn* pPawn) override;

protected:
	UPROPERTY(EditAnywhere)
		float mSpeed = 15.0f;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class APreviewTower> PreviewTowerClass;
	UPROPERTY()
		class APreviewTower* PreviewTower;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABaseTower> TowerClass;
	UPROPERTY()
	class ABaseTower* Tower;

	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaSeconds) override;

	void PlaceTower();

private:
	UPROPERTY()
	class AnCovTDPawn* mCovTDPawn;

	bool isPlacing = false;

	void CreatePreviewTower();
	void CanclePlace();
	void UpdatePreviewLocation();
};
