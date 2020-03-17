/****************************************************************************
 * Copyright (C) Kamstrup A/S, 2020. All rights reserved.
 ****************************************************************************/
#ifndef __main_2020__
#define __main_2020__
/**
 *
 * @file   main.cpp
 *
 * Created:
 * @author Nikolaj Emil Sørensen <nikolaj.eriksen@gmail.com>
 * @date   Wednesday, 15th January 2020 1:06:53
 *
 *
 * Modified:
 * mod @author Nikolaj Emil Sørensen <nikolaj.eriksen@gmail.com>
 * mod @date   Wednesday, 15th January 2020 3:02:29
 *
 */
#include "Class.hpp"
#include "MyFile.hpp"

#include <stdbool.h>
#include <string.h>

/**
 *
 * brief
 *
 * @param argc
 * @param args
 * @return int
 */
int main( int argc, char** args )
{
	MyClass firstObject;
	MyClass secondObject( 10, '2', false );
	MyClass thirdObject( std::string( "supz" ) );
}
/****************************************************************************/

#endif	// __main.cpp__
