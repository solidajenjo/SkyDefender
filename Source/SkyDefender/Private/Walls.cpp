// Fill out your copyright notice in the Description page of Project Settings.

#include "Walls.h"

void UWalls::insertWall(FVector wallPos, FVector firePos)
{
	FWall newWall ;
	newWall.wallPos = wallPos;
	newWall.firePos = firePos;
	newWall.notPicked = true;
	if (walls.Contains(newWall)) walls.Remove(newWall);
	walls.Add(newWall);
}

void UWalls::removeWall(FWall wall)
{
	walls.Remove(wall);
	
}

bool UWalls::equals(FWall wall1, FWall wall2)
{
	return wall1 == wall2;
}

FWall UWalls::pickRandomWall()
{
	//UE_LOG(LogTemp, Warning, TEXT("Pick Random Wall %d"), walls.Num());
	if (walls.Num() >= 0) {
		int w = rand() % walls.Num();
		FWall* wall = &walls[w];
		if (wall->notPicked) {
			wall->notPicked = false;
			wall->valid = true;
			return *wall;
		}
	}else UE_LOG(LogTemp, Warning, TEXT("Not Finding"));
	return FWall(FVector(), FVector(), false, false);
}

