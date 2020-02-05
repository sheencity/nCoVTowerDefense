// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Towers/BaseTower.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

#include "Enemys/BaseEnemy.h"

// Sets default values
ABaseTower::ABaseTower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = RootComp;
	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMesh"));
	MainMesh->SetupAttachment(RootComponent);
	RangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RangeSphere"));
	RangeSphere->SetupAttachment(RootComponent);
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetupAttachment(RootComponent);
	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	Muzzle->SetupAttachment(GunMesh);
}

// Called when the game starts or when spawned
void ABaseTower::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (hasTarget) {
		if (TargetEnemy && IsTargetInRange(TargetEnemy)) {
			GunMesh->SetWorldRotation(FRotator(0,0,ProjectileRotation().Yaw));
		}
		else {
			hasTarget = false;
			LookForTarget();
		}
	}
}

bool ABaseTower::IsTargetInRange(ABaseEnemy* pEnemy)
{
	return 	FVector::Distance(this->GetActorLocation(), pEnemy->GetActorLocation()) < Range;
}

void ABaseTower::LookForTarget()
{
	TArray<AActor*> ignoreChars;
	ignoreChars.Add(this);
	TArray<AActor*> overlappedActors;
	TArray<TEnumAsByte <EObjectTypeQuery>>  destObjectTypes;

	AActor* tempActor = nullptr;
	ABaseEnemy* tempTarget = nullptr;
	if (UKismetSystemLibrary::SphereOverlapActors(GetWorld(),
		GetActorLocation(),
		Range,
		destObjectTypes,
		ABaseEnemy::StaticClass(),
		ignoreChars,
		overlappedActors)) {

		for (AActor* target : overlappedActors) {
			tempActor = target;
			if (tempTarget) {
				if (this->GetDistanceTo(tempActor) < this->GetDistanceTo(tempTarget)) {
					tempTarget = Cast<ABaseEnemy>(tempActor);
				}
			}
			else {
				tempTarget = Cast<ABaseEnemy>(tempActor);
			}
		}
		hasTarget = true;
		TargetEnemy = tempTarget;
	}
	else {
		RangeSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

FRotator ABaseTower::ProjectileRotation()
{
	if (TargetEnemy)
	{
		UKismetMathLibrary::FindLookAtRotation(Muzzle->GetComponentLocation(), TargetEnemy->GetActorLocation());
	}
	return FRotator();
}

