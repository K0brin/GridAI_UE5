// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

class AGridComponent;

UCLASS()
class ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();
	
	//_________________________________________GRID_SPAWNING___________________________________________
	UFUNCTION(BlueprintCallable, Category = "Grid_Spawning") void SpawnGrid();
	UFUNCTION(BlueprintCallable, Category = "Grid_Spawning") void ChangeColor(AActor* actorToChange);
	UPROPERTY(EditAnywhere, Category = "Grid_Spawning") TSubclassOf<AActor> gridComponentToSpawn;
	UPROPERTY(EditAnywhere, Category = "Grid_Spawning") TArray<AActor*> GridArray;
	UPROPERTY(EditAnywhere, Category = "Grid_Spawning") float GridTiles = 260;
	UPROPERTY(EditAnywhere, Category = "Grid_Spawning") float GridHeight = 20;
	UPROPERTY() float ColorNum = 1;
	UPROPERTY(EditAnywhere, Category = "Grid_Spawning") UMaterialInterface* BlackColor;
	UPROPERTY(EditAnywhere, Category = "Grid_Spawning") UMaterialInterface* WhiteColor;
	
	//________________________________________ENEMY_SPAWNING_______________________________________________
	UFUNCTION(BlueprintCallable, Category = "Enemy_Spawning") void SpawnEnemies();
	UPROPERTY(EditAnywhere, Category = "Enemy_Spawning") TSubclassOf<AActor> EnemyToSpawn;
	UPROPERTY(EditAnywhere, Category = "Enemy_Spawning") int NumberSpawned;
	UPROPERTY(EditAnywhere, Category = "Enemy_Spawning") TArray<AActor*> EnemyArray;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
