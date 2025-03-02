// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class DUNGEONCRAWLER_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Default constructor
	AAuraEffectActor();

protected:
	// ~Methods: Start
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	// ~Methods: End

	// Member variable
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	


};
