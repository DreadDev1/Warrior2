// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "ARPG_Types/ARPG_StructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UARPG_AbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FARPG_HeroAbilitySet> HeroStartUpAbilitySets;
};
