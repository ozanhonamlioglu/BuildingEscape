// Copyrights Ozan Honamlioglu


#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get the player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewPointLocation, 
			OUT PlayerViewPointRotation
		);
	// log out to test
	/* UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"),
		*PlayerViewPointLocation.ToString(),
		*PlayerViewPointRotation.ToString()
	) */

	// Draw a red trace in the world to visualise
	FVector LinetraceEnd = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		OUT LinetraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	// set query params
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	// Line trace (AKA Ray-cast) out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LinetraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	// see what we hit
	AActor* ActorHit = Hit.GetActor();
	if(ActorHit) // Actor can return nullpntr, so that we need to handle it
	{
		UE_LOG(LogTemp, Log, TEXT("You hit %s"), *(ActorHit->GetName()))
	}

}

