// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	// Sets WidgetController and calls WidgetControllerSet event
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	// Store a pointer to a WidgetController UObject
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	// Event to trigger that the WidgetController has been set
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
