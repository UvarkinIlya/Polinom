#include "../TPolinom/TList.h"

#include "gtest.h"

TEST(TList, can_create_list){
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_insFirst){
	TList<int> list;

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

TEST(TList, can_insLast){
	TList<int> list;

	list.InsLast(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsLast(4);

	int arr[4] = {1, 2, 3, 4};
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

TEST(TList, can_insCurrent){
	TList<int> list;

	list.InsFirst(1);
	list.InsLast(3);
	list.InsLast(4);

	list.Reset();
	list.InsCurrent(2);

	int arr[4] = {1, 2, 3, 4};
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

TEST(TList, can_delFirst){
	TList<int> list;

	list.InsFirst(1);
	list.DelFirst();

	list.Reset();
	
	EXPECT_EQ(list.IsEnd(),true);
}

TEST(TList,can_delLast){
	TList<int> list;

	list.InsFirst(1);
	list.DelLast();

	list.Reset();

	EXPECT_EQ(list.IsEnd(),true);
}

TEST(TList,can_delCurrent){
	TList<int> list;

	list.InsFirst(1);
	list.InsLast(3);
	list.InsLast(4);

	list.Reset();
	list.InsCurrent(2);

	list.DelCurrent();

	int arr[3] = {1, 3, 4};
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