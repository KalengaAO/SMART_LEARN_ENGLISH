#include "../inc/read_file.hpp"

read_file::read_file(void) {}

read_file::~read_file(void) {}

void read_file::open( std::string const &file ) {
	if (_file.is_open())
		_file.close();
	_file.open(file);
}

std::string read_file::read( void ){
	if (!_file.is_open())
		return "FNP";
	std::string	line;
	if (!std::getline(_file, line))
		return "EOF";
	return line;
}
