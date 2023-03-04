#include "DomainTest.h"
#include "Domain.h"
#include <iostream>
#include <assert.h>

void DomainTest::runAllTests()
{
	std::cout << "Domain tests begin...\n";
	std::cout << "Getters test begin...\n";
	GettersTest();
	std::cout << "Getters test ended...\n";
	std::cout << "Setters test begin...\n";
	SettersTest();
	std::cout << "Setters test ended...\n";
}

int DomainTest::GettersTest()
{
	Cookies c{ 1, "white", "123", 1 };

	assert(c.GetId() == "123");
	assert(c.GetPrice() == 1);
	assert(c.GetType() == "white");

	ChocolateCake cc{ 2, "dark", "124", "fluffy" };

	assert(cc.GetId() == "124");
	assert(cc.GetPrice() == 2);
	assert(cc.GetType() == "dark");

	return 0;

}

int DomainTest::SettersTest()
{
	Cookies c{ 1, "white", "123", 1 };

	assert(c.GetId() == "123");
	assert(c.GetPrice() == 1);
	assert(c.GetType() == "white");

	c.setPrice(2);
	c.setId("345");
	c.setType("milky");

	assert(c.GetId() == "345");
	assert(c.GetPrice() == 2);
	assert(c.GetType() == "milky");

	ChocolateCake cc{ 2, "dark", "124", "fluffy" };

	cc.setPrice(3);
	cc.setId("345");
	cc.setType("milky");

	assert(cc.GetId() != "124");
	assert(cc.GetPrice() != 2);
	assert(cc.GetType() != "dark");
	
	return 0;
}
