// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameManager.generated.h"

class ASpawnManager;
class ATurnManager;

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
	UFUNCTION(BlueprintCallable) void CreateTurnManager();
	UFUNCTION(BlueprintCallable) void DeleteTurnManager();
	UPROPERTY(EditAnywhere, Category = "Managers") TSubclassOf<AActor> spawnManagerToSpawn;
	UPROPERTY(EditAnywhere, Category = "Managers") TSubclassOf<AActor> turnManagerToSpawn;
	
	UPROPERTY() ASpawnManager* ActiveSpawnManager;
	UPROPERTY() ATurnManager* ActiveTurnManager;
	
};
