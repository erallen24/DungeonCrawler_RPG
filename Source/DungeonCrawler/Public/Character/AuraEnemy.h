// Copyright Evan Allen

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONCRAWLER_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	// Default constructor
	AAuraEnemy();

	// ~Enemy Interface: Start
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	// ~Enemy Interface: End

protected:
	// Static override
	virtual void BeginPlay() override;
};
