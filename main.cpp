#include <iostream> /* cout */
#include "tException_t.h"


/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
using std::cout;

/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~ Function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


void NormalTest(void);

void NormalTest(void)
{
	
	throw TException_t<int>( -42 , "dont panic", __FILE__, __LINE__ );
	
//	cout << ex.GetExLine() << '\n';
	
	return;
}	


int main()
{
	cout << "---START---\n" ;
	
	try {
		NormalTest();
	} catch (TException_t<int>& _ex)
	{
		//_ex.Print();
		cout << _ex;
	} catch (...)
	{
		cout << "\nUnknown throw type\n";
		return 1;
	}
	
	
	cout << "\n---END---\n";
	return 0;
}


