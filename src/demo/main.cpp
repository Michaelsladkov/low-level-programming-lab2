#include <iostream>
#include "../lib/ast.hpp"
#include "../lib/driver.hpp"

int yyFlexLexer::yywrap() {
    return 1;
}

int main()
{
    FlexLexer* lexer = new yyFlexLexer;
    yy::ParserDriver driver(lexer);
    std::cout << "begin parsing" << std::endl;
    driver.parse();
    std::cout << "parsing finished" << std::endl;
    driver.printout();
    delete lexer;
}