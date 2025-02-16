// Copyright Evan Allen


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/Aura_AbilitySystemComponent.h"
#include "AbilitySystem/Aura_AttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	// Construct AbilitySystemComponent: Start
	AbilitySystemComponent = CreateDefaultSubobject<UAura_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	// Construct AbilitySystemComponent: End
	
	// Construct AttributeSet
	AttributeSet = CreateDefaultSubobject<UAura_AttributeSet>("AttributeSet");
	
	// Server update speed  
	SetNetUpdateFrequency(100.0f);
}

// Getter for AbilitySystemComponent
UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
