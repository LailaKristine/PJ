 // Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	collider->SetupAttachment(RootComponent);
	Cast<UShapeComponent>(collider)->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = collider;

}


// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	Cast<UShapeComponent>(collider)->SetGenerateOverlapEvents(true);
	collider->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::recieveDamage(float Damage)
{
	health -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("EnemyHealth = %f"), health);
}

void AEnemy::checkHealth()
{
	if (health <= 0)
	{
		this->Destroy();
	}
}

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->GetName() == "collider")
	{
		recieveDamage(1.f);
		checkHealth();
		UE_LOG(LogTemp, Warning, TEXT("i was hit"));
	}

}