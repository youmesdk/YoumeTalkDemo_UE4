// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "YouMeBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE4_YOUMETALK_API UYouMeBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		static FString GetPlatformBaseDir();

	UFUNCTION(BlueprintCallable)
		static FString LoadBackgroundMusic();
};
