// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "logic.tab.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 115 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 103 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
         { (yylhs.value.request) = (yystack_[1].value.request); }
#line 552 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 3:
#line 104 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
         { (yylhs.value.request) = (yystack_[1].value.request); }
#line 558 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 5:
#line 107 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
           { (yylhs.value.request) = (yystack_[1].value.request); }
#line 564 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 6:
#line 108 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
           { (yylhs.value.request) = (yystack_[1].value.request); }
#line 570 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 7:
#line 109 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
           { (yylhs.value.request) = (yystack_[1].value.request); }
#line 576 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 8:
#line 110 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
           { (yylhs.value.request) = (yystack_[1].value.request); }
#line 582 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 9:
#line 111 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
           { (yylhs.value.request) = (yystack_[1].value.request); }
#line 588 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 22:
#line 138 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
                    { (yylhs.value.logicalExpressionNode) = (yystack_[2].value.logicalExpressionNode); }
#line 594 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 23:
#line 139 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
                    { (yylhs.value.logicalExpressionNode) = (yystack_[2].value.logicalExpressionNode); }
#line 600 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;

  case 34:
#line 158 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"
                   { (yylhs.value.returnExpressionNode) = (yystack_[2].value.returnExpressionNode); }
#line 606 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"
    break;


#line 610 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -52;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      11,    -6,    25,    -2,   -52,   -19,   -10,   -52,    19,    -6,
      -9,    -5,   -52,   -52,   -52,     6,   -52,   -52,   -52,     7,
      20,    21,   -52,     8,     8,   -52,   -52,   -52,   -52,    26,
     -52,    -1,   -52,    33,    19,    22,    23,    24,    32,   -52,
     -52,   -52,   -52,    34,    -6,    35,   -52,     3,    13,    36,
     -15,   -52,   -52,    45,     4,    37,    43,    38,    39,   -52,
      19,     4,    31,   -52,    14,    49,    46,   -52,    50,    51,
     -52,   -52,    19,    19,    19,    19,    19,    19,     4,     4,
      41,    54,    63,    65,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,    76,    64,   -52,   -52,   -52,    19,    60,    37,   -52
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     4,     0,    10,     1,     0,     0,
       0,     0,     2,     3,     5,     9,     7,     6,     8,     0,
       0,     0,    20,     0,     0,    44,    42,    43,    41,    40,
      35,    38,    33,     0,     0,     0,     0,     0,     0,    13,
      14,    12,    11,     0,     0,     0,    34,     0,     0,     0,
       0,    45,    39,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,    25,    21,     0,     0,    15,     0,     0,
      32,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    26,    27,    30,    31,
      22,    23,     0,    16,    18,    19,     0,    37,     0,    36
  };

  const signed char
  parser::yypgoto_[] =
  {
     -52,   -52,   -52,    86,    66,    -7,   -52,    61,   -52,    -8,
     -52,   -52,   -52,   -52,   -52,   -51,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    39,     6,    23,    24,    15,    62,
      16,    17,    18,    63,    56,    64,    66
  };

  const signed char
  parser::yytable_[] =
  {
      30,     1,    31,     8,     9,    10,    11,    54,    35,    20,
      71,    21,    22,    59,     1,    61,    40,    42,    20,    19,
      21,     5,    12,    78,    79,     7,    46,    90,    91,    32,
      35,    13,    34,    33,    55,    38,    57,    52,    25,    26,
      27,    28,    29,    72,    73,    74,    75,    76,    77,    36,
      37,    43,    70,    25,    26,    27,    28,    29,    45,    58,
      47,    48,    49,    60,    84,    85,    86,    87,    88,    89,
      50,    67,    51,    53,    80,    65,    68,    69,    81,    92,
      82,    83,    93,    94,    95,    78,    98,    96,    97,    14,
      41,     0,    44,     0,    99
  };

  const signed char
  parser::yycheck_[] =
  {
       8,     3,     9,     5,     6,     7,     8,     4,    23,    19,
      61,    21,    22,    28,     3,    11,    23,    24,    19,    38,
      21,    27,    24,     9,    10,     0,    34,    78,    79,    38,
      23,    33,    26,    38,    31,    27,    23,    44,    34,    35,
      36,    37,    38,    12,    13,    14,    15,    16,    17,    29,
      29,    25,    60,    34,    35,    36,    37,    38,    25,    23,
      38,    38,    38,    18,    72,    73,    74,    75,    76,    77,
      38,    28,    38,    38,    25,    38,    38,    38,    32,    38,
      30,    30,    28,    20,    19,     9,    26,    23,    96,     3,
      24,    -1,    31,    -1,    98
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    40,    41,    42,    27,    44,     0,     5,     6,
       7,     8,    24,    33,    42,    47,    49,    50,    51,    38,
      19,    21,    22,    45,    46,    34,    35,    36,    37,    38,
      48,    44,    38,    38,    26,    23,    29,    29,    27,    43,
      44,    43,    44,    25,    46,    25,    48,    38,    38,    38,
      38,    38,    44,    38,     4,    31,    53,    23,    23,    28,
      18,    11,    48,    52,    54,    38,    55,    28,    38,    38,
      48,    54,    12,    13,    14,    15,    16,    17,     9,    10,
      25,    32,    30,    30,    48,    48,    48,    48,    48,    48,
      54,    54,    38,    28,    20,    19,    23,    48,    26,    55
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      42,    42,    42,    42,    42,    44,    44,    43,    46,    46,
      45,    53,    54,    54,    54,    54,    52,    52,    52,    52,
      52,    52,    50,    51,    47,    47,    55,    55,    49,    49,
      48,    48,    48,    48,    48,    48
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     6,     8,     3,     7,     7,
       1,     2,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     6,     2,     3,     2,     7,     5,     2,     4,
       1,     1,     1,     1,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "MATCH_KEYWORD", "WHERE_KEYWORD",
  "RETURN_KEYWORD", "CREATE_KEYWORD", "DELETE_KEYWORD", "SET_KEYWORD",
  "AND_KEYMORD", "OR_KEYWORD", "NOT_KEYWORD", "GREATER_CMP",
  "GREATER_OR_EUQAL_CMP", "LESS_CMP", "LESS_OR_EQUAL_CMP", "EQUAL_CMP",
  "CONTAINS_OP", "ASSIGNMENT", "DASH", "RIGHT_ARROW", "LEFT_ARROW",
  "DOUBLE_DASH", "COLON", "SCOLON", "PERIOD", "COMMA", "LPAR", "RPAR",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "END_OF_FILE",
  "STRING_LITERAL", "INT_LITERAL", "FLOAT_LITERAL", "BOOL_LITERAL", "NAME",
  "$accept", "REQUEST", "REQUEST_B", "MATCH_EXPRESSION",
  "ANY_VARIABLE_MATCH", "VARIABLE_MATCH", "ANY_RELATION_MATCH",
  "RELATION_MATCH", "RETURN_EXPRESSION", "VALUE", "CREATE_EXPRESSION",
  "SET_EXPRESSION", "DELETE_EXPRESSION", "FILTER", "PREDICATE",
  "LOGICAL_EXPRESSION", "ATTRIBUTE_LIST", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,   103,   103,   104,   106,   107,   108,   109,   110,   111,
     114,   115,   116,   117,   118,   121,   122,   125,   128,   129,
     132,   135,   138,   139,   140,   141,   144,   145,   146,   147,
     148,   149,   152,   155,   158,   159,   161,   162,   164,   165,
     167,   168,   169,   170,   171,   172
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
    };
    const int user_token_number_max_ = 293;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 1013 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/generated/parser.cpp"

#line 174 "/mnt/c/Users/User/ITMO/low-level-programming/low-level-programming-lab2/src/lib/parser/parser.y"

