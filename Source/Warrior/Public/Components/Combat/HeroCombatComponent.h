

#pragma once

#include "CoreMinimal.h"
#include "PawnCombatCompontent.h"
#include "HeroCombatComponent.generated.h"

class AARPG_HeroWeapon;
/**
 * 
 */
UCLASS()
class WARRIOR_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ARPG_|Combat")
	AARPG_HeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
};