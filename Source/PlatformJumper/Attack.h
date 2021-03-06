// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.h"
#include "Enemy.h"
#include "Engine/Classes/Components/SphereComponent.h"
#include "Attack.generated.h"

UCLASS()
class PLATFORMJUMPER_API AAttack : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAttack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float delay = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UShapeComponent* collider;

	UFUNCTION(BlueprintCallable)
		virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};