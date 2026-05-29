#include "../inc/read_file.hpp"

read_file::read_file(void) : _file(".welcome/welcome"){}

read_file::~read_file(void){}

void read_file::open( std::string const &file ) {
	if (!_file.is_open())
		_file.close();
	_file.open(file);
}

std::string read_file::read( void ){
//	if (_file.is_open())
///		return "FNP";
	std::string	line;
//	if (!std::getline(_file, line))
//		return "EOF";
	getline(_file, line);
	return line;
}
