// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Projectile.h"
#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Add Camera
    MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
    MyCamera->SetupAttachment(RootComponent);
    MyCamera->bUsePawnControlRotation = true; 

    // Add weapon and attach it to the camera
    Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Weapon"));
    Weapon->SetupAttachment(MyCamera);

    // Add collider and attach it to weapon
    BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Weapon Collision"));
    BoxCollider->SetupAttachment(Weapon);

    // Add projectile spawn point and attach it to weapon
    ProjectileSpawnPosition = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
    ProjectileSpawnPosition->SetupAttachment(Weapon);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    /* [Set Up Player Bindings] */

    // Jumping
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);

    // Shooting
    PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyCharacter::Shoot);

    // Player Movement
    PlayerInputComponent->BindAxis("MoveFB", this, &AMyCharacter::MoveFB);
    PlayerInputComponent->BindAxis("MoveLR", this, &AMyCharacter::MoveLR);

    // Camera Movement
    PlayerInputComponent->BindAxis("MouseUD", this, &AMyCharacter::MouseUD);
    PlayerInputComponent->BindAxis("MouseLR", this, &AMyCharacter::MouseLR);
}

// Moves the character forwards and backwrds
void AMyCharacter::MoveFB(float InputValue)
{
    FVector forwardDir = GetActorForwardVector();
    AddMovementInput(forwardDir, InputValue);
}

void AMyCharacter::MoveLR(float InputValue)
{
    FVector rightDir = GetActorRightVector();
    AddMovementInput(rightDir, InputValue);
}

void AMyCharacter::MouseUD(float InputValue)
{
   AddControllerPitchInput(InputValue); 
}

void AMyCharacter::MouseLR(float InputValue)
{
    AddControllerYawInput(InputValue);
}

void AMyCharacter::Shoot()
{
    GetWorld()->SpawnActor<AProjectile>(proj, ProjectileSpawnPosition->GetComponentLocation(),
                                        ProjectileSpawnPosition->GetComponentRotation());
}
