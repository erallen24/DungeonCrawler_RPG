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
	// Setter
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	// ~Public member variables: Start
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	// ~Public member variables: End

protected:
	// Event to trigger that the WidgetController has been set
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
