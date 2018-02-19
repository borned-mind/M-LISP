#include<string>

struct Token{
	Token(std::string name, double value) : name(name), value_int(value){}
	Token(const char *name, double value) : name(std::string(name)) , value_int(value){}
	Token(const char name, double value) : name(std::string(1,name)) , value_int(value){}

	Token(std::string name, std::string value) : name(name), value_str(value){}
	Token(const char name, const char * value) : name(std::string(1,name)) , value_str( std::string(value) ){}


	Token(const char name) : name(std::string(1,name)) {}
	Token(const char *name) : name(std::string(name)) {}
	Token(std::string name) : name(name){}

	[[deprecated("What for you use it?")]] Token(double value): name("_"), value_int(value){}

	double value_int=0;
	std::string value_str;
	
	std::string name;
};


