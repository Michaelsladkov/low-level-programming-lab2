#include <iostream>
#include "../lib/ast.hpp"
#include "../lib/driver.hpp"

int yyFlexLexer::yywrap() {
    return 1;
}

int main()
{
    FlexLexer* lexer = new yyFlexLexer;
    yy::ParserDriver driver(lexer, 0);
    driver.parse();
    driver.printout();
    delete lexer;
}