#pragma once
#include "TList.h"
#include "TNode.h"

template <class T>
class THeadList: public TList<T>{
	public:
		TNode<T>* pHead;

		THeadList():TList<T>(){
			pHead = new TNode<T>(-1,TList<T>::pFirst);
			pHead->SetNext(pHead);
			TList<T>::pFirst = TList<T>::pLast = TList<T>::pCurr = TList<T>::pPrev = TList<T>::pStop = pHead;
		}

		void InsFirst(T pValue){
			TList<T>::InsFirst(pValue);
			pHead->SetNext(TList<T>::pFirst);
		}

		void InsLast(T pValue){
			TList<T>::InsLast(pValue);
			pHead->SetNext(TList<T>::pFirst);
		}

		void InsCurrent(T pValue){
			TList<T>::InsCurrent(pValue);
			pHead->SetNext(TList<T>::pFirst);
		}

		void DelFirst(){
			TList<T>::DelFirst();
			pHead->SetNext(TList<T>::pFirst);
		}

		void DelLast(){
			TList<T>::DelLast();
			pHead->SetNext(TList<T>::pFirst);
		}

		void DelCurrent(){
			TList<T>::DelCurrent();
			pHead->SetNext(TList<T>::pFirst);
		}
};

