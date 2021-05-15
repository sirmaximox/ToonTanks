// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBasic.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBasic : public APlayerController
{
	GENERATED_BODY()
	
public:
	void GetTest(int32 test);

	bool testeo;
};
