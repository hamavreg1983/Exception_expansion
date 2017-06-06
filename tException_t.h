#ifndef __T_EXCEPTION_H__
#define __T_EXCEPTION_H__

/** 
 *  @file TException_t.h
 *  @brief A class that expand the throw-catch method with object's text msg, file and line.
 * 
 *  @details 
 * 
 *  @author Author Yuval Hamberg (yuval.hamberg@gmail.com) 
 *	@date June 2017
 * 
 *  @bug No known bugs. 
 */ 
 
#include <string>
#include <iostream>

/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
typedef unsigned int Uint;

/* ~~~ Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

template <class Data>
class TException_t
{
	public:
		//TException_t();		/* Default CTOR doesnot exsist */
		TException_t(const Data& _expObj , const std::string& _expText, const std::string& _file, Uint _line);
		TException_t(const TException_t& _other);		/* copy CTOR */
		virtual ~TException_t() {}	/* DTOR */
		
		inline const Data& GetExObj() const;
		inline const std::string& GetExText() const; // return by referance and not value
		inline const std::string& GetExFile() const; // return by referance and not value
		inline Uint 			  GetExLine() const;
		
	protected:
	
	private:
		
		const Data		m_expObj;
		const std::string m_expText;
		const std::string m_file;
		const Uint 		m_line;
		
		TException_t& operator=(TException_t& _other);	// blocked. can't copy class with const member data
};

template <class Data>
std::ostream& operator<<(std::ostream& _os, const TException_t<Data>& _object)
{
	std::cout << "Exception:\n----------\n";
	std::cout << _object.GetExFile() << ":";
	std::cout << _object.GetExLine() << "\n";
	std::cout << "error:" << _object.GetExText() << "\n";
	std::cout << "object:" << _object.GetExObj() << "\n";
}
/*
// all data member are const so no use for input
template <class Data>
std::istream& operator>>(std::istream& _is, TException_t<Data>& _object); 
*/

/* ~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

template <class Data>
TException_t<Data>::TException_t(const Data& _expObj , const std::string& _expText, const std::string& _file, Uint _line) : m_expObj(_expObj), m_expText(_expText), m_file(_file), m_line(_line)
{ }

template <class Data>
TException_t<Data>::TException_t(const TException_t& _other) : m_expObj(_other.m_expObj), m_expText(_other.m_expText), m_file(_other.m_file), m_line(_other.m_line)
{ }

template <class Data>
const Data& TException_t<Data>::GetExObj() const
{
	return m_expObj;
}

template <class Data>
const std::string& TException_t<Data>::GetExText() const
{
	return m_expText;
}


template <class Data>
const std::string& TException_t<Data>::GetExFile() const
{
	return m_file;
}


template <class Data>
Uint TException_t<Data>::GetExLine() const
{
	return m_line;
}



#endif /* __T_EXCEPTION_H__ */
