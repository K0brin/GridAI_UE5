// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameObjects/GridComponent.h"

// Sets default values
AGridComponent::AGridComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGridComponent::BeginPlay()
{
	Super::BeginPlay();
	SetTileScale();
	
}

// Called every frame
void AGridComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridComponent::SetTileScale()
{
	SetActorScale3D(FVector(tileWidth, tileWidth, tileHeight));
}

void AGridComponent::SetXXLocaton(int32 value)
{
	XXLocation = value;
}

void AGridComponent::SetYYLocaton(int32 value)
{
	YYLocation = value;
}

int32 AGridComponent::GetXXLocaton()
{
	return XXLocation;
}

int32 AGridComponent::GetYYLocaton()
{
	return YYLocation;
}


