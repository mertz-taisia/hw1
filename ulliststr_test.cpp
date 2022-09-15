/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include "ulliststr.cpp"
using namespace std;

//Provided Test
bool testOne()
{
	ULListStr dat;
	//Calls pushback 
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");

	//Check expected values and size
	if(!(dat.get(0) == "8" && dat.get(1) == "7" && dat.get(2) == "9"))
	{
		return false;
	}
	if(!(dat.size() == 3))
	{
		return false;
	}
	return true;
}

//Test on Push Back function
bool pushBackTest()
{
	ULListStr dat;
	//Calls push_back on empty list
	dat.push_back("0");

	
	//Check expected value and size
	if(!(dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 1))
	{
		return false;
	}

	//Adds multiple vals to list
	dat.push_back("1");
	dat.push_back("2");
	dat.push_back("3");
	dat.push_back("4");

	
	//Check expected values and size
	if(!(dat.get(0) == "0" && dat.get(1) == "1" && dat.get(2) == "2" && dat.get(3) == "3" && dat.get(4) == "4"))
	{
		return false;
	}
	if(!(dat.size() == 5))
	{
		return false;
	}

	//Adds vals till Item full
	dat.push_back("5");
	dat.push_back("6");
	dat.push_back("7");
	dat.push_back("8");
	dat.push_back("9");

	//Adds val past Item capacity
	dat.push_back("10");

	//Check expected values and size
	if(!(dat.get(0) == "0" && dat.get(dat.size() - 1) == "10"))
	{
		return false;
	}
	if(!(dat.size() == 11))
	{
		return false;
	}
	return true;
}

//Test on Push Front function
bool pushFrontTest()
{
	ULListStr dat;
	//Calls push_front on empty list
	dat.push_front("0");

	//Check expected value and size
	if(!(dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 1))
	{
		return false;
	}

	//Adds multiple vals to list
	dat.push_front("1");
	dat.push_front("2");
	dat.push_front("3");
	dat.push_front("4");

	//Check expected values and size
	if(!(dat.get(0) == "4" && dat.get(1) == "3" && dat.get(2) == "2" && dat.get(3) == "1" && dat.get(4) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 5))
	{
		return false;
	}

	//Adds vals till Item full
	dat.push_front("5");
	dat.push_front("6");
	dat.push_front("7");
	dat.push_front("8");
	dat.push_front("9");

	//Adds val past Item capacity
	dat.push_front("10");

	//Check expected values and size
	if(!(dat.get(0) == "10" && dat.get(dat.size() - 1) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 11))
	{
		return false;
	}
	return true;
}

bool largeInputTest()
{
	ULListStr dat;
	
	//Adds vals till 3 Items are filled
	for(int i = 0; i < 3; i++)
	{
		dat.push_back("0");
		dat.push_back("1");
		dat.push_back("2");
		dat.push_back("3");
		dat.push_back("4");
		dat.push_back("5");
		dat.push_back("6");
		dat.push_back("7");
		dat.push_back("8");
		dat.push_back("9");
	}

	//Checks first and last value of every function
	if(!(dat.get(0) == "0" && dat.get(9) == "9" && dat.get(10) == "0" && dat.get(19) == "9" && dat.get(20) == "0" && dat.get(29) == "9"))
	{
		return false;
	}
	dat.clear();
	return true;
}

bool popFrontTest()
{
	ULListStr dat;
	//Adds val to list
	dat.push_front("0");
	
	//Check expected value and size
	if(!(dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 1))
	{
		return false;
	}

	//Calls pop_front
	dat.pop_front();

	//Checks expected size
	if(!(dat.size() == 0))
	{
		return false;
	}
	
	//Adds vals to list
	dat.push_back("0");
	dat.push_back("1");
	dat.push_back("2");
	dat.push_back("3");
	dat.push_back("4");
	dat.push_back("5");
	dat.push_back("6");
	dat.push_back("7");
	dat.push_back("8");
	dat.push_back("9");

	//Check expected first value and size
	if(!(dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 10))
	{
		return false;
	}

	//Calls pop_front to delete val at index 0
	dat.pop_front();

	//Check expected first value and size
	if(!(dat.get(0) == "1"))
	{
		return false;
	}
	if(!(dat.size() == 9))
	{
		return false;
	}

	//Adds vals to list until Item capacity is passed
	dat.push_front("0");
	dat.push_front("-1");
	
	//Check expected first value and size
	if(!(dat.get(0) == "-1"))
	{
		return false;
	}
	if(!(dat.size() == 11))
	{
		return false;
	}

	//Calls pop_front on val in Item with only one val
	dat.pop_front();

	//Check expected first value and size
	if(!(dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 10))
	{
		return false;
	}

	dat.clear();
	
	return true;
}




bool popBackTest()
{
	ULListStr dat;

	//Adds val to list
	dat.push_front("0");
	
	//Check expected value and size
	if(!(dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 1))
	{
		return false;
	}

	//Calls pop_back
	dat.pop_back();

	//Check expected first value and size
	if(!(dat.size() == 0))
	{
		return false;
	}

	//Adds vals to list
	dat.push_back("0");
	dat.push_back("1");
	dat.push_back("2");
	dat.push_back("3");
	dat.push_back("4");
	dat.push_back("5");
	dat.push_back("6");
	dat.push_back("7");
	dat.push_back("8");
	dat.push_back("9");

	//Checks size and last value
	if(!(dat.get(dat.size() - 1) == "9"))
	{
		return false;
	}
	if(!(dat.size() == 10))
	{
		return false;
	}
	
	dat.pop_back();
	
	//Checks size and last value after pop_front
	
	if(!(dat.get(dat.size() - 1) == "8"))
	{
		return false;
	}
	if(!(dat.size() == 9))
	{
		return false;
	}
	
	//Adds values to increase above one Item
	dat.push_back("9");
	dat.push_back("10");

	//Checks size and first value
	if(!(dat.get(dat.size() - 1) == "10"))
	{
		return false;
	}
	if(!(dat.size() == 11))
	{
		return false;
	}
	
	//pops value and deletes Item
	dat.pop_back();
	
	//Checks size and first value
	if(!(dat.get(dat.size() - 1) == "9" && dat.get(0) == "0"))
	{
		return false;
	}
	if(!(dat.size() == 10))
	{
		return false;
	}
	dat.clear();
	return true;
}


int main(int argc, char* argv[])
{
	//Provided Test
	std::cout << testOne() << endl;

	//Tests push back function
	std::cout << pushBackTest() << endl;

	//Tests push front function
	std::cout << pushFrontTest() << endl;

	//Tests push back function
	std::cout << largeInputTest() << endl;

	// //Tests pop front function
	std::cout << popFrontTest() << endl;

	// //Tests pop back function
	std::cout << popBackTest() << endl;

	if(testOne() == 1 && pushBackTest() == 1 && pushFrontTest() == 1 && largeInputTest() == 1 && popFrontTest() == 1 && popBackTest() == 1)
	{
	 	std::cout << "All tests passed" << endl;
	}
  return 0;
}
