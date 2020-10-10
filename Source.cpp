#include<iostream>
#include<list>
#include<ctime>
#include<string>
#include "Bidder.h"
#include "Exchange.h"

using namespace std;


int main() {
	srand(unsigned(time(0)));

	AmericanBidder*  bd1= new AmericanBidder("Bob", 5);
	AmericanBidder* bd2 = new AmericanBidder("John", 0);

	Currency* cr1 = new Currency(200000,"Bitcoin");
	Currency* cr2 = new Currency(1260, "Litecoin");
	Currency* cr3 = new Currency(9, "XRP");
	Currency* cr4 = new Currency(10420, "Ethereum");
	Currency* cr5 = new Currency(25, "Tether");

	cr2->ShowCourse();

	Exchange exchange;
	exchange.AddCurrency(cr1);
	exchange.AddCurrency(cr2);
	exchange.AddCurrency(cr3);
	exchange.AddCurrency(cr4);
	exchange.AddCurrency(cr5);


	exchange.Attach(bd1);
	exchange.Attach(bd2);


	bd1->SetCurrency(cr4);
	bd2->SetCurrency(cr2);

	exchange.ChangeCourses();
	

	system("pause");
	return 0;
}