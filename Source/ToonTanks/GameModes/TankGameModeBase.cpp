// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay()
{
	// Get references and game win/lose conditions.

	// Call HandleGameStart() to initialise the start countdown, turrent activation, pawn check etc.

	Super::BeginPlay();

	HandleGameStart();
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//Check what type of Actor died. If Turrent, tally. If Player -> go to lose condition.
	if (DeadActor == PlayerTank)
	{
		PlayerTank->HandleDestruction();
		HandleGameOver(false);

		/*if (PlayerControllerRef)
		{
			
		}*/
	}
	else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		TargetTurrets--;
		if (TargetTurrets <= 0)
		{
			HandleGameOver(true);
		}
	}
}

int32 ATankGameModeBase::GetTargetTurretCount()
{
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	return TurretActors.Num();
}

void ATankGameModeBase::HandleGameStart()
{
	//Initialise the start countdown, turret activation, pawn check etc.
	//Call Blueprint version GameStart();
	TargetTurrets = GetTargetTurretCount();
	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	//PlayerControllerRef = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));

	GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	//See if the player has destroyed all the turrents, show win result.
	//else if turret destroyed player, show lose result.
	//Call blueprint version GameOver(bool).
	GameOver(PlayerWon);
}


