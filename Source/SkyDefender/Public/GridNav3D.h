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

	UFUNCTION(BlueprintCallable)
	FVector worldToGrid(FVector worldPos);

	UFUNCTION(BlueprintCallable)
	FVector gridToWorld(FVector gridPos);		

	UFUNCTION(BlueprintCallable)
	bool initGrid();	

	UFUNCTION(BlueprintCallable)
	TArray<FVector> getPath(FVector originWorld, FVector destinationWorld);


	bool isValid(FVector cell, FVector direction, std::vector<std::vector<std::vector<bool> > > &visited);


	class Compare
	{
	public:
		bool operator() (const FVector4 &a, const FVector4 &b)
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
