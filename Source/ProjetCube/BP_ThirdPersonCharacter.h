// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjetCubeCharacter.h"
#include "BP_ThirdPersonCharacter.generated.h"

class UInputAction;

UCLASS()
class PROJETCUBE_API ABP_ThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABP_ThirdPersonCharacter();
	void AjouterPoint(int32 Points);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void DebutSprint();
	void FinSprint();
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SprintAction;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	float walkingSpeed = 250.f;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	float sprintSpeed = 500.f;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	float jumpForce = 700.f;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	int32 jumpNumber = 2;
	
	UPROPERTY(EditAnywhere, Category = "Score")
	int32 score = 0;
	
	UPROPERTY(EditAnywhere, Category = "Score")
	int32 scoreToWin = 100;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
