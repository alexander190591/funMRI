/****************************************************************************
 * Copyright (C) Kamstrup A/S, 2020. All rights reserved.
 ****************************************************************************/
#ifndef __Class_2020__
#define __Class_2020__
/**
 *
 * @file   Class.hpp
 *
 * Created:
 * @author Nikolaj Emil Sørensen <nikolaj.eriksen@gmail.com>
 * @date   Wednesday, 15th January 2020 2:28:16
 *
 *
 * Modified:
 * mod @author Nikolaj Emil Sørensen <nikolaj.eriksen@gmail.com>
 * mod @date   Wednesday, 15th January 2020 3:04:17
 *
 */
#include <stdlib.h>
#include <string>


/**
 *
 * brief
 *
 */
class MyClass : public std::string
{
	int myInt	= 42;
	char myChar = 'c';
	bool myBool = true;

  public:
	/**
	 *
	 * brief
	 *
	 * @param intIn
	 * @param charIn
	 * @param boolIn
	 */
	MyClass( int intIn, char charIn, bool boolIn ) : std::string( "Hellow worldz" )
	{
		myInt  = intIn;
		myChar = charIn;
		myBool = boolIn;
	}
	/****************************************************************************/

	/**
	 *
	 * brief
	 *
	 * @param in
	 */
	MyClass( std::string in ) : std::string( in )
	{
	}
	/****************************************************************************/

	/**
	 *
	 * brief
	 *
	 */
	MyClass()
	{
	}
	/****************************************************************************/

	/**
	 *
	 * brief
	 *
	 * @param intIn
	 * @param charIn
	 * @param boolIn
	 */
	void doSomeThingLongThatTakesForeverToWriteButUsesCamelBackInMethodButHasToBeWrappedDueToLongNameSoYeahDone(
		int intIn,
		char charIn,
		bool boolIn )
	{
	}
	/****************************************************************************/

	/**
	 *
	 * brief
	 *
	 * @return int
	 */
	int getMyInt( void )
	{
		return myInt;
	}
	/****************************************************************************/
};

#endif	// __Class.hpp__
