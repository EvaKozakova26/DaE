// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class DAE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	AActor* Player;

	// The TextRenderComponent that appears above this Actor when the PlayerCharacter
	// is able to interact with a part of it.
	UPROPERTY(EditAnywhere)
    class UTextRenderComponent* NoticeText;

	// info about loot contained in chest or something
	UPROPERTY(EditAnywhere)
	class UTextRenderComponent* LootText;

	// items in chest ready to be looted
	TArray<FString> ItemsInChest;


private:
	FVector mCurrentMeshLocation;

};
