#pragma once

#include <iostream>
#include <exception>
#include "read_file.hpp"

class menu : public read_file
{

	public:
		menu( void );

		void read_f( void );
		void open_f( void );

		class end_of_file : public std::exception{
			const char *what() const noexcept;
		};

		class file_not_open : public std::exception{
			const char *what() const noexcept;	
		};	

};
