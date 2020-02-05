// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PreviewTower.generated.h"

UCLASS()
class NCOVTOWERDEFENSE_API APreviewTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APreviewTower();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
		class USceneComponent* RootComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
		class UStaticMeshComponent* MainMesh;
};
