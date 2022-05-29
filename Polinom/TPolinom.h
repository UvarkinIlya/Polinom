#pragma once
#include "THeadList.h"
class TMonom{
	int x, y, z;
	public:
	double coef;

	public:
		TMonom(double _coef = 0, int _x = 0, int _y = 0, int _z = 0){
			x = _x;
			y = _y;
			z = _z;
			coef = _coef;
		}

		bool operator==(const TMonom& monom){
			return x==monom.x && 
					y==monom.y &&
					z==monom.z;
		}

		bool operator>(const TMonom& monom){
			return x > monom.x ||
					(x == monom.x && y > monom.y) ||
					(x == monom.x && y == monom.y && z > monom.z);
		}

		bool operator<(const TMonom& monom){
			return x < monom.x ||
				(x == monom.x && y < monom.y) ||
				(x == monom.x && y == monom.y && z < monom.z);
		}

		void operator*=(const TMonom& monom){
			x += monom.x;
			y += monom.y;
			z += monom.z;
			coef *= monom.coef;
		}

		friend std::ostream& operator<<(std::ostream& out, TMonom& monom){
			out << monom.coef << "x^" << monom.x << "y^" << monom.y << "z^" << monom.z << " ";

			return out;
		}
};

class TPolinom: public THeadList<TMonom>{
	public:
		TPolinom(){
			TMonom monom(0, 0, 0, -1);
			pHead->pValue = monom;
		}

		TPolinom(const TPolinom& pol){
			TMonom monom(0,0,0,-1);
			pHead->pValue = monom;

			TNode<TMonom> *p = pol.pFirst;
			reset();

			while( p!= pol.pStop){
				insLast(p->pValue);
				p = p->pNext;
			}
		}

		int getLen(){
			return len;
		}

		void addMonom(TMonom monom){
			if(pFirst == nullptr || monom > pFirst->pValue){
				insFirst(monom);
				return;
			}

			for(reset(); !isEnd(); goNext()){
				if(monom == pCurrent->pValue){
					pCurrent->pValue.coef += monom.coef;

					if(pCurrent->pValue.coef == 0){
						delCrurrent();
						return;
					}
					break;
				} else if (monom > pCurrent->pValue) {
					insCurrent(monom);
					return;
				}
			}
		}

		TPolinom operator+(TPolinom& pol){
			TPolinom res(pol);

			reset();
			res.reset();
			while(!res.isEnd()){
				if(res.pCurrent->pValue == pCurrent->pValue){
					res.pCurrent->pValue.coef += pCurrent->pValue.coef;

					if(res.pCurrent->pValue.coef == 0){
						res.delCrurrent();
					} else{
						res.goNext();
					}

					goNext();
				} else if(res.pCurrent->pValue > pCurrent->pValue){
					res.goNext();
				} else{
					res.insCurrent(pCurrent->pValue);
					goNext();
				}
			}

			
			while(!isEnd()){
				res.insLast(pCurrent->pValue);
				goNext();
			}

			return res;
		}

		TPolinom operator*(TMonom monom){
			TPolinom res(*this);

			for(res.reset(); !res.isEnd(); res.goNext()){
				res.pCurrent->pValue *= monom;
			}

			return res;
		}
		
		void multiplicationToMonom(TMonom monom){
			for(reset(); !isEnd(); goNext()){
				pCurrent->pValue *= monom;
			}
		}

		TPolinom operator*(TPolinom pol){
			TPolinom res(pol);

			reset();
			res.reset();
			while(!isEnd()){
				res.multiplicationToMonom(getCurrentValue());
				goNext();
			}

			return res;
		}
};

