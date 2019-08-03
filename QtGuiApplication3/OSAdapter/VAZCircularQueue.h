#pragma once
#include "VAZLock.h"

template<class T>
class CVAZCircularQueue
{
public:
	CVAZCircularQueue(int iSize = 1024);
	virtual ~CVAZCircularQueue();
	bool IsEmpty();
	bool IsFull();
	int  GetCount();
	int	 GetBufSize(){return m_iMaxSize - 1;}; //能存放的大小比空间大小少1

	void Clear();
	bool EnQueue(const T &Data);
	bool EnQueue(const T *pData, int iCount);
	void EnQueueWithCycleReplace(const T &Data);

	bool DeQueue(T *pData);
	bool DeQueue(T *pData, int iCount);

	bool GetHead(T *pData);
	bool GetTail(T *pData);
	bool GetItem(int idx, T *pData);

private:
	T	*m_pData;
	volatile int m_iHead;
	volatile int m_iTail;
	volatile int m_iMaxSize;
};


template<class T>
CVAZCircularQueue<T>::CVAZCircularQueue(int iSize) : m_iMaxSize(iSize), m_iHead(0), m_iTail(0)
{
	if (m_iMaxSize <= 0)
		m_iMaxSize = 1024;

	m_pData = new T[m_iMaxSize];
	ASSERT(m_pData != NULL);
}

template<class T>
CVAZCircularQueue<T>::~CVAZCircularQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iMaxSize = 0;
	delete[] m_pData;
}

template<class T>
bool CVAZCircularQueue<T>::IsFull()  
{
	int iTemp  = m_iTail + 1;
	iTemp %= m_iMaxSize;
	bool bRet = (iTemp == m_iHead);

	return bRet;
}

template<class T>
bool CVAZCircularQueue<T>::IsEmpty() 
{
	bool bRet = (m_iHead == m_iTail);

	return bRet;
}

template<class T>
void CVAZCircularQueue<T>::Clear()
{
	T Data;
	while(!IsEmpty())
	{
		DeQueue(&Data);
	}
}

template<class T>
bool CVAZCircularQueue<T>::EnQueue(const T &Data)
{
	int iCount = 0;

	if(IsFull())
	{	
		return false;
	}

	m_pData[m_iTail] = Data;
	int iTemp  = m_iTail + 1;
	iTemp %= m_iMaxSize;
	m_iTail = iTemp;

	return true;
}

template<class T>
bool CVAZCircularQueue<T>::EnQueue(const T *pData, int iCount)
{
	ASSERT(pData);
	if (!pData)
		return false;

	for (int i=0; i<iCount; ++i)
	{
		if (!EnQueue(pData[i]))
		{
			return false;
		}
	}

	return true;

}

template<class T>
void CVAZCircularQueue<T>::EnQueueWithCycleReplace(const T &Data)
{
	T Head;

	if(IsFull())
	{
		DeQueue(&Head);
	}
	m_pData[m_iTail] = Data;	
	m_iTail = (m_iTail + 1) % m_iMaxSize;		
}

template<class T>
bool CVAZCircularQueue<T>::DeQueue(T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	if (IsEmpty())
	{
		return false;
	}
	else
	{
		*pData = m_pData[m_iHead];
		int iTemp  = m_iHead + 1;
		iTemp %= m_iMaxSize;
		m_iHead = iTemp;
		return true;
	}
}



template<class T>
bool CVAZCircularQueue<T>::DeQueue(T *pData,int iCount)
{	
	ASSERT(pData);
	if (!pData)
		return false;

	for (int i=0; i<iCount; ++i)
	{
		if (!DeQueue(&pData[i]))
		{
			return false;
		}
	}
	return true;
}

template<class T>
int CVAZCircularQueue<T>::GetCount() 
{
	int iCount = 0;

	int iTemp  = m_iTail - m_iHead;
	iTemp += m_iMaxSize;
	iTemp %= m_iMaxSize;
	iCount = iTemp;
	if (iCount < 0)
		iCount = 0;

	return iCount;
}


template<class T>
bool CVAZCircularQueue<T>::GetHead(T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	if (IsEmpty())
	{
		//ASSERT(false);
		return false;
	}
	else
	{
		*pData = m_pData[m_iHead];
		return true;
	}
}

template<class T>
bool CVAZCircularQueue<T>::GetTail(T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	if (IsEmpty())
	{
		//ASSERT(false);
		return false;
	}
	else
	{
		int iTemp  = m_iTail - 1;
		iTemp += m_iMaxSize;
		iTemp %= m_iMaxSize;
		*pData = m_pData[iTemp];
		return true;
	}
};

template<class T>
bool CVAZCircularQueue<T>::GetItem(int idx, T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	//ASSERT(GetCount() >= idx);
	if (GetCount() < idx)
	{
		return false;
	}
	else
	{
		*pData = m_pData[(m_iHead+idx)% m_iMaxSize];
		return true;
	}
}


///////////////////////////////////////////////////////////////////////

template<class T>
class CVAZThreadSafeCircularQueue
{
public:
	CVAZThreadSafeCircularQueue(int iSize = 1024);
	virtual ~CVAZThreadSafeCircularQueue();
	bool IsEmpty();
	bool IsFull();
	int  GetCount();
	int	 GetBufSize(){return m_iMaxSize - 1;}; //能存放的大小比空间大小少1

	void Clear();
	bool EnQueue(const T &Data);
	bool EnQueue(const T *pData, int iCount);
	void EnQueueWithCycleReplace(const T &Data);

	bool DeQueue(T *pData);
	bool DeQueue(T *pData, int iCount);

	bool GetHead(T *pData);
	bool GetTail(T *pData);
	bool GetItem(int idx, T *pData); 

private:
	T	*m_pData;
	volatile int m_iHead;
	volatile int m_iTail;
	volatile int m_iMaxSize;

	CVAZLock m_Lock;
};


template<class T>
CVAZThreadSafeCircularQueue<T>::CVAZThreadSafeCircularQueue(int iSize) : m_iMaxSize(iSize), m_iHead(0), m_iTail(0),m_Lock(_T("CVAZThreadSafeCircularQueue:m_Lock"))
{
	if (m_iMaxSize <= 0)
		m_iMaxSize = 1024;

	m_pData = new T[m_iMaxSize];
}

template<class T>
CVAZThreadSafeCircularQueue<T>::~CVAZThreadSafeCircularQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iMaxSize = 0;
	delete[] m_pData;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::IsFull()  
{
	LOCK(m_Lock);
	int iTemp  = m_iTail + 1;
	iTemp %= m_iMaxSize;
	bool bRet = (iTemp == m_iHead);
	UNLOCK(m_Lock);
	return bRet;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::IsEmpty() 
{
	LOCK(m_Lock);
	bool bRet = (m_iHead == m_iTail);
	UNLOCK(m_Lock);

	return bRet;
}

template<class T>
void CVAZThreadSafeCircularQueue<T>::Clear()
{
	LOCK(m_Lock);
	T Data;
	while(!IsEmpty())
	{
		DeQueue(&Data);
	}
	UNLOCK(m_Lock);
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::EnQueue(const T &Data)
{
	int iCount = 0;

	LOCK(m_Lock);
	if(IsFull())
	{
		UNLOCK(m_Lock);
		//ASSERT(false);
		return false;
	}

	m_pData[m_iTail] = Data;
	int iTemp  = m_iTail + 1;
	iTemp %= m_iMaxSize;
	m_iTail = iTemp;
	UNLOCK(m_Lock);

	return true;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::EnQueue(const T *pData, int iCount)
{
	ASSERT(pData);
	if (!pData)
		return false;

	LOCK(m_Lock);
	for (int i=0; i<iCount; ++i)
	{
		if (!EnQueue(pData[i]))
		{
			UNLOCK(m_Lock);
			return false;
		}
	}
	UNLOCK(m_Lock);

	return true;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::DeQueue(T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	LOCK(m_Lock);
	if (IsEmpty())
	{
		UNLOCK(m_Lock);
		//ASSERT(false);
		return false;
	}
	else
	{
		*pData = m_pData[m_iHead];
		int iTemp  = m_iHead + 1;
		iTemp %= m_iMaxSize;
		m_iHead = iTemp;
	}
	UNLOCK(m_Lock);
	return true;
}


template<class T>
bool CVAZThreadSafeCircularQueue<T>::DeQueue(T *pData,int iCount)
{	
	ASSERT(pData);
	if (!pData)
		return false;

	LOCK(m_Lock);
	for (int i=0; i<iCount; ++i)
	{
		if (!DeQueue(&pData[i]))
		{
			UNLOCK(m_Lock);
			return false;
		}
	}
	UNLOCK(m_Lock);
	return true;
}

template<class T>
int CVAZThreadSafeCircularQueue<T>::GetCount() 
{
	int iCount = 0;

	LOCK(m_Lock);
	int iTemp  = m_iTail - m_iHead;
	iTemp += m_iMaxSize;
	iTemp %= m_iMaxSize;
	iCount = iTemp;
	if (iCount < 0)
		iCount = 0;
	UNLOCK(m_Lock);
	return iCount;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::GetItem(int idx, T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	LOCK(m_Lock);
	if (GetCount() < idx)
	{
		UNLOCK(m_Lock);
		//ASSERT(false);
		return false;
	}
	else
	{
		int iTemp  = m_iHead + idx;
		iTemp %= m_iMaxSize;
		*pData = m_pData[iTemp];
	}
	UNLOCK(m_Lock);
	return true;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::GetHead(T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	LOCK(m_Lock);
	//ASSERT(!IsEmpty());
	if (IsEmpty())
	{
		UNLOCK(m_Lock);
		return false;
	}
	else
	{
		*pData = m_pData[m_iHead];
	}
	UNLOCK(m_Lock);
	return true;
}

template<class T>
bool CVAZThreadSafeCircularQueue<T>::GetTail(T *pData)
{
	ASSERT(pData);
	if (!pData)
		return false;

	LOCK(m_Lock);
	//ASSERT(!IsEmpty());
	if (IsEmpty())
	{
		UNLOCK(m_Lock);
		return false;
	}
	else
	{
		int iTemp  = m_iTail - 1;
		iTemp += m_iMaxSize;
		iTemp %= m_iMaxSize;
		*pData = m_pData[iTemp];
	}
	UNLOCK(m_Lock);
	return true;
};

template<class T>
void CVAZThreadSafeCircularQueue<T>::EnQueueWithCycleReplace(const T &Data)
{
	T Head;

	LOCK(m_Lock);
	if(IsFull())
	{
		DeQueue(&Head);
	}
	m_pData[m_iTail] = Data;	
	m_iTail = (m_iTail + 1) % m_iMaxSize;		
	UNLOCK(m_Lock);
}
