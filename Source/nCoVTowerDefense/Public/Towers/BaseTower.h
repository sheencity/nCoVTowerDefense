// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTower.generated.h"

UCLASS()
class NCOVTOWERDEFENSE_API ABaseTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTower();

protected:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
		class USceneComponent* RootComp;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
			class UStaticMeshComponent* MainMesh;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
			class USphereComponent* RangeSphere;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
			class UStaticMeshComponent* GunMesh;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
			class USceneComponent* Muzzle;

		UPROPERTY(EditAnywhere, Category = "Tower")
			float Range;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	bool IsTargetInRange();
};
