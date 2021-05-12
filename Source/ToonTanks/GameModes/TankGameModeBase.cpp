// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	// Get references and game win/lose conditions.

	// Call HandleGameStart() to initialise the start countdown, turrent activation, pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//Check what type of Actor died. If Turrent, tally. If Player -> go to lose condition.
}

void ATankGameModeBase::HandleGameStart()
{
	//Initialise the start countdown, turret activation, pawn check etc.
	//Call Blueprint version GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	//See if the player has destroyed all the turrents, show win result.
	//else if turret destroyed player, show lose result.
	//Call blueprint version GameOver(bool).
}


