// Copyrights Ozan Honamlioglu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDebugDrawHelpers.generated.h"

UCLASS()
class BUILDINGESCAPE_API AMyDebugDrawHelpers : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDebugDrawHelpers();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FVector LocationOne;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FVector LocationTwo;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FVector LocationThree;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FVector LocationFour;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FVector LocationFive;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FBox MyBox;

	UPROPERTY(EditAnywhere, Category = "Locations")
	FTransform MyTransform;
	
};
