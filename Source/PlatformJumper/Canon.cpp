// Fill out your copyright notice in the Description page of Project Settings.


#include "Canon.h"
#include "Bullet.h"
#include "Engine/World.h"

// Sets default values
ACanon::ACanon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACanon::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ACanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	delay -= DeltaTime;

	if (delay <= 0)
	{
		
		GetWorld()->SpawnActor<ABullet>(Bullet_BP, GetActorLocation() + FVector(0.f, 100.f, 60.f), GetActorRotation() + FRotator(0.f, 90.f, 0.f));
		delay = 1.f;
	}
	

	

}

