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
	UFUNCTION(BlueprintCallable) void SpawnGrid();
	UPROPERTY(EditAnywhere, Category = "Grid Component") TSubclassOf<AActor> gridComponentToSpawn;
	UPROPERTY(EditAnywhere) TArray<AActor*> GridArray;
	UPROPERTY(EditAnywhere) float GridTiles = 10;
	UPROPERTY(EditAnywhere) float GridHeight = 2;
	UPROPERTY(EditAnywhere) UMaterial* BlackColor;
	UPROPERTY(EditAnywhere) UMaterial* WhiteColor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
