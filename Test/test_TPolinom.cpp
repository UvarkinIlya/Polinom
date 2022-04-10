//#include "../Polinom/TPolinom.h"
//
//#include "gtest.h"
//#include <iostream>
//
//using namespace std;
//
//TEST(TList,can_create_TPolinom){
//	ASSERT_NO_THROW(TPolinom pol);
//}
//
//TEST(TList, can_add_monom){
//	TPolinom pol;
//	pol.insFirst(TMonom(-9,1,1,1));
//
//	pol.reset();
//	TMonom value = pol.getCurrentValue();
//	EXPECT_EQ(TMonom(-9,1,1,1).operator==(value), true);
//}
//
//TEST(TList,can_add_polinom_zero_value){
//	TPolinom pol1;
//	pol1.addMonom(TMonom(-9,1,1,1));
//	pol1.addMonom(TMonom(-1,5,3,3));
//	pol1.addMonom(TMonom(5,3,3,3));
//	//std::cout << pol1;
//	//std::cout << "Hello world!" << std::endl;
//
//	TPolinom pol2;
//	pol2.addMonom(TMonom(9,1,1,1));
//	pol2.addMonom(TMonom(-5,3,3,3));
//	pol2.addMonom(TMonom(1,5,3,3));
//	//std::cout << pol2 << std::endl;
//
//	TPolinom pol = pol1 + pol2;
//	EXPECT_EQ(pol.getLen(), 0);
//	//std::cout << pol;
//}
//
//TEST(TList, can_add_polinom_one_value){
//	TPolinom pol1;
//	pol1.addMonom(TMonom(-9,1,1,1));
//	pol1.addMonom(TMonom(5,3,3,3));
//	//cout << pol1;
//
//	TPolinom pol2;
//	pol2.addMonom(TMonom(9,1,1,1));
//	pol2.addMonom(TMonom(-5,3,3,3));
//	pol2.addMonom(TMonom(1,5,3,3));
//	//cout << pol2 << endl;
//
//	TPolinom pol= pol1 + pol2;
//	EXPECT_EQ(pol.getLen(), 1);
//	//cout << pol;
//}
//
//TEST(TList,can_add_empty_polinom){
//	TPolinom pol1;
//	//cout << pol1;
//
//	TPolinom pol2;
//	pol2.addMonom(TMonom(9,1,1,1));
//	pol2.addMonom(TMonom(-5,3,3,3));
//	pol2.addMonom(TMonom(1,5,3,3));
//	//cout << pol2 << endl;
//
//	TPolinom pol = pol1 + pol2;
//	EXPECT_EQ(pol.getLen(),3);
//	//cout << pol;
//}