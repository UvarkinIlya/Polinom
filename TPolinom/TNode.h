#pragma once
template <class T>
class TNode{
	private:
		T pValue;
		TNode<T>* pNext;
	public:
		TNode(T _pValue, TNode<T>* _pNext){
			pValue = _pValue;
			pNext = _pNext;
		}

		TNode<T>* GetNext(){
			return pNext;
		}

		void SetNext(TNode<T>* _pNext){
			pNext = _pNext;
		}

		T GetValue(){
			return pValue;
		}

		void SetValue(T _pValue){
			pValue = _pValue;
		}
};

