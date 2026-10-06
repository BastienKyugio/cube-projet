// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjetCubeCharacter.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UInputAction;
class UScoreWidget;

UCLASS()
class PROJETCUBE_API AMyCharacter : public AProjetCubeCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	
	void AddPoint(int32 Point);
	
	void LoseLife();
	
	void Die();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	void StartSprint();
	void StopSprint();
	
	// VIE ET MORT
	void UpdateLivesDisplay();
	void RestartLevel();
	
	// REGLAGE DU PERSONNAGE
	
	UPROPERTY(EditAnywhere, category = "Input")
	UInputAction* SprintAction;
	
	UPROPERTY(EditAnywhere, category = "Movement")
	float WalkSpeed = 250.f;
	
	UPROPERTY(EditAnywhere, category = "Movement")
	float SprintSpeed = 700.f;
	
	UPROPERTY(EditAnywhere, category = "Movement")
	float JumpForce = 700.f;
	
	UPROPERTY(EditAnywhere, category = "Movement")
	int32 MaxJumps = 2;
	
	// SCORE
	
	UPROPERTY(VisibleAnywhere, category = "Score")
	int32 Score = 0;
	
	UPROPERTY(EditAnywhere, category = "Score")
	int32 ScoreToWin = 5;
	
	// VIES
	
	UPROPERTY(EditAnywhere, category = "Lives", meta=(ClampMin="1"))
	int32 MaxLives = 3;
	
	UPROPERTY(EditAnywhere, category = "Lives")
	int32 Lives = 0;
	
	UPROPERTY(EditAnywhere, category = "Lives")
	bool bIsDead = false;
	
	UPROPERTY(EditAnywhere, category = "Lives")
	float RestartDelay = 3.f;
	
	FTimerHandle RestartTimer;
	
};
