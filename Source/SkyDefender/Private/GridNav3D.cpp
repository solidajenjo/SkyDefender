// Fill out your copyright notice in the Description page of Project Settings.

#include "GridNav3D.h"


#define GRID_SIZE 200
#define CELL_SIZE 20.f
#define DIRECTION_AMOUNT 78

FIntVector4 DIRECTIONS[DIRECTION_AMOUNT] = {
{ -1, -1, -1, 0 },
{ -1, -1, 1, 0 },
{ -1, 1, -1, 0 },
{ 1, -1, -1, 0 },
{ 1, 1, -1, 0 },
{ 1, 1, 1, 0 },
{ -1, -1, 0, 0 },
{ -1, 0, -1, 0 },
{ -1, 0, 0, 0 },
{ -1, 0, 1, 0 },
{ -1, 1, 0, 0 },
{ -1, 1, 1, 0 },
{ 0, -1, -1, 0 },
{ 0, -1, 1, 0 },
{ 0, 1, -1, 0 },
{ 0, 1, 1, 0 },
{ 1, -1, 0, 0 },
{ 1, -1, 1, 0 },
{ 1, 0, -1, 0 },
{ 1, 0, 1, 0 },
{ 1, 1, 0, 0 },
{ 1, 0, 0, 0 },
{ 0, 1, 0, 0 },
{ 0, 0, 1, 0 },
{ 0, 0, -1, 0 },
{ 0, -1, 0, 0 },
{16,16,16, 0 },
{16,16,0, 0 },
{16,16,-16, 0 },
{16,0,16, 0 },
{16,0,0, 0 },
{16,0,-16, 0 },
{16,-16,16, 0 },
{16,-16,0, 0 },
{16,-16,-16, 0 },
{0,16,16, 0 },
{0,16,0, 0 },
{0,16,-16, 0 },
{0,0,16, 0 },
{0,0,-16, 0 },
{0,-16,16, 0 },
{0,-16,0, 0 },
{0,-16,-16, 0 },
{-16,16,16, 0 },
{-16,16,0, 0 },
{-16,16,-16, 0 },
{-16,0,16, 0 },
{-16,0,0, 0 },
{-16,0,-16, 0 },
{-16,-16,16, 0 },
{-16,-16,0, 0 },
{-16,-16,-16, 0 },
{32,32,32, 0 },
{32,32,0, 0 },
{32,32,-32, 0 },
{32,0,32, 0 },
{32,0,0, 0 },
{32,0,-32, 0 },
{32,-32,32, 0 },
{32,-32,0, 0 },
{32,-32,-32, 0 },
{0,32,32, 0 },
{0,32,0, 0 },
{0,32,-32, 0 },
{0,0,32, 0 },
{0,0,-32, 0 },
{0,-32,32, 0 },
{0,-32,0, 0 },
{0,-32,-32, 0 },
{-32,32,32, 0 },
{-32,32,0, 0 },
{-32,32,-32, 0 },
{-32,0,32, 0 },
{-32,0,0, 0 },
{-32,0,-32, 0 },
{-32,-32,32, 0 },
{-32,-32,0, 0 },
{-32,-32,-32, 0 }
};
vector<vector<vector<int> > > matrix(GRID_SIZE, vector<vector<int>>(GRID_SIZE, vector<int>(GRID_SIZE, 0)));


FIntVector4 destCell;

// Sets default values
AGridNav3D::AGridNav3D()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

bool AGridNav3D::initGrid()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("Initiating scan"));
	bool foundAnything = false;
	for (int x = 0; x < GRID_SIZE; x++)
		for (int y = 0; y < GRID_SIZE; y++)
			for (int z = 0; z < GRID_SIZE; z++) {
				//Hit contains information about what the raycast hit.
				FHitResult Hit;

				//The length of the ray in units.
				//For more flexibility you can expose a public variable in the editor
				float RayLength = 2000;

				//The Origin of the raycast
				FVector StartLocation = gridToWorld(FVector(x, y, z));

				for (int i = 0; i < 26; i++) {
					//The EndLocation of the raycast
					FVector EndLocation = StartLocation + ((StartLocation + DIRECTIONS[i]) * RayLength);

					//Collision parameters. The following syntax means that we don't want the trace to be complex
					FCollisionQueryParams CollisionParameters;

					//Perform the line trace
					//The ECollisionChannel parameter is used in order to determine what we are looking for when performing the raycast
					
					if (GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, CollisionParameters)) {
						FVector gridImpactPoint = worldToGrid(Hit.ImpactPoint);
						int xP = (int)gridImpactPoint.X;
						int yP = (int)gridImpactPoint.Y;
						int zP = (int)gridImpactPoint.Z;
						//matrix[xP][yP][zP] = 1;
						//UE_LOG(LogTemp, Warning, TEXT("Detected solid %d %d %d"), xP, yP, zP);
						DrawDebugSolidBox(GetWorld(), gridToWorld(gridImpactPoint), FVector(25, 25, 25), FColor(181, 0, 0), true, 100.f);

						foundAnything = true;
					}

					//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1, 0, 1.f);

				}


			}
	*/
	UE_LOG(LogTemp, Warning, TEXT("Setting matrix"));
	for (int z = 0; z < 35; z++) {
		for (int x = 95; x < 106; x++) {
			for (int y = 45; y < 56; y++) {
				matrix[x][y][z] = 1;
			}

			for (int y = 95; y < 106; y++) {
				matrix[x][y][z] = 1;
			}

			for (int y = 145; y < 156; y++) {
				matrix[x][y][z] = 1;
			}
		}

		for (int y = 95; y < 106; y++) {
			for (int x = 45; x < 56; x++) {
				matrix[x][y][z] = 1;
			}

			for (int x = 145; x < 156; x++) {
				matrix[x][y][z] = 1;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Setting matrix - END"));
	/*
	for (int x = 0; x < GRID_SIZE; x++)
		for (int y = 0; y < GRID_SIZE; y++)
			for (int z = 0; z < GRID_SIZE; z++) {
				if (matrix[x][y][z] == 1 && z % 10 == 0) {
					FVector center = gridToWorld(FVector(x, y, z));
					DrawDebugSolidBox(GetWorld(), center, FVector(20, 20, 20), FColor(181, 0, 0), true, 100.f);
					//DrawDebugSphere(GetWorld(), center, 20, 26, FColor(181, 0, 0), true, -1, 0, 2);
				}

			}
	*/

	return true;
}

TArray<FVector> AGridNav3D::getPath(FVector originWorld, FVector destinationWorld)
{
	//UE_LOG(LogTemp, Warning, TEXT("get Path INI"));
	std::vector<std::vector<std::vector<bool> > > visited(GRID_SIZE, std::vector<std::vector<bool>>(GRID_SIZE, std::vector<bool>(GRID_SIZE, false)));
	std::vector<std::vector<std::vector<FVector> > > previousCellLocation(GRID_SIZE, std::vector<std::vector<FVector>>(GRID_SIZE, std::vector<FVector>(GRID_SIZE)));
	std::vector<std::vector<std::vector<FIntVector4> > > previousCellLocationGrid(GRID_SIZE, std::vector<std::vector<FIntVector4>>(GRID_SIZE, std::vector<FIntVector4>(GRID_SIZE)));
	priority_queue<FIntVector4, vector<FIntVector4>, Compare> Q;
	//queue<FVector> Q;
	FIntVector4 originCell = worldToGrid(originWorld);
	destCell = worldToGrid(destinationWorld);
	FIntVector4 nextCell, currentCell;
	nextCell = worldToGrid(originWorld);
	Q.push(nextCell);
	bool done = false;
	while (!Q.empty() && !done) {
		currentCell = Q.top();
		//currentCell = Q.front();
		Q.pop();
		for (int i = DIRECTION_AMOUNT - 1; i >= 0; i--) {
			nextCell = sum(currentCell,DIRECTIONS[i]);
			if (isValid(nextCell, visited)) {
				visited[nextCell.X][nextCell.Y][nextCell.Z] = true;
				previousCellLocation[nextCell.X][nextCell.Y][nextCell.Z] = gridToWorld(currentCell);
				previousCellLocationGrid[nextCell.X][nextCell.Y][nextCell.Z] = currentCell;
				nextCell.W = distance(nextCell, destCell);
				//nextCell.W = rand()%20;
				Q.push(nextCell);
			}
			if (nextCell == destCell) {
				done = true;
				previousCellLocation[nextCell.X][nextCell.Y][nextCell.Z] = gridToWorld(currentCell);
				previousCellLocationGrid[nextCell.X][nextCell.Y][nextCell.Z] = currentCell;
			}
		}
	}
	TArray<FVector> ret;
	nextCell = destCell;/*
	while (done && (nextCell != originCell)) {
		ret.Add(previousCellLocation[nextCell.X][nextCell.Y][nextCell.Z]);
		UE_LOG(LogTemp, Warning, TEXT("Step %9.6f %9.6f %9.6f"), previousCellLocation[nextCell.X][nextCell.Y][nextCell.Z].X, previousCellLocation[nextCell.X][nextCell.Y][nextCell.Z].Y, previousCellLocation[nextCell.X][nextCell.Y][nextCell.Z].Z);
		nextCell = previousCellLocationGrid[nextCell.X][nextCell.Y][nextCell.Z];
	}*/
	ret.Add(gridToWorld(destCell));
	//UE_LOG(LogTemp, Warning, TEXT("get Path FIN"));
	return ret;
}

FIntVector4 AGridNav3D::sum(FIntVector4 a, FIntVector4 b)
{
	a.X += b.X;
	a.Y += b.Y;
	a.Z += b.Z;
	return a;
}

int AGridNav3D::distance(FIntVector4 a, FIntVector4 b)
{
	return (int)sqrt((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y) + (a.Z - b.Z)*(a.Z - b.Z));
}


bool AGridNav3D::isValid(const FIntVector4 &cell, const std::vector<std::vector<std::vector<bool> > > &visited)
{
	if (cell.X < 0 || cell.X >= GRID_SIZE || cell.Y < 0 || cell.Y >= GRID_SIZE
		|| cell.Z < 0 || cell.Z >= GRID_SIZE) return false;
	return !visited[cell.X][cell.Y][cell.Z];
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


FVector AGridNav3D::gridToWorld(FIntVector4 gridPos) {
	return FVector(gridPos.X * CELL_SIZE, gridPos.Y * CELL_SIZE, gridPos.Z * CELL_SIZE);
}

FIntVector4 AGridNav3D::worldToGrid(FVector worldPos)
{
	FIntVector4 p;
	p.X = (int)worldPos.X / CELL_SIZE;
	p.Y = (int)worldPos.Y / CELL_SIZE;
	p.Z = (int)worldPos.Z / CELL_SIZE;
	return p;
}

