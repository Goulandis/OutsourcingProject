// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FFastChangeLanguageModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	//���ڳ�ʼ��Py�ű�
	void Tick(const float InDeltaTime);
	bool bHasTicked = false;
	FDelegateHandle TickHandle;
};
