// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include <queue>
#include "CoreMinimal.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "GridNav3D.generated.h"
using namespace std;

UCLASS()
class SKYDEFENDER_API AGridNav3D : public AActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	AGridNav3D();

	UPROPERTY(EditAnywhere)
	int32 gridSize;

	FIntVector4 worldToGrid(FVector worldPos);

	FVector gridToWorld(FIntVector4 gridPos);

	UFUNCTION(BlueprintCallable)
	bool initGrid();	

	UFUNCTION(BlueprintCallable)
	TArray<FVector> getPath(FVector originWorld, FVector destinationWorld);

	FIntVector4 sum(FIntVector4 a, FIntVector4 b);
	int distance(FIntVector4 a, FIntVector4 b);

	bool isValid(const FIntVector4 &cell, const std::vector<std::vector<std::vector<bool> > > &visited);


	class Compare
	{
	public:
		bool operator() (const FIntVector4 &a, const FIntVector4 &b)
		{		
			return a.W > b.W;
		}
	};


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
