#pragma once
#include "TList.h"

template <class T>
class THeadList:public TList<T>{
	protected:
		TNode<T> *pHead;
	public:
		THeadList(){
			pHead = new TNode<T>();
			pHead->pNext = TList<T>::pStop;
			pHead->pValue = -1;
			TList<T>::pStop = pHead;
			TList<T>::pCurrent = pHead;
			TList<T>::pFirst = pHead;
			TList<T>::pPrev = pHead;
			TList<T>::pLast = pHead;
		}

		~THeadList(){
			TList<T>::reset();

			while(TList<T>::pCurrent != TList<T>::pStop){
				TNode<T>* del = TList<T>::pCurrent;
				TList<T>::pCurrent = TList<T>::pCurrent->pNext;
				TList<T>::len--;

				delete del;
			}

			delete pHead;
		}

		void insFirst(T value){
			TList<T>::insFirst(value);
			pHead->pNext = TList<T>::pFirst;
		}

		void insLast(T value){
			TList<T>::insLast(value);
			pHead->pNext = TList<T>::pFirst;
		}

		void delFirst(){
			TList<T>::delFirst();
			pHead->pNext = TList<T>::pFirst;
		}

		void delLast(){
			TList<T>::delLast();
			pHead->pNext = TList<T>::pFirst;
		}
};