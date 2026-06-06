#include "../inc/menu.hpp"
#include "../inc/janela.hpp"
#include "../inc/read_file.hpp"

using	namespace std;

int	main(int argc, char *argv[])
{
	try {
		auto	app = Gtk::Application::create("com.sle");
		return app->make_window_and_run<janela>(argc, argv);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
