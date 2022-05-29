#pragma once
#include "THeadList.h"
#include "TMonom.h"

class TPolinom:public THeadList<TMonom>{
public:
	TPolinom():THeadList<TMonom>(){
		TMonom monom(0,-1);
		pHead->SetValue(monom);
	}

	TPolinom(const TPolinom& pol){
		TMonom monom(0,-1);
		pHead->SetValue(monom);

		TNode<TMonom>* p = pol.pFirst;
		Reset();

		while(p != pol.pStop){
			InsLast(p->GetValue());
			p = p->GetNext();
		}
	}

	int GetLen(){
		return ListLen;
	}

	void AddMonom(TMonom monom){
		Reset();
		bool isFirst = false;
		if(monom > pCurr->GetValue()){
			isFirst = true;
		} else{
			while(pCurr->GetNext()->GetValue() > monom){
				GoNext();
			}
		}

		if(pCurr->GetValue() == monom){
			int coeff = pCurr->GetValue().GetCoeff() + monom.GetCoeff();
			if(coeff == 0){
				DelCurrent();
			} else{
				monom.SetCoeff(coeff);
				pCurr->SetValue(monom);
			}
		} else{
			if(isFirst){
				InsFirst(monom);
			} else{
				InsCurrent(monom);
			}
		}
	}

	TPolinom operator+(TPolinom& pol){
		TPolinom res(*this);

		res.Reset();
		for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
			TMonom monom = pol.pCurr->GetValue();

			bool isFirst = false;
			if(monom > res.pFirst->GetValue()){
				isFirst = true;
			} else{
				while(res.pCurr->GetNext()->GetValue() > monom || (res.pCurr->GetNext()->GetValue() == monom)){
					res.GoNext();
				}
			}

			if(monom == res.pCurr->GetValue()){
				int coeff = res.pCurr->GetValue().GetCoeff() + monom.GetCoeff();
				if(coeff == 0){
					res.DelCurrent();
				} else{
					monom.SetCoeff(coeff);
					res.pCurr->SetValue(monom);
				}
			} else{
				if(isFirst){
					res.InsFirst(monom);
					res.pCurr = res.pFirst;
				} else{
					res.InsCurrent(monom);
				}
			}
		}

		return res;
	}
};

