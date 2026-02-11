


#include "Core/Systems/Managers/TurnManager.h"

// Sets default values
ATurnManager::ATurnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ATurnManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentPlayer = SpawnManager->CurrentPlayer;
	//Spawn Button For Start - when button pressed call NextTurn();
}

// Called every frame
void ATurnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurnManager::NextTurn()
{
	//CurrentTurn = 0 - Calculate Formation; 1 <-> 5 - Enemy Turn; 6 - Player Turn
	switch (CurrentTurn)
	{
	case 0: CalculateFormation(); break;
	case 1: TakeEnemyTurn(); break;
	case 2: TakeEnemyTurn(); break;
	case 3: TakeEnemyTurn(); break;
	case 4: TakeEnemyTurn(); break;
	case 5: TakeEnemyTurn(); break;
	case 6: TakePlayerTurn(); break;
	}
	CurrentTurn++;
	if (CurrentTurn >= 7){CurrentTurn = 0;}
}

void ATurnManager::CalculateFormation()
{
	//use player position and number of enemies to calculate a circle around the player
}

void ATurnManager::TakeEnemyTurn()
{
	//if too close to player Run(); else Move()
}

void ATurnManager::TakePlayerTurn()
{
	//allow player to move
}
