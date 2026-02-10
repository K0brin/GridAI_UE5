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
	UFUNCTION(BlueprintCallable) void SetXLocaton(int32 value);
	UFUNCTION(BlueprintCallable) void SetYLocaton(int32 value);
	UFUNCTION(BlueprintCallable) int32 GetXLocaton();
	UFUNCTION(BlueprintCallable) int32 GetYLocaton();
	
	UPROPERTY(EditAnywhere, Category = "Tile Transforms") double tileWidth = 1;
	UPROPERTY(EditAnywhere, Category = "Tile Transforms") double tileHeight = 0.25;
	
private:
	UPROPERTY(VisibleAnywhere) int32 XLocation  = 0;
	UPROPERTY(VisibleAnywhere) int32 YLocation  = 0;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
