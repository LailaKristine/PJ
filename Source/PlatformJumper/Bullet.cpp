// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
		collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	collider->SetupAttachment(RootComponent);
	Cast<UShapeComponent>(collider)->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = collider;
	*/


}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	//Cast<UShapeComponent>(collider)->SetGenerateOverlapEvents(true);
	//collider->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlapBegin);
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * speed * DeltaTime;
	SetActorLocation(NewLocation);


	deathTimer -= DeltaTime;

	if (deathTimer <= 0)
	{
		this->Destroy();
	}

}

void ABullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*
	AMyCharacter* getHealth = Cast<AMyCharacter>(OtherActor);

	if (OtherComp->GetName() == "collider")
	{	
		getHealth->Health -= 1.f;
		UE_LOG(LogTemp, Warning, TEXT("Applying damage"));
	}
	*/
	
}


