#include <iostream>
#include "TPolinom.h"

using namespace std;

void main(){
	try{
		//TPolinom pol1;
		//pol1.insFirst(TMonom(-9,1,1,1));
		//pol1.insFirst(TMonom(5,3,3,3));
		//cout << pol1 << endl;

		//TPolinom pol2;
		//pol2.insFirst(TMonom(9,1,1,1));
		//pol2.insFirst(TMonom(-5,3,3,3));
		//pol2.insFirst(TMonom(1,5,3,3));
		//cout << pol2 << endl;

		//TPolinom pol = pol1 + pol2;
		//cout << pol;

		///*TPolinom pol3 = pol1 * TMonom(1,5,5,5);
		//cout << pol3;

		//TPolinom pol4 = pol1 * pol2;
		//cout << pol4;*/
		TPolinom pol1;
		pol1.insFirst(TMonom(-9,1,1,1));
		pol1.insFirst(TMonom(-1,5,3,3));
		pol1.insFirst(TMonom(5,3,3,3));
		cout << pol1 << endl;
		//std::cout << "Hello world!" << std::endl;

		TPolinom pol2;
		pol2.insFirst(TMonom(9,1,1,1));
		pol2.insFirst(TMonom(-5,3,3,3));
		pol2.insFirst(TMonom(1,5,3,3));
		cout << pol2 << endl;

		TPolinom pol = pol1 + pol2;
		cout << pol;
		//EXPECT_EQ(pol.getLen(),0);
	} catch(char* str){
		cout << str;
	}
}