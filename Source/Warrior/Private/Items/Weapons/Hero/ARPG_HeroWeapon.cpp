// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Hero/ARPG_HeroWeapon.h"

void AARPG_HeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AARPG_HeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
