

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCharacter.generated.h"

UCLASS()
class AMainCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainCharacter();
	
	UPROPERTY(VisibleAnywhere) FVector2D XYLocation = FVector2D(0,0);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
