// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RoboEyes.h"

using namespace std;

URoboEyes::URoboEyes() {
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	SetStaticMesh(SphereVisualAsset.Object);

	RelativeLocation = FVector(0.f, 0.f, 0.f);
	playerSighted = false;
}

// Called every frame
void URoboEyes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	for (std::list<UPointOfInterest *>::iterator iterator = targets.begin(), end = targets.end(); iterator != end; ++iterator) {
		//std::cout << *iterator;
		if (canSeeTarget((*iterator))) {
			if (targetMap.count((*iterator)) < 0 || !targetMap[(*iterator)]) {
				targetMap[(*iterator)] = true;
			//	UE_LOG(LogTemp, Warning, TEXT("EYES: target sighted - %s"), *(*iterator)->getTargetType());

				RobotMessage message("eyes", "player sighted", *iterator);
				componentController->submitMessage(message);
			}
		}
		else {
			targetMap[(*iterator)] = false;
			list<UPointOfInterest *>::iterator prev = iterator;
			iterator--;
			//UTargetInfo2 infoCopy(UTargetInfo2(*(*iterator)));
			RobotMessage message("eyes", "player lost", *prev);
			(*prev) = NULL;
			targets.erase(prev);
			componentController->submitMessage(message);
		}
	}
	
/*	for (int i = 0; i < targets.size(); i++) {
		if (canSeeTarget(targets[i])) {
			targetMap[targets[i]->getTargetID()] = true;
		}
		else {
			targetMap[targets[i]->getTargetID()] = false;
			targets.remove(targets[i]->getTargetID());

			//TODO remove from vector
		}
	}*/
	/*bool playerInSight = canSeePlayer();

	if (playerInSight && !playerSighted) {
		RobotMessage message("eyes", "player sighted");
		componentController->submitMessage(message);
		playerSighted = true;
	}
	else if (!playerInSight && playerSighted) {
		RobotMessage message("eyes", "player lost");
		componentController->submitMessage(message);
		playerSighted = false;
	}*/

}

bool URoboEyes::canSeeTarget(UPointOfInterest * target) {
	UWorld * world = GetWorld();
	//FVector dir = world->GetFirstPlayerController()->GetCharacter()->GetActorLocation();// GetActorLocation();
	FVector dir = target->getTarget()->GetActorLocation();// GetActorLocation();

	FHitResult hit;
	world->LineTraceSingle(hit, this->RelativeLocation + this->AttachParent->GetAttachmentRootActor()->GetActorLocation(), dir, FCollisionQueryParams(true),
		FCollisionObjectQueryParams(
		ECC_TO_BITFIELD(ECollisionChannel::ECC_Pawn)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_Visibility)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_WorldStatic)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_WorldDynamic)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_PhysicsBody)));

	return hit.GetActor() == target->getTarget();
}

void URoboEyes::InitializeComponent() {
	Super::InitializeComponent();
	/*TArray<UAIPerceptionComponent *> Comps;
	GetAttachmentRootActor()->GetComponents(Comps);
	UE_LOG(LogTemp, Warning, TEXT("seeking sensing component..."));
	if (Comps.Num() > 0) {
		UE_LOG(LogTemp, Warning, TEXT("...sensing component found!!!"));
		UAIPerceptionComponent * FoundComp = Comps[0];
		//FoundComp->
	}*/
	TArray<UPawnSensingComponent*> Comps;
	GetAttachmentRootActor()->GetComponents(Comps);
	//UE_LOG(LogTemp, Warning, TEXT("EYES: checking for UPawnSensingComponent..."));
	if (Comps.Num() > 0) {
		//	UE_LOG(LogTemp, Warning, TEXT("...UPawnSensingComponent found!!!"));
		UPawnSensingComponent* FoundComp = Comps[0];
		//FoundComp->registerListener(this);
		//listeners.push_back(FoundComp);
		FoundComp->OnSeePawn.AddDynamic(this, &URoboEyes::OnSeePawn);

		//do stuff with FoundComp
	}
}

void URoboEyes::OnSeePawn(APawn *OtherPawn) {
	//UE_LOG(LogTemp, Warning, TEXT("EYES: Vision info received"));
	TArray<UPointOfInterest*> Comps;
	OtherPawn->GetComponents(Comps);
	//UE_LOG(LogTemp, Warning, TEXT("EYES: checking for UPointOfInterest..."));
	if (Comps.Num() > 0) {
		//UE_LOG(LogTemp, Warning, TEXT("...UPointOfInterest found!!!"));
		UPointOfInterest * FoundComp = Comps[0];
		//UTargetInfo2 * info = FoundComp->getTargetInfo();
		if (targetMap.count(FoundComp) == 0 || !targetMap[FoundComp]) {
			targets.push_back(FoundComp);
		}
		//FoundComp->registerListener(this);
		//listeners.push_back(FoundComp);
		//FoundComp->OnSeePawn.AddDynamic(this, &URoboEyes::OnSeePawn);
	}

}

/*void URoboEyes::PostInitProperties() {
	//Super::PostInitializeComponent();
	Super::PostInitProperties();
	Super::Post
	TArray<UPawnSensingComponent*> Comps;
	GetAttachmentRootActor()->GetComponents(Comps);
	//UE_LOG(LogTemp, Warning, TEXT("EYES: checking for UPawnSensingComponent..."));
	if (Comps.Num() > 0) {
	//	UE_LOG(LogTemp, Warning, TEXT("...UPawnSensingComponent found!!!"));
		UPawnSensingComponent* FoundComp = Comps[0];
		//FoundComp->registerListener(this);
		//listeners.push_back(FoundComp);
		FoundComp->OnSeePawn.AddDynamic(this, &URoboEyes::OnSeePawn);

		//do stuff with FoundComp
	}
}*/