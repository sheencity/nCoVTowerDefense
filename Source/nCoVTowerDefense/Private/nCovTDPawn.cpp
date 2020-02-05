// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/nCovTDPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AnCovTDPawn::AnCovTDPawn()
{
	ViewTransform = CreateDefaultSubobject<USceneComponent>(TEXT("ViewTransform"));
	RootComponent = ViewTransform;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AnCovTDPawn::BeginPlay()
{
	Super::BeginPlay();
}



