// Copyright Evan Allen


#include "Character/AuraEnemy.h"

#include "AbilitySystem/Aura_AbilitySystemComponent.h"
#include "AbilitySystem/Aura_AttributeSet.h"
#include "DungeonCrawler/DungeonCrawler.h"

AAuraEnemy::AAuraEnemy()
{
	// Blocks the visibility collision channel for all enemies.
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// Construct AbilitySystemComponent
	AbilitySystemComponent = CreateDefaultSubobject<UAura_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	// Construct AttributeSet
	AttributeSet = CreateDefaultSubobject<UAura_AttributeSet>("AttributeSet");
	
}

void AAuraEnemy::HighlightActor()
{
	// Set the CustomDepth of the enemy mesh to true.
	GetMesh()->SetRenderCustomDepth(true);
	
	//Set the CustomDepthStencilValue on the enemy mesh to the CUSTOM_DEPTH_RED const.
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
	// Set the CustomDepth of the enemy weapon to true.
	Weapon->SetRenderCustomDepth(true);
	
	//Set the CustomDepthStencilValue on the enemy weapon to the CUSTOM_DEPTH_RED const.
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	// Set the CustomDepth on the enemy mesh to false.
	GetMesh()->SetRenderCustomDepth(false);
	
	// Set the CustomDepth on the enemy weapon to false.
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	//Set AbilitySystemComponent ActorInfo to this actor
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}
