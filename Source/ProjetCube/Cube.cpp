// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"


// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh")); 
	
	RootComponent = Mesh;
	
	Mesh->SetMobility(EComponentMobility::Movable);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ModeleCube(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (ModeleCube.Succeeded())
	{
		Mesh->SetStaticMesh(ModeleCube.Object);
	}
	
}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	
	PositionDepart = GetActorLocation();
	
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float AngleAjoute = VitesseRotation * DeltaTime;
	
	AddActorLocalRotation(FRotator(0.f, AngleAjoute, 0.f));
	
	if (bFlotter)
	{
		TempsEcoule = TempsEcoule + DeltaTime;
		
		float Decalage = FMath::Sin(TempsEcoule * VitesseFlottement) * HauteurFlottement;
		
		FVector NouvellePosition = PositionDepart;
		NouvellePosition.Z = PositionDepart.Z + Decalage;
		SetActorLocation(NouvellePosition);
	}

}

