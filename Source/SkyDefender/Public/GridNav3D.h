// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridNav3D.generated.h"


UCLASS()
class SKYDEFENDER_API AGridNav3D : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FVector worldToGrid(FVector worldPos);

	UFUNCTION(BlueprintCallable)
	FVector gridToWorld(FVector gridPos);

	UPROPERTY(EditAnywhere)
	int32 gridSize;
	// Sets default values for this actor's properties
	AGridNav3D();
	UFUNCTION(BlueprintCallable)
	void initGrid(TArray<FVector> walls);	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
