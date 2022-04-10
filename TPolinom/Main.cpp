#include "TList.h"
#include <iostream>

using namespace std;
void main(){
	TList<int> list;

	list.InsCurrent(1);
	list.InsFirst(2);
	list.InsLast(3);

	cout << list;
}