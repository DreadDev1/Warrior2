// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ARPG_BaseCharacter.h"
#include "Game/AbilitySystem/ARPG_AbilitySystemComponent.h"
#include "Game/AbilitySystem/Attributes/ARPG_AttributeSet.h"

// Sets default values
AARPG_BaseCharacter::AARPG_BaseCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	ARPG_AbilitySystemComponent = CreateDefaultSubobject<UARPG_AbilitySystemComponent>(TEXT("ARPGAbilitySystemComponent"));

	ARPGAttributeSet = CreateDefaultSubobject<UARPG_AttributeSet>(TEXT("ARPGAttributeSet"));
}

UAbilitySystemComponent* AARPG_BaseCharacter::GetAbilitySystemComponent() const
{
	return GetARPGAbilitySystemComponent();
}

void AARPG_BaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ARPG_AbilitySystemComponent)
	{
		ARPG_AbilitySystemComponent->InitAbilityActorInfo(this,this);

		ensureMsgf(!CharacterStartUpData.IsNull(),TEXT("Forgot to assign start up data to %s"),*GetName());
	}
}