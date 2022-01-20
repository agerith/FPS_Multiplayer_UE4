// Fill out your copyright notice in the Description page of Project Settings.

#include "MyDamageType.h"
#include "TestRyseUp.h"

UMyDamageType::UMyDamageType(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	HeadDmgModifier = 2.0f;
	LimbDmgModifier = 0.5f;

	bCanDieFrom = true;
}


bool UMyDamageType::GetCanDieFrom()
{
	return bCanDieFrom;
}


float UMyDamageType::GetHeadDamageModifier()
{
	return HeadDmgModifier;
}

float UMyDamageType::GetLimbDamageModifier()
{
	return LimbDmgModifier;
}


