// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Systems/Managers/GameManager.h"

UGameManager::UGameManager()
{
	
}

void UGameManager::Init()
{
	Super::Init();
	
	CreateSpawnManager();
}

void UGameManager::CreateSpawnManager()
{
	ASpawnManager* createdSpawnManager = GetWorld()->SpawnActor<ASpawnManager>
		(spawnManagerToSpawn, FVector (0.f, 0.f, 10.f), FRotator::ZeroRotator  );
	UE_LOG(LogTemp, Warning, TEXT("CreatedSpawnManager"));
}

void UGameManager::DeleteSpawnManager()
{
	
}

