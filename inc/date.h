//============================================================================//
//
//	File Name	: date.h
//	Create Date	: 2018/05/15
//	Designers	: Deniz Uras
//	Description	: Date Class
//
//	Important Notes:
//
//============================================================================//

#ifndef _DATE_H_
#define _DATE_H_

//============================================================================//
//=============================== INCLUDES ===================================//
//============================================================================//
#include <string>
#include <iosfwd>

//============================================================================//
//==========================  MACRO DEFINITIONS ==============================//
//============================================================================//

//============================================================================//
//=========================== TYPE DEFINITIONS ===============================//
//============================================================================//

//============================================================================//
//=========================== CLASS DEFINITIONS ==============================//
//============================================================================//
class Date {
public:
	const static int random_min_year = 1940;
	const static int random_max_year = 2018;
	
	//constructors
	Date();							// default ctor as today's date
	Date(int d, int m, int y);		// ctor
	Date(const char *pstr);			// ctor as cstring gg/aa/yyyyy
	Date(const std::string &s);		// ctor as string  gg/aa/yyyyy

	//accesors
	int MonthDay()const;	//ayin kaci
	int WeekDay()const;		//haftanin kacinci gunu
	int YearDay()const;		//yilin kacinci gunu
	int Year()const;		//yil
	int Month()const;		//ay

	//mutators
	Date &setMonth(int m);
	Date &setYear(int y);
	Date &setMonthDay(int d);
	Date &operator+=(int n);
	Date &operator-=(int n);

	//fixes
	Date &operator++();		//onek
	Date operator++(int);	//sonek
	Date &operator--();		//onek
	Date operator--(int);	//sonek

	// comparing operators
	friend bool operator<(const Date &d1, const Date &d2);
	friend bool operator<=(const Date &d1, const Date &d2);
	friend bool operator>(const Date &d1, const Date &d2);
	friend bool operator>=(const Date &d1, const Date &d2);
	friend bool operator==(const Date &d1, const Date &d2);
	friend bool operator!=(const Date &d1, const Date &d2);

	// operators
	friend int operator-(const Date &r1, const Date &r2);  //aradaki gun farki

	// sign operators
	Date operator+(int)const;
	Date operator-(int)const;

	// io
	friend std::ostream &operator<<(std::ostream &os, const Date &r);  //12 Mayis 1987 Sali
	friend std::istream &operator>>(std::istream &is, Date &r);
	
	// conversion operators
	std::string to_string()const;

	// utility functions
	static Date randomDate();

private:
	int day;
	int month;
	int year;
};

//============================================================================//
//========================== FUNCTION PROTOTYPES =============================//
//============================================================================//

#endif //_DATE_H_
