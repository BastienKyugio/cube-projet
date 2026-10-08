
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpPiece.generated.h"

class UStaticMeshComponent;

UCLASS()
class PROJETCUBE_API APickUpPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpPiece();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cours")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cours")
	float VitesseRotation = 90.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cours")
	bool bFlotter = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cours")
	float HauteurFlottement = 50.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cours")
	float VitesseFlottement = 2.f;
	
private:
	FVector PositionDepart;
	float TempsEcoule = 0.f;
};
