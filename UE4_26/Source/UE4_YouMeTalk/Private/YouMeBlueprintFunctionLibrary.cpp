// Fill out your copyright notice in the Description page of Project Settings.


#include "YouMeBlueprintFunctionLibrary.h"
#include "HAL/PlatformFilemanager.h"
#include "IPlatformFilePak.h"
#include "Engine/StreamableManager.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

FString UYouMeBlueprintFunctionLibrary::GetPlatformBaseDir()
{
#if PLATFORM_ANDROID
	extern FString GFilePathBase;
	return GFilePathBase + TEXT("/UE4Game/UE4_YouMeTalk");
#elif PLATFORM_IOS
    NSArray *documentArr = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentPath = [documentArr firstObject];
    FString path(documentPath);
    return path;
#elif PLATFORM_WINDOWS
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
#else
    return TEXT("");
#endif
}

FString UYouMeBlueprintFunctionLibrary::LoadBackgroundMusic()
{
	 FString BackgroundMusicDir = FPaths::ProjectContentDir() / TEXT("Media/Music.mp3");

	 if (FPaths::FileExists(BackgroundMusicDir))
	 {
		 TArray<uint8> BackgroundMusicData;

		 FFileHelper::LoadFileToArray(BackgroundMusicData, *BackgroundMusicDir, 0);

		 FString BackgroundMusicSaveDir = TEXT("BackgroundMusic/Music.mp3");

		 FString PlayformBaseDir = GetPlatformBaseDir();

		 BackgroundMusicSaveDir = PlayformBaseDir + BackgroundMusicSaveDir;

		 FFileHelper::SaveArrayToFile(BackgroundMusicData, *BackgroundMusicSaveDir);

		 return BackgroundMusicSaveDir;
	 }
	 else
	 {
		 return TEXT("BackgroundMusic is not exist");
	 }

	 return TEXT("Load BackgroundMusic failed");
}
