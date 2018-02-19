#include"parser.hpp"
#include<unistd.h>
#if !defined(VERSION) || !defined(NAMEPROGRAM)
	#error "Not defined version/nameprogram"
#endif






void parser::welcome(void) noexcept{
	std::cout << NAMEPROGRAM 
					<< " " << VERSION << " " 
						<< __TIME__  << " "<< __DATE__ << std::endl << welcome_string;
}

parser::parser(void) noexcept{
	welcome();
	Lexer lexer(dup(STDIN_FILENO));
	
}
