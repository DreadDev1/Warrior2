// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ARPG_BaseCharacter.generated.h"

class UARPG_AbilitySystemComponent;
class UARPG_AttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class WARRIOR_API AARPG_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AARPG_BaseCharacter();
	
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UARPG_AbilitySystemComponent* ARPG_AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UARPG_AttributeSet* ARPGAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UARPG_AbilitySystemComponent* GetARPGAbilitySystemComponent() const {return ARPG_AbilitySystemComponent;}

	FORCEINLINE UARPG_AttributeSet* GetARPGAttributeSet() const {return ARPGAttributeSet;}
};
