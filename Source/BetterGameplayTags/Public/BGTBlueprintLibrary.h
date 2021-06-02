// Copyright 2021 Skyler Clark. All Rights Reserved.

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "BGTBlueprintLibrary.generated.h"

UCLASS()
class UBGTBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Gameplay Tag To Name", CompactNodeTitle = "->", BlueprintAutocast), Category = "Better Gameplay Tags")
	static FName Conv_GameplayTagToName(FGameplayTag GameplayTag);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Name To Gameplay Tag", CompactNodeTitle = "->", BlueprintAutocast), Category = "Better Gameplay Tags")
	static FGameplayTag Conv_NameToGameplayTag(FName Name);


};