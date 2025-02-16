// Copyright Evan Allen


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	// ~Line trace: Start
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();
	/** ~Line trace: End
	 * 
	 * Result from line trace from cursor scenerios:
	 * A. LastActor is null && ThisActor is null
	 *	- Do nothing
	 *	
	 * B. LastActor is null && ThisActor is valid
	 *	- Highlight ThisActor
	 *	
	 * C. LastaActor is valid && ThisActor is null
	 *	- UnHighlight LastActor
	 *	
	 * D. Both actors are valid, but LastActor != ThisActor
	 *	- UnHighlight LastActor, and Highlight ThisActor
	 *	
	 * E. Both actor are valid, and are the same actor
	 *	- Do nothing
	 */
	if (LastActor == nullptr) // LastActor is null
	{
		if (ThisActor != nullptr) // ThisActor is valid
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else // ThisActor is null
		{
			// Case A - Do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr) // ThisActor is null
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else // Both Actors are valid
		{
			if (LastActor != ThisActor) // LastActor is not ThisActor
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else // LastActor is ThisActor
			{
				// Case E - Do nothing
			}
		}
	}
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	// Get the EnhancedInputLocalPlayerSubsystem 
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	
	// Add an InputMappingContext
	Subsystem->AddMappingContext(AuraContext, 0);

	// ~Define cursor behavior: Start
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	// ~Define cursor behavior: End
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// Create a pointer to the EnhancedInputComponent.
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	// Bind the MoveAction InputAction to the EnhancedInputComponent pointer
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// ~Player movement: Start
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Only pass input if the actor is a pawn in the level.
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	// ~Player movement: End
}


