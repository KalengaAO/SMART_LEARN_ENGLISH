#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include <vector>
#include "read_file.hpp"

class menu : public read_file
{

	public:
		menu( void );
		virtual ~menu( void );

		std::string read_f( void );
		void open_f( std::string &mod );
		void set_history(std::string line);
		std::string	&get_history(void );
		std::string	join_dir(std::string mod, std::string const &n_pag);

		class end_of_file : public std::exception {
			const char *what() const noexcept;
		};

		class file_not_open : public std::exception {
			const char *what() const noexcept;
		};	

		protected:
			std::string	history;

};
