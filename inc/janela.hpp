#pragma once

#include <gtkmm.h>
#include <string>
# include <iostream>
# include <cstdlib>
# include <thread>
# include <curl/curl.h>
# include <nlohmann/json.hpp>
#include "../inc/menu.hpp"

using json = nlohmann::json;
using namespace std;


class menu;

class janela : public Gtk::Window
{

	public:
		janela( void );
		~janela( void );

		void try_gramm(void);
		void try_phrase(void);
		void try_text(void);
		void send( void );
		void env_send( void );
	
	protected:
		void	set_grid( void );
		void	set_reader( void );
		void	set_char_IA( void );
        std::string	requisition(std::string const  &prompt);

		Gtk::Box	box_main;
		Gtk::Box	reader;
		Gtk::Grid	grid;
		Gtk::Box	chat_IA;
		std::jthread	t_send;

		Gtk::Entry	prompt;
		Gtk::Label	response;
		Gtk::Button	send_prompt;
		
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
