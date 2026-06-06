#include "../inc/menu.hpp"

menu::menu(void) {}

std::string menu::read_f(void){
	std::string	line;
	std::string	full_line;

	while (true){
		line = read_file::read();
		set_history(line);
		if (line == "FNP")
			throw file_not_open();
		if (line == "EOF")
			break ;
		full_line += "\n" + line;
	}
	return full_line;
}

menu::~menu(void ) {}

std::string	menu::get_history( void ) const {
	return this->history;
}

void	menu::set_history(std::string line)
{
	if (!std::strncmp(line.c_str(), "<big>", 5))
		this->history.append("\n" + line);
}

std::string	menu::join_dir(std::string mod, std::string const &n_pag)
{
	mod += n_pag;
	return mod;
}

void menu::open_f( std::string	&modulo) {
	read_file::open(modulo);
}

const char *menu::end_of_file::what() const noexcept {
	return "error: reached end of file.";
}

const char *menu::file_not_open::what() const noexcept {
	return "error: file do not open.";
}
