// Copyright Evan Allen


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Aura_AttributeSet.h"

#include "UI/HUD/AuraHUD.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	// Store a ptr to the AuraAttributeSet
	const UAura_AttributeSet* AuraAttributeSet = CastChecked<UAura_AttributeSet>(AttributeSet);

	// Using the ptr and the class delegates for health and max health change, broadcast the initial values
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
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
