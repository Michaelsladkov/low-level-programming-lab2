/*
    Parser for my Cypher-based querry language
*/
%require "3.2"
%language "c++"

%skeleton "lalr1.cc"

%code requires 
{
#include "ast.hpp"
#include <string>
}

%union
{
    const char  *name;
    std::string *string;
    INode       *iNode;
    ReturnList  *returnList;
    ValueNode   *Value;
    int         integer;
    float       real;
    bool        boolean;
}

%token
    MATCH_KEYWORD
    WHERE_KEYWORD
    RETURN_KEYWORD
    CREATE_KEYWORD
    DELETE_KEYWORD
    SET_KEYWORD
    AND_KEYMORD
    OR_KEYWORD
    NOT_KEYWORD
    GREATER_CMP
    GREATER_OR_EUQAL_CMP
    LESS_CMP
    LESS_OR_EQUAL_CMP
    EQUAL_CMP
    CONTAINS_OP
    ASSIGNMENT
    DASH
    RIGHT_ARROW
    LEFT_ARROW
    DOUBLE_DASH
    COLON
    SCOLON
    PERIOD
    COMMA
    LPAR
    RPAR
    LBRACKET
    RBRACKET
    LBRACE
    RBRACE
    END_OF_FILE
;

%token <string>  STRING_LITERAL
%token <integer> INT_LITERAL
%token <real>    FLOAT_LITERAL
%token <boolean> BOOL_LITERAL
%token <name>    NAME

%nterm <iNode>       REQUEST
%nterm <iNode>       REQUEST_B
%nterm <iNode>       MATCH_QUERRY //described
%nterm <iNode>       ANY_VARIABLE_MATCH //described
%nterm <iNode>       VARIABLE_MATCH //described
%nterm <iNode>       ANY_RELATION_MATCH //described
%nterm <iNode>       RELATION_MATCH //described
%nterm <iNode>       RETURN_EXPRESSION
%nterm <returnList>  RETURN_LIST
%nterm <Value>       VALUE //described
%nterm <iNode>       CREATE_QUERRY
%nterm <iNode>       SET_EXPRESSION
%nterm <iNode>       DELETE_EXPRESSION
%nterm <iNode>       FILTER //described
%nterm <iNode>       PREDICATE //described
%nterm <iNode>       LOGICAL_EXPRESSION //described
%nterm <iNode>       ATTRIBUTE_LIST //described
%nterm <iNode>       ATTRIBUTE //described

%left OR_KEYWORD
%left AND_KEYMORD
%left NOT_KEYWORD

%start REQUEST

%%
REQUEST: REQUEST_B SCOLON
       | REQUEST_B END_OF_FILE

REQUEST_B: MATCH_QUERRY
         | REQUEST_B PREDICATE
         | REQUEST_B SET_EXPRESSION
         | REQUEST_B CREATE_QUERRY
         | REQUEST_B DELETE_EXPRESSION
         | REQUEST_B RETURN_EXPRESSION
;

MATCH_QUERRY: MATCH_KEYWORD VARIABLE_MATCH
            | MATCH_KEYWORD VARIABLE_MATCH RELATION_MATCH VARIABLE_MATCH
            | MATCH_KEYWORD VARIABLE_MATCH RELATION_MATCH ANY_VARIABLE_MATCH
            | MATCH_KEYWORD VARIABLE_MATCH ANY_RELATION_MATCH ANY_VARIABLE_MATCH
            | MATCH_KEYWORD VARIABLE_MATCH ANY_RELATION_MATCH VARIABLE_MATCH
;

VARIABLE_MATCH: LPAR NAME COLON NAME PREDICATE RPAR
              | LPAR NAME COLON NAME LBRACE ATTRIBUTE_LIST RBRACE RPAR
;

ANY_VARIABLE_MATCH: LPAR NAME RPAR
;

RELATION_MATCH: DASH LBRACKET NAME COLON NAME RBRACKET RIGHT_ARROW
              | LEFT_ARROW LBRACKET NAME COLON NAME RBRACKET DASH
;

ANY_RELATION_MATCH: DOUBLE_DASH
;

PREDICATE: WHERE_KEYWORD LOGICAL_EXPRESSION
;

LOGICAL_EXPRESSION: LOGICAL_EXPRESSION AND_KEYMORD LOGICAL_EXPRESSION
                  | LOGICAL_EXPRESSION OR_KEYWORD LOGICAL_EXPRESSION
                  | NOT_KEYWORD LOGICAL_EXPRESSION
                  | FILTER
;

FILTER: VALUE LESS_CMP VALUE
      | VALUE LESS_OR_EQUAL_CMP VALUE
      | VALUE GREATER_CMP VALUE
      | VALUE GREATER_OR_EUQAL_CMP VALUE
      | VALUE EQUAL_CMP VALUE
      | VALUE CONTAINS_OP VALUE
;

SET_EXPRESSION: SET_KEYWORD NAME PERIOD NAME ASSIGNMENT VALUE
;

DELETE_EXPRESSION: DELETE_KEYWORD NAME
;

RETURN_EXPRESSION: RETURN_EXPRESSION COMMA VALUE
                 | RETURN_KEYWORD VALUE

ATTRIBUTE_LIST: NAME PERIOD NAME COLON VALUE COMMA ATTRIBUTE_LIST
              | NAME PERIOD NAME COLON VALUE

CREATE_QUERRY: CREATE_KEYWORD VARIABLE_MATCH
             | CREATE_KEYWORD VARIABLE_MATCH RELATION_MATCH VARIABLE_MATCH

VALUE: NAME
     | BOOL_LITERAL
     | INT_LITERAL
     | FLOAT_LITERAL
     | STRING_LITERAL
     | NAME PERIOD NAME
;
%%
