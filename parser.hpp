#include"lexer.hpp"
constexpr char welcome_string[] =
		"Source license: not\n"
		"Binary license: not\n"
		"Use help; to get some basic infromation\n";

class parser{
	private:
		void welcome(void) noexcept;
	public:
		explicit parser(std::string * argv) = delete;
		explicit parser(void) noexcept;
};
