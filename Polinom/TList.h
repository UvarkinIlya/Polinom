#pragma once
#include <iostream>

template <class T>
struct TNode{
	T pValue;
	TNode* pNext;

	TNode(T value = T(), TNode* next = NULL){
		pValue = value;
		pNext = next;
	}
};

template <class T>
class TList{
	protected:
	TNode<T> *pFirst, *pCurrent, *pPrev, *pLast, *pStop;
	int len;
	
	public:
		TList(){
			pFirst = nullptr;
			pCurrent = nullptr;
			pPrev = nullptr;
			pLast = nullptr;
			pStop = nullptr;
			len = 0;
		}

		~TList(){
			reset();

			while(pCurrent != pStop){
				TNode<T> *del = pCurrent;
				pCurrent = pCurrent->pNext;
				len--;

				delete del;
			}
		}

		void insFirst(T value){
			TNode<T>* node = new TNode<T>;
			node->pValue = value;
			node->pNext = pFirst;
			pFirst = node;
			len++;

			if(len == 1){
				pLast = node;
			}
		}

		void insLast(T value){
			TNode<T>* node = new TNode<T>;
			node->pValue = value;
			node->pNext = pStop;

			if(pLast != pStop){
				pLast->pNext = node;
			} else{
				pFirst = node;
			}

			pLast = node;
			pLast->pNext = pStop;
			len++;
 		}

		void insCurrent(T value){
			if(pCurrent == nullptr || pFirst == nullptr){
				throw "wrong current";
			}

			if(pCurrent == pFirst){
				insFirst(value);
			} else{
				TNode<T>* node = new TNode<T>;
				node->pValue = value;
				node->pNext = pCurrent;

				if(pPrev == nullptr){
					throw "wrong pPrev!";
				}

				pCurrent = node;
				pPrev->pNext = pCurrent;
				len++;
			}
		}

		void delFirst(){
			TNode<T> *first;
			first = pFirst;

			pFirst = pFirst->pNext;
			pCurrent = pFirst;

			delete first;
			len--;

			if(len == 0){
				pLast = pStop;
			}
		}

		void delCrurrent(){
			if(pCurrent == pStop){
				throw "Wrong pointer";
				return;
			}

			if(pCurrent == pFirst){
				delFirst();
				return;
			}

			if(pPrev == nullptr){
				throw "Wrong pPrev!";
			}

			TNode<T> *delCurrent = pCurrent;
			pCurrent = pCurrent->pNext;
			pPrev->pNext = pCurrent;

			delete delCurrent;
			len--;
		}

		/*void delLast(){
			reset();

			prevLast = pFirst
			while(prevLast->pNext != pStop){
				prevLast = prevLast->pNext;
			}

			delete pLast;
			pLast = prevLast;
		}*/

		T getCurrentValue(){
			if(pCurrent == pStop){
				throw "pCurrnet is NULL";
			}

			return pCurrent->pValue;
		}

		void reset(){
			pCurrent = pFirst;
			pPrev = pStop;
		}

		void goNext(){
			pPrev = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		bool isEnd(){
			return pCurrent == pStop;
		}

		friend std::ostream& operator<<(std::ostream& out, TList<T>& list){
			list.reset();
			if(list.isEnd()){
				out << "0";
				return out;
			}

			for(list.reset(); !list.isEnd(); list.goNext()){
				out << list.getCurrentValue() << " ";
			}

			return out;
		}
};

