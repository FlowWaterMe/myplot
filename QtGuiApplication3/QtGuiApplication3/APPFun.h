#pragma once
#include "../QtGuiApplication3/GlobalDefine.h"
#include <vector>
void VAZSplitStrToIntArray(const tstring& sToSplit, vector<int> &vecValue, const tstring& sDelimit)
{
	TCHAR *pSrc = NULL;
	TCHAR *pTemp = NULL;
	TCHAR *pMark = NULL;

	vecValue.clear();
	if (sToSplit.empty())
	{
		return;
	}

	tstring sToSplitTmp = sToSplit;
	pSrc = (TCHAR *)sToSplitTmp.c_str();
	pMark = (TCHAR *)sDelimit.c_str();

	pTemp = _tcstok(pSrc, pMark);
	while (pTemp)
	{
		vecValue.push_back(VAZConvToInt(pTemp));
		pTemp = _tcstok(NULL, pMark);
	}
}

void SplitStrToArrayKeepWhiteSpaceA(const string& sToSplit, vector<string> &vecValue, const string& sDelimit)
{
	int iBeginPos = 0;
	int iEndPos = sToSplit.find(sDelimit, iBeginPos);
	if (iEndPos == string::npos)
	{
		vecValue.push_back(sToSplit);
		return;
	}

	while (iEndPos != string::npos)
	{
		vecValue.push_back(sToSplit.substr(iBeginPos, iEndPos - iBeginPos));
		iBeginPos = iEndPos + sDelimit.size();
		iEndPos = sToSplit.find(sDelimit, iBeginPos);
	}

	if (iBeginPos < sToSplit.size())
	{
		vecValue.push_back(sToSplit.substr(iBeginPos, sToSplit.size()));
	}
}