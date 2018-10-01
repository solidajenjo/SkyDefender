// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "Walls.generated.h"


USTRUCT(BlueprintType)
struct FWall {
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector wallPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector firePos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool notPicked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool valid;

	FWall(FVector wP, FVector fP, bool nP, bool v) { wallPos = wP; firePos = fP; notPicked = nP, valid = v; };
	FWall() {};
	inline bool operator==(const FWall& otherWall) const
	{
		return wallPos == otherWall.wallPos;
	}
};

UCLASS()
class SKYDEFENDER_API UWalls : public UChildActorComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void insertWall(FVector wallPos, FVector firePos);

	UFUNCTION(BlueprintCallable)
	void removeWall(FWall wall);

	UFUNCTION(BlueprintCallable)
	bool equals(FWall wall1, FWall wall2);

	UFUNCTION(BlueprintCallable)
	FWall pickRandomWall();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWall> walls;
	
};
