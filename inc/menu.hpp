#pragma once
#include <iostream>
#include <exception>

class menu : public read_file {

	public:
		menu( void );

		class end_of_file : public std::exception{
			const char *what() const noexcept;
		};

		class file_not_open : public std::exception{
			const char *what() const noexcept;	
		};	

	protected:
		void read_f( void );
		void try_open_file( void );

}
