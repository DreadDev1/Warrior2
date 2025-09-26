// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/ARPG_CharacterAniminstance.h"
#include "Characters/ARPG_BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UARPG_CharacterAniminstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AARPG_BaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UARPG_CharacterAniminstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
}
