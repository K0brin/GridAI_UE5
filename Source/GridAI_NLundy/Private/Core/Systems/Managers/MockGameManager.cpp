


#include "Core/Systems/Managers/MockGameManager.h"

#include "SpawnManager.h"
#include "TurnManager.h"

// Sets default values
AMockGameManager::AMockGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMockGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	CreateSpawnManager();
	CreateTurnManager();
}

// Called every frame
void AMockGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMockGameManager::CreateSpawnManager()
{
	ActiveSpawnManager = GetWorld()->SpawnActor<ASpawnManager>(spawnManagerToSpawn, FVector (0.f, 0.f, 0.f), FRotator::ZeroRotator  );
	//ActiveSpawnManager->SetFolderPath(FName("Managers"));
	UE_LOG(LogTemp, Warning, TEXT("CreatedSpawnManager"));
}

void AMockGameManager::DeleteSpawnManager()
{
	
}

void AMockGameManager::CreateTurnManager()
{
	ActiveTurnManager = GetWorld()->SpawnActor<ATurnManager>(turnManagerToSpawn, FVector (0.f, 0.f, 0.f), FRotator::ZeroRotator  );
	//ActiveTurnManager->SetFolderPath(FName("Managers"));
	ActiveTurnManager->SpawnManager = ActiveSpawnManager;
	UE_LOG(LogTemp, Warning, TEXT("CreatedTurnManager"));
}

void AMockGameManager::DeleteTurnManager()
{
}

void AMockGameManager::SpawnGrid()
{
	ActiveSpawnManager->GenerateGrid();
}

void AMockGameManager::SetNumEnemy(int num)
{
	ActiveSpawnManager->NumberSpawned = num;
}

void AMockGameManager::SetGridWidth(float num)
{
	ActiveSpawnManager->GridWidth = num;
}

