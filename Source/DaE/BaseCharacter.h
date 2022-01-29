// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <DaE/Item.h>
#include "GameFramework/Character.h"
#include "Engine/Canvas.h"

#include "BaseCharacter.generated.h"

UCLASS()
class DAE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// items in chest ready to be looted
	TArray<AItem*> Inventory;

	TArray<AItem*> GetInventory();

	void AddToInventory(AItem* item);

	// info about items in inventory
	UPROPERTY(EditAnywhere)
    class UTextRenderComponent* InventoryText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UInventoryComponent* InventorySystem;

	UPROPERTY()
    UCanvas* Canvas;

	void ShowInventory();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float Health;

	UFUNCTION(BlueprintCallable, Category = "Items")
	void UseItem(class UGeneralItem* Item);
};
