


#include "Components/Combat/PawnCombatCompontent.h"
#include "Items/Weapons/ARPG_WeaponBase.h"

#include "ARPG_DebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AARPG_WeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),TEXT("A named named %s has already been added as carried weapon"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister,InWeaponToRegister);

	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"),*InWeaponToRegister->GetName(),*InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
}

AARPG_WeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (AARPG_WeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

AARPG_WeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
