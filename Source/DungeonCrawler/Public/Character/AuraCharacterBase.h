// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class DUNGEONCRAWLER_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	//Constructor
	AAuraCharacterBase();

	// Override for AbilitySystemComponent
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	// Getter 
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	// Static override
	virtual void BeginPlay() override;

	// ~Member variables: Start
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	// ~Member variables: End

	virtual void InitAbilityActorInfo();
};
