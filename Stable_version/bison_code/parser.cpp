/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "lexer.hpp"
using namespace std;

struct ASTNode {
    std::string type;
    std::vector<ASTNode*> children;
    std::string value;
};

ASTNode* makeNode(std::string type, std::string value) {
    ASTNode* node = new ASTNode;
    node->type = type;
    node->value = value;
    return node;
}

void printAST(ASTNode* node, int level = 0) {
    // print the current node
    std::cout << std::string(level, ' ') << "- " << node->type << " : " << node->value << std::endl;

    // recursively print the children nodes
    for (ASTNode* child : node->children) {
        printAST(child, level + 2);
    }
}

std::vector<ASTNode*> ASTNODES;

void yyerror(const char* msg, ...) {
    std::cerr << "Syntax error at line " << yylineno << ": " << msg << std::endl;
}

#line 108 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RETURN = 258,
    VAR = 259,
    TYPE = 260,
    IS = 261,
    ROUTINE = 262,
    END = 263,
    BOOL_LITERAL = 264,
    INTEGER = 265,
    REAL = 266,
    BOOLEAN = 267,
    RECORD = 268,
    ARRAY = 269,
    IN = 270,
    REVERSE = 271,
    LOOP = 272,
    FOR = 273,
    WHILE = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    AND = 278,
    OR = 279,
    XOR = 280,
    NOT = 281,
    IDENTIFIER = 282,
    INTEGER_LITERAL = 283,
    REAL_LITERAL = 284,
    STRING_LITERAL = 285,
    RANGE = 286,
    COMMA = 287,
    COLON = 288,
    SEMICOLON = 289,
    LPAREN = 290,
    RPAREN = 291,
    LBRACKET = 292,
    RBRACKET = 293,
    ASSIGN = 294,
    EQUALS = 295,
    NOT_EQUAL = 296,
    LESS_THAN = 297,
    LESS_THAN_EQUAL = 298,
    GREATER_THAN = 299,
    GREATER_THAN_EQUAL = 300,
    MULTIPLY = 301,
    DIVIDE = 302,
    MODULO = 303,
    INVALID_CHARACTER = 304,
    BOOLEAN_LITERAL = 305,
    PLUS = 306,
    MINUS = 307,
    DOT = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "parser.y"

    struct ASTNode* node;
    char* value;

#line 219 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    65,    66,    67,    70,    71,    74,    75,
      78,    79,    80,    83,    86,    87,    90,    91,    94,    97,
      98,    99,   102,   103,   104,   105,   108,   112,   114,   118,
     120,   124,   126,   128,   130,   132,   134,   138,   140,   142,
     144,   146,   150,   154,   156,   160,   162,   166,   174,   183,
     189,   197,   203,   212,   213,   219,   225,   233,   234,   243,
     244,   245,   246,   247,   248,   251,   252,   253,   254,   257,
     258,   261,   262,   265,   266,   267,   268,   269,   270,   271,
     272,   275,   276,   279,   280,   281
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "VAR", "TYPE", "IS", "ROUTINE",
  "END", "BOOL_LITERAL", "INTEGER", "REAL", "BOOLEAN", "RECORD", "ARRAY",
  "IN", "REVERSE", "LOOP", "FOR", "WHILE", "IF", "THEN", "ELSE", "AND",
  "OR", "XOR", "NOT", "IDENTIFIER", "INTEGER_LITERAL", "REAL_LITERAL",
  "STRING_LITERAL", "RANGE", "COMMA", "COLON", "SEMICOLON", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "ASSIGN", "EQUALS", "NOT_EQUAL",
  "LESS_THAN", "LESS_THAN_EQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL",
  "MULTIPLY", "DIVIDE", "MODULO", "INVALID_CHARACTER", "BOOLEAN_LITERAL",
  "PLUS", "MINUS", "DOT", "$accept", "Program", "SimpleDeclaration",
  "SemicolonOrNothing", "VariableDeclaration", "TypeDeclaration",
  "RoutineDeclaration", "Parameters", "ParameterDeclaration",
  "PrimitiveType", "Type", "RecordType", "MultipleVariableDeclaration",
  "ArrayType", "Body", "Statement", "Assignment", "RoutineCall",
  "ExpressionList", "WhileLoop", "ForLoop", "Range", "IfStatement",
  "Expression", "Relation", "RelationOperand", "Simple", "Factor",
  "Summand", "Primary", "Sign", "ModifiablePrimary", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,   -19,   -11,    17,    15,  -122,     3,     3,  -122,    -1,
      64,    34,  -122,  -122,  -122,  -122,  -122,  -122,   297,   125,
     125,    53,    56,    44,  -122,  -122,   297,  -122,  -122,  -122,
    -122,  -122,    51,   143,    43,     6,  -122,    23,    -5,  -122,
    -122,  -122,    82,    67,  -122,  -122,    90,  -122,  -122,  -122,
      72,    -9,  -122,  -122,   297,    68,   297,   297,   297,  -122,
    -122,  -122,  -122,  -122,  -122,   297,   297,   297,   297,   297,
    -122,  -122,   297,    81,  -122,    61,   292,   297,   125,    53,
       1,    -7,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,    73,  -122,  -122,  -122,   125,    78,  -122,  -122,
    -122,     8,   125,   297,  -122,  -122,  -122,   125,   297,    88,
     297,   297,  -122,   199,  -122,  -122,  -122,  -122,  -122,  -122,
      10,   111,  -122,  -122,  -122,   106,   108,   102,     3,  -122,
    -122,   315,  -122,    10,   297,     8,   285,   109,     8,     8,
    -122,  -122,   145,   297,   110,     8,   226,   172,   297,   112,
     297,   253,  -122,  -122,     8,   136,   297,  -122,  -122,   280,
       3,  -122,  -122,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     8,     8,     3,     0,
       0,     0,     1,     4,     5,     9,     6,     7,     0,     0,
       0,     0,     0,    43,    73,    76,     0,    78,    81,    82,
      80,    12,    53,    57,    65,    69,    71,     0,    79,    19,
      20,    21,     0,     0,    25,    22,    10,    23,    24,    13,
       0,     0,    16,    75,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
      74,    77,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,    45,    72,    55,    54,    56,    58,    66,    67,
      68,    70,     0,    84,    26,    28,     0,     0,    11,    18,
      17,     0,     0,     0,    44,    85,    29,     0,     0,     0,
       0,     0,    32,     0,    31,    37,    38,    39,    40,    41,
       0,     0,    46,    30,    33,     0,     0,     0,     8,    35,
      34,    38,    36,    79,     0,     0,     0,     0,     0,     0,
      14,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    51,     0,     0,     0,    49,    48,     0,
       8,    50,    52,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,     0,    -6,   -39,  -122,   129,  -122,    66,  -122,
     -14,  -122,  -122,  -122,  -121,   -74,  -122,   -92,  -122,  -122,
    -122,  -122,  -122,   -16,  -122,  -122,    63,    84,  -122,  -122,
     120,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,   112,    16,     6,     7,     8,    51,    52,    45,
      46,    47,    75,    48,   113,   114,   115,    30,    81,   117,
     118,   137,   119,   132,    32,    65,    33,    34,    35,    36,
      37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    17,    31,    74,    13,    18,    49,   101,     9,   116,
      55,   108,     1,     2,   142,    12,    10,   146,   147,     1,
       2,   131,     3,    79,   151,   103,   109,   110,   111,    80,
      72,   104,    19,   159,   102,    23,    95,    15,    82,   130,
      84,    85,    86,   116,    11,    72,   116,   116,    73,   134,
     131,    70,    71,   116,   131,   131,    92,    28,    29,   131,
      97,    98,   116,    73,    99,     1,   120,   131,   130,    94,
      20,    21,   130,   130,    56,    57,    58,   130,   133,   -83,
      50,    54,   106,   -83,    53,   130,     1,   122,   121,    66,
      67,    68,   124,   123,   126,   127,    77,   -83,     1,     2,
     120,     3,    76,   120,   120,    78,    83,   133,    93,   105,
     120,   133,   133,   129,   107,   125,   133,   135,   141,   120,
     144,   136,   140,   139,   133,   138,   145,   149,    87,    88,
      89,    90,   155,    14,   157,    39,    40,    41,    42,    43,
     161,   150,   129,   156,   160,   100,   129,   129,   148,     1,
       2,   129,    44,    91,   163,    69,     0,     0,     0,   129,
       0,     0,     0,   109,   110,   111,     0,     0,     0,     0,
       0,    22,    23,    24,    25,     0,     1,     2,     0,     0,
     153,     0,    26,    59,    60,    61,    62,    63,    64,     0,
     109,   110,   111,     0,   154,    27,    28,    29,    22,    23,
      24,    25,     0,     1,     2,     0,     0,   128,     0,    26,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
       0,     0,    27,    28,    29,    22,    23,    24,    25,     0,
       1,     2,     0,     0,   152,     0,    26,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   111,     0,     0,    27,
      28,    29,    22,    23,    24,    25,     0,     1,     2,     0,
       0,   158,     0,    26,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,     0,     0,    27,    28,    29,    22,
      23,    24,    25,     0,     1,     2,     0,     0,   162,     0,
      26,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   143,     0,    27,    28,    29,    22,    23,    24,    25,
       0,    22,    23,    24,    25,     0,     0,    26,    22,    23,
      24,    25,    26,    22,    23,    24,    25,     0,    96,    26,
      27,    28,    29,     0,    26,    27,    28,    29,   -80,   -80,
     -80,     0,    27,    28,    29,     0,     0,    27,    28,    29,
       0,     0,     0,     0,     0,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80
};

static const yytype_int16 yycheck[] =
{
       0,     7,    18,    42,     4,     6,    20,     6,    27,   101,
      26,     3,     4,     5,   135,     0,    27,   138,   139,     4,
       5,   113,     7,    32,   145,    32,    18,    19,    20,    38,
      35,    38,    33,   154,    33,    27,    75,    34,    54,   113,
      56,    57,    58,   135,    27,    35,   138,   139,    53,    39,
     142,    28,    29,   145,   146,   147,    72,    51,    52,   151,
      76,    77,   154,    53,    78,     4,   101,   159,   142,     8,
       6,    37,   146,   147,    23,    24,    25,   151,   113,    35,
      27,    37,    96,    39,    28,   159,     4,   103,   102,    46,
      47,    48,   108,   107,   110,   111,     6,    53,     4,     5,
     135,     7,    35,   138,   139,    33,    38,   142,    27,    36,
     145,   146,   147,   113,    36,    27,   151,     6,   134,   154,
     136,    15,   128,    21,   159,    17,    17,   143,    65,    66,
      67,    68,   148,     4,   150,    10,    11,    12,    13,    14,
     156,    31,   142,    31,     8,    79,   146,   147,     3,     4,
       5,   151,    27,    69,   160,    35,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,     4,     5,    -1,    -1,
       8,    -1,    37,    40,    41,    42,    43,    44,    45,    -1,
      18,    19,    20,    -1,    22,    50,    51,    52,    26,    27,
      28,    29,    -1,     4,     5,    -1,    -1,     8,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    50,    51,    52,    26,    27,    28,    29,    -1,
       4,     5,    -1,    -1,     8,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    50,
      51,    52,    26,    27,    28,    29,    -1,     4,     5,    -1,
      -1,     8,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    -1,    -1,    50,    51,    52,    26,
      27,    28,    29,    -1,     4,     5,    -1,    -1,     8,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    16,    -1,    50,    51,    52,    26,    27,    28,    29,
      -1,    26,    27,    28,    29,    -1,    -1,    37,    26,    27,
      28,    29,    37,    26,    27,    28,    29,    -1,    36,    37,
      50,    51,    52,    -1,    37,    50,    51,    52,    23,    24,
      25,    -1,    50,    51,    52,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,    55,    56,    58,    59,    60,    27,
      27,    27,     0,    56,    60,    34,    57,    57,     6,    33,
       6,    37,    26,    27,    28,    29,    37,    50,    51,    52,
      71,    77,    78,    80,    81,    82,    83,    84,    85,    10,
      11,    12,    13,    14,    27,    63,    64,    65,    67,    64,
      27,    61,    62,    28,    37,    77,    23,    24,    25,    40,
      41,    42,    43,    44,    45,    79,    46,    47,    48,    84,
      28,    29,    35,    53,    58,    66,    35,     6,    33,    32,
      38,    72,    77,    38,    77,    77,    77,    80,    80,    80,
      80,    81,    77,    27,     8,    58,    36,    77,    77,    64,
      62,     6,    33,    32,    38,    36,    64,    36,     3,    18,
      19,    20,    56,    68,    69,    70,    71,    73,    74,    76,
      85,    64,    77,    64,    77,    27,    77,    77,     8,    56,
      69,    71,    77,    85,    39,     6,    15,    75,    17,    21,
      57,    77,    68,    16,    77,    17,    68,    68,     3,    77,
      31,    68,     8,     8,    22,    77,    31,    77,     8,    68,
       8,    77,     8,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    59,    60,    60,    61,    61,    62,    63,
      63,    63,    64,    64,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    70,    71,    71,    72,    72,    73,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     0,     1,
       4,     6,     4,     4,     9,    13,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     4,
       5,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     3,     1,     4,     1,     3,     5,     6,     4,
       5,     5,     7,     1,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     1,     3,     1,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 64 "parser.y"
                            {ASTNODES.push_back((yyvsp[0].node));}
#line 1555 "parser.cpp"
    break;

  case 3:
#line 65 "parser.y"
                             {ASTNODES.push_back((yyvsp[0].node));}
#line 1561 "parser.cpp"
    break;

  case 4:
#line 66 "parser.y"
                                    {ASTNODES.push_back((yyvsp[0].node));}
#line 1567 "parser.cpp"
    break;

  case 5:
#line 67 "parser.y"
                                     {ASTNODES.push_back((yyvsp[0].node));}
#line 1573 "parser.cpp"
    break;

  case 6:
#line 70 "parser.y"
                                                           { (yyval.node) =(yyvsp[-1].node); }
#line 1579 "parser.cpp"
    break;

  case 7:
#line 71 "parser.y"
                                                       { (yyval.node) =(yyvsp[-1].node); }
#line 1585 "parser.cpp"
    break;

  case 10:
#line 78 "parser.y"
                                                { (yyval.node) = makeNode("VariableDeclaration",(yyvsp[-2].value)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1591 "parser.cpp"
    break;

  case 11:
#line 79 "parser.y"
                                                              { (yyval.node) = makeNode("VariableDeclaration",(yyvsp[-4].value)); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1597 "parser.cpp"
    break;

  case 12:
#line 80 "parser.y"
                                                   { (yyval.node) = makeNode("VariableDeclaration",(yyvsp[-2].value)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1603 "parser.cpp"
    break;

  case 13:
#line 83 "parser.y"
                                          { (yyval.node) = makeNode("TypeDeclaration",(yyvsp[-2].value)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1609 "parser.cpp"
    break;

  case 14:
#line 86 "parser.y"
                                                                                                    { (yyval.node) = makeNode("RoutineDeclaration",(yyvsp[-7].value)); (yyval.node)->children.push_back((yyvsp[-5].node)); (yyval.node)->children.push_back((yyvsp[-2].node)); }
#line 1615 "parser.cpp"
    break;

  case 15:
#line 87 "parser.y"
                                                                                                                                 { (yyval.node) = makeNode("RoutineDeclaration",(yyvsp[-11].value)); (yyval.node)->children.push_back((yyvsp[-9].node)); (yyval.node)->children.push_back((yyvsp[-6].node)); (yyval.node)->children.push_back((yyvsp[-4].node)); }
#line 1621 "parser.cpp"
    break;

  case 16:
#line 90 "parser.y"
                                  { (yyval.node) = makeNode("Parameters", ""); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1627 "parser.cpp"
    break;

  case 17:
#line 91 "parser.y"
                                                   { (yyval.node) =(yyvsp[-2].node); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1633 "parser.cpp"
    break;

  case 18:
#line 94 "parser.y"
                                             { (yyval.node) = makeNode("ParameterDeclaration",(yyvsp[-2].value)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1639 "parser.cpp"
    break;

  case 19:
#line 97 "parser.y"
                        { (yyval.node) = makeNode("IntegerType",(yyvsp[0].value)); }
#line 1645 "parser.cpp"
    break;

  case 20:
#line 98 "parser.y"
                     { (yyval.node) = makeNode("RealType",(yyvsp[0].value)); }
#line 1651 "parser.cpp"
    break;

  case 21:
#line 99 "parser.y"
                        { (yyval.node) = makeNode("BooleanType",(yyvsp[0].value)); }
#line 1657 "parser.cpp"
    break;

  case 22:
#line 102 "parser.y"
                     { (yyval.node) = makeNode("PrimitiveType",(yyvsp[0].node)->type); }
#line 1663 "parser.cpp"
    break;

  case 23:
#line 103 "parser.y"
                  { (yyval.node) =(yyvsp[0].node); }
#line 1669 "parser.cpp"
    break;

  case 24:
#line 104 "parser.y"
                 { (yyval.node) =(yyvsp[0].node); }
#line 1675 "parser.cpp"
    break;

  case 25:
#line 105 "parser.y"
                  { (yyval.node) = makeNode("Identifier",(yyvsp[0].value)); }
#line 1681 "parser.cpp"
    break;

  case 26:
#line 109 "parser.y"
           { (yyval.node) = makeNode("RecordType", ""); (yyval.node)->children.push_back((yyvsp[-1].node)); }
#line 1687 "parser.cpp"
    break;

  case 27:
#line 113 "parser.y"
                            { (yyval.node) = makeNode("MultipleVariableDeclaration", ""); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1693 "parser.cpp"
    break;

  case 28:
#line 115 "parser.y"
                            { (yyval.node) =(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1699 "parser.cpp"
    break;

  case 29:
#line 119 "parser.y"
          { (yyval.node) = makeNode("ArrayType", ""); (yyval.node)->children.push_back(makeNode("Type",(yyvsp[0].node)->value)); }
#line 1705 "parser.cpp"
    break;

  case 30:
#line 121 "parser.y"
          { (yyval.node) = makeNode("ArrayType", ""); (yyval.node)->children.push_back(makeNode("Expression",(yyvsp[-2].node)->value)); (yyval.node)->children.push_back(makeNode("Type",(yyvsp[0].node)->value)); }
#line 1711 "parser.cpp"
    break;

  case 31:
#line 125 "parser.y"
     { (yyval.node) = makeNode("Body", ""); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1717 "parser.cpp"
    break;

  case 32:
#line 127 "parser.y"
     { (yyval.node) = makeNode("Body", ""); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1723 "parser.cpp"
    break;

  case 33:
#line 129 "parser.y"
     { (yyval.node) = makeNode("Body", ""); (yyval.node)->children.push_back(makeNode("Return",(yyvsp[0].node)->value)); }
#line 1729 "parser.cpp"
    break;

  case 34:
#line 131 "parser.y"
     { (yyval.node) =(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1735 "parser.cpp"
    break;

  case 35:
#line 133 "parser.y"
     { (yyval.node) =(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1741 "parser.cpp"
    break;

  case 36:
#line 135 "parser.y"
     { (yyval.node) =(yyvsp[-1].node); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1747 "parser.cpp"
    break;

  case 37:
#line 139 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1753 "parser.cpp"
    break;

  case 38:
#line 141 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1759 "parser.cpp"
    break;

  case 39:
#line 143 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1765 "parser.cpp"
    break;

  case 40:
#line 145 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1771 "parser.cpp"
    break;

  case 41:
#line 147 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1777 "parser.cpp"
    break;

  case 42:
#line 151 "parser.y"
           { (yyval.node) = makeNode("Assignment", ""); (yyval.node)->children.push_back(makeNode("ModifiablePrimary",(yyvsp[-2].node)->value)); (yyval.node)->children.push_back(makeNode("Expression",(yyvsp[0].node)->value)); }
#line 1783 "parser.cpp"
    break;

  case 43:
#line 155 "parser.y"
            { (yyval.node) = makeNode("RoutineCall", ""); (yyval.node)->children.push_back(makeNode("Identifier",(yyvsp[0].value))); }
#line 1789 "parser.cpp"
    break;

  case 44:
#line 157 "parser.y"
            { (yyval.node) = makeNode("RoutineCall", ""); (yyval.node)->children.push_back(makeNode("Identifier",(yyvsp[-3].value))); (yyval.node)->children.push_back(makeNode("ExpressionList", "")); (yyval.node)->children.back()->children =(yyvsp[-1].node)->children; }
#line 1795 "parser.cpp"
    break;

  case 45:
#line 161 "parser.y"
               { (yyval.node) = makeNode("ExpressionList", ""); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1801 "parser.cpp"
    break;

  case 46:
#line 163 "parser.y"
               { (yyval.node) =(yyvsp[-2].node); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1807 "parser.cpp"
    break;

  case 47:
#line 167 "parser.y"
          {
            (yyval.node) = makeNode("WhileLoop", "");
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
          }
#line 1817 "parser.cpp"
    break;

  case 48:
#line 175 "parser.y"
        {
          (yyval.node) = makeNode("ForLoop", "");
          (yyval.node)->value =(yyvsp[-4].value); // save identifier name as value
          (yyval.node)->children.push_back((yyvsp[-3].node));
          (yyval.node)->children.push_back((yyvsp[-1].node));
        }
#line 1828 "parser.cpp"
    break;

  case 49:
#line 184 "parser.y"
      {
        (yyval.node) = makeNode("Range", "");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
      }
#line 1838 "parser.cpp"
    break;

  case 50:
#line 190 "parser.y"
      {
        (yyval.node) = makeNode("Range", "");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
      }
#line 1848 "parser.cpp"
    break;

  case 51:
#line 198 "parser.y"
            {
              (yyval.node) = makeNode("IfStatement", "");
              (yyval.node)->children.push_back((yyvsp[-3].node));
              (yyval.node)->children.push_back((yyvsp[-1].node));
            }
#line 1858 "parser.cpp"
    break;

  case 52:
#line 204 "parser.y"
            {
              (yyval.node) = makeNode("IfStatement", "");
              (yyval.node)->children.push_back((yyvsp[-5].node));
              (yyval.node)->children.push_back((yyvsp[-3].node));
              (yyval.node)->children.push_back((yyvsp[-1].node));
            }
#line 1869 "parser.cpp"
    break;

  case 53:
#line 212 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1875 "parser.cpp"
    break;

  case 54:
#line 214 "parser.y"
           {
             (yyval.node) = makeNode("OrExpression", "");
             (yyval.node)->children.push_back((yyvsp[-2].node));
             (yyval.node)->children.push_back((yyvsp[0].node));
           }
#line 1885 "parser.cpp"
    break;

  case 55:
#line 220 "parser.y"
           {
             (yyval.node) = makeNode("AndExpression", "");
             (yyval.node)->children.push_back((yyvsp[-2].node));
             (yyval.node)->children.push_back((yyvsp[0].node));
           }
#line 1895 "parser.cpp"
    break;

  case 56:
#line 226 "parser.y"
           {
             (yyval.node) = makeNode("XorExpression", "");
             (yyval.node)->children.push_back((yyvsp[-2].node));
             (yyval.node)->children.push_back((yyvsp[0].node));
           }
#line 1905 "parser.cpp"
    break;

  case 57:
#line 233 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1911 "parser.cpp"
    break;

  case 58:
#line 235 "parser.y"
         {
           (yyval.node) = makeNode("Relation", "");
           (yyval.node)->children.push_back((yyvsp[-2].node));
           (yyval.node)->children.push_back(makeNode("RelationOperand",(yyvsp[-1].value)));
           (yyval.node)->children.push_back((yyvsp[0].node));
         }
#line 1922 "parser.cpp"
    break;

  case 59:
#line 243 "parser.y"
                         {(yyval.value) = (yyvsp[0].value);}
#line 1928 "parser.cpp"
    break;

  case 60:
#line 244 "parser.y"
                            {(yyval.value) = (yyvsp[0].value);}
#line 1934 "parser.cpp"
    break;

  case 61:
#line 245 "parser.y"
                            {(yyval.value) = (yyvsp[0].value);}
#line 1940 "parser.cpp"
    break;

  case 62:
#line 246 "parser.y"
                                  {(yyval.value) = (yyvsp[0].value);}
#line 1946 "parser.cpp"
    break;

  case 63:
#line 247 "parser.y"
                               {(yyval.value) = (yyvsp[0].value);}
#line 1952 "parser.cpp"
    break;

  case 64:
#line 248 "parser.y"
                                     {(yyval.value) = (yyvsp[0].value);}
#line 1958 "parser.cpp"
    break;

  case 65:
#line 251 "parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 1964 "parser.cpp"
    break;

  case 66:
#line 252 "parser.y"
                                                     { (yyval.node) = makeNode("MULTIPLY", ""); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1970 "parser.cpp"
    break;

  case 67:
#line 253 "parser.y"
                                                     { (yyval.node) = makeNode("DIVIDE", ""); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1976 "parser.cpp"
    break;

  case 68:
#line 254 "parser.y"
                                                     { (yyval.node) = makeNode("MODULO", ""); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1982 "parser.cpp"
    break;

  case 69:
#line 257 "parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 1988 "parser.cpp"
    break;

  case 70:
#line 258 "parser.y"
                                                     { (yyval.node) = makeNode("SIGN",(yyvsp[-1].value)); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1994 "parser.cpp"
    break;

  case 71:
#line 261 "parser.y"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 2000 "parser.cpp"
    break;

  case 72:
#line 262 "parser.y"
                                                     { (yyval.node) = makeNode("BRACKETS", ""); (yyval.node)->children.push_back((yyvsp[-1].node)); }
#line 2006 "parser.cpp"
    break;

  case 73:
#line 265 "parser.y"
                                                    { (yyval.node) = makeNode("INTEGER_LITERAL",(yyvsp[0].value)); }
#line 2012 "parser.cpp"
    break;

  case 74:
#line 266 "parser.y"
                                                    { (yyval.node) = makeNode("INTEGER_LITERAL","-" + std::string((yyvsp[0].value))); }
#line 2018 "parser.cpp"
    break;

  case 75:
#line 267 "parser.y"
                                                    { (yyval.node) = makeNode("INTEGER_LITERAL", "NOT(" + std::string((yyvsp[0].value)) + ")"); }
#line 2024 "parser.cpp"
    break;

  case 76:
#line 268 "parser.y"
                                                    { (yyval.node) = makeNode("REAL_LITERAL",(yyvsp[0].value)); }
#line 2030 "parser.cpp"
    break;

  case 77:
#line 269 "parser.y"
                                                    { (yyval.node) = makeNode("REAL_LITERAL","-" + std::string((yyvsp[0].value))); }
#line 2036 "parser.cpp"
    break;

  case 78:
#line 270 "parser.y"
                                                    { (yyval.node) = makeNode("BOOLEAN_LITERAL",(yyvsp[0].value)); }
#line 2042 "parser.cpp"
    break;

  case 79:
#line 271 "parser.y"
                                                    { (yyval.node) =(yyvsp[0].node); }
#line 2048 "parser.cpp"
    break;

  case 80:
#line 272 "parser.y"
                                                    { (yyval.node) =(yyvsp[0].node); }
#line 2054 "parser.cpp"
    break;

  case 81:
#line 275 "parser.y"
                                                    { (yyval.value) = "+"; }
#line 2060 "parser.cpp"
    break;

  case 82:
#line 276 "parser.y"
                                                    { (yyval.value) = "-"; }
#line 2066 "parser.cpp"
    break;

  case 83:
#line 279 "parser.y"
                                                    { (yyval.node) = makeNode("IDENTIFIER",(yyvsp[0].value)); }
#line 2072 "parser.cpp"
    break;

  case 84:
#line 280 "parser.y"
                                                     { (yyval.node) = makeNode("DOT", ""); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back(makeNode("IDENTIFIER",(yyvsp[0].value))); }
#line 2078 "parser.cpp"
    break;

  case 85:
#line 281 "parser.y"
                                                               { (yyval.node) = makeNode("ROUTINE_CALL", ""); (yyval.node)->children.push_back((yyvsp[-3].node)); (yyval.node)->children.push_back((yyvsp[-1].node)); }
#line 2084 "parser.cpp"
    break;


#line 2088 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 283 "parser.y"


int main(int argc, char **argv) {
        
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            printf("syntax error: %s filename\n", argv[1]);
            return 0;
        }//end if
    }//end if
    yyparse(); // Calls yylex() for tokens.
    for (int i = 0; i < ASTNODES.size(); ++i)
      printAST(ASTNODES[i]);
    return 0;
}
