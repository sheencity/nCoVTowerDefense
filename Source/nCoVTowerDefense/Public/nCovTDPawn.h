// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "nCovTDPawn.generated.h"

UCLASS()
class NCOVTOWERDEFENSE_API AnCovTDPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AnCovTDPawn();

protected:
	UPROPERTY(EditAnywhere, Category = Camera)
		float MinCameraZoom_V = 75.0f;
	UPROPERTY(EditAnywhere, Category = Camera)
		float MaxCameraZoom_V = 1000.0f;
	UPROPERTY(EditAnywhere, Category = Camera)
		float CameraZoomAlpha = 25.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class USceneComponent* ViewTransform;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCameraComponent* CameraComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void CameraZoomIn();
	void CameraZoomOut();
};
