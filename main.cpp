#include <iostream>
#include "Controller.h"
#include "Repository.h"
#include "Domain.h"
#include "DomainTest.h"
#include "RepositoryTest.h"
#include "interface.h"
#include <stack>

using namespace std;

int main() {



	DomainTest::runAllTests();
	cout << "\n-------------------\n\n";
	RepositoyTest::runAllTests();
	cout << "\n-------------------\n\n";

	auto ui = UI();

	return 0;
}