// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Managers/SpawnManager.h"
#include "Components/StaticMeshComponent.h"
#include "Core/GameObjects/Enemy.h"
#include "Core/GameObjects/GridComponent.h"
#include "Core/GameObjects/MainCharacter.h"

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
	SpawnPlayer();
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnManager::SpawnGrid()
{
	float columnSize = GridTiles / GridWidth;
	float compareNum = 1;
	int yyLocation = 0;
	int xxLocation = 1;
	
	FVector spawnPos = FVector(0.f, 0.f, 0.f);
	for (float i = 1; i <= GridTiles; i++)
	{
		if ( (i / columnSize) == compareNum) //new row
		{
			//UE_LOG(LogTemp, Warning, TEXT("%f"),rowSize);
			//UE_LOG(LogTemp, Warning, TEXT("%f"),i);
			AGridComponent* createdGrid = GetWorld()->SpawnActor<AGridComponent>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			ChangeColor(createdGrid);
			createdGrid->SetFolderPath(FName("Grid"));
			spawnPos.Y += 100;
			spawnPos.X = 0;
			GridArray.Add(createdGrid);
			compareNum++;
			yyLocation++;
			createdGrid->SetYYLocaton(yyLocation);
			createdGrid->SetXXLocaton(xxLocation);
			//for next spawn
			yyLocation = 0;
			xxLocation++;
		}
		else //continue row
		{
			AGridComponent* createdGrid = GetWorld()->SpawnActor<AGridComponent>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			ChangeColor(createdGrid);
			createdGrid->SetFolderPath(FName("Grid"));
			spawnPos.X -= 100;
			GridArray.Add(createdGrid);
			yyLocation++;
			createdGrid->SetYYLocaton(yyLocation);
			createdGrid->SetXXLocaton(xxLocation);
			
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
	
	float offset = (GridWidth / NumberSpawned) * 100;
	int32 yyLocation = 1;
	int32 xxLocation = 1;
	
	for (int i = 1; i <= NumberSpawned; i++)
	{
		AEnemy* createdEnemy = GetWorld()->SpawnActor<AEnemy>
				(EnemyToSpawn, spawnPos, FRotator::ZeroRotator  );
		EnemyArray.Add(createdEnemy);
		spawnPos.Y += offset;
		createdEnemy->XLocation = yyLocation;
		createdEnemy->YLocation = xxLocation;
		yyLocation += offset/100;
	}
}

void ASpawnManager::SpawnPlayer()
{
	FVector spawnPos = FVector(100.f, 0.f, 50.f);
	spawnPos.X -= (GridTiles / GridWidth) * 100;
	spawnPos.Y += (GridWidth / 2) * 100;
	//spawn player
	CurrentPlayer = GetWorld()->SpawnActor<AMainCharacter>(PlayerToSpawn, spawnPos, FRotator::ZeroRotator );
}
