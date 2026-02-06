// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Managers/SpawnManager.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	GridArray.Reserve(10); 
	SpawnGrid();
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnManager::SpawnGrid()
{
	float rowSize = GridTiles / GridHeight;
	float compareNum = 1;
	float colorNum = 1;
	
	FVector spawnPos = FVector(0.f, 0.f, 0.f);
	for (float i = 1; i <= GridTiles; i++)
	{
		UStaticMeshComponent* gridMesh = Cast<UStaticMeshComponent>(gridComponentToSpawn);
		
		/*if (FMath::Fmod(colorNum, 2) == 0 )
		{
			gridMesh->SetMaterial(0, BlackColor);
		}
		else
		{
			gridMesh->SetMaterial(0, WhiteColor);
		}*/
		
		
		
		
		if ( (i / rowSize) == compareNum)
		{
			//UE_LOG(LogTemp, Warning, TEXT("%f"),rowSize);
			//UE_LOG(LogTemp, Warning, TEXT("%f"),i);
			AActor* createdGrid = GetWorld()->SpawnActor<AActor>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			spawnPos.Y += 100;
			spawnPos.X = 0;
			GridArray.Add(createdGrid);
			compareNum++;
		}
		else
		{
			AActor* createdGrid = GetWorld()->SpawnActor<AActor>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			spawnPos.X += 100;
			GridArray.Add(createdGrid);
		}
	}
	
}

