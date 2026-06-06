#include "../inc/menu.hpp"
#include "../inc/janela.hpp"
#include "../inc/read_file.hpp"

using	namespace std;

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (cerr << "error: way of use: ./prog dir lesson" << endl, 1);
	menu first;

	try{
		std::string mod = first.join_dir(argv[1], argv[2]);
		first.open_f(mod);
		first.read_f();
	} catch( std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
