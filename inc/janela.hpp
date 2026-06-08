#pragma once

#include <gtkmm.h>
#include "../inc/menu.hpp"

class menu;


class janela : public Gtk::Window
{

	public:
		janela( void );
		~janela( void );

	private:
		void	set_grid( void );
		void	set_reader( void );
		void	set_char_IA( void );
		Gtk::Box	box_main;
		Gtk::Box	reader;
		Gtk::Grid	grid;
		Gtk::Box	chat_IA;
		menu 	first;
};
