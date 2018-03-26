// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "UObject/ScriptMacros.h"
#include "EnvironmentQuery/Items/EnvQueryItemType.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "EnvQueryInstanceBlueprintWrapper.generated.h"

class AActor;
struct FEnvQueryRequest;

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "EQS Query Instance"))
class AIMODULE_API UEnvQueryInstanceBlueprintWrapper : public UObject, public IEQSQueryResultSourceInterface
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEQSQueryDoneSignature, UEnvQueryInstanceBlueprintWrapper*, QueryInstance, EEnvQueryStatus::Type, QueryStatus);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "EQS")
	int32 QueryID;

	EEnvQueryRunMode::Type RunMode;

	TSharedPtr<FEnvQueryResult> QueryResult;
	TSharedPtr<FEnvQueryInstance> QueryInstance;

	UPROPERTY(BlueprintReadOnly, Category = "EQS")
	TSubclassOf<UEnvQueryItemType> ItemType;

	/** index of query option, that generated items */
	UPROPERTY(BlueprintReadOnly, Category = "EQS")
	int32 OptionIndex;
	
	UPROPERTY(BlueprintAssignable, Category = "AI|EQS", meta = (DisplayName = "OnQueryFinished"))
	FEQSQueryDoneSignature OnQueryFinishedEvent;

public:
	UEnvQueryInstanceBlueprintWrapper(const FObjectInitializer& ObjectInitializer);
	
	void RunQuery(const EEnvQueryRunMode::Type InRunMode, FEnvQueryRequest& QueryRequest);

	UFUNCTION(BlueprintPure, Category = "AI|EQS")
	float GetItemScore(int32 ItemIndex);

	/** return an array filled with resulting actors. Not that it makes sense only if ItemType is a EnvQueryItemType_ActorBase-derived type */
	UFUNCTION(BlueprintPure, Category = "AI|EQS")
	TArray<AActor*> GetResultsAsActors();

	/** returns an array of locations generated by the query. If the query generated Actors the the array is filled with their locations */
	UFUNCTION(BlueprintPure, Category = "AI|EQS")
	TArray<FVector> GetResultsAsLocations();

	UFUNCTION(BlueprintCallable, Category = "AI|EQS")
	void SetNamedParam(FName ParamName, float Value);

protected:
	void OnQueryFinished(TSharedPtr<FEnvQueryResult> Result);
};
