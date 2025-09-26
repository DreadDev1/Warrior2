// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARPG_GameplayAbility.h"
#include "ARPG_HeroGameplayAbility.generated.h"

class AARPG_HeroCharacter;
class AARPG_HeroController;
/**
 * 
 */
UCLASS()
class WARRIOR_API UARPG_HeroGameplayAbility : public UARPG_GameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "ARPG_|Ability")
	AARPG_HeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "ARPG_|Ability")
	AARPG_HeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "ARPG_|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AARPG_HeroCharacter> CachedARPG_HeroCharacter;
	TWeakObjectPtr<AARPG_HeroController> CachedARPG_HeroController;
};
