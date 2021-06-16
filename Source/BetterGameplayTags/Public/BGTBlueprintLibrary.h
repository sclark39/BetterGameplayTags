// Copyright 2021 Skyler Clark. All Rights Reserved.

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "BGTBlueprintLibrary.generated.h"

UCLASS(meta = (ScriptName = "BetterGameplayTagLibrary", DisplayName = "Better Gameplay Tag Library"))
class UBGTBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Gameplay Tag To Name", CompactNodeTitle = "->", BlueprintAutocast), Category = "Better Gameplay Tags")
	static FName Conv_GameplayTagToName(FGameplayTag GameplayTag);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Name To Gameplay Tag", CompactNodeTitle = "->", BlueprintAutocast), Category = "Better Gameplay Tags")
	static FGameplayTag Conv_NameToGameplayTag(FName Name);

	/**
	 * Returns a filtered version of this container, returns all tags that match against the tags in FilterContainer
	 *
	 * @param TagContainer			Container that needs filtering
	 * @param FilterContainer		The container to filter against
	 * @param ExactMatch			If true, tags must exactly match one in FilterContainer. If false, tags can match by expanding parents.
	 *
	 * @return A FGameplayTagContainer containing the filtered tags
	 */
	UFUNCTION(BlueprintCallable, Category = "Better Gameplay Tags")
	static FGameplayTagContainer FilterTags(const FGameplayTagContainer &TagContainer, const FGameplayTagContainer &FilterContainer, bool bExactMatch = false);

	/**
	 * Returns all tags in TagContainer that match the ParentFilter tag, expanding parents.
	 *
	 * @param TagContainer			Container To Search
	 * @param ParentTag				The Parent Tag To expand
	 *
	 * @return An array of FGameplayTags containing the children of ParentTags from TagContainer
	 */
	UFUNCTION(BlueprintCallable, Category = "Better Gameplay Tags")
	static TArray<FGameplayTag> GetTagsWithParent(const FGameplayTagContainer &TagContainer, FGameplayTag ParentTag);

};