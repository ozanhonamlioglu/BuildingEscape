// Copyrights Ozan Honamlioglu


#include "MyDebugDrawHelpers.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMyDebugDrawHelpers::AMyDebugDrawHelpers()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LocationOne = FVector(0, 0, 300);
	LocationTwo = FVector(0, 300, 300);
	LocationThree = FVector(0, -300, 300);
	LocationFour = FVector(-300, -300, 300);
	LocationFive = FVector(-400, 600, 600);

	MyBox = FBox(FVector(0,0,0), FVector(200,200,200));

	MyTransform.SetLocation(FVector(0, 500, 600));

}

// Called when the game starts or when spawned
void AMyDebugDrawHelpers::BeginPlay()
{
	Super::BeginPlay();
	
	DrawDebugPoint(GetWorld(), LocationOne, 200, FColor(52,220,239), true);
	DrawDebugSphere(GetWorld(), LocationTwo, 200, 26, FColor(181,0,0), true, -1, 0, 2);
	DrawDebugCircle(GetWorld(), LocationFour, 200, 50, FColor(0,0,0), true, -1, 0, 10);
	DrawDebugSolidBox(GetWorld(), MyBox, FColor(20, 100, 240), MyTransform, true);
}

// Called every frame
void AMyDebugDrawHelpers::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

