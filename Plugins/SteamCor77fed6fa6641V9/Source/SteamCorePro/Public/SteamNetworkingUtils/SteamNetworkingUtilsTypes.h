/**
* Copyright (C) 2017-2024 eelDev AB
*
* Official Steamworks Documentation: https://partner.steamgames.com/doc/api/ISteamNetworkingUtils
*/

#pragma once

#include "CoreMinimal.h"
#include "SteamCorePro/SteamCoreProModule.h"
#include "SteamCorePro/Steam.h"
#include "SteamNetworkingUtilsTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		Structs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

USTRUCT(BlueprintType)
struct FSteamNetworkPingLocation
{
	GENERATED_BODY()
public:
	FSteamNetworkPingLocation() = default;

#if WITH_STEAMCORE
	FSteamNetworkPingLocation(const SteamNetworkPingLocation_t& Val)
	{
		char* Data = new char[k_cchMaxSteamNetworkingPingLocationString];
		SteamNetworkingUtils()->ConvertPingLocationToString(Val, Data, k_cchMaxSteamNetworkingPingLocationString);
		Location = UTF8_TO_TCHAR(Data);
		delete[] Data;
	}
#endif

public:
#if WITH_STEAMCORE
	operator SteamNetworkPingLocation_t()
	{
		SteamNetworkPingLocation_t Data;
		SteamNetworkingUtils()->ParsePingLocationString(TCHAR_TO_UTF8(*Location), Data);
		return Data;
	}

	operator SteamNetworkPingLocation_t() const
	{
		SteamNetworkPingLocation_t Data;
		SteamNetworkingUtils()->ParsePingLocationString(TCHAR_TO_UTF8(*Location), Data);
		return Data;
	}
#endif

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "NetworkingUtils")
	FString Location;
};
