// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class DANMENDOZAGAME2342_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayerHealth; // The current health the player has


    bool IsDead; // Inidicates if the player is dead
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    /* [Objects That Will Appear in The Blueprint's Hierarchy] */
    UPROPERTY(EditAnywhere)
    class UCameraComponent* MyCamera; // The player's camera

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* Arms; // The player's weapon
    
    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* Weapon; // The player's weapon
    
    UPROPERTY(EditAnywhere)
    class UBoxComponent* BoxCollider; // The collision for the player's weapon
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class USceneComponent* ProjectileSpawnPosition; // Position where the bullet will spawn

    UPROPERTY(EditAnywhere)
    TSubclassOf<class AProjectile> proj; // Reference to the weapon's projectile

    /* [Character Movement] */
    void MoveFB(float InputValue);
    void MoveLR(float InputValue);

    /* [Camera Movement] */
    void MouseUD(float InputValue);
    void MouseLR(float InputValue);

    // Other Character actions
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Shoot();

    void Shoot_Implementation();

    // Restarts the level
    void RestartLevel();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
