// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
// constructor of the class, called when the Actor is created
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
// can be used when we want to spawn this Actor dynamically
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FString sText = FString::Printf(TEXT("Actor name is %s"), *this->GetName());
	UE_LOG(LogActor, Warning, TEXT("**** UE4 started - %s "), *sText);
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

