#include"lexer.hpp"
#include"util.hpp"
#include<sstream>




std::vector<Token> Lexer::getTokens(const charptr string){
	std::size_t sarr = getArraySize(string);
	std::vector<Token> returns;

	using namespace grammar;

	for(std::size_t i = 0; i < sarr; i++)
	{

		if(grammarly.find("comment")->second == string[i] 
			&& grammarly.find("comment")->second == string[i+1] ) GETNEWLINE(string,i);
		if(grammarly.find("space")->second == string[i]) continue;


		auto it = grammarly.cbegin();
		for(it ; it != grammarly.cend();it++){
			if(it->second == string[i]) {
				returns.push_back( Token(it->first) );
				break;
			}
		}
		if(it != grammarly.cend()) continue;

		
		LEXER_GET(isNumerical, string, i, grammarly.find("number")->second, atof(s.str().c_str()), returns);
		LEXER_GET(isLetter, string, i, grammarly.find("identificator")->second, std::move( s.str().c_str() ), returns);
		throw( std::runtime_error("Parsing error: '" + std::string(1,string[i]) + "' < in ->" + string ) );
	}
	std::cout << "Return tokens" << std::endl;
	return returns;
}


Lexer::Lexer(int fd){
	this->f = fdopen(fd, "rb");
	char buffer[buff_size];
	std::vector<Token> tokens;
	while(1){
		std::cout << "> ";
		fgets(buffer, buff_size-1, this->f);
		

		try{
			tokens = getTokens(buffer);
		}catch(std::runtime_error & e){
			std::cerr << e.what() << std::endl;
			continue;
		}

		for(auto x : tokens)
				std::cout <<
					 "num_val:" << x.value_int << std::endl
					<< "value_str: " << x.value_str << std::endl
					<< "name(type): " << x.name << std::endl << "~~~~~~~~~~" << std::endl;
		
	}	
	
}

Lexer::Lexer(const char * fn){
	std::ifstream file(fn, std::ios::binary);
		
}

Lexer::~Lexer(void){
	if(this->f != nullptr){
		fclose(this->f);
	}
}

//grammar

bool grammar::isLetter(char ch) 
{
		if( (ch >= 'a' && ch <='z') || (ch >='A' && ch<='Z') ) return true;
		return false;
}

bool grammar::isNumerical(char ch){
		if(ch >= '0' && ch <= '9') return true;
		return false;
}
