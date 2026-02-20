

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MockGameManager.generated.h"

class ASpawnManager;
class ATurnManager;

UCLASS()
class AMockGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMockGameManager();
	UFUNCTION(BlueprintCallable) void CreateSpawnManager();
	UFUNCTION(BlueprintCallable) void DeleteSpawnManager();
	UFUNCTION(BlueprintCallable) void CreateTurnManager();
	UFUNCTION(BlueprintCallable) void DeleteTurnManager();
	UFUNCTION(BlueprintCallable) void SpawnGrid();
	UFUNCTION(BlueprintCallable) void SetNumEnemy(int num);
	UFUNCTION(BlueprintCallable) void SetGridWidth(float num);
	UPROPERTY(EditAnywhere, Category = "Managers") TSubclassOf<AActor> spawnManagerToSpawn;
	UPROPERTY(EditAnywhere, Category = "Managers") TSubclassOf<AActor> turnManagerToSpawn;
	
	UPROPERTY() ASpawnManager* ActiveSpawnManager;
	UPROPERTY() ATurnManager* ActiveTurnManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
