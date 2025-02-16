// Copyright Evan Allen


#include "Character/AuraEnemy.h"

#include "DungeonCrawler/DungeonCrawler.h"

AAuraEnemy::AAuraEnemy()
{
	// Blocks the visibility collision channel for all enemies.
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	// Set the CustomDepth of the enemy mesh and weapon to true.
	//Set the CustomDepthStencilValue on the enemy mesh and weapon to the CUSTOM_DEPTH_RED const.
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	// Set the CustomDepth on the enemy mesh and weapon to false.
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
