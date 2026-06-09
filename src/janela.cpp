#include "../inc/janela.hpp"

janela::janela( void ) : box_main(Gtk::Orientation::HORIZONTAL), 
		chat_IA(Gtk::Orientation::VERTICAL) {
	set_title("SMART LEARN ENGLISH");
	set_default_size(1200, 800);
	this->set_reader();
	this->set_grid();
	this->set_char_IA();
	set_child(box_main);
	box_main.append(grid);
	box_main.append(reader);
	box_main.append(chat_IA);
}

janela::~janela( void ) {}

void	janela::set_grid(void)
{
	label.set_markup("<big><b>\nEnglish modules</b></big>");
	hist_title.set_markup("<b>\nRelated topic</b>");
	lesson.set_placeholder_text("ex: 1lesson (max: 50lesson)");
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

	gramm.signal_clicked().connect(sigc::mem_fun(*this, &janela::try_gramm));
	phrase.signal_clicked().connect(sigc::mem_fun(*this, &janela::try_phrase));
	text.signal_clicked().connect(sigc::mem_fun(*this, &janela::try_text));
}

void janela::try_gramm( void ) {
	try{
		first.open_gramm(lesson.get_text());
		r_label.set_markup(this->first.read_f());
	} catch( std::exception &e){
		r_label.set_text(e.what());
	}
}

void janela::try_phrase( void ) {
	try{
		first.open_phrase(lesson.get_text());
		r_label.set_markup(this->first.read_f());
	} catch( std::exception &e){
		r_label.set_text(e.what());
	}
}

void janela::try_text( void ) {
	try{
		first.open_text(lesson.get_text());
		r_label.set_markup(this->first.read_f());
	} catch( std::exception &e){
		r_label.set_text(e.what());
	}
}

void	janela::set_reader( void )
{
	scroll.set_child(r_label);
	scroll.set_size_request(600, 300);
	reader.append(scroll);

	try{
		std::string dir = this->first.join_dir(".welcome/", "welcome");
		this->first.open_f(dir);
		r_label.set_markup(this->first.read_f());
	}catch (std::exception &e){
		r_label.set_text(e.what());
	}
}


void	janela::send( void ){
	t_send =  std::jthread([this](){ env_send();});
}

void	janela::env_send( void )
{
	std::string two("All responses must be displayed in gtkmm4");
	try{
		std::string prom = prompt.get_text();
		prom += two;

		prompt.set_text("");
		response.set_text("");
		std::string	res = requisition(prom);
		response.set_markup(res);
	} catch( std::exception &e){
		response.set_text(e.what());
	}
}

void	janela::set_char_IA( void )
{
	Gtk::ScrolledWindow scroll;
	prompt.set_placeholder_text("write here only english topics");
	scroll.set_child(response);
	send_prompt.set_label("send");
	scroll.set_size_request(450, 680);

	chat_IA.append(scroll);
	chat_IA.append(send_prompt);
	chat_IA.append(prompt);
	send_prompt.signal_clicked().connect(sigc::mem_fun(*this, &janela::send));
}
