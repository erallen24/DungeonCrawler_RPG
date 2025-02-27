// Copyright Evan Allen


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Aura_AttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	// Store a ptr to the AuraAttributeSet
	const UAura_AttributeSet* AuraAttributeSet = CastChecked<UAura_AttributeSet>(AttributeSet);

	// Using the ptr and the class delegates for health and max health change, broadcast the initial values
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());

	// Using the ptr and the class delegates for mana and max mana change, broadcast the initial values
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	// Store a ptr to the AuraAttributeSet
	const UAura_AttributeSet* AuraAttributeSet = CastChecked<UAura_AttributeSet>(AttributeSet);

	// Bind the attributes to the respected events
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data)const 
{
	// Update the health when event is triggered 
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	// Update the  max health when event is triggered 
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	// Update the mana when event is triggered 
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	// Update the  max mana when event is triggered 
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
