// Fill out your copyright notice in the Description page of Project Settings.


#include "Attack.h"

// Sets default values
AAttack::AAttack()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	collider->SetupAttachment(RootComponent);
	Cast<UShapeComponent>(collider)->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = collider;

}

// Called when the game starts or when spawned
void AAttack::BeginPlay()
{
	Super::BeginPlay();

	Cast<UShapeComponent>(collider)->SetGenerateOverlapEvents(true);
	collider->OnComponentBeginOverlap.AddDynamic(this, &AAttack::OnOverlapBegin);

}

void AAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	delay -= DeltaTime;

	if (delay <= 0)
	{
		this->Destroy();
	}

}

void AAttack::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}




