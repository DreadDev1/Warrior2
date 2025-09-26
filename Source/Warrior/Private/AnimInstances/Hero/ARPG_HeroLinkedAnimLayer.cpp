// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/ARPG_HeroLinkedAnimLayer.h"

#include "AnimInstances/Hero/ARPG_HeroAnimInstance.h"

UARPG_HeroAnimInstance* UARPG_HeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UARPG_HeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
