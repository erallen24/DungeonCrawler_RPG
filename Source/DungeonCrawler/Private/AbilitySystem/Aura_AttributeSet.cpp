// Copyright Evan Allen


#include "AbilitySystem/Aura_AttributeSet.h"

#include "Net/UnrealNetwork.h"

UAura_AttributeSet::UAura_AttributeSet()
{
	// ~Initialize attribute values: Start
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
	InitMana(100.0f);
	InitMaxHealth(100.0f);
	// ~Initialize attribute values: End
}

void UAura_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	// Register Health to be replicated with no conditions and always replicate regardless of change.
	DOREPLIFETIME_CONDITION_NOTIFY(UAura_AttributeSet, Health, COND_None, REPNOTIFY_Always);

	// Register MaxHealth to be replicated with no conditions and always replicate regardless of change.
	DOREPLIFETIME_CONDITION_NOTIFY(UAura_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	// Register Mana to be replicated with no conditions and always replicate regardless of change.
	DOREPLIFETIME_CONDITION_NOTIFY(UAura_AttributeSet, Mana, COND_None, REPNOTIFY_Always);

	// Register MaxMana to be replicated with no conditions and always replicate regardless of change.
	DOREPLIFETIME_CONDITION_NOTIFY(UAura_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}
void UAura_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	// Update Health Attribute
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura_AttributeSet, Health, OldHealth);
}
void UAura_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	// Update MaxHealth Attribute
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura_AttributeSet, MaxHealth, OldMaxHealth);
}
void UAura_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	// Update Mana Attribute
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura_AttributeSet, Mana, OldMana);
}
void UAura_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	// Update MaxMana Attribute
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura_AttributeSet, MaxMana, OldMaxMana);
}
