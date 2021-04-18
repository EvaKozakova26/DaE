// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Item.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <iostream> 
using namespace std;

// Sets default values
// constructor of the class, called when the Actor is created
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create instance of Root Component defined in .h file
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// each Actor has RootComonent which represents transform of Actot - translation, rotation and scale
	// in UE editor - axis are visible
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(Root);

	// Create the TextRenderComponent and add a generic "Press E to Interact"
	// message and set it to be invisible so the PlayerCharacter can't see it
	// and lastly attach it to the RootComponent.
	NoticeText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NoticeText"));
	NoticeText->SetRelativeLocation(FVector(-130.f, -90.f, 80.f));
	NoticeText->SetRelativeRotation(FQuat(90.0f, 0.f, 90.0f, 1.0f));
	NoticeText->SetText(FText::FromString("Press E to Interact"));
	NoticeText->SetTextRenderColor(FColor::White);
	NoticeText->SetVisibility(false);
	NoticeText->AttachTo(Root);

	// create TextRenderComponent with loot information from the chest (object)
	LootText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("LootText"));
	LootText->SetRelativeLocation(FVector(-200.f, -90.f, 80.f));
	LootText->SetRelativeRotation(FQuat(90.0f, 0.f, 90.0f, 1.0f));
	LootText->SetTextRenderColor(FColor::White);
	LootText->SetVisibility(false);
	LootText->AttachTo(Root);
}

// Called when the game starts or when spawned
// can be used when we want to spawn this Actor dynamically
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FString sText = FString::Printf(TEXT("Actor name is %s"), *this->GetName());
	UE_LOG(LogActor, Warning, TEXT("**** UE4 started - %s "), *sText);

	// gets current location of actor mesh
	mCurrentMeshLocation = Mesh->GetRelativeTransform().GetLocation();

	// init loot items
	// AItem - musi byt pointer, protoze TArray je plneno pointery (kvuli garbage collectoru)
	// inicializace itemu = musi se spawnout actor do sveta (item je Actor)
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	AItem* ItemPrkno = (AItem*) GetWorld()->SpawnActor<AItem>(SpawnParams);
	if (ItemPrkno != nullptr) {
		ItemPrkno->SetName("Prkno");
		ItemsInChest.Add(ItemPrkno);
	}

	AItem* ItemKamen = (AItem*) GetWorld()->SpawnActor<AItem>(SpawnParams);
	if (ItemKamen != nullptr) {
		ItemKamen->SetName("Kamen");
		ItemsInChest.Add(ItemKamen);
	}


	// find length of array
	int len = sizeof(ItemsInChest) / sizeof(ItemsInChest[0]);
	// write out items in chest (names)
	FString lootText = "";
	if (len > 0) {
		for (int i = 0; i <= len - 1; i++) {
			AItem* tempItem = ItemsInChest[i];
			lootText.Append("[" + FString::FromInt(i + 1) + "]").Append(FString::Printf(TEXT(" %s"), *tempItem->GetName()));
			lootText.Append("\n");
		}
	}
	LootText->SetText(lootText);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// calculates the distance between player and this actor
	float distance = this->GetDistanceTo(Player); 
	FVector meshLocation = mCurrentMeshLocation;

	if (distance < 150)
	{
		NoticeText->SetVisibility(true);

		// lift the object up (increase Z location)
		// mesh component has to be set to "moveable" in UE editor
		if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustPressed(EKeys::E))
		{
			NoticeText->SetRelativeLocation(FVector(-130.f, -50.f, 80.f));
			NoticeText->SetText(FText::FromString("Looting..."));
			meshLocation.Z += 30;
			Mesh->SetRelativeLocation(meshLocation);
			LootText->SetVisibility(true);
		}
	}
	else {
		// set default state for object and notice text
		NoticeText->SetRelativeLocation(FVector(-130.f, -90.f, 80.f));
		NoticeText->SetText(FText::FromString("Press E to Interact"));
		NoticeText->SetVisibility(false);
		Mesh->SetRelativeLocation(mCurrentMeshLocation);
		LootText->SetVisibility(false);
	}
	
}

