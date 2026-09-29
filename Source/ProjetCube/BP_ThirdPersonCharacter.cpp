// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_ThirdPersonCharacter.h"

// Sets default values
ABP_ThirdPersonCharacter::ABP_ThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_ThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_ThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABP_ThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

