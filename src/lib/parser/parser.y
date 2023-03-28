/*
    Parser for my Cypher-based querry language
*/
%require "3.2"
%language "c++"

%skeleton "lalr1.cc"

%code requires 
{
#include "../ast.hpp"
#include <string>
}

%union
{
    const char               *name;
    std::string              *string;
    INode                    *iNode;
    Request                  *request;
    ExpressionNode           *expressionNode;
    MatchExpressionNode      *matchExpressionNode;
    CreateExpressionNode     *createExpressionNode;
    SetExpressionNode        *setExpressionNode;
    ReturnExpressionNode     *returnExpressionNode;
    DeleteExpressionNode     *deleteExpressionNode;
    VariableMatchNode        *variableMatchNode;
    RelationMatchNode        *relationMatchNode;
    ValueNode                *Value;
    FilterNode               *filterNode;
    PredicateNode            *predicateNode;
    LogicalExpressionNode    *logicalExpressionNode;
    AttributeListNode        *attributeListNode;
    int                      integer;
    float                    real;
    bool                     boolean;
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

%token <string>     STRING_LITERAL
%token <integer>    INT_LITERAL
%token <real>       FLOAT_LITERAL
%token <boolean>    BOOL_LITERAL
%token <name>       NAME

%nterm <request>                  REQUEST
%nterm <request>                  REQUEST_B
%nterm <matchExpressionNode>      MATCH_EXPRESSION
%nterm <variableMatchNode>        ANY_VARIABLE_MATCH
%nterm <variableMatchNode>        VARIABLE_MATCH
%nterm <relationMatchNode>        ANY_RELATION_MATCH
%nterm <relationMatchNode>        RELATION_MATCH
%nterm <returnExpressionNode>     RETURN_EXPRESSION
%nterm <Value>                    VALUE
%nterm <createExpressionNode>     CREATE_EXPRESSION 
%nterm <setExpressionNode>        SET_EXPRESSION
%nterm <deleteExpressionNode>     DELETE_EXPRESSION
%nterm <filterNode>               FILTER
%nterm <predicateNode>            PREDICATE
%nterm <logicalExpressionNode>    LOGICAL_EXPRESSION
%nterm <attributeListNode>        ATTRIBUTE_LIST

%left OR_KEYWORD
%left AND_KEYMORD
%left NOT_KEYWORD

%start REQUEST

%%
REQUEST: REQUEST_B SCOLON
       | REQUEST_B END_OF_FILE

REQUEST_B: MATCH_EXPRESSION
         | REQUEST_B MATCH_EXPRESSION
         | REQUEST_B SET_EXPRESSION
         | REQUEST_B CREATE_EXPRESSION
         | REQUEST_B DELETE_EXPRESSION
         | REQUEST_B RETURN_EXPRESSION
;

MATCH_EXPRESSION: MATCH_KEYWORD VARIABLE_MATCH
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

CREATE_EXPRESSION: CREATE_KEYWORD VARIABLE_MATCH
                 | CREATE_KEYWORD VARIABLE_MATCH RELATION_MATCH VARIABLE_MATCH

VALUE: NAME
     | BOOL_LITERAL
     | INT_LITERAL
     | FLOAT_LITERAL
     | STRING_LITERAL
     | NAME PERIOD NAME
;
%%
