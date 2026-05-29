#include "../inc/menu.hpp"
#include "../inc/read_file.hpp"

int	main(void){

	menu first;

	try{
		first.open_f();
		first.read_f();
	} catch( std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
