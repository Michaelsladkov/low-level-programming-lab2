#pragma once

#include <cstdlib>
#include <cstring>
#include <string>
#include <FlexLexer.h>

#include "ast.hpp"
#include "generated/parser.tab.hpp"

namespace yy{

class ParserDriver {
    FlexLexer *plex_;
    RequestNode *result;
    int DebugLevel;

public:
    ParserDriver(FlexLexer *plex, int Debug) : plex_(plex), DebugLevel(Debug) {}
    yy::parser::token_type yylex(yy::parser::semantic_type *yylval) {
        yy::parser::token_type tt = static_cast<yy::parser::token_type>(plex_->yylex());
        if (DebugLevel) std::cout << "lexer brought this: " << plex_->YYText() << std::endl;
        const char *TokenStr = plex_->YYText();
        if (tt == yy::parser::token_type::INT_LITERAL) {
            yylval->integer = std::stoi(TokenStr);
        }
        if (tt == yy::parser::token_type::FLOAT_LITERAL) {
            yylval->real = std::atof(TokenStr);
        }
        if (tt == yy::parser::token_type::BOOL_LITERAL) {
            bool value = false;
            if (std::strcmp(TokenStr, "true") == 0) {
                value = true;
            }
            yylval->boolean = value;
        }
        if (tt == yy::parser::token_type::STRING_LITERAL) {
            yylval->string = new std::string(TokenStr);
        }
        if (tt == yy::parser::token_type::NAME) {
            yylval->name = new std::string(TokenStr);
        }
        return tt;
    }

    bool parse() {
        parser parser(this);
        parser.set_debug_level(DebugLevel);
        if (DebugLevel) std::cout << "begin parsing via parser" << std::endl;
        bool res = parser.parse();
        return !res;
    }

    void insert(RequestNode *v) {
        result = v;
        if (DebugLevel) std::cout << "something inserted into controller" << std::endl;
    }

    void printout() const {
        result->print(0, std::cout);
    }

    ~ParserDriver() {
       delete result;
    }
};

} // namespace yy