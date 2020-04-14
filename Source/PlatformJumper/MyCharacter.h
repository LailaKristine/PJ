// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class PLATFORMJUMPER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void Attack();
	void Jump(float axisValue);

	void MoveForward(float axisValue);
	void MoveRight(float axisValue);

	UPROPERTY(EditAnywhere, Blueprintreadwrite)
		float Health = 6.0f;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<class AAttack> Attack_BP;

};