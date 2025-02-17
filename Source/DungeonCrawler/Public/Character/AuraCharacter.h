// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	//Constructor
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();	
};
