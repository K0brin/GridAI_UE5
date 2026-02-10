

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
	
	UPROPERTY(VisibleAnywhere) int32 XLocation = 0;
	UPROPERTY(VisibleAnywhere) int32 YLocation = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
