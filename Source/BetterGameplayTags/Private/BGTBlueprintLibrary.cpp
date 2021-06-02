// Copyright 2021 Skyler Clark. All Rights Reserved.

#include "BGTBlueprintLibrary.h"

FName UBGTBlueprintLibrary::Conv_GameplayTagToName(FGameplayTag GameplayTag)
{
	return GameplayTag.GetTagName();
}

FGameplayTag UBGTBlueprintLibrary::Conv_NameToGameplayTag(FName Name)
{
	return FGameplayTag::RequestGameplayTag(Name, true);
}
