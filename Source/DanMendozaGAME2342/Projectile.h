// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class DANMENDOZAGAME2342_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    /* [Objects That Will Appear in The Blueprint's Hierarchy] */
    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere)
    class UBoxComponent* BoxCollider; // The collision for the projectile 

    UPROPERTY(EditAnywhere)
    class UProjectileMovementComponent* ProjectileComponent;

    UPROPERTY(EditAnywhere)
    int ProjectileDamage; // Damage done when hit by the projectile
};
