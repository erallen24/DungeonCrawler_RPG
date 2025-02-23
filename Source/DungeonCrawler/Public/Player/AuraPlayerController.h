// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	// Default constructor
	AAuraPlayerController();
	
	// Static override 
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	// Static overrides
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	// ~Member variables: Start
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
	// ~Member variables:

	// Methods
	void Move(const FInputActionValue& InputActionValue);
	
	void CursorTrace();
	
	

	
};


