#include "..\TPolinom\TPolinom.h"
#include "gtest.h"

TEST(TPolinom, can_create_TPolinom){
	ASSERT_NO_THROW(TPolinom pol);
}

TEST(TPolinom,can_copy_TPolinom){
	TPolinom pol;
	pol.InsFirst(1);
	pol.InsFirst(2);
	pol.InsFirst(3);

	int arr[3] = {3, 2, 1};
	TPolinom copyPol(pol);

	int i = 0;
	bool isOk = true;
	for(copyPol.Reset(), pol.Reset(); !copyPol.IsEnd(); copyPol.GoNext(), pol.GoNext()){
		if(!(pol.GetCurrentValue() == copyPol.GetCurrentValue())){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom,can_add_Monom_First_TPolinom){
	TPolinom pol;
	pol.InsLast(TMonom(1,888));
	pol.InsLast(TMonom(2,666));
	pol.InsLast(TMonom(3,444));

	pol.AddMonom(TMonom(1,999));

	TMonom arr[4] = {TMonom(1,999), TMonom(1,888), TMonom(2,666), TMonom(3,444)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom, can_add_Monom_Middle_TPolinom){
	TPolinom pol;
	pol.InsLast(TMonom(1,888));
	pol.InsLast(TMonom(2,666));
	pol.InsLast(TMonom(3,444));

	pol.AddMonom(TMonom(1,777));

	TMonom arr[4] = {TMonom(1,888), TMonom(1,777), TMonom(2,666), TMonom(3,444)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom,can_add_Monom_End_TPolinom){
	TPolinom pol;
	pol.InsLast(TMonom(1,888));
	pol.InsLast(TMonom(2,666));
	pol.InsLast(TMonom(3,444));

	pol.AddMonom(TMonom(1,333));

	TMonom arr[4] = {TMonom(1,888), TMonom(2,666), TMonom(3,444), TMonom(1,333)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom,can_add_two_TPolinoms){
	TPolinom pol1;
	pol1.InsLast(TMonom(1,888));
	pol1.InsLast(TMonom(2,666));
	pol1.InsLast(TMonom(3,444));

	TPolinom pol2;
	pol2.InsLast(TMonom(1,999));
	pol2.InsLast(TMonom(2,777));
	pol2.InsLast(TMonom(3,555));
	pol2.InsLast(TMonom(3,333));

	TPolinom pol = pol1 + pol2;

	TMonom arr[] = {TMonom(1,999), TMonom(1,888), TMonom(2,777), TMonom(2,666), TMonom(3,555), TMonom(3,444), TMonom(3,333)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom,can_add_two_TPolinoms_one_del){
	TPolinom pol1;
	pol1.InsLast(TMonom(1,888));
	pol1.InsLast(TMonom(2,666));
	pol1.InsLast(TMonom(3,555));

	TPolinom pol2;
	pol2.InsLast(TMonom(1,999));
	pol2.InsLast(TMonom(-2,666));
	pol2.InsLast(TMonom(3,555));
	pol2.InsLast(TMonom(3,333));

	TPolinom pol = pol1 + pol2;

	TMonom arr[] = {TMonom(1,999), TMonom(1,888), TMonom(6,555), TMonom(3,333)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom, can_add_two_first_TPolinoms){
	TPolinom pol1;
	pol1.InsLast(TMonom(5,555));
	pol1.InsLast(TMonom(4,444));
	pol1.InsLast(TMonom(3,333));

	TPolinom pol2;
	pol2.InsLast(TMonom(9,999));
	pol2.InsLast(TMonom(8,888));
	pol2.InsLast(TMonom(7,777));
	pol2.InsLast(TMonom(6,666));

	TPolinom pol = pol1 + pol2;

	TMonom arr[] = {TMonom(9,999), TMonom(8,888), TMonom(7,777), TMonom(6,666), TMonom(5,555), TMonom(4,444), TMonom(3,333)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom,can_add_two_last_TPolinoms){
	TPolinom pol1;
	pol1.InsLast(TMonom(9,999));
	pol1.InsLast(TMonom(8,888));
	pol1.InsLast(TMonom(7,777));
	pol1.InsLast(TMonom(6,666));

	TPolinom pol2;
	pol2.InsLast(TMonom(5,555));
	pol2.InsLast(TMonom(4,444));
	pol2.InsLast(TMonom(3,333));

	TPolinom pol = pol1 + pol2;

	TMonom arr[] = {TMonom(9,999), TMonom(8,888), TMonom(7,777), TMonom(6,666), TMonom(5,555), TMonom(4,444), TMonom(3,333)};

	int i = 0;
	bool isOk = true;
	for(pol.Reset(); !pol.IsEnd(); pol.GoNext()){
		if(!(pol.GetCurrentValue() == arr[i++])){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(TPolinom,can_add_two_TPolinoms_res_empty){
	TPolinom pol1;
	pol1.InsLast(TMonom(-5,555));
	pol1.InsLast(TMonom(-4,444));
	pol1.InsLast(TMonom(-3,333));

	TPolinom pol2;
	pol2.InsLast(TMonom(5,555));
	pol2.InsLast(TMonom(4,444));
	pol2.InsLast(TMonom(3,333));

	TPolinom pol = pol1 + pol2;

	EXPECT_EQ(0, pol.GetLen());
}

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