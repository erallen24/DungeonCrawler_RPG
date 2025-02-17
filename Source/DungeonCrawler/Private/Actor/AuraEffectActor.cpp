// Copyright Evan Allen


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Aura_AttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 
	PrimaryActorTick.bCanEverTick = false;

	// Create static mesh and set it to the root component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	// Create a sphere component and attatch it to the root component
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// if the ASCInterface is not null
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		// Get the AttributeSet of the other actor
		const UAura_AttributeSet* AuraAttributeSet = Cast<UAura_AttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAura_AttributeSet::StaticClass()));
		
		// TODO: Change this to apply Gameplay Effect. For now, using const_cast. ONLY DO THIS FOR TESTING!
		// Update Attributes
		UAura_AttributeSet* MutableAuraAttributeSet= const_cast<UAura_AttributeSet*>(AuraAttributeSet);
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.0f);
		Destroy();
	}
}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

	// Bind Overlap Event to sphere object 
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
}




