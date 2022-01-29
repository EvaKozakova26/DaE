// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "GeneralItem.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 20;

	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}
}


bool UInventoryComponent::AddItem(UGeneralItem* Item)
{
	if (Items.Num() >= Capacity || !Item) 
	{
		return false;
	}

	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);
	
	// Update UI
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UGeneralItem* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		// Update UI
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;

}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


