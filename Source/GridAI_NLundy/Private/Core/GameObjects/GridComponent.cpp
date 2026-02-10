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

void AGridComponent::SetXLocaton(int32 value)
{
	XLocation = value;
}

void AGridComponent::SetYLocaton(int32 value)
{
	YLocation = value;
}

int32 AGridComponent::GetXLocaton()
{
	return XLocation;
}

int32 AGridComponent::GetYLocaton()
{
	return YLocation;
}

