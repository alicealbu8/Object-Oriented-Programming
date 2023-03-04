#include "Repository.h"
#include "RepositoryTest.h"
#include "Domain.h"
#include <iostream>
#include <assert.h>

void RepositoyTest::runAllTests()
{
	std::cout << "Repository test begin...\n";
	std::cout << "Add function test...\n";
	AddTest();
	std::cout << "Add function test ended \n";
	std::cout << "Remove function test...\n";
	RemoveTest();
	std::cout << "Remove function test ended \n";
	std::cout << "Edit function test...\n";
	EditTest();
	std::cout << "Edit function test ended \n";
	std::cout << "Repository test ended \n";
}

int RepositoyTest::AddTest()
{
	//tests for function add

	ChocolateRepo c;
	Cookies cookie1{10, "white", "1234", 0};
	ChocolateCake chocolatecake{6, "dark", "1235", "soft"};

	Chocolate* chocolate1 = &cookie1;
	Chocolate* chocolate2 = &chocolatecake;

	c.addChocolate(chocolate1);
	c.addChocolate(chocolate2);

	assert(c.GetChocolate()[0]->GetId() == "1234");
	assert(c.GetChocolate()[1]->GetId() == "1235");
	assert(c.GetChocolate()[0]->GetPrice() == 10);
	assert(c.GetChocolate()[1]->GetPrice() == 6);
	assert(c.GetChocolate()[0]->GetType() == "white");
	assert(c.GetChocolate()[1]->GetType() == "dark");
	

	return 0;
}

int RepositoyTest::RemoveTest()
{
	//test for function remove

	ChocolateRepo c;
	Cookies cookie1{ 10, "white", "1234", 0 };
	ChocolateCake chocolatecake{ 6, "dark", "1235", "soft" };

	Chocolate* chocolate1 = &cookie1;
	Chocolate* chocolate2 = &chocolatecake;

	c.addChocolate(chocolate1);
	c.addChocolate(chocolate2); 

	assert(c.GetChocolate().size() == 2);

	c.removeChocolate("1234"); //removes the last one added

	assert(c.GetChocolate()[0]->GetId() == "1235");
	assert(c.GetChocolate().size() == 1);

	return 0;
}

int RepositoyTest::EditTest()
{
	//test for edit remove

	ChocolateRepo c;
	Cookies cookie1{ 10, "white", "1234", 0 };
	ChocolateCake chocolatecake{ 6, "dark", "1235", "soft" };

	Chocolate* chocolate1 = &cookie1;
	Chocolate* chocolate2 = &chocolatecake;

	c.addChocolate(chocolate1);
	c.addChocolate(chocolate2);

	c.editChocolate("1234", 3, "milky", "1236");

	assert(c.GetChocolate()[0]->GetId() == "1236");
	assert(c.GetChocolate()[0]->GetPrice() == 3);
	assert(c.GetChocolate()[0]->GetType() == "milky");

	return 0;
}
