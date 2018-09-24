// Fill out your copyright notice in the Description page of Project Settings.

#include "GridNav3D.h"
#include <vector>

#define GRID_SIZE 100

FVector DIRECTIONS[26] = { {-1, -1, -1},
							{-1, -1, 0},
							{-1, -1, 1},
							{-1, 0, -1},
							{-1, 0, 0},
							{-1, 0, 1},
							{-1, 1, -1},
							{-1, 1, 0},
							{-1, 1, 1},
							{0, -1, -1},
							{0, -1, 0},
							{0, -1, 1},
							{0, 0, -1},
							{0, 0, 1},
							{0, 1, -1},
							{0, 1, 0},
							{0, 1, 1},
							{1, -1, -1},
							{1, -1, 0},
							{1, -1, 1},
							{1, 0, -1},
							{1, 0, 0},
							{1, 0, 1},
							{1, 1, -1},
							{1, 1, 0},
							{1, 1, 1} };
int matrix[GRID_SIZE][GRID_SIZE][GRID_SIZE];
// Sets default values
AGridNav3D::AGridNav3D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	

}

void AGridNav3D::initGrid(TArray<FVector> walls)
{
	//Reset grid
	for (int i = 0; i < GRID_SIZE; i++)
		for (int j = 0; j < GRID_SIZE; j++)
			for (int k = 0; k < GRID_SIZE; k++) matrix[i][j][k] = 0;
	//Put walls in the grid
	for (int i = 0; i < walls.Num(); i++) {
		UE_LOG(LogTemp, Warning, TEXT("Catching wall #%d"), i);
		UE_LOG(LogTemp, Warning, TEXT("Wall #%d world positions: %9.6f %9.6f %9.6f"), i, walls[i].X, walls[i].Y, walls[i].Z);
		FVector gridPositonsF = worldToGrid(walls[i]);
		std::vector<int> gridPositions{ (int)gridPositonsF.X, (int)gridPositonsF.Y, (int)gridPositonsF.Z};		
		int xPos = gridPositions[0];
		int yPos = gridPositions[1];
		int zPos = gridPositions[2];
		UE_LOG(LogTemp, Warning, TEXT("Wall #%d grid int positions: %d %d %d"), i, xPos, yPos, zPos);
		
		matrix[xPos][yPos][zPos] = 1;
		
	}
	
}

// Called when the game starts or when spawned
void AGridNav3D::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridNav3D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AGridNav3D::worldToGrid(FVector worldPos) {
	return FVector(floorf(worldPos.X / 50.f), floorf(worldPos.Y / 50.f), floorf(worldPos.Z / 31.f));
}

FVector AGridNav3D::gridToWorld(FVector gridPos) {
	return FVector(gridPos.X * 50.f, gridPos.Y * 50.f, gridPos.Z * 31.f);
}
