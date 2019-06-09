// Copyrights Ozan Honamlioglu


#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

void UGrabber::FindPhysicsHandleComponent()
{
	// Look for attached physics handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(PhysicsHandle)
	{
		// Physics handle is found
		
	} else {
		// not found
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName());
	}
}

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent)
	{
		// Physics handle is found
		UE_LOG(LogTemp, Warning, TEXT("input component found"));
		// Bind the input axis
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);

	} else {
		// not found
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	}
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Key pressed"));

	// LINE TRACE and see if we reach any actors hit physics body collusion hannel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();
	
	// If we hit something then attach a physics handle
	if(ActorHit)
	{
		// TODO attach physics handle
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			ComponentToGrab, 
			NAME_None, 
			ComponentToGrab->GetOwner()->GetActorLocation(), 
			ComponentToGrab->GetOwner()->GetActorRotation()
		);
	}

}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Key released"));
	// TODO release physics handle
	PhysicsHandle->ReleaseComponent();
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

	FVector LinetraceEnd = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);

	// if the physics handle is attached
	if(PhysicsHandle->GrabbedComponent)
	{
		// move the object that we are holding
		PhysicsHandle->SetTargetLocation(LinetraceEnd);
	}

}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{

	// Get the player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewPointLocation, 
			OUT PlayerViewPointRotation
		);

	FVector LinetraceEnd = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);

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

	return Hit;

}
