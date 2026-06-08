#include "../inc/janela.hpp"

janela::janela( void ) : box_main(Gtk::Orientation::HORIZONTAL) {
	set_title("SMART LEARN ENGLISH");
	set_default_size(1200, 800);
	this->set_reader();
	this->set_grid();
//	this->set_char_IA();
	set_child(box_main);
	box_main.append(grid);
	box_main.append(reader);
}

janela::~janela( void ) {}

void	janela::set_grid(void)
{
	Gtk::Label	label;
	Gtk::Label	history;
	Gtk::Label	hist_title;
	Gtk::Button	gramm;
	Gtk::Button	text;
	Gtk::Button	phrase;
	Gtk::Entry	n_pag;

	label.set_markup("<b>MODULOS DE ENGLISH</b>");

	hist_title.set_markup("<b>Topicos Relacionados</b>");
	history.set_markup(first.get_history());
	gramm.set_label("Gramática");
	text.set_label("Textos");
	phrase.set_label("Frase verbos");
	grid.set_row_spacing(5);
	grid.set_column_spacing(5);

	grid.attach(label, 0,0);
	grid.attach(gramm, 0,2);
	n_pag.set_placeholder_text("ex: 1lesson (max: 50lesson)");
	grid.attach(n_pag,0,1,3);
	grid.attach(text, 0,3);
	grid.attach(phrase, 0,4);
	grid.attach(hist_title, 0,5);
	grid.attach(history, 0,6);

}

void	janela::set_reader( void )
{
	Gtk::Label	label;
	Gtk::ScrolledWindow	scroll;

	scroll.set_child(label);
	scroll.set_size_request(600, 300);
	reader.append(scroll);

	try{
		std::string dir = this->first.join_dir(".texto/", "1lesson");
		this->first.open_f(dir);
		label.set_markup(this->first.read_f());
	}catch (std::exception &e){
		label.set_text(e.what());
	}
}
