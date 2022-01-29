// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Components/TextRenderComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <DaE/Item.h>
#include "CanvasItem.h"
#include "Engine/Canvas.h"
#include "GeneralItem.h"
#include "InventoryComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// default value of health
	Health = 100.f;
	InventorySystem = CreateDefaultSubobject<UInventoryComponent>("InventorySystem");
	InventorySystem->Capacity = 20;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<AItem*> ABaseCharacter::GetInventory()
{
	return Inventory;
}

void ABaseCharacter::AddToInventory(AItem* Item) 
{
	Inventory.Add(Item);
}

void ABaseCharacter::ShowInventory()
{
	if (!Canvas) return;

	int invLen = Inventory.Num();
	FString invText = "Inventory:";
	invText.Append("\n");
	for (int i = 0; i <= invLen - 1; i++) {
		AItem* tempItem = Inventory[i];
		invText.Append("[" + FString::FromInt(i + 1) + "]").Append(FString::Printf(TEXT(" %s"), *tempItem->GetName()));
		invText.Append("\n");
	}
	FText SomeText = FText::FromString("Something..");
	FLinearColor TheFontColour = FLinearColor(1.0f, 1.0f, 1.0f);
	FCanvasTextItem NewText(FVector2D(20.0f, 20.0f), SomeText, GEngine->GetSmallFont(), TheFontColour);

	//Text Scale
	//NewText.Scale.Set(ScaleX, ScaleY);
	UE_LOG(LogActor, Warning, TEXT("**** ready to draw to canvas "));

	//Draw
	UE_LOG(LogActor, Warning, TEXT("**** Ready to draw in canvas "));
	
	Canvas->DrawItem(NewText);
}

void ABaseCharacter::UseItem(class UGeneralItem* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this); // bp event
	}
}
