// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Managers/GameManager.h"

#include "SpawnManager.h"
#include "TurnManager.h"

UGameManager::UGameManager()
{
	
}

void UGameManager::Init()
{
	Super::Init();
	
	//CreateSpawnManager();
	//CreateTurnManager();
}

void UGameManager::OnStart()
{
	Super::OnStart();
	
	/*UWorld* World = GetWorld();
	
	if (World)
	{
		CreateSpawnManager();
		CreateTurnManager();
	}*/
}

void UGameManager::CreateSpawnManager()
{
	ActiveSpawnManager = GetWorld()->SpawnActor<ASpawnManager>(spawnManagerToSpawn, FVector (0.f, 0.f, 0.f), FRotator::ZeroRotator  );
	//ActiveSpawnManager->SetFolderPath(FName("Managers"));
	UE_LOG(LogTemp, Warning, TEXT("CreatedSpawnManager"));
}

void UGameManager::DeleteSpawnManager()
{
	
}

void UGameManager::CreateTurnManager()
{
	ActiveTurnManager = GetWorld()->SpawnActor<ATurnManager>(turnManagerToSpawn, FVector (0.f, 0.f, 0.f), FRotator::ZeroRotator  );
	//ActiveTurnManager->SetFolderPath(FName("Managers"));
	ActiveTurnManager->SpawnManager = ActiveSpawnManager;
	UE_LOG(LogTemp, Warning, TEXT("CreatedTurnManager"));
}

void UGameManager::DeleteTurnManager()
{
	
}

void UGameManager::SpawnGrid()
{
	ActiveSpawnManager->GenerateGrid();
}

void UGameManager::SetNumEnemy(int num)
{
	ActiveSpawnManager->NumberSpawned = num;
}

void UGameManager::SetGridWidth(float num)
{
	ActiveSpawnManager->GridWidth = num;
}


