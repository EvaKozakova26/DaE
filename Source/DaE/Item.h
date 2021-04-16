// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class DAE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UShapeComponent* TBox;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_TBox;

	UPROPERTY(EditAnywhere)
		FString ItemName = FString(TEXT(""));

	void Pickup();

	void GetPlayer(AActor* Player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
