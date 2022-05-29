#include "TPolinom.h"
#include <iostream>

using namespace std;
void main(){
	TPolinom pol1;
	pol1.InsLast(TMonom(1,888));
	pol1.InsLast(TMonom(2,666));
	pol1.InsLast(TMonom(3,444));
    std::cout << pol1 << endl;

	TPolinom pol2;
	pol2.InsLast(TMonom(1,999));
	pol2.InsLast(TMonom(-2,666));
	pol2.InsLast(TMonom(3,555));
	pol2.InsLast(TMonom(3,333));
    std::cout << pol2 << endl;

	TPolinom pol = pol1 + pol2;
    cout << pol;
}