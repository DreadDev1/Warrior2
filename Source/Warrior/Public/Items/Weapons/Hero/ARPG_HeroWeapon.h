// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARPG_Types/ARPG_StructTypes.h"
#include "Items/Weapons/ARPG_WeaponBase.h"
#include "ARPG_HeroWeapon.generated.h"




UCLASS()
class WARRIOR_API AARPG_HeroWeapon : public AARPG_WeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FARPG_HeroWeaponData HeroWeaponData;
};
