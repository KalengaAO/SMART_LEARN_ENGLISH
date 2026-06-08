#pragma once

#include <gtkmm.h>
#include <string>
#include "../inc/menu.hpp"

class menu;


class janela : public Gtk::Window
{

	public:
		janela( void );
		~janela( void );

		void try_gramm(void);
	
	protected:
		void	set_grid( void );
		void	set_reader( void );
		void	set_char_IA( void );
		Gtk::Box	box_main;
		Gtk::Box	reader;
		Gtk::Grid	grid;
		Gtk::Box	chat_IA;

		Gtk::Entry	lesson;
		Gtk::Button	gramm;
		Gtk::Button	text;
		Gtk::Button	phrase;
		Gtk::Label	label;
		Gtk::Label	history;
		Gtk::Label	hist_title;

		Gtk::Label	r_label;
		Gtk::ScrolledWindow	scroll;

		menu 	first;
};
