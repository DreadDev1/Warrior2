// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ARPG_FunctionLibrary.generated.h"

class UARPG_AbilitySystemComponent;

UENUM()
enum class EARPG_ConfirmType : uint8
{
	Yes,
	No
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UARPG_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UARPG_AbilitySystemComponent* NativeGetARPG_ASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "ARPG_|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "ARPG_|FunctionLibrary")
	static void RemoveGameplayFromActorIfFound(AActor* InActor,FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "ARPG_|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck,EARPG_ConfirmType& OutConfirmType);
};
