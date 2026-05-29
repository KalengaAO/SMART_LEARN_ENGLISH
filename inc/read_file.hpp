#pragma once

#include <ifstream>
#include <string>

class Read_file {


	protected:
		void	open( std::string const &file );
		string	read( void ); 

	private:
		iostream	_file;
		Read_file( void );
};
