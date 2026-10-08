// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->JumpZVelocity = JumpForce;
	JumpMaxCount = MaxJumps;
	
	AddPoint(0);
	
	Lives = MaxLives;
	UpdateLivesDisplay();
}	



// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (InputComp && SprintAction)
	{
		InputComp->BindAction(SprintAction, ETriggerEvent::Started,this, &AMyCharacter::StartSprint);
		InputComp->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMyCharacter::StopSprint);
	
	}
}
void AMyCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed; // on passe a la vitesse de sprint
}
void AMyCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed; // on repasse a la vitesse de marche
}

void AMyCharacter::AddPoint(int32 Points)
{
	Score += Points;
	
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("Score : %d / %d"), Score, ScoreToWin);
		GEngine->AddOnScreenDebugMessage(1,100.f,FColor::Yellow,Message);
	
		if (Score>= ScoreToWin)
		{
			GEngine->AddOnScreenDebugMessage(2, 100.f,FColor::Green,TEXT("Gagne !!!"), true, FVector2D(3.f, 3.f));
		}	
	}
}

void AMyCharacter::LoseLife()
{
	if (bIsDead)
	{
		return;
	}
	
	Lives -= 1;
	
	if (Lives <= 0)
	{
		Die();
	}
}

void AMyCharacter::UpdateLivesDisplay()
{
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("Vie : %d / %d"), Lives, MaxLives);
		GEngine->AddOnScreenDebugMessage(3,100.f,FColor::Red,Message);
	}
}

void AMyCharacter::Die()
{
	if (bIsDead)
	{
		return;
	}
	
	bIsDead = true;
	
	Lives = 0;
	UpdateLivesDisplay();
	
	GetCharacterMovement()->DisableMovement();
	DisableInput(Cast<APlayerController>(GetController()));
	
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
	GetMesh()->SetSimulatePhysics(true);
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(4, RestartDelay, FColor::Red,TEXT("Mort !!!"), true, FVector2D(3.f, 3.f));
		
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &AMyCharacter::RestartLevel, RestartDelay, false);
}
void AMyCharacter::RestartLevel()
{
	FString LevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}		