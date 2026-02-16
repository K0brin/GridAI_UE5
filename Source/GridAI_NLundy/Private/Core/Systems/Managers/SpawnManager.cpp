// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Managers/SpawnManager.h"
#include "Components/StaticMeshComponent.h"
#include "Core/GameObjects/Enemy.h"
#include "Core/GameObjects/GridComponent.h"
#include "Core/GameObjects/MainCharacter.h"
#include "Kismet/GameplayStatics.h"

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
	FVector2D relativeLocation = FVector2D(1,0);
	//int yyLocation = 0;
	//int xxLocation = 1;
	
	FVector spawnPos = FVector(0.f, 0.f, 0.f);
	for (float i = 1; i <= GridTiles; i++)
	{
		if ( (i / columnSize) == compareNum) //last of row
		{
			//UE_LOG(LogTemp, Warning, TEXT("Hello"));
			AGridComponent* createdGrid = GetWorld()->SpawnActor<AGridComponent>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator);
			ChangeColor(createdGrid);
			createdGrid->SetFolderPath(FName("Grid"));
			GridArray.Add(createdGrid);
			relativeLocation.Y++;
			SetGridSlotData(createdGrid, spawnPos, relativeLocation);
			//for next spawn
			relativeLocation.Y = 0;
			relativeLocation.X++;
			spawnPos.Y += 100;
			spawnPos.X = 0;
			compareNum++;
		}
		else //start/continue row
		{
			//UE_LOG(LogTemp, Warning, TEXT("Two"));
			AGridComponent* createdGrid = GetWorld()->SpawnActor<AGridComponent>
				(gridComponentToSpawn, spawnPos, FRotator::ZeroRotator  );
			ChangeColor(createdGrid);
			createdGrid->SetFolderPath(FName("Grid"));
			GridArray.Add(createdGrid);
			relativeLocation.Y++;
			SetGridSlotData(createdGrid, spawnPos, relativeLocation);
			spawnPos.X -= 100;
			
		}
	}
	
}

void ASpawnManager::SetGridSlotData(AGridComponent* gridObject, FVector worldLocation, FVector2D relativeLocation)
{
	
	gridObject->GridSlotData.WorldLocation = worldLocation;
	gridObject->GridSlotData.RelativeLocation = relativeLocation;
	gridObject->GridSlotData.SlotIsFull = false;
	
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
		
	}
	
}

void ASpawnManager::SpawnEnemies()
{
	//start spawning off to the side of the grid
	FVector spawnPos = FVector(0, 0.f, 50.f);
	
	float offset = (GridWidth / NumberSpawned) * 100;
	//FVector2D xyLocation = FVector2D(1,1);
	
	for (int i = 1; i <= NumberSpawned; i++)
	{
		AEnemy* createdEnemy = GetWorld()->SpawnActor<AEnemy>
				(EnemyToSpawn, spawnPos, FRotator::ZeroRotator);
		EnemyArray.Add(createdEnemy);
		createdEnemy->SetFolderPath(FName("Enemies"));
		spawnPos.Y += offset;
		SetNewLocation(createdEnemy, AEnemy::StaticClass());
		//xyLocation.Y += offset/100;
	}
}

void ASpawnManager::SpawnPlayer()
{
	FVector spawnPos = FVector(100.f, 0.f, 50.f);
	spawnPos.X -= (GridTiles / GridWidth) * 100;
	spawnPos.Y += (GridWidth / 2) * 100;
	//spawn player
	CurrentPlayer = GetWorld()->SpawnActor<AMainCharacter>(PlayerToSpawn, spawnPos, FRotator::ZeroRotator );
	CurrentPlayer->SetFolderPath(FName("PlayerCharacter"));
	SetNewLocation(CurrentPlayer, AMainCharacter::StaticClass());
	//CurrentPlayer->XLocation = (spawnPos.Y / 100) + 1;
	//CurrentPlayer->YLocation = FMath::Abs((spawnPos.X - 100)/100); 
}

void ASpawnManager::SetNewLocation(AActor* movingActor, TSubclassOf<AActor> inputSubclass)
{
	//Getting Grid Component
	float distance = 0;
	AActor* closestActor = UGameplayStatics::FindNearestActor(movingActor->GetActorLocation(), GridArray, distance);
	AGridComponent* closestGridComponent = Cast<AGridComponent>(closestActor);
	
	//Getting Input Actor Component
	if (inputSubclass == AMainCharacter::StaticClass())
	{
		AMainCharacter* inputActor = Cast<AMainCharacter>(movingActor);
		inputActor->XYLocation = closestGridComponent->GridSlotData.RelativeLocation;
		closestGridComponent->GridSlotData.SlotIsFull = true;
	}
	else if (inputSubclass == AEnemy::StaticClass())
	{
		AEnemy* inputActor = Cast<AEnemy>(movingActor);
		inputActor->XYLocation = closestGridComponent->GridSlotData.RelativeLocation;
		closestGridComponent->GridSlotData.SlotIsFull = true;
		
	}
}
