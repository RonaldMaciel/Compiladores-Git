/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "ast.h"
    #include "hash.h"
    #include "semantic.h"
    
    int yylex();
    int yyerror();
    extern int getLineNumber();

    AST *root;
    extern int SemanticErrors;

#line 88 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_REAL = 260,                 /* KW_REAL  */
    KW_BOOL = 261,                 /* KW_BOOL  */
    KW_IF = 262,                   /* KW_IF  */
    KW_THEN = 263,                 /* KW_THEN  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_LOOP = 265,                 /* KW_LOOP  */
    KW_INPUT = 266,                /* KW_INPUT  */
    KW_OUTPUT = 267,               /* KW_OUTPUT  */
    KW_RETURN = 268,               /* KW_RETURN  */
    OPERATOR_LE = 269,             /* OPERATOR_LE  */
    OPERATOR_GE = 270,             /* OPERATOR_GE  */
    OPERATOR_EQ = 271,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 272,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 273,           /* TK_IDENTIFIER  */
    LIT_INT = 274,                 /* LIT_INT  */
    LIT_CHAR = 275,                /* LIT_CHAR  */
    LIT_STRING = 276,              /* LIT_STRING  */
    LIT_REAL = 277,                /* LIT_REAL  */
    TOKEN_ERROR = 278              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_REAL 260
#define KW_BOOL 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_LOOP 265
#define KW_INPUT 266
#define KW_OUTPUT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define TK_IDENTIFIER 273
#define LIT_INT 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define LIT_REAL 277
#define TOKEN_ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

  HASH_NODE *symbol;
  AST *ast;

#line 192 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_REAL = 5,                    /* KW_REAL  */
  YYSYMBOL_KW_BOOL = 6,                    /* KW_BOOL  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_THEN = 8,                    /* KW_THEN  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_LOOP = 10,                   /* KW_LOOP  */
  YYSYMBOL_KW_INPUT = 11,                  /* KW_INPUT  */
  YYSYMBOL_KW_OUTPUT = 12,                 /* KW_OUTPUT  */
  YYSYMBOL_KW_RETURN = 13,                 /* KW_RETURN  */
  YYSYMBOL_OPERATOR_LE = 14,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 15,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 16,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 17,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 18,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INT = 19,                   /* LIT_INT  */
  YYSYMBOL_LIT_CHAR = 20,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 21,                /* LIT_STRING  */
  YYSYMBOL_LIT_REAL = 22,                  /* LIT_REAL  */
  YYSYMBOL_TOKEN_ERROR = 23,               /* TOKEN_ERROR  */
  YYSYMBOL_24_ = 24,                       /* '<'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '&'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '~'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_declarat = 45,                  /* declarat  */
  YYSYMBOL_declarations = 46,              /* declarations  */
  YYSYMBOL_func_parameters = 47,           /* func_parameters  */
  YYSYMBOL_end_parameters = 48,            /* end_parameters  */
  YYSYMBOL_literal = 49,                   /* literal  */
  YYSYMBOL_tipo = 50,                      /* tipo  */
  YYSYMBOL_create_array = 51,              /* create_array  */
  YYSYMBOL_bloco = 52,                     /* bloco  */
  YYSYMBOL_commands_list = 53,             /* commands_list  */
  YYSYMBOL_commands = 54,                  /* commands  */
  YYSYMBOL_output_list = 55,               /* output_list  */
  YYSYMBOL_end_output = 56,                /* end_output  */
  YYSYMBOL_elements_to_output = 57,        /* elements_to_output  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_arguments_list = 59,            /* arguments_list  */
  YYSYMBOL_arguments_list_end = 60         /* arguments_list_end  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,    31,     2,
      38,    39,    28,    26,    40,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      24,    34,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    30,    42,    33,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    87,    88,    92,    93,    94,    97,    98,
     101,   102,   106,   107,   108,   112,   113,   114,   115,   119,
     120,   124,   128,   129,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   144,   148,   149,   152,   153,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   175,   176,   180,   181,   184,
     185
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_REAL", "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_LOOP",
  "KW_INPUT", "KW_OUTPUT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE",
  "OPERATOR_EQ", "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INT", "LIT_CHAR",
  "LIT_STRING", "LIT_REAL", "TOKEN_ERROR", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'|'", "'&'", "'%'", "'~'", "'='", "';'", "'['", "']'",
  "'('", "')'", "','", "'{'", "'}'", "$accept", "program", "declarat",
  "declarations", "func_parameters", "end_parameters", "literal", "tipo",
  "create_array", "bloco", "commands_list", "commands", "output_list",
  "end_output", "elements_to_output", "expr", "arguments_list",
  "arguments_list_end", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -61,   -61,   -61,   -61,    15,   -61,    25,    30,   -61,
     -61,   -32,    86,    34,    25,   -61,   -61,   -61,    21,    22,
      19,    48,   -61,    86,    29,    32,    86,    40,     9,   -61,
      25,   -61,   -61,   -61,    41,    43,    49,   -31,   -61,   -61,
      36,     9,    74,    49,    72,   -28,   -61,    49,    49,   -61,
      88,    67,   225,   159,    49,    49,   -61,   -61,    32,    87,
      25,    49,    49,   -61,   105,   -61,    43,   -61,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
     -61,   181,   123,   -61,    39,    85,   141,    69,    89,   -61,
      67,   173,   173,   173,   173,   173,   173,    60,    60,   -17,
     -17,   -61,   -61,   -61,    91,     9,   118,   -61,   -61,    49,
     -61,   -61,   -61,    49,   -61,     9,    69,   203,   -61,   -61,
     -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    15,    16,    17,    18,     0,     2,     4,     0,     1,
       3,     0,     0,     0,     9,    12,    13,    14,     0,     0,
       0,     0,     5,    19,     0,    11,    19,     0,    23,     7,
       0,     8,    20,     6,     0,     0,     0,     0,    32,    24,
       0,    23,     0,     0,     0,    39,    36,     0,     0,    38,
       0,    34,    37,     0,     0,     0,    21,    22,    11,     0,
       0,     0,    58,    50,     0,    30,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,    10,     0,     0,     0,    60,     0,    56,
      34,    51,    52,    53,    54,    46,    47,    42,    43,    44,
      45,    49,    48,    25,     0,     0,    27,    55,    40,     0,
      57,    41,    35,     0,    29,     0,    60,     0,    28,    59,
      26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   134,   -61,   -61,    84,    -3,   -13,   117,   121,
     120,   -60,   -61,    56,    93,   -36,   -61,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    20,    31,    49,     8,    27,    39,
      40,    41,    50,    67,    51,    52,    88,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    21,    12,    54,    13,    55,    14,    59,    61,    18,
      62,    63,    64,    78,    79,     9,    34,    42,    81,    82,
      26,    35,    36,    26,   106,    86,    87,    37,     1,     2,
       3,     4,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    38,   114,    34,    85,    11,   105,
      28,    35,    36,    19,    44,   118,    22,    37,    24,    23,
      44,    45,    15,    16,    46,    17,    25,    45,    15,    16,
      28,    17,    30,   116,    38,    33,    47,   117,    56,    43,
      28,    48,    47,    68,    69,    70,    71,    48,    76,    77,
      78,    79,    58,    72,    73,    74,    75,    76,    77,    78,
      79,    68,    69,    70,    71,    15,    16,    66,    17,   109,
      60,    72,    73,    74,    75,    76,    77,    78,    79,    68,
      69,    70,    71,    65,   107,   113,    84,   115,   111,    72,
      73,    74,    75,    76,    77,    78,    79,    68,    69,    70,
      71,    10,    83,    32,    89,    29,   112,    72,    73,    74,
      75,    76,    77,    78,    79,    68,    69,    70,    71,    90,
     104,    57,   119,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    68,    69,    70,    71,     0,   108,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    80,    68,    69,    70,    71,    74,
      75,    76,    77,    78,    79,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,   103,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,   120,    68,
      69,    70,    71,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79
};

static const yytype_int8 yycheck[] =
{
      36,    14,    34,    34,    36,    36,    38,    43,    36,    12,
      38,    47,    48,    30,    31,     0,     7,    30,    54,    55,
      23,    12,    13,    26,    84,    61,    62,    18,     3,     4,
       5,     6,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    35,   105,     7,    60,    18,    10,
      41,    12,    13,    19,    11,   115,    35,    18,    39,    37,
      11,    18,    19,    20,    21,    22,    18,    18,    19,    20,
      41,    22,    40,   109,    35,    35,    33,   113,    42,    38,
      41,    38,    33,    14,    15,    16,    17,    38,    28,    29,
      30,    31,    18,    24,    25,    26,    27,    28,    29,    30,
      31,    14,    15,    16,    17,    19,    20,    40,    22,    40,
      38,    24,    25,    26,    27,    28,    29,    30,    31,    14,
      15,    16,    17,    35,    39,    34,    39,     9,    39,    24,
      25,    26,    27,    28,    29,    30,    31,    14,    15,    16,
      17,     7,    58,    26,    39,    24,    90,    24,    25,    26,
      27,    28,    29,    30,    31,    14,    15,    16,    17,    66,
      37,    41,   116,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    14,    15,    16,    17,    -1,    37,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    14,    15,    16,    17,    26,
      27,    28,    29,    30,    31,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    35,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    44,    45,    46,    50,     0,
      45,    18,    34,    36,    38,    19,    20,    22,    49,    19,
      47,    50,    35,    37,    39,    18,    49,    51,    41,    52,
      40,    48,    51,    35,     7,    12,    13,    18,    35,    52,
      53,    54,    50,    38,    11,    18,    21,    33,    38,    49,
      55,    57,    58,    58,    34,    36,    42,    53,    18,    58,
      38,    36,    38,    58,    58,    35,    40,    56,    14,    15,
      16,    17,    24,    25,    26,    27,    28,    29,    30,    31,
      35,    58,    58,    48,    39,    50,    58,    58,    59,    39,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    35,    37,    10,    54,    39,    37,    40,
      60,    39,    56,    34,    54,     9,    58,    58,    54,    60,
      35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     7,     6,     3,     0,
       4,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     3,     2,     0,     1,     4,     7,     5,     7,     6,
       3,     3,     1,     2,     0,     3,     1,     1,     1,     1,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     4,     3,     2,     0,     3,
       0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: declarat  */
#line 83 "parser.y"
                                           { (yyval.ast) = astCreate(AST_PROGRAM, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); root = (yyval.ast); SemanticErrors=semanticVerification(root); }
#line 1334 "y.tab.c"
    break;

  case 3: /* declarat: declarations declarat  */
#line 87 "parser.y"
                                           { (yyval.ast) = astCreate(AST_DECLARAT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1340 "y.tab.c"
    break;

  case 4: /* declarat: %empty  */
#line 88 "parser.y"
                                           { (yyval.ast) = 0;}
#line 1346 "y.tab.c"
    break;

  case 5: /* declarations: tipo TK_IDENTIFIER '=' literal ';'  */
#line 92 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_DECVAR, (yyvsp[-3].symbol), (yyvsp[-4].ast), (yyvsp[-1].ast), 0, 0, getLineNumber());}
#line 1352 "y.tab.c"
    break;

  case 6: /* declarations: tipo TK_IDENTIFIER '[' LIT_INT ']' create_array ';'  */
#line 93 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_DECARRAY, (yyvsp[-5].symbol), (yyvsp[-6].ast), astCreate(AST_ARGVEC, (yyvsp[-3].symbol), 0, 0, 0, 0, getLineNumber()), (yyvsp[-1].ast), 0, getLineNumber() );}
#line 1358 "y.tab.c"
    break;

  case 7: /* declarations: tipo TK_IDENTIFIER '(' func_parameters ')' bloco  */
#line 94 "parser.y"
                                                                            { (yyval.ast) = astCreate(AST_DECFUNC, (yyvsp[-4].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0, getLineNumber());}
#line 1364 "y.tab.c"
    break;

  case 8: /* func_parameters: tipo TK_IDENTIFIER end_parameters  */
#line 97 "parser.y"
                                                           { (yyval.ast) = astCreate(AST_PARAMINIT, (yyvsp[-1].symbol), (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1370 "y.tab.c"
    break;

  case 9: /* func_parameters: %empty  */
#line 98 "parser.y"
                                                           { (yyval.ast) = 0;}
#line 1376 "y.tab.c"
    break;

  case 10: /* end_parameters: ',' tipo TK_IDENTIFIER end_parameters  */
#line 101 "parser.y"
                                                           { (yyval.ast) = astCreate(AST_PARAMLIST, (yyvsp[-1].symbol), (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1382 "y.tab.c"
    break;

  case 11: /* end_parameters: %empty  */
#line 102 "parser.y"
                                                           { (yyval.ast) = 0;}
#line 1388 "y.tab.c"
    break;

  case 12: /* literal: LIT_INT  */
#line 106 "parser.y"
                               { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1394 "y.tab.c"
    break;

  case 13: /* literal: LIT_CHAR  */
#line 107 "parser.y"
                               { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1400 "y.tab.c"
    break;

  case 14: /* literal: LIT_REAL  */
#line 108 "parser.y"
                               { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1406 "y.tab.c"
    break;

  case 15: /* tipo: KW_CHAR  */
#line 112 "parser.y"
                               { (yyval.ast) = astCreate(AST_DECCHAR, 0, 0, 0, 0, 0, getLineNumber());}
#line 1412 "y.tab.c"
    break;

  case 16: /* tipo: KW_INT  */
#line 113 "parser.y"
                               { (yyval.ast) = astCreate(AST_DECINT, 0, 0, 0, 0, 0, getLineNumber());}
#line 1418 "y.tab.c"
    break;

  case 17: /* tipo: KW_REAL  */
#line 114 "parser.y"
                               { (yyval.ast) = astCreate(AST_DECREAL, 0, 0, 0, 0, 0, getLineNumber());}
#line 1424 "y.tab.c"
    break;

  case 18: /* tipo: KW_BOOL  */
#line 115 "parser.y"
                               { (yyval.ast) = astCreate(AST_DECBOOL, 0, 0, 0, 0, 0, getLineNumber());}
#line 1430 "y.tab.c"
    break;

  case 19: /* create_array: %empty  */
#line 119 "parser.y"
                                           { (yyval.ast) = 0;}
#line 1436 "y.tab.c"
    break;

  case 20: /* create_array: literal create_array  */
#line 120 "parser.y"
                                           { (yyval.ast) = astCreate(AST_ARR_ELEMENT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1442 "y.tab.c"
    break;

  case 21: /* bloco: '{' commands_list '}'  */
#line 124 "parser.y"
                                          { (yyval.ast) = astCreate(AST_BLOCO, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1448 "y.tab.c"
    break;

  case 22: /* commands_list: commands commands_list  */
#line 128 "parser.y"
                                         { (yyval.ast) = astCreate(AST_COMMANDOLIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1454 "y.tab.c"
    break;

  case 23: /* commands_list: %empty  */
#line 129 "parser.y"
                                         { (yyval.ast) = 0; }
#line 1460 "y.tab.c"
    break;

  case 24: /* commands: bloco  */
#line 133 "parser.y"
                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1466 "y.tab.c"
    break;

  case 25: /* commands: TK_IDENTIFIER '=' expr ';'  */
#line 134 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_ATTR, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1472 "y.tab.c"
    break;

  case 26: /* commands: TK_IDENTIFIER '[' expr ']' '=' expr ';'  */
#line 135 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_ARR_ATTR, (yyvsp[-6].symbol), (yyvsp[-4].ast), (yyvsp[-1].ast), 0, 0, getLineNumber());}
#line 1478 "y.tab.c"
    break;

  case 27: /* commands: KW_IF '(' expr ')' commands  */
#line 136 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_IF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1484 "y.tab.c"
    break;

  case 28: /* commands: KW_IF '(' expr ')' commands KW_ELSE commands  */
#line 137 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_IFELSE, 0, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0, getLineNumber());}
#line 1490 "y.tab.c"
    break;

  case 29: /* commands: KW_IF '(' expr ')' KW_LOOP commands  */
#line 138 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_IFLOOP, 0, (yyvsp[-3].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1496 "y.tab.c"
    break;

  case 30: /* commands: KW_OUTPUT output_list ';'  */
#line 139 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_OUTPUT, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1502 "y.tab.c"
    break;

  case 31: /* commands: KW_RETURN expr ';'  */
#line 140 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_RETURN, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1508 "y.tab.c"
    break;

  case 32: /* commands: ';'  */
#line 141 "parser.y"
                                                                { (yyval.ast) = 0; }
#line 1514 "y.tab.c"
    break;

  case 33: /* output_list: elements_to_output end_output  */
#line 144 "parser.y"
                                                      { (yyval.ast) = astCreate(AST_OUTPUTINIT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1520 "y.tab.c"
    break;

  case 34: /* end_output: %empty  */
#line 148 "parser.y"
                                                    { (yyval.ast) = 0; }
#line 1526 "y.tab.c"
    break;

  case 35: /* end_output: ',' elements_to_output end_output  */
#line 149 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_OUTPUTLIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1532 "y.tab.c"
    break;

  case 36: /* elements_to_output: LIT_STRING  */
#line 152 "parser.y"
                                             { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1538 "y.tab.c"
    break;

  case 37: /* elements_to_output: expr  */
#line 153 "parser.y"
                                             { (yyval.ast) = (yyvsp[0].ast); }
#line 1544 "y.tab.c"
    break;

  case 38: /* expr: literal  */
#line 157 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1550 "y.tab.c"
    break;

  case 39: /* expr: TK_IDENTIFIER  */
#line 158 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0, getLineNumber());}
#line 1556 "y.tab.c"
    break;

  case 40: /* expr: TK_IDENTIFIER '[' expr ']'  */
#line 159 "parser.y"
                                                { (yyval.ast) = astCreate(AST_ARRAY, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0,0, getLineNumber());}
#line 1562 "y.tab.c"
    break;

  case 41: /* expr: TK_IDENTIFIER '(' arguments_list ')'  */
#line 160 "parser.y"
                                                { (yyval.ast) = astCreate(AST_FUNC_CALL, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0,0, getLineNumber());}
#line 1568 "y.tab.c"
    break;

  case 42: /* expr: expr '+' expr  */
#line 161 "parser.y"
                                                { (yyval.ast) = astCreate(AST_ADD, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1574 "y.tab.c"
    break;

  case 43: /* expr: expr '-' expr  */
#line 162 "parser.y"
                                                { (yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1580 "y.tab.c"
    break;

  case 44: /* expr: expr '*' expr  */
#line 163 "parser.y"
                                                { (yyval.ast) = astCreate(AST_MUL, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1586 "y.tab.c"
    break;

  case 45: /* expr: expr '/' expr  */
#line 164 "parser.y"
                                                { (yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1592 "y.tab.c"
    break;

  case 46: /* expr: expr '<' expr  */
#line 165 "parser.y"
                                                { (yyval.ast) = astCreate(AST_LESS, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1598 "y.tab.c"
    break;

  case 47: /* expr: expr '>' expr  */
#line 166 "parser.y"
                                                { (yyval.ast) = astCreate(AST_GREATER, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1604 "y.tab.c"
    break;

  case 48: /* expr: expr '&' expr  */
#line 167 "parser.y"
                                                { (yyval.ast) = astCreate(AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1610 "y.tab.c"
    break;

  case 49: /* expr: expr '|' expr  */
#line 168 "parser.y"
                                                { (yyval.ast) = astCreate(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1616 "y.tab.c"
    break;

  case 50: /* expr: '~' expr  */
#line 169 "parser.y"
                                                { (yyval.ast) = astCreate(AST_NOT, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber());}
#line 1622 "y.tab.c"
    break;

  case 51: /* expr: expr OPERATOR_LE expr  */
#line 170 "parser.y"
                                                { (yyval.ast) = astCreate(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1628 "y.tab.c"
    break;

  case 52: /* expr: expr OPERATOR_GE expr  */
#line 171 "parser.y"
                                                { (yyval.ast) = astCreate(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1634 "y.tab.c"
    break;

  case 53: /* expr: expr OPERATOR_EQ expr  */
#line 172 "parser.y"
                                                { (yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1640 "y.tab.c"
    break;

  case 54: /* expr: expr OPERATOR_DIF expr  */
#line 173 "parser.y"
                                                { (yyval.ast) = astCreate(AST_DIF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1646 "y.tab.c"
    break;

  case 55: /* expr: KW_INPUT '(' tipo ')'  */
#line 175 "parser.y"
                                                { (yyval.ast) = astCreate(AST_INPUT, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1652 "y.tab.c"
    break;

  case 56: /* expr: '(' expr ')'  */
#line 176 "parser.y"
                                                { (yyval.ast) = astCreate(AST_PARENTESES, 0, (yyvsp[-1].ast), 0, 0, 0, getLineNumber());}
#line 1658 "y.tab.c"
    break;

  case 57: /* arguments_list: expr arguments_list_end  */
#line 180 "parser.y"
                                               { (yyval.ast) = astCreate(AST_ARGFUNCCALL, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1664 "y.tab.c"
    break;

  case 58: /* arguments_list: %empty  */
#line 181 "parser.y"
                                               { (yyval.ast) = 0; }
#line 1670 "y.tab.c"
    break;

  case 59: /* arguments_list_end: ',' expr arguments_list_end  */
#line 184 "parser.y"
                                                    { (yyval.ast) = astCreate(AST_ARGFUNCCALLLIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0, getLineNumber());}
#line 1676 "y.tab.c"
    break;

  case 60: /* arguments_list_end: %empty  */
#line 185 "parser.y"
                                                    { (yyval.ast) = 0; }
#line 1682 "y.tab.c"
    break;


#line 1686 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 189 "parser.y"


void checkSemantic(){
  if(SemanticErrors > 0){
    fprintf(stderr, "%d Semantic Errors in Total.\n", SemanticErrors);
    exit(4);
  }
}

int yyerror() {
    printf("Erro na linha %d\n\n",getLineNumber());  
    exit(3);
}
