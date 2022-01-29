// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneralItem.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS()
class DAE_API UFoodItem : public UGeneralItem
{
	GENERATED_BODY()

public:

	/**The health of the food*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float HealthToHeal;

protected:

	/**
	Food heals the player
	*/
	virtual void Use(class ABaseCharacter* Character) override;

};
