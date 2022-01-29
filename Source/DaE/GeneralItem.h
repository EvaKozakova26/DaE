// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GeneralItem.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class DAE_API UGeneralItem : public UObject
{
	GENERATED_BODY()

public:

	UGeneralItem();

	virtual class UWorld* GetWorld() const { return World; }

	// item musi zmat, v jakem je svete, aby se mohl spawnovat
	UPROPERTY(Transient)
	class UWorld* World;

	/**The text for using the item (Eat, Drop, etc...)*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText UseActionText;

	/**The mesh to display for this items pickup*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	class UStaticMesh* PickupMesh;

	/**The thumbnail for this item*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	class UTexture2D* Thumbnail;

	/**The display name for this item in the inventory*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText ItemDisplayName;

	/**The description name for this item*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText ItemDescription;

	/**The weight of the item*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float Weight;

	/**The inventory that owns this item*/
	UPROPERTY()
	class UInventoryComponent* OwningInventory;

	// pure virtual - ciste virtualni metoda, nevolam totiy tuto metodu primo na AGeneralItem, ale na jeho potomkovi (rodic je abstraktni)
	virtual void Use(class ABaseCharacter* Character) PURE_VIRTUAL(UGeneralItem, );

	// blueprintova obdoba Use metody
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class ABaseCharacter* Character);
	
};
