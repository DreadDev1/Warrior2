// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UARPG_GameplayAbility;
class UARPG_AbilitySystemComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UARPG_AbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UARPG_GameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UARPG_GameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UARPG_GameplayAbility>>& InAbilitiesToGive,UARPG_AbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1);
	
};
