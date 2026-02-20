// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridComponent.generated.h"

USTRUCT(BlueprintType)
struct FSlotData
{
	GENERATED_BODY()
	
	UPROPERTY() FVector WorldLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) FVector2D RelativeLocation;
	UPROPERTY(VisibleAnywhere) bool SlotIsFull;
};


UCLASS()
class AGridComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridComponent();
	//size of scale x,y
	UFUNCTION(BlueprintCallable) void SetTileScale();
	
	UPROPERTY(EditAnywhere, Category = "Tile Transforms") double tileWidth = 1;
	UPROPERTY(EditAnywhere, Category = "Tile Transforms") double tileHeight = 0.25;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) FSlotData GridSlotData;
	
private:
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
