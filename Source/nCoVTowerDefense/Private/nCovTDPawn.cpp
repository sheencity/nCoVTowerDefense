// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/nCovTDPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AnCovTDPawn::AnCovTDPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ViewTransform = CreateDefaultSubobject<USceneComponent>(TEXT("ViewTransform"));
	RootComponent = ViewTransform;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	CapsuleComp->SetupAttachment(RootComponent);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(CapsuleComp);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AnCovTDPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AnCovTDPawn::CameraZoomIn()
{
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength - CameraZoomAlpha, MinCameraZoom_V, MaxCameraZoom_V);
}

void AnCovTDPawn::CameraZoomOut()
{
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength + CameraZoomAlpha, MinCameraZoom_V, MaxCameraZoom_V);
}


