#pragma once
#include "TNode.h"
#include <ostream>

template <class T>
class TList{
	protected:
		TNode<T>* pFirst; // первое звено
		TNode<T>* pLast; // последнее звено
		TNode<T>* pCurr; // текущее звено
		TNode<T>* pPrev; // звено перед текущим
		TNode<T>* pStop; // значение указателя, означающего конец списка
		int CurrPos; // номер текущего звена (нумерация от 0)
		int ListLen; // количество звеньев в списке
	protected:
		int GetListLen(){
			return ListLen;
		}

	public:
		TList(){
			pStop = nullptr;
			pFirst = pLast = pCurr = pPrev = pStop;
			CurrPos = -1;
			ListLen = 0;
		}

		~TList(){
			int len = GetListLen();
			for(int i = 0; i < len; i++){
				DelFirst();
			}

			pFirst = pLast = pCurr = pPrev = pStop;
		}

		void Reset(){
			pCurr = pFirst;
			pPrev = pStop;
		}

		bool IsEnd(){
			return pCurr == pStop;
		}

		void GoNext(){
			pPrev = pCurr;
			pCurr = pCurr->GetNext();
		}

		void InsFirst(T pValue){
			TNode<T>* node = new TNode<T>(pValue, pFirst);

			if (GetListLen() == 0){
				pFirst = pLast = node;
			} else{
				pFirst = node;
			}

			ListLen++;
		}

		void InsLast(T pValue){
			if(GetListLen() == 0){
				InsFirst(pValue);
				return;
			}

			TNode<T>* node = new TNode<T>(pValue, pStop);

			pLast->SetNext(node);
			pLast = node;
			ListLen++;
		}

		void InsCurrent(T pValue){
			if(GetListLen() == 0){
				InsFirst(pValue);
			} else if(pCurr == pLast){
				InsLast(pValue);
			} else if (pCurr == pStop){
				return;
			} else{
				TNode<T>* node = new TNode<T>(pValue, pCurr->GetNext());
				pCurr->SetNext(node);

				pPrev = pCurr;
				pCurr = node;
				ListLen++;
			}
		}

		void DelFirst(){
			if(GetListLen() == 0){
				return;
			}

			TNode<T>* delNode = pFirst;

			if(GetListLen() == 1){
				pFirst = pLast = pStop;
			} else{
				pFirst = pFirst->GetNext();
			}

			delete delNode;
			ListLen--;
		}

		void DelLast(){
			if(GetListLen() == 0){
				return;
			}

			TNode<T>* delNode = pLast;

			if(GetListLen() == 1){
				pFirst = pLast = pStop;
			} else{
				Reset();
				while(pCurr != pLast){
					GoNext();
				}

				pLast = pPrev;
				pLast->SetNext(pStop);
				pCurr = pStop;
				pLast = pStop;
			}

			delete delNode;
			ListLen--;
		}

		void DelCurrent(){
			if(GetListLen() == 0){
				return;
			}

			if(pCurr == pFirst){
				DelFirst();
			} else if(pCurr == pLast){
				DelLast();
			} else{
				TNode<T>* delNode = pCurr;

				pCurr = pCurr->GetNext();
				pPrev->SetNext(pCurr);

				delete delNode;
				ListLen--;
			}
		}

		T GetCurrentValue(){
			return pCurr->GetValue();
		}

		friend std::ostream& operator<<(std::ostream& out,TList<T>& list){
			if(list.GetListLen() == 0){
				out << "Empty List!";
				return out;
			}

			for(list.Reset(); !list.IsEnd(); list.GoNext()){
				out << list.GetCurrentValue() << " ";
			}

			return out;
		}
};

