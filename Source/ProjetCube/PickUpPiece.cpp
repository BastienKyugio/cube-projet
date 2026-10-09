// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpPiece.h"
#include "MyCharacter.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APickUpPiece::APickUpPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	
	RootComponent = Mesh;
	
	Mesh->SetMobility(EComponentMobility::Movable);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ModeleCylinder(TEXT("/Game/LevelPrototyping/Meshes/SM_Cylinder"));
	if (ModeleCylinder.Succeeded())
	{
		Mesh->SetStaticMesh(ModeleCylinder.Object);
	}
	CollisionComponent = CreateDefaultSubobject<USphereComponent>("CollisionComponent");
	CollisionComponent->SetupAttachment(Mesh);
	CollisionComponent->InitSphereRadius(100.f);
	
	CollisionComponent->SetCollisionProfileName(TEXT("Trigger"));
}

// Called when the game starts or when spawned
void APickUpPiece::BeginPlay()
{
	Super::BeginPlay();
	
	PositionDepart = GetActorLocation();
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this,&APickUpPiece::OnOverlapBegin);
}

// Called every frame
void APickUpPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float AngleAjoute = VitesseRotation * DeltaTime;
	
	AddActorLocalRotation(FRotator(AngleAjoute, 0.f, 0.0f));
	
	if (bFlotter)
	{
		TempsEcoule = TempsEcoule + DeltaTime;
		
		float Decalage = FMath::Sin(TempsEcoule * VitesseFlottement) * HauteurFlottement;
	
		FVector NouvellePosition = PositionDepart;
		NouvellePosition.Z = PositionDepart.Z + Decalage;
		SetActorLocation(NouvellePosition);
	}
}

void APickUpPiece::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(OtherActor);
		if (PlayerCharacter)
		{
			PlayerCharacter->AddPoint(1);
			Destroy();
		}
	}
}

