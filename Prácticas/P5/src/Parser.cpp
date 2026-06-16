// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.hpp"


// Unqualified %code blocks.
#line 25 "parser.yy"

    #include "headers/Lexer.hpp"

    // Definir yylex para que Bison llame a nuestro Lexer
    #define yylex(yylval) lexer->lex(yylval)

    // ========================================================
    // Variables globales del esquema de traducción
    // ========================================================
    TypeTab tablaTipos;         // Tabla de tipos global
    PilaTs pilaTs;             // Pila de tablas de símbolos
    std::stack<int> pilaDir;   // Pila de direcciones
    int dir = 0;               // Dirección actual de memoria

    // Variable auxiliar para propagar L.tipo (atributo heredado)
    int currentType = 0;

    // Variable auxiliar para propagar A.base (heredado de B)
    int currentBaseType = 0;

    // Variable para el tipo de retorno de funciones
    int tipoReturnFunc = 0;

    // Lista de tipos de parámetros (para F.lista)
    std::vector<int> listaParams;

#line 73 "Parser.cpp"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "parser.yy"
namespace C1 {
#line 147 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer* lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
  case 2: // $@1: %empty
#line 92 "parser.yy"
    {
        // TODO: Implementar
        // 1. dir ← 0
        // 2. Crear nueva tabla de símbolos global: new SymTab()
        // 3. Empujarla en pilaTs: pilaTs.push(...)
        
        // 1. dir ← 0
        dir = 0;
        // 2 y 3. Crear nueva tabla de símbolos global y empujarla
        pilaTs.push(new SymTab());
    }
#line 614 "Parser.cpp"
    break;

  case 3: // P: $@1 D
#line 104 "parser.yy"
    {
        // Al finalizar, imprimir resultados
        std::cout << std::endl;
        tablaTipos.print();
        std::cout << std::endl;
        std::cout << "Tabla de simbolos global:" << std::endl;
        pilaTs.top()->print();
    }
#line 627 "Parser.cpp"
    break;

  case 4: // D: T L SEMICOLON D
#line 118 "parser.yy"
    {
        // Regla semántica: L.tipo = T.tipo
        // (ya se propagó vía currentType al reducir T)
    }
#line 636 "Parser.cpp"
    break;

  case 5: // $@2: %empty
#line 137 "parser.yy"
    {
        // TODO: Implementar (mid-rule action: antes de { S })
        // 1. Obtener id: string id = $3
        // 2. Verificar: if (!pilaTs.bottom()->existe(id))
        //    a) pilaTs.push(new SymTab())  ← nuevo alcance para la función
        //    b) pilaDir.push(dir)          ← guardar dir actual
        //    c) dir = 0                    ← reiniciar dir para la función
        //    d) tipoReturnFunc = $2.tipo   ← guardar tipo de retorno
        //    Nota: Aquí también se generaría label(id) si hubiera generación de código
        // 3. Sino: cerr << "Error: El id " << id << " ya fue declarado" << endl;

        std::string id = (yystack_[3].value.sval);
        if (!pilaTs.bottom()->existe(id)) {
            pilaTs.push(new SymTab()); // Nuevo alcance para la función
            pilaDir.push(dir);         // Guardar dir actual
            dir = 0;                   // Reiniciar dir para variables locales
            tipoReturnFunc = (yystack_[4].value.attr).tipo;  // Guardar tipo de retorno
        } else {
            std::cerr << "Error: La funcion '" << id << "' ya fue declarada." << std::endl;
        }
    }
#line 662 "Parser.cpp"
    break;

  case 6: // $@3: %empty
#line 159 "parser.yy"
    {
        // TODO: Implementar (después de { S })
        // 1. Obtener id: string id = $3
        // 2. SymTab* tsFunc = pilaTs.pop()   ← retirar tabla de la función
        //    (se podría guardar tsFunc para depuración)
        // 3. dir = pilaDir.top(); pilaDir.pop()  ← restaurar dir
        // 4. Registrar la función en alcance global:
        //    pilaTs.bottom()->addSym(id, -1, $2.tipo, "func", listaParams)
        // 5. listaParams.clear()             ← limpiar para la siguiente función

        // Acción final (al salir de la función)
        std::string id = (yystack_[7].value.sval);
        SymTab* tsFunc = pilaTs.pop(); // Retiramos la tabla de la función
        
        dir = pilaDir.top();           // Restaurar dir global
        pilaDir.pop();
        
        // Registrar la función en alcance global (bottom)
        pilaTs.bottom()->addSym(id, -1, (yystack_[8].value.attr).tipo, "func", listaParams);
        listaParams.clear();           // Limpiar lista para la siguiente función
        
        if ((yystack_[7].value.sval)) free((yystack_[7].value.sval));
    }
#line 690 "Parser.cpp"
    break;

  case 7: // D: DEF T ID LPAREN F RPAREN $@2 LBRACE S RBRACE $@3 D
#line 183 "parser.yy"
    {
        // Continuar con más declaraciones
    }
#line 698 "Parser.cpp"
    break;

  case 8: // D: %empty
#line 187 "parser.yy"
    {
        // Producción vacía, no hacer nada
    }
#line 706 "Parser.cpp"
    break;

  case 9: // T: B A
#line 195 "parser.yy"
    {
        // TODO: Implementar
        // 1. Propagar: $$.tipo = $2.tipo (A.tipo)
        // 2. Actualizar currentType para que L lo use
        //
        // Nota: A.base = B.tipo se propaga como atributo heredado.
        // En Bison, los heredados se manejan con variables globales
        // o acciones intermedias (mid-rule actions).
        (yylhs.value.attr).tipo = (yystack_[0].value.attr).tipo;
        currentType = (yylhs.value.attr).tipo; // Propagamos para las variables
    }
#line 722 "Parser.cpp"
    break;

  case 10: // $@4: %empty
#line 214 "parser.yy"
    {
        // TODO: Implementar
        // 1. Empujar nueva tabla de símbolos: pilaTs.push(new SymTab())
        // 2. Guardar dir actual: pilaDir.push(dir)
        // 3. Reiniciar dir: dir ← 0

        pilaTs.push(new SymTab()); // Nuevo alcance para el struct
        pilaDir.push(dir);         // Guardar dir
        dir = 0;                   // Reiniciar dir para sumar los campos del struct
    }
#line 737 "Parser.cpp"
    break;

  case 11: // T: REGISTER LBRACE $@4 D RBRACE
#line 225 "parser.yy"
    {
        // TODO: Implementar
        // 1. El tamaño del struct es el valor actual de dir
        //    (dir acumuló los tamaños de los campos del struct)
        // 2. Retirar la tabla del struct: SymTab* tsStruct = pilaTs.pop()
        // 3. Registrar el struct en tablaTipos: tablaTipos.addStructType(dir)
        // 4. Restaurar dir: dir = pilaDir.top(); pilaDir.pop()
        // 5. Asignar $$.tipo con el ID del nuevo tipo struct
        // 6. Actualizar currentType
        int tamStruct = dir;           // El tamaño del struct es la suma de sus campos
        SymTab* tsStruct = pilaTs.pop(); 
        
        int idNuevoStruct = tablaTipos.addStructType(tamStruct); // Registrar en tabla de tipos
        
        dir = pilaDir.top();           // Restaurar dir global
        pilaDir.pop();
        
        (yylhs.value.attr).tipo = idNuevoStruct;
        currentType = (yylhs.value.attr).tipo;
    }
#line 762 "Parser.cpp"
    break;

  case 12: // B: INT
#line 250 "parser.yy"
    {
        // TODO: Implementar
        // $$.tipo = tablaTipos.getId("int")
        // $$.base = $$.tipo (se usará como A.base)
        (yylhs.value.attr).tipo = tablaTipos.getId("int");
        (yylhs.value.attr).base = (yylhs.value.attr).tipo;
        currentBaseType = (yylhs.value.attr).tipo; // Guardamos globalmente para que A lo herede
    }
#line 775 "Parser.cpp"
    break;

  case 13: // B: FLOAT
#line 261 "parser.yy"
    {
        // TODO: Implementar
        // $$.tipo = tablaTipos.getId("float")
        // $$.base = $$.tipo
        (yylhs.value.attr).tipo = tablaTipos.getId("float");
        (yylhs.value.attr).base = (yylhs.value.attr).tipo;
        currentBaseType = (yylhs.value.attr).tipo;
    }
#line 788 "Parser.cpp"
    break;

  case 14: // A: LBRACKET NUM RBRACKET A
#line 278 "parser.yy"
    {
        // TODO: Implementar
        // 1. Verificar que $2 (NUM) > 0
        //    Si no: error("El índice debe ser mayor a cero")
        // 2. A₁.base ya se propagó (hereda de A.base → B.tipo)
        // 3. $$.tipo = tablaTipos.addArrayType($2, $4.tipo)
        //    donde $4.tipo es A₁.tipo
        // 4. $$.base = $1... (heredado, pero no se usa aquí)
        if ((yystack_[2].value.ival) > 0) {
            // Se le pasa el número de elementos y el tipo del A₁
            (yylhs.value.attr).tipo = tablaTipos.addArrayType((yystack_[2].value.ival), (yystack_[0].value.attr).tipo); 
        } else {
            std::cerr << "Error: El indice del arreglo debe ser mayor a cero." << std::endl;
            (yylhs.value.attr).tipo = (yystack_[0].value.attr).tipo; // Fallback para evitar crashear
        }
    }
#line 809 "Parser.cpp"
    break;

  case 15: // A: %empty
#line 297 "parser.yy"
    {
        // TODO: Implementar
        // A.tipo = A.base
        // Como A.base se hereda de B.tipo, y lo tenemos en la variable
        // global currentType (que se fijó en B), usamos:
        // $$.tipo = ??? (necesitamos el valor de B.tipo que llegó como heredado)
        //
        // Solución: Usar $0 o una variable global.
        // Aquí usamos $<attr>0.base (referencia al símbolo anterior en la pila)
        // O más simple: una variable global baseType
        // Hereda el tipo base guardado desde B
        (yylhs.value.attr).tipo = currentBaseType;
    }
#line 827 "Parser.cpp"
    break;

  case 16: // F: T ID COMMA F
#line 319 "parser.yy"
    {
        // TODO: Implementar
        // 1. string id = $2
        // 2. pilaTs.top()->addSym(id, dir, $1.tipo, "param")
        // 3. dir += tablaTipos.getTam($1.tipo)
        // 4. listaParams.push_back($1.tipo)
        std::string id = (yystack_[2].value.sval);
        pilaTs.top()->addSym(id, dir, (yystack_[3].value.attr).tipo, "param"); // Guardar como parametro
        dir += tablaTipos.getTam((yystack_[3].value.attr).tipo);              // Aumentar la memoria local
        listaParams.push_back((yystack_[3].value.attr).tipo);                 // Registrar firma
        if ((yystack_[2].value.sval)) free((yystack_[2].value.sval));
    }
#line 844 "Parser.cpp"
    break;

  case 17: // F: T ID
#line 332 "parser.yy"
    {
        // TODO: Implementar
        // 1. string id = $2
        // 2. pilaTs.top()->addSym(id, dir, $1.tipo, "param")
        // 3. dir += tablaTipos.getTam($1.tipo)
        // 4. listaParams.push_back($1.tipo)
        std::string id = (yystack_[0].value.sval);
        pilaTs.top()->addSym(id, dir, (yystack_[1].value.attr).tipo, "param");
        dir += tablaTipos.getTam((yystack_[1].value.attr).tipo);
        listaParams.push_back((yystack_[1].value.attr).tipo);
        if ((yystack_[0].value.sval)) free((yystack_[0].value.sval));
    }
#line 861 "Parser.cpp"
    break;

  case 18: // F: %empty
#line 345 "parser.yy"
    {
        // Sin parámetros
    }
#line 869 "Parser.cpp"
    break;

  case 19: // S: %empty
#line 357 "parser.yy"
    {
        // El cuerpo de sentencias se implementará en prácticas posteriores
    }
#line 877 "Parser.cpp"
    break;

  case 20: // L: L COMMA ID
#line 369 "parser.yy"
    {
        // TODO: Implementar
        // 1. Obtener el id: string id = $3
        // 2. Verificar: if (!pilaTs.top()->existe(id))
        // 3. Si no existe: pilaTs.top()->addSym(id, dir, currentType, "var")
        //                   dir += tablaTipos.getTam(currentType)
        // 4. Si existe: cerr << "Error: La variable " << id << " ya fue declarada" << endl;
        //
        // Nota: L.tipo se propaga vía la variable global currentType
        std::string id = (yystack_[0].value.sval);
        if (!pilaTs.top()->existe(id)) {
            pilaTs.top()->addSym(id, dir, currentType, "var");
            dir += tablaTipos.getTam(currentType); // Aumentar memoria
        } else {
            std::cerr << "Error: La variable '" << id << "' ya fue declarada en este alcance." << std::endl;
        }
        if ((yystack_[0].value.sval)) free((yystack_[0].value.sval));
    }
#line 900 "Parser.cpp"
    break;

  case 21: // L: ID
#line 390 "parser.yy"
    {
        // TODO: Implementar
        // 1. Obtener el id: string id = $1
        // 2. Verificar: if (!pilaTs.top()->existe(id))
        // 3. Si no existe: pilaTs.top()->addSym(id, dir, currentType, "var")
        //                   dir += tablaTipos.getTam(currentType)
        // 4. Si existe: cerr << "Error: La variable " << id << " ya fue declarada" << endl;
        std::string id = (yystack_[0].value.sval);
        if (!pilaTs.top()->existe(id)) {
            pilaTs.top()->addSym(id, dir, currentType, "var");
            dir += tablaTipos.getTam(currentType);
        } else {
            std::cerr << "Error: La variable '" << id << "' ya fue declarada en este alcance." << std::endl;
        }
        if ((yystack_[0].value.sval)) free((yystack_[0].value.sval));
    }
#line 921 "Parser.cpp"
    break;


#line 925 "Parser.cpp"

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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;


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
    YY_STACK_PRINT ();
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -17;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -17,    13,    -1,   -17,   -17,   -17,   -11,     3,   -17,    11,
       4,   -17,    14,   -17,     2,    15,   -17,    -1,     5,    -1,
      18,     6,     8,     3,   -17,   -17,     4,   -17,    21,     9,
     -17,    17,   -17,     3,    16,   -17,   -17,    19,   -17,    -1,
     -17
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     8,     1,    12,    13,     0,     0,     3,     0,
      15,    10,     0,    21,     0,     0,     9,     8,     0,     8,
       0,     0,     0,    18,     4,    20,    15,    11,     0,     0,
      14,    17,     5,    18,     0,    16,    19,     0,     6,     8,
       7
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -17,   -17,   -17,   -16,   -17,   -17,    -7,   -17,   -17,    10,
      -5,   -17,   -17
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     8,    34,    39,     9,    17,    10,    16,
      29,    37,    14
  };

  const signed char
  Parser::yytable_[] =
  {
      12,    22,    11,    24,     4,     5,     6,     7,     4,     5,
       6,    19,    20,     3,    13,    15,    28,    18,    26,    21,
      23,    25,    27,    40,    31,    32,    28,    33,    35,    36,
       0,     0,     0,    38,     0,     0,    30
  };

  const signed char
  Parser::yycheck_[] =
  {
       7,    17,    13,    19,     5,     6,     7,     8,     5,     6,
       7,     9,    10,     0,     3,    11,    23,     3,    12,     4,
      15,     3,    14,    39,     3,    16,    33,    10,    33,    13,
      -1,    -1,    -1,    14,    -1,    -1,    26
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    18,    19,     0,     5,     6,     7,     8,    20,    23,
      25,    13,    23,     3,    29,    11,    26,    24,     3,     9,
      10,     4,    20,    15,    20,     3,    12,    14,    23,    27,
      26,     3,    16,    10,    21,    27,    13,    28,    14,    22,
      20
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    17,    19,    18,    20,    21,    22,    20,    20,    23,
      24,    23,    25,    25,    26,    26,    27,    27,    27,    28,
      29,    29
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     4,     0,     0,    12,     0,     2,
       0,     5,     1,     1,     4,     0,     4,     2,     0,     0,
       3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "INT",
  "FLOAT", "REGISTER", "DEF", "SEMICOLON", "COMMA", "LBRACKET", "RBRACKET",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "$accept", "P", "$@1", "D",
  "$@2", "$@3", "T", "$@4", "B", "A", "F", "S", "L", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    92,    92,    92,   117,   137,   159,   136,   187,   194,
     214,   213,   249,   260,   277,   297,   318,   331,   345,   357,
     368,   389
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      15,    16
    };
    // Last valid token kind.
    const int code_max = 271;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "parser.yy"
} // C1
#line 1298 "Parser.cpp"

#line 408 "parser.yy"


// Manejo de errores de Bison
void C1::Parser::error(const std::string& msg) {
    std::cerr << "Error de sintaxis: " << msg << std::endl;
}
