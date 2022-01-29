// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "BaseCharacter.h"


void UFoodItem::Use(class ABaseCharacter* Character)
{
	// grab character (is valid)
	if (Character)
	{
		// give him health
		Character->Health += HealthToHeal;
	}
}

