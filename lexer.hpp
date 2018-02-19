#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<map>

#include"token.hpp"


// to template? hm
#define GETNEWLINE(buffer, index) while(buffer[index]!=grammarly.find("newline")->second && buffer[index++]) 

#define LEXER_GET(func, buf, index, type, add, returns)\
{\
			if( func(buf[index]) ){\
				std::ostringstream s;\
				while( func(buf[index]) )\
					s<<buf[index++];\
				returns.push_back( Token( type, add) );\
				index--;continue;\
			}\
}





using charptr = char*;

constexpr std::size_t buff_size = 1024;

namespace grammar{
	const std::map<std::string , char> grammarly=
	{
		{"space", ' '},
		{"newline", '\n'},
		{"identificator", 'i'},
		{"number", 'n'},
		{"comment", ';'},
		{"assign" , '='},
		{"plus" , '+'},
		{"minus" , '-'},
		{"divide" , '/'},
		{"multiply" , '*'},
		{"identificator" , 'i'},
		{"type" , 't'},	
		{"round_begin" , '('},		
		{"round_end" , ')'},		
		{"block_begin" , '{'},
		{"block_end" , '}'},			
	};


	bool isNumerical(char ch);
	bool isLetter(char ch);


}

class Lexer{
	protected:
		FILE * f =nullptr;
		std::vector<Token> getTokens(const charptr );
	public:
		Lexer(int);
		Lexer(const char* );
		~Lexer(void) noexcept;
		
};
