


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/Hero/ARPG_HeroWeapon.h"

AARPG_HeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AARPG_HeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
