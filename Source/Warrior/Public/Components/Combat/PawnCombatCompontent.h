

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatCompontent.generated.h"

class AARPG_WeaponBase;
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ARPG_|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AARPG_WeaponBase* InWeaponToRegister,bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "ARPG_|Combat")
	AARPG_WeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "ARPG_|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "ARPG_|Combat")
	AARPG_WeaponBase* GetCharacterCurrentEquippedWeapon() const;

private:
	TMap<FGameplayTag,AARPG_WeaponBase*> CharacterCarriedWeaponMap;
	
};