// Written by TheBeardedBerry
// MIT License

/**
 * PluginSettings.h
 * ----------------------------------------------------------
 * Created: 2025/06/26
 * Tested: Unreal 5.5
 * ----------------------------------------------------------
 * Minimum viable example of a working settings page.
 *
**/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"              // DeveloperSettings needs to be added to the dependencies list
#include "WMDEditorValidationSettings.generated.h"

USTRUCT()
struct FMyStruct
{
	GENERATED_BODY()

	// structs can be used in settings as well, you just need to be sure to add the UPROPERTY element to each property you want to be visible in the settings window.
	UPROPERTY(EditAnywhere)
	FString Name;
	UPROPERTY(EditAnywhere)
	int32 Quantity;
};

enum class EMyEnum : uint8
{
	A,
	B,
	C,
	D
};

/**
 * config=Editor               defines the section of the project settings page your settings will appear in
 * defaultconfig               tells the editor to put these settings in the Default____.ini files (the ones that arent distributed to users).
 * DisplayName="My Plugin"     is the title of the settings page
 * 
 * the "meta" argument is a very flexible part of the UCLASS/UPROPERTY/etc system. Epic has written out many of the options you can use in the meta arguement here: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/CoreUObject/UObject/UM_3
 */

UCLASS(config=Editor, defaultconfig, meta=(DisplayName="My Plugin"))
class MYPLUGIN_API UPluginSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	// config tells the system to save the value to the .ini filebuf
	UPROPERTY(config, EditAnywhere, Category="Category A")
	int32 MyIntValue;
	
	UPROPERTY(config, EditAnywhere, Category="Category A")
	float MyFloatWithDefaultValue = 32.7f;

	// Subcategories can be defined by adding a pipe "|" between the category and sub-category name (be careful with spelling here when you use the same category between options).
	UPROPERTY(config, EditAnywhere, Category="Category A|Bool Settings")
	bool MyBoolValue;

	UPROPERTY(config, EditAnywhere, Category="Category A|Array Settings")
	TArray<FString> MyStringArray;

	UPROPERTY(config, EditAnywhere, Category="Category for Custom Structs")
	TArray<FMyStruct>;

	UPROPERTY(config, EditAnywhere, Category="Category B|Custom Enums")
	EMyEnum MyEnumValue;
	
	UPROPERTY(config, EditAnywhere, Category="Category B|Custom Enums")
	EMyEnum MyEnumWithDefaultValue = EMyEnum::C;
};
