#pragma once
#include <ostream>

class TMonom{
	protected:
		int Coeff; // коэффициент монома
		int Index; // индекс (свертка степеней)
	public:
		TMonom(int _Coeff = 1,int _Index = 0){
			Coeff = _Coeff;
			Index = _Index;
		}

		TMonom(const TMonom& monom){
			Coeff = monom.Coeff;
			Index = monom.Index;
		}

		void SetCoeff(int _Coeff){
			Coeff = _Coeff;
		}

		int GetCoeff(){
			return Coeff;
		}

		void SetIndex(int _Index){
			Index = _Index;
		}

		int GetIndex(){
			return Index;
		}

		TMonom& operator=(const TMonom& monom){
			Coeff = monom.Coeff;
			Index = monom.Index;
			return *this;
		}

		bool operator==(const TMonom& monom){
			return Index == monom.Index;
		}

		bool operator<(const TMonom& monom){
			return Index < monom.Index;
		}

		bool operator>(const TMonom& monom){
			return Index > monom.Index;
		}

		friend std::ostream& operator<<(std::ostream& out, TMonom& monom) {
                  out << monom.Coeff << "x^" << monom.Index / 100 << "y^"
                      << monom.Index / 10 % 5 << "z^" << monom.Index % 10 << " ";

			return out;
		}
};

