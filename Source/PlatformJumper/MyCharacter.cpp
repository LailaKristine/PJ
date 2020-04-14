// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Attack.h"
#include "SpawnP.h"
#include "Components/InputComponent.h"
#include "Engine/Classes/Engine/LocalPlayer.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyCharacter::Attack);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}

void AMyCharacter::Jump(float axisValue)
{
	AddMovementInput(FVector(0.f, 0.f, 1.f), axisValue);
}

void AMyCharacter::MoveForward(float axisValue)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), axisValue);
}

void AMyCharacter::MoveRight(float axisValue)
{
	AddMovementInput(FVector(0.f, 1.f, 0.f), axisValue);
}

void AMyCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attacking"));
	GetWorld()->SpawnActor<AAttack>(Attack_BP, GetActorLocation() + FVector(100.f, 0.f, 0.f), GetActorRotation());
}


