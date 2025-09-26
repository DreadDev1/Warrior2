

#pragma once

#include "GameplayTagContainer.h"
#include "ARPG_StructTypes.generated.h"

class UARPG_HeroLinkedAnimLayer;
class UARPG_GameplayAbility;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FARPG_HeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UARPG_GameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FARPG_HeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UARPG_HeroLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FARPG_HeroAbilitySet> DefaultWeaponAbilities;
};