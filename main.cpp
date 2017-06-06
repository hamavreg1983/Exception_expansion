#include <iostream> /* cout */
#include "tException_t.h"


/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
using std::cout;

/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~ Function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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
		// do something, like printing the object
		cout << _ex;
		
		// or just one member
		cout << "\n Msg catched " << _ex.GetExText();
		
	} catch (...)
	{
		cout << "\nUnknown throw type\n";
		return 1;
	}
	
	
	cout << "\n---END---\n";
	return 0;
}


