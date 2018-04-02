/**********************************************************************/
// File:	MainTest.cpp
// Summary:	Test file for Lab 2, Step 1
//			The program tests that a definition of CashRegister class 
//			works according to requirements in given specification. 
//			It makes subsequent calls to the registerItem() function to
//			check that required validation is provided. The result of 
//			execution is expected to give 5 error messages in console.
//			NO CHANGES of the predefined code are allowed!
// Version: Version 1.1 - 2013-03-17
// Author:	Christer Lundberg
// -------------------------------------------
// Log:	2002-08-28	Created the file. Christer
//		2013-03-17	Uppdate  Version 1.1 by Anne. 
//					Converted to English and VS 2012 
//		2015-03-05	Revised by Anne. Converted to VS 2013
/**********************************************************************/

#include <iomanip>
	using std::setw;
	using std::left;
#include <iostream>
	using std::cout;
	using std::endl;
	using std::ios;
#include "CashRegister.h"

const char ERROR[] = "Error! Registration failed."; 

int main()
{
	CashRegister cash("Register.txt", 5);

	cout << "This test should give five error messages below!" << endl;
	cout << "------------------------------------------------" << endl;

	if (!cash.registerItem( 3,"Tvål Sun", 18.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Äppelmos Bob", 14.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Coca Cola 2 lit.",  12.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Kroppkakor 4 st.", 18.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Mjölk mellan 1 lit", 6.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 2,"Skottkärran Emil",  389.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 2,"Räfsan Gunda", 110.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Socker bit ½ kg", 14.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 3,"Tandkräm Linnéa",  9.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 3,"Deodorant Axe", 37.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 4,"Aftonbladet", 8.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 4,"Mitt livs korsord",  39.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Svenssons äppelpaj", 30.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 4,"Skraplott Lyckans Ost", 25.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 5,"Räfflade dyckert 1000 st.",  89.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 5,"Hammaren Adam", 65.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Sörens Grova Limpa", 12.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Kaffe Gevalia Mörk",  29.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Glass Holland Eis", 32.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 2,"Myrgift Sudda Bort", 82.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 5,"Sandpapper blandat set",  32.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 3,"Munvatten Dentovit", 31.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 5,"Borrmaskinen Herbert", 310.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Makrillfiléer ½ kg",  38.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 6,"Golvlampan Hilda", 230.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 0,"Öl Pripps Blå 6-pack", 30.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 6,"Rakapparaten Orvar",  99.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 1,"Findus Köttfärssås 2,5 dl.", 16.00 ))
		cout << ERROR << endl;
	if (!cash.registerItem( 0,"Skruv 4x22 1000 st.", 80.50 ))
		cout << ERROR << endl;
	if (!cash.registerItem(-1,"Blå Castello  100 gr.",  19.50 ))
		cout << ERROR << endl << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << setw(30) << left << "The total for this sale was:" << cash.batchTotal() << " SEK" << endl;
	cout << setw(30) << left << "Expected result should be: " << "1473.00 SEK" << endl << endl;

	return 0;
}