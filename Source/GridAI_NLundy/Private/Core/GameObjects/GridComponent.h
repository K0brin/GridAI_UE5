// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridComponent.generated.h"

UCLASS()
class AGridComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridComponent();
	//size of scale x,y
	UFUNCTION(BlueprintCallable) void SetTileScale();
	UFUNCTION(BlueprintCallable) void SetXXLocaton(int32 value);
	UFUNCTION(BlueprintCallable) void SetYYLocaton(int32 value);
	UFUNCTION(BlueprintCallable) int32 GetYYLocaton();
	UFUNCTION(BlueprintCallable) int32 GetXXLocaton();
	
	UPROPERTY(EditAnywhere, Category = "Tile Transforms") double tileWidth = 1;
	UPROPERTY(EditAnywhere, Category = "Tile Transforms") double tileHeight = 0.25;
	
private:
	UPROPERTY(VisibleAnywhere) int32 XXLocation  = 0;
	UPROPERTY(VisibleAnywhere) int32 YYLocation  = 0;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
