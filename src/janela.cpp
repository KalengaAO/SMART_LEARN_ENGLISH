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
	label.set_markup("<big><b>\nEnglish modules</b></big>");
	hist_title.set_markup("<b>\nRelated topic</b>");
	lesson.set_placeholder_text("ex: 1lesson (max: 50lesson)");
	history.set_markup(first.get_history());
	gramm.set_label("Grammar");
	text.set_label("Texts");
	phrase.set_label("Phrase verb");

	grid.set_row_spacing(5);
	grid.set_column_spacing(5);
	grid.attach(label, 0,0);
	grid.attach(lesson,0,1);
	grid.attach(gramm, 0,2);
	grid.attach(phrase, 0,3);
	grid.attach(text, 0,4);
	grid.attach(hist_title, 0,5);
	grid.attach(history, 0,6);

	gramm.signal_clicked().connect([](){std::cout << "clicado" << std::endl;});
}

void	janela::set_reader( void )
{
	Gtk::Label	label;
	Gtk::ScrolledWindow	scroll;
	Gtk::Button	next;

	scroll.set_child(label);
	scroll.set_size_request(600, 300);
	next.set_label("next lesson");
	reader.append(scroll);

	try{
		std::string dir = this->first.join_dir(".welcome/", "welcome");
		this->first.open_f(dir);
		label.set_markup(this->first.read_f());
	}catch (std::exception &e){
		label.set_text(e.what());
	}
}
