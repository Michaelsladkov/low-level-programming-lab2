#pragma once

#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <FlexLexer.h>

#include "ast.hpp"
#include "generated/parser.tab.hpp"

namespace yy{

class ParserDriver {
    FlexLexer *plex_;
    RequestNode *result;
    int DebugLevel;
    bool BadInput;

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

    void markBadInput() {
        BadInput = true;
    }

    bool parse() {
        BadInput = false;
        parser parser(this);
        parser.set_debug_level(DebugLevel);
        if (DebugLevel) std::cout << "begin parsing via parser" << std::endl;
        bool res = parser.parse();
        return !res;
    }

    bool parse(std::string string) {
        BadInput = false;
        auto StringStream = std::istringstream(string);
        auto Buff = plex_->yy_create_buffer(StringStream, string.length());
        plex_->yy_switch_to_buffer(Buff);
        parser parser(this);
        parser.set_debug_level(DebugLevel);
        bool res = parser.parse();
        plex_->yy_delete_buffer(Buff);
        return !res;
    }

    void insert(RequestNode *v) {
        result = v;
        if (DebugLevel) std::cout << "something inserted into controller" << std::endl;
    }

    void printout() const {
        if (BadInput) {
            std::cout << "Input request incorrect, AST can't be built" << std::endl;
        } else {
            result->print(0, std::cout);
        }
    }

    ~ParserDriver() {
        if (!BadInput)
            delete result;
    }
};

} // namespace yy