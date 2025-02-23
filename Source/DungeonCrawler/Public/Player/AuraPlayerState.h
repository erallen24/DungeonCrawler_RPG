// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class DUNGEONCRAWLER_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	// Default constructor
	AAuraPlayerState();
	
	//Static override (Getter)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	// Getter 
	UAttributeSet* GetAttributeSet() const { return AttributeSet; };
protected:
	// ~Member Variables: Start
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	// ~Member Variables: End
};
