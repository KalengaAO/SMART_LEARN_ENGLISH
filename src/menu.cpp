#include "../inc/menu.hpp"

menu::menu(void) {}

void menu::read_f(void){
	std::string	line;
	for(size_t n_read = 15; n_read > 0; n_read--){
		line = read_file::read();
		if (line == "FNP")
			throw file_not_open();
		if (line == "EOF")
			throw end_of_file();
		std::cout << line << std::endl;
	}
}

void menu::open_f( void ) {
	read_file::open(".gramm/1lesson");
}

const char *menu::end_of_file::what() const noexcept {
	return "error: reached end of file.";
}

const char *menu::file_not_open::what() const noexcept {
	return "error: file do not open.";
}
