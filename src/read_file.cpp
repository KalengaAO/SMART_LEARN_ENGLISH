#include "../inc/read_file.hpp"

void Read_file::open( std::string const &file ) {
	if (_file.open())
		_file.close();
	_file(file);
}

string Read_file::read( void ){

	if (!_file.open())
		return NULL;
	std::string	line;
	if (!std::getline(_file, line))
		return EOF;
	return line;
}
