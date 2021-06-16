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

FGameplayTagContainer UBGTBlueprintLibrary::FilterTags(const FGameplayTagContainer &Tags, const FGameplayTagContainer &Filter, bool bExactMatch)
{
	return bExactMatch ? Tags.FilterExact(Filter) : Tags.Filter(Filter);

}

TArray<FGameplayTag> UBGTBlueprintLibrary::GetTagsWithParent(const FGameplayTagContainer &Tags, FGameplayTag ParentTag)
{
	TArray<FGameplayTag> ReturnArray;

	for (auto TagIt = Tags.CreateConstIterator(); TagIt; ++TagIt )
	{
		FGameplayTag Tag = *TagIt;
		if (Tag.MatchesTag(ParentTag))
		{
			ReturnArray.Add(Tag);
		}
	}

	return ReturnArray;
}