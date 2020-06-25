// Copyright 2020 Rick Dennison

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



private:
	float Reach = 100.f;

	UPROPERTY()
		UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UPROPERTY()
		UInputComponent* InputComponent = nullptr;

	void Grab();
	void Realeased();
	void FindPhysicsHandle();
	void SetupInputComponent();

	// Returns the first Actor within reach with a physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Returns Line Trace End
	FVector GetPlayersReach() const;
	// Gets the players position in the world
	FVector GetPlayersWorldPos() const;
};
