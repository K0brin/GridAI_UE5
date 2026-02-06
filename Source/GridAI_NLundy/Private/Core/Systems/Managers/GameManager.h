// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnManager.h"
#include "Engine/GameInstance.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class GRIDAI_NLUNDY_API UGameManager : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	virtual void Init() override;
	
public:
	UGameManager();
	UFUNCTION(BlueprintCallable) void CreateSpawnManager();
	UFUNCTION(BlueprintCallable) void DeleteSpawnManager();
	UPROPERTY(EditAnywhere, Category = "Managers") TSubclassOf<AActor> spawnManagerToSpawn;
	
};
