#include "../TPolinom/THeadList.h"
#include "gtest.h"

TEST(THeadList, can_create_list){
	ASSERT_NO_THROW(THeadList<int> list);
}

TEST(THeadList, can_insFirst){
	THeadList<int> list;

	list.InsFirst(1);
	list.InsFirst(2);
	list.InsFirst(3);
	list.InsFirst(4);

	int arr[4] = {4, 3, 2, 1};
	int i = 0;
	bool isOk = true;
	for(list.Reset(); !list.IsEnd(); list.GoNext()){
		if(arr[i++] != list.GetCurrentValue()){
			isOk = false;
			break;
		}
	}

	EXPECT_EQ(isOk,true);
}

TEST(THeadList,can_delFirst){
	THeadList<int> list;

	list.InsFirst(1);
	list.DelFirst();

	list.Reset();

	EXPECT_EQ(list.IsEnd(),true);
}