// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RoboEyes.h"




// Sets default values
ARoboEyes::ARoboEyes() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//UPROPERTY(VisibleDefaultsOnly, Category = Test)
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));

	//UPROPERTY(VisibleDefaultsOnly, Category = Test)
	ConstructorHelpers::FObjectFinder <UMaterial>Material_Green(TEXT("Material'/Game/AutoDoor/progressBarGreen.progressBarGreen'"));

	//UPROPERTY(VisibleDefaultsOnly, Category = Test)
	ConstructorHelpers::FObjectFinder <UMaterial>Material_Red(TEXT("Material'/Game/AutoDoor/progressBarRed.progressBarRed'"));
// Sets default values
	red = Material_Red.Object;
	green = Material_Green.Object;
	isGreen = false;
	seconds = 0;
	//cone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("/Engine/BasicShapes/Cube"));
	UE_LOG(LogTemp, Warning, TEXT("before"));
	cone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone'"));
	UE_LOG(LogTemp, Warning, TEXT("after"));
	RootComponent = cone;
	cone->RelativeLocation = FVector(0.f, 0.f, 0.f);


	cone->SetStaticMesh(SphereVisualAsset.Object);
	cone->SetMaterial(0, Material_Red.Object);
	//seconds = 0.f;
}

// Called when the game starts or when spawned
void ARoboEyes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoboEyes::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
	//seconds += DeltaTime;
	if (canSeePlayer()) {
		cone->SetMaterial(0, green);
	}
	else {
		cone->SetMaterial(0, red);
	}
	/*if (seconds > 2) {
		if (isGreen) {
			cone->SetMaterial(0, red);
			isGreen = false;
		}
		else {
			cone->SetMaterial(0, green);
			isGreen = true;
		}
		seconds = 0;
	}*/
}

bool ARoboEyes::canSeePlayer() {
	UWorld * world = GetWorld();
	FVector dir = world->GetFirstPlayerController()->GetCharacter()->GetActorLocation();// GetActorLocation();
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::SanitizeFloat(dir.X));
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, FString::SanitizeFloat(dir.Y));
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Blue, FString::SanitizeFloat(dir.Z));

	FHitResult hit;
	world->LineTraceSingle(hit, this->GetActorLocation(), dir, FCollisionQueryParams(true), 
		FCollisionObjectQueryParams(
			ECC_TO_BITFIELD(ECollisionChannel::ECC_Pawn) 
			| ECC_TO_BITFIELD(ECollisionChannel::ECC_Visibility) 
			| ECC_TO_BITFIELD(ECollisionChannel::ECC_WorldStatic)
			| ECC_TO_BITFIELD(ECollisionChannel::ECC_WorldDynamic)
			| ECC_TO_BITFIELD(ECollisionChannel::ECC_PhysicsBody)));
	
	return hit.GetActor() == world->GetFirstPlayerController()->GetCharacter();
}
