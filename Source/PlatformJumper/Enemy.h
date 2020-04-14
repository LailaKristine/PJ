// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Enemy.generated.h"

UCLASS()
class PLATFORMJUMPER_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void recieveDamage(float Damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float health = 12;

	UFUNCTION(BlueprintCallable)
		void checkHealth();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UShapeComponent* collider;

	UFUNCTION(BlueprintCallable)
		virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
