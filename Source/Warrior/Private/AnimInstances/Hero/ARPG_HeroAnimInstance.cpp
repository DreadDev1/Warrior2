// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/ARPG_HeroAnimInstance.h"

#include "Characters/Hero/ARPG_HeroCharacter.h"

void UARPG_HeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AARPG_HeroCharacter>(OwningCharacter);
	}
}

void UARPG_HeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
	}
	
}
