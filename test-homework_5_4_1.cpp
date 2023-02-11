#include <iostream>
#include <windows.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


#include "classes.cpp"


TEST_CASE("test List", "[list]") {

	SECTION("empty") {
		List list1;	
		{
			INFO("Список не пуст после создания");
			CHECK(list1.Empty() == true);
		}
		{
			list1.PushBack(1);
			list1.PopBack();
			INFO("Список не пуст после выдачи значения");
			CHECK(list1.Empty() == true);
		}
	}

	SECTION("size") {
		List list2;
		{
			INFO("Размер при создании не равен 0");
			CHECK(list2.Size() == 0);
		}
		{
			list2.PushBack(1);
			list2.PushBack(2);
			list2.PushFront(3);
			INFO("Размер не равен 3");
			CHECK(list2.Size() == 3);
		}
		{
			list2.PopFront();
			INFO("Размер не равен 2");
			CHECK(list2.Size() == 2);
		}
		{
			list2.PopBack();
			INFO("Размер не равен 1");
			CHECK(list2.Size() == 1);
		}
	}

	SECTION("clear") {
		List list3;
		INFO("Error in Clear() method");
		list3.PushBack(1);
		list3.PushBack(2);
		list3.PushFront(3);
		int s1 = list3.Size();
		list3.Clear();
		CHECK(( s1 !=0 && list3.Size() == 0));
	}
}

int main() {

	return Catch::Session().run();

}