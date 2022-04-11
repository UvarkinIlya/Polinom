#pragma once
#include "TList.h"
#include "TNode.h"

template <class T>
class THeadList:TList<T>{
	TNode<T>* pHead;
	public:
		THeadList():TList<T>(){
			pHead = new TNode<T>(-1,TList<T>::pFirst);
			pHead->SetNext(pHead);
			TList<T>::pFirst = TList<T>::pLast = TList<T>::pCurr = TList<T>::pPrev = TList<T>::pStop = pHead;
		}

		void InsFirst(T pValue){
			TList<T>::InsFirst(pValue);
			pHead->SetNext(TList<T>::pFirst);
		}

		void DelFirst(){
			TList<T>::DelFirst();
			pHead->SetNext(TList<T>::pFirst);
		}
};

