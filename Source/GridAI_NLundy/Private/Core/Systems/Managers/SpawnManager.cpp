// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Managers/SpawnManager.h"
#include "Components/StaticMeshComponent.h"
#include "Core/GameObjects/Enemy.h"
#include "Core/GameObjects/GridComponent.h"

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
	ColorNum = 1.f;
	SpawnGrid();
	SpawnEnemies();
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
	int xLocation = 0;
	int yLocation = 1;
	
	FVector spawnPos = FVector(0.f, 0.f, 0.f);
	for (float i = 1; i <= GridTiles; i++)
	{
		if ( (i / rowSize) == compareNum) //new row
		{
			//UE_LOG(LogTemp, Warning, TEXT("%f"),rowSize);
			//UE_LOG(LogTemp, Warning, TEXT("%f"),i);
			AGridComponent* createdGrid = GetWorld()->SpawnActor<AGridComponent>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			ChangeColor(createdGrid);
			spawnPos.Y += 100;
			spawnPos.X = 0;
			GridArray.Add(createdGrid);
			compareNum++;
			xLocation++;
			createdGrid->SetXLocaton(xLocation);
			createdGrid->SetYLocaton(yLocation);
			//for next spawn
			xLocation = 0;
			yLocation++;
		}
		else //continue row
		{
			AGridComponent* createdGrid = GetWorld()->SpawnActor<AGridComponent>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			ChangeColor(createdGrid);
			spawnPos.X -= 100;
			GridArray.Add(createdGrid);
			xLocation++;
			createdGrid->SetXLocaton(xLocation);
			createdGrid->SetYLocaton(yLocation);
			
		}
	}
	
}

void ASpawnManager::ChangeColor(AActor* actorToChange)
{
	UStaticMeshComponent* gridMesh = actorToChange->FindComponentByClass<UStaticMeshComponent>();
		
	if (gridMesh)
	{
		if (FMath::Fmod(ColorNum, 2) == 0 )
		{
			gridMesh->SetMaterial(0, BlackColor);
			ColorNum++;
		}
		else
		{
			gridMesh->SetMaterial(0, WhiteColor);
			ColorNum++;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor %s has no Static Mesh Component!"), *actorToChange->GetName());
	}
	
}

void ASpawnManager::SpawnEnemies()
{
	//start spawning off to the side of the grid
	FVector spawnPos = FVector(0, 0.f, 50.f);
	
	float offset = (GridHeight / NumberSpawned) * 100;
	int32 xLocation = 1;
	int32 yLocation = 1;
	
	for (int i = 1; i <= NumberSpawned; i++)
	{
		AEnemy* createdEnemy = GetWorld()->SpawnActor<AEnemy>
				(EnemyToSpawn, spawnPos, FRotator::ZeroRotator  );
		EnemyArray.Add(createdEnemy);
		spawnPos.Y += offset;
		createdEnemy->XLocation = xLocation;
		createdEnemy->YLocation = yLocation;
		xLocation += offset/100;
		
	}
	
	
}

