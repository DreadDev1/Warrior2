// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ARPG_BaseAniminstance.h"
#include "ARPG_HeroLinkedAnimLayer.generated.h"

class UARPG_HeroAnimInstance;
/**
*
 */
UCLASS()
class WARRIOR_API UARPG_HeroLinkedAnimLayer : public UARPG_BaseAniminstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UARPG_HeroAnimInstance* GetHeroAnimInstance() const;
};
