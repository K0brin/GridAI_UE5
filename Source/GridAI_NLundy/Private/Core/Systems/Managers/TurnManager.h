

#pragma once

#include "CoreMinimal.h"
#include "SpawnManager.h"
#include "GameFramework/Actor.h"
#include "TurnManager.generated.h"

class UGameManager;
class ASpawnManager;
class AMainCharacter;

UCLASS()
class ATurnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurnManager();
	UFUNCTION() void NextTurn();
	UFUNCTION() void CalculateFormation();
	UFUNCTION() void TakeEnemyTurn();
	UFUNCTION() void TakePlayerTurn();
	
	UPROPERTY() int32 CurrentTurn = 0;
	UPROPERTY() ASpawnManager* SpawnManager;
	UPROPERTY() AMainCharacter* CurrentPlayer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
