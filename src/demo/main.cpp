#include <iostream>
#include "../lib/ast.hpp"
#include "../lib/driver.hpp"

int yyFlexLexer::yywrap() {
    return 1;
}

#define PARSE_STRING 0

int main()
{
    FlexLexer* lexer = new yyFlexLexer;
    yy::ParserDriver driver(lexer, 0);
    #if PARSE_STRING
        std::string Inp = "MATCH (E)";
        driver.parse(Inp);
    #else
        driver.parse();
    #endif
    driver.printout();
    delete lexer;
    
}