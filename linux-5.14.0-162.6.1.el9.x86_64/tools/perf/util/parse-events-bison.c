/* A Bison parser, made by GNU Bison 3.7.4.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         parse_events_parse
#define yylex           parse_events_lex
#define yyerror         parse_events_error
#define yydebug         parse_events_debug
#define yynerrs         parse_events_nerrs

/* First part of user prologue.  */
#line 7 "util/parse-events.y"


#define YYDEBUG 1

#include <fnmatch.h>
#include <stdio.h>
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/zalloc.h>
#include "pmu.h"
#include "evsel.h"
#include "parse-events.h"
#include "parse-events-bison.h"

void parse_events_error(YYLTYPE *loc, void *parse_state, void *scanner, char const *msg);

#define ABORT_ON(val) \
do { \
	if (val) \
		YYABORT; \
} while (0)

static struct list_head* alloc_list(void)
{
	struct list_head *list;

	list = malloc(sizeof(*list));
	if (!list)
		return NULL;

	INIT_LIST_HEAD(list);
	return list;
}

static void free_list_evsel(struct list_head* list_evsel)
{
	struct evsel *evsel, *tmp;

	list_for_each_entry_safe(evsel, tmp, list_evsel, core.node) {
		list_del_init(&evsel->core.node);
		evsel__delete(evsel);
	}
	free(list_evsel);
}

static void inc_group_count(struct list_head *list,
		       struct parse_events_state *parse_state)
{
	/* Count groups only have more than 1 members */
	if (!list_is_last(list->next, list))
		parse_state->nr_groups++;
}


#line 131 "util/parse-events-bison.c"

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

#include "parse-events-bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PE_START_EVENTS = 3,            /* PE_START_EVENTS  */
  YYSYMBOL_PE_START_TERMS = 4,             /* PE_START_TERMS  */
  YYSYMBOL_PE_VALUE = 5,                   /* PE_VALUE  */
  YYSYMBOL_PE_VALUE_SYM_HW = 6,            /* PE_VALUE_SYM_HW  */
  YYSYMBOL_PE_VALUE_SYM_SW = 7,            /* PE_VALUE_SYM_SW  */
  YYSYMBOL_PE_RAW = 8,                     /* PE_RAW  */
  YYSYMBOL_PE_TERM = 9,                    /* PE_TERM  */
  YYSYMBOL_PE_VALUE_SYM_TOOL = 10,         /* PE_VALUE_SYM_TOOL  */
  YYSYMBOL_PE_EVENT_NAME = 11,             /* PE_EVENT_NAME  */
  YYSYMBOL_PE_NAME = 12,                   /* PE_NAME  */
  YYSYMBOL_PE_BPF_OBJECT = 13,             /* PE_BPF_OBJECT  */
  YYSYMBOL_PE_BPF_SOURCE = 14,             /* PE_BPF_SOURCE  */
  YYSYMBOL_PE_MODIFIER_EVENT = 15,         /* PE_MODIFIER_EVENT  */
  YYSYMBOL_PE_MODIFIER_BP = 16,            /* PE_MODIFIER_BP  */
  YYSYMBOL_PE_NAME_CACHE_TYPE = 17,        /* PE_NAME_CACHE_TYPE  */
  YYSYMBOL_PE_NAME_CACHE_OP_RESULT = 18,   /* PE_NAME_CACHE_OP_RESULT  */
  YYSYMBOL_PE_PREFIX_MEM = 19,             /* PE_PREFIX_MEM  */
  YYSYMBOL_PE_PREFIX_RAW = 20,             /* PE_PREFIX_RAW  */
  YYSYMBOL_PE_PREFIX_GROUP = 21,           /* PE_PREFIX_GROUP  */
  YYSYMBOL_PE_ERROR = 22,                  /* PE_ERROR  */
  YYSYMBOL_PE_PMU_EVENT_PRE = 23,          /* PE_PMU_EVENT_PRE  */
  YYSYMBOL_PE_PMU_EVENT_SUF = 24,          /* PE_PMU_EVENT_SUF  */
  YYSYMBOL_PE_PMU_EVENT_SUF2 = 25,         /* PE_PMU_EVENT_SUF2  */
  YYSYMBOL_PE_KERNEL_PMU_EVENT = 26,       /* PE_KERNEL_PMU_EVENT  */
  YYSYMBOL_PE_PMU_EVENT_FAKE = 27,         /* PE_PMU_EVENT_FAKE  */
  YYSYMBOL_PE_ARRAY_ALL = 28,              /* PE_ARRAY_ALL  */
  YYSYMBOL_PE_ARRAY_RANGE = 29,            /* PE_ARRAY_RANGE  */
  YYSYMBOL_PE_DRV_CFG_TERM = 30,           /* PE_DRV_CFG_TERM  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* ':'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_start = 41,                     /* start  */
  YYSYMBOL_start_events = 42,              /* start_events  */
  YYSYMBOL_groups = 43,                    /* groups  */
  YYSYMBOL_group = 44,                     /* group  */
  YYSYMBOL_group_def = 45,                 /* group_def  */
  YYSYMBOL_events = 46,                    /* events  */
  YYSYMBOL_event = 47,                     /* event  */
  YYSYMBOL_event_mod = 48,                 /* event_mod  */
  YYSYMBOL_event_name = 49,                /* event_name  */
  YYSYMBOL_event_def = 50,                 /* event_def  */
  YYSYMBOL_event_pmu_name = 51,            /* event_pmu_name  */
  YYSYMBOL_event_pmu = 52,                 /* event_pmu  */
  YYSYMBOL_value_sym = 53,                 /* value_sym  */
  YYSYMBOL_event_legacy_symbol = 54,       /* event_legacy_symbol  */
  YYSYMBOL_event_legacy_cache = 55,        /* event_legacy_cache  */
  YYSYMBOL_event_legacy_mem = 56,          /* event_legacy_mem  */
  YYSYMBOL_event_legacy_tracepoint = 57,   /* event_legacy_tracepoint  */
  YYSYMBOL_tracepoint_name = 58,           /* tracepoint_name  */
  YYSYMBOL_event_legacy_numeric = 59,      /* event_legacy_numeric  */
  YYSYMBOL_event_legacy_raw = 60,          /* event_legacy_raw  */
  YYSYMBOL_event_bpf_file = 61,            /* event_bpf_file  */
  YYSYMBOL_opt_event_config = 62,          /* opt_event_config  */
  YYSYMBOL_opt_pmu_config = 63,            /* opt_pmu_config  */
  YYSYMBOL_start_terms = 64,               /* start_terms  */
  YYSYMBOL_event_config = 65,              /* event_config  */
  YYSYMBOL_event_term = 66,                /* event_term  */
  YYSYMBOL_array = 67,                     /* array  */
  YYSYMBOL_array_terms = 68,               /* array_terms  */
  YYSYMBOL_array_term = 69,                /* array_term  */
  YYSYMBOL_sep_dc = 70,                    /* sep_dc  */
  YYSYMBOL_sep_slash_slash_dc = 71         /* sep_slash_slash_dc  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,    35,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,     2,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   142,   144,   153,   163,   173,   175,   178,
     197,   200,   210,   220,   230,   232,   235,   259,   262,   275,
     277,   278,   279,   280,   281,   282,   283,   284,   287,   287,
     290,   350,   362,   375,   388,   401,   419,   439,   441,   444,
     462,   474,   485,   507,   528,   549,   567,   582,   600,   616,
     642,   653,   661,   678,   695,   713,   730,   735,   740,   745,
     750,   755,   766,   779,   791,   800,   813,   825,   837,   849,
     858,   869,   877,   885,   900,   914,   930,   935,   942,   957,
     960,   972,   985,   985,   987,   987,   987
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
  "\"end of file\"", "error", "\"invalid token\"", "PE_START_EVENTS",
  "PE_START_TERMS", "PE_VALUE", "PE_VALUE_SYM_HW", "PE_VALUE_SYM_SW",
  "PE_RAW", "PE_TERM", "PE_VALUE_SYM_TOOL", "PE_EVENT_NAME", "PE_NAME",
  "PE_BPF_OBJECT", "PE_BPF_SOURCE", "PE_MODIFIER_EVENT", "PE_MODIFIER_BP",
  "PE_NAME_CACHE_TYPE", "PE_NAME_CACHE_OP_RESULT", "PE_PREFIX_MEM",
  "PE_PREFIX_RAW", "PE_PREFIX_GROUP", "PE_ERROR", "PE_PMU_EVENT_PRE",
  "PE_PMU_EVENT_SUF", "PE_PMU_EVENT_SUF2", "PE_KERNEL_PMU_EVENT",
  "PE_PMU_EVENT_FAKE", "PE_ARRAY_ALL", "PE_ARRAY_RANGE", "PE_DRV_CFG_TERM",
  "','", "':'", "'{'", "'}'", "'-'", "'/'", "'='", "'['", "']'", "$accept",
  "start", "start_events", "groups", "group", "group_def", "events",
  "event", "event_mod", "event_name", "event_def", "event_pmu_name",
  "event_pmu", "value_sym", "event_legacy_symbol", "event_legacy_cache",
  "event_legacy_mem", "event_legacy_tracepoint", "tracepoint_name",
  "event_legacy_numeric", "event_legacy_raw", "event_bpf_file",
  "opt_event_config", "opt_pmu_config", "start_terms", "event_config",
  "event_term", "array", "array_terms", "array_term", "sep_dc",
  "sep_slash_slash_dc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    44,    58,   123,   125,    45,    47,    61,    91,    93
};
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     128,    51,    30,     6,   -20,   -36,   -36,   -15,    49,   107,
     103,   -15,   -15,    36,    27,     5,    68,    68,    84,   -36,
      21,   -36,     2,   -36,   -36,    90,   -36,    46,   -36,    86,
     -36,   111,   -36,   111,   -15,   111,   111,   -36,   -36,   -36,
      79,     9,   -36,   -36,   108,   -36,   -36,   137,    -1,   -36,
     -36,   112,   -36,    67,   -36,   135,    84,   138,   -36,   -36,
     131,   -36,    91,   127,   -36,    14,   -36,   -36,   -36,   -36,
      20,   -36,    51,   139,   -36,   -36,    19,   -36,   -36,   -36,
     -36,   -36,   -36,    64,   -36,    61,   147,   116,    30,   -15,
     -36,   -21,   -36,   -36,   106,   123,   110,   140,   152,   -36,
     109,   -36,    17,    84,   -36,   -36,   -36,   -36,    57,   -36,
     -36,   -36,   -36,   -36,   129,   -22,   -36,    75,   -36,   -36,
     -36,   -36,   148,   141,   -36,   111,   130,   136,   -36,   -36,
     -36,   -36,   158,   147,   -36,   -36,   -36,   -36,   -15,   -36,
     149,   -36,   111,   -36,   -36,   -36,   111,   -36,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    37,    38,    58,    86,     0,
      28,    58,    58,    58,     0,    29,    83,    83,     0,     2,
       4,     7,    10,     8,    15,    17,    19,     0,    20,    86,
      21,    83,    23,    83,    58,    83,    83,    27,    69,    64,
      72,    68,    75,     3,    61,    63,     1,     0,     0,    53,
      85,     0,    41,    28,    18,     0,     0,     0,    54,    55,
       0,    44,    83,     0,    82,     0,    32,    31,    36,    35,
       0,    14,     0,     0,    16,    30,     0,    40,    22,    24,
      49,    25,    26,     0,    77,     0,     0,     0,     0,    58,
      57,     0,    84,    51,     0,     0,    58,    82,     0,    48,
      83,    60,     0,     0,    12,     5,     6,     9,     0,    71,
      70,    66,    67,    65,    80,     0,    79,     0,    62,    52,
      56,    11,     0,     0,    43,    83,    83,     0,    34,    59,
      13,    39,     0,     0,    76,    74,    73,    50,    58,    47,
      82,    46,    83,    81,    78,    42,    83,    33,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,   -36,   -36,    92,   -36,   113,     3,   -36,   -36,
     157,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -10,    16,   -36,   -35,    80,   -36,   -36,    34,
     -17,   142
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    19,    20,    21,    22,    70,    71,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    49,    66,    43,    44,    45,    87,   115,   116,
      67,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    58,    59,    61,    23,    38,    46,    39,    40,   133,
      88,    41,    47,    91,    78,   120,    79,   134,    81,    82,
      38,    48,    39,    40,    80,    38,    41,    39,    40,    42,
     102,    41,    62,    68,    73,    90,    38,    84,    39,    40,
      63,   108,    41,    75,    42,    99,    85,    86,    88,    42,
     101,   103,    72,   129,   104,    92,     4,     5,     6,     7,
      42,     8,     9,    10,    11,    12,   111,   112,    13,   109,
      14,    60,    48,   113,    15,   106,   110,    16,    17,   119,
     135,    50,    65,   128,    18,    51,   124,   136,    88,     4,
       5,     6,     7,   131,     8,     9,    53,    11,    12,    55,
      64,    13,    57,    14,    65,    74,   130,    15,   139,   141,
      16,    17,     4,     5,     6,     7,    83,     8,    50,    53,
      11,    12,    76,    97,    13,   147,    14,    98,   145,   148,
      15,     1,     2,    16,    17,    55,    56,   103,    57,    88,
     121,    64,    89,    64,   127,   123,    48,    93,    92,    96,
      95,   100,   114,   117,   107,   122,   125,   126,   132,   138,
     137,   142,   140,   143,   105,   146,    54,   144,   118,    94,
       0,    77
};

static const yytype_int16 yycheck[] =
{
      17,    11,    12,    13,     1,     6,     0,     8,     9,    31,
      31,    12,    32,    48,    31,    36,    33,    39,    35,    36,
       6,    36,     8,     9,    34,     6,    12,     8,     9,    30,
      65,    12,     5,    17,    32,    36,     6,    28,     8,     9,
      35,    76,    12,    27,    30,    62,    37,    38,    31,    30,
      36,    31,    31,    36,    34,    36,     5,     6,     7,     8,
      30,    10,    11,    12,    13,    14,     5,     6,    17,     5,
      19,    35,    36,    12,    23,    72,    12,    26,    27,    89,
       5,    32,    36,   100,    33,    36,    96,    12,    31,     5,
       6,     7,     8,    36,    10,    11,    12,    13,    14,    32,
      32,    17,    35,    19,    36,    15,   103,    23,   125,   126,
      26,    27,     5,     6,     7,     8,    37,    10,    32,    12,
      13,    14,    36,    32,    17,   142,    19,    36,   138,   146,
      23,     3,     4,    26,    27,    32,    33,    31,    35,    31,
      34,    32,     5,    32,    35,    35,    36,    12,    36,    18,
      12,    24,     5,    37,    15,    32,    16,     5,    29,    18,
      12,    25,    32,     5,    72,    16,     9,   133,    88,    56,
      -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    41,     5,     6,     7,     8,    10,    11,
      12,    13,    14,    17,    19,    23,    26,    27,    33,    42,
      43,    44,    45,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     6,     8,
       9,    12,    30,    64,    65,    66,     0,    32,    36,    62,
      32,    36,    71,    12,    50,    32,    33,    35,    62,    62,
      35,    62,     5,    35,    32,    36,    63,    70,    63,    70,
      46,    47,    31,    32,    15,    63,    36,    71,    70,    70,
      62,    70,    70,    37,    28,    37,    38,    67,    31,     5,
      36,    65,    36,    12,    46,    12,    18,    32,    36,    70,
      24,    36,    65,    31,    34,    44,    47,    15,    65,     5,
      12,     5,     6,    12,     5,    68,    69,    37,    66,    62,
      36,    34,    32,    35,    62,    16,     5,    35,    70,    36,
      47,    36,    29,    31,    39,     5,    12,    12,    18,    70,
      32,    70,    25,     5,    69,    62,    16,    70,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    43,    43,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    57,
      58,    58,    59,    60,    61,    61,    62,    62,    62,    63,
      63,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     3,     3,     1,     1,     3,
       1,     4,     3,     3,     1,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     6,     4,     2,     2,     1,     1,     4,
       2,     2,     6,     4,     2,     7,     5,     5,     3,     2,
       5,     3,     4,     2,     2,     2,     3,     2,     0,     3,
       2,     1,     3,     1,     1,     3,     3,     3,     1,     1,
       3,     3,     1,     4,     4,     1,     3,     1,     3,     1,
       1,     3,     1,     0,     2,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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
        yyerror (&yylloc, _parse_state, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, _parse_state, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *_parse_state, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (_parse_state);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *_parse_state, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, _parse_state, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void *_parse_state, void *scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), _parse_state, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, _parse_state, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *_parse_state, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (_parse_state);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_PE_EVENT_NAME: /* PE_EVENT_NAME  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1116 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_NAME: /* PE_NAME  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1122 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_BPF_OBJECT: /* PE_BPF_OBJECT  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1128 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_BPF_SOURCE: /* PE_BPF_SOURCE  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1134 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_MODIFIER_EVENT: /* PE_MODIFIER_EVENT  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1140 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_MODIFIER_BP: /* PE_MODIFIER_BP  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1146 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_NAME_CACHE_TYPE: /* PE_NAME_CACHE_TYPE  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1152 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_NAME_CACHE_OP_RESULT: /* PE_NAME_CACHE_OP_RESULT  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1158 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_PMU_EVENT_PRE: /* PE_PMU_EVENT_PRE  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1164 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_PMU_EVENT_SUF: /* PE_PMU_EVENT_SUF  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1170 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_PMU_EVENT_SUF2: /* PE_PMU_EVENT_SUF2  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1176 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_KERNEL_PMU_EVENT: /* PE_KERNEL_PMU_EVENT  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1182 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_PMU_EVENT_FAKE: /* PE_PMU_EVENT_FAKE  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1188 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_PE_DRV_CFG_TERM: /* PE_DRV_CFG_TERM  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1194 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_groups: /* groups  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1200 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_group: /* group  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1206 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_group_def: /* group_def  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1212 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_events: /* events  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1218 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event: /* event  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1224 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_mod: /* event_mod  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1230 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_name: /* event_name  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1236 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_def: /* event_def  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1242 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_pmu_name: /* event_pmu_name  */
#line 93 "util/parse-events.y"
            { free (((*yyvaluep).str)); }
#line 1248 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_pmu: /* event_pmu  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1254 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_legacy_symbol: /* event_legacy_symbol  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1260 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_legacy_cache: /* event_legacy_cache  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1266 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_legacy_mem: /* event_legacy_mem  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1272 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_legacy_tracepoint: /* event_legacy_tracepoint  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1278 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_tracepoint_name: /* tracepoint_name  */
#line 118 "util/parse-events.y"
            { free (((*yyvaluep).tracepoint_name).sys); free (((*yyvaluep).tracepoint_name).event); }
#line 1284 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_legacy_numeric: /* event_legacy_numeric  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1290 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_legacy_raw: /* event_legacy_raw  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1296 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_bpf_file: /* event_bpf_file  */
#line 116 "util/parse-events.y"
            { free_list_evsel (((*yyvaluep).list_evsel)); }
#line 1302 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_opt_event_config: /* opt_event_config  */
#line 99 "util/parse-events.y"
            { parse_events_terms__delete (((*yyvaluep).list_terms)); }
#line 1308 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_opt_pmu_config: /* opt_pmu_config  */
#line 99 "util/parse-events.y"
            { parse_events_terms__delete (((*yyvaluep).list_terms)); }
#line 1314 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_config: /* event_config  */
#line 99 "util/parse-events.y"
            { parse_events_terms__delete (((*yyvaluep).list_terms)); }
#line 1320 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_event_term: /* event_term  */
#line 95 "util/parse-events.y"
            { parse_events_term__delete (((*yyvaluep).term)); }
#line 1326 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_array: /* array  */
#line 122 "util/parse-events.y"
            { free (((*yyvaluep).array).ranges); }
#line 1332 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_array_terms: /* array_terms  */
#line 122 "util/parse-events.y"
            { free (((*yyvaluep).array).ranges); }
#line 1338 "util/parse-events-bison.c"
        break;

    case YYSYMBOL_array_term: /* array_term  */
#line 122 "util/parse-events.y"
            { free (((*yyvaluep).array).ranges); }
#line 1344 "util/parse-events-bison.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *_parse_state, void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* start_events: groups  */
#line 145 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;

	/* frees $1 */
	parse_events_update_lists((yyvsp[0].list_evsel), &parse_state->list);
}
#line 1650 "util/parse-events-bison.c"
    break;

  case 5: /* groups: groups ',' group  */
#line 154 "util/parse-events.y"
{
	struct list_head *list  = (yyvsp[-2].list_evsel);
	struct list_head *group = (yyvsp[0].list_evsel);

	/* frees $3 */
	parse_events_update_lists(group, list);
	(yyval.list_evsel) = list;
}
#line 1663 "util/parse-events-bison.c"
    break;

  case 6: /* groups: groups ',' event  */
#line 164 "util/parse-events.y"
{
	struct list_head *list  = (yyvsp[-2].list_evsel);
	struct list_head *event = (yyvsp[0].list_evsel);

	/* frees $3 */
	parse_events_update_lists(event, list);
	(yyval.list_evsel) = list;
}
#line 1676 "util/parse-events-bison.c"
    break;

  case 9: /* group: group_def ':' PE_MODIFIER_EVENT  */
#line 179 "util/parse-events.y"
{
	struct list_head *list = (yyvsp[-2].list_evsel);
	int err;

	err = parse_events__modifier_group(list, (yyvsp[0].str));
	free((yyvsp[0].str));
	if (err) {
		struct parse_events_state *parse_state = _parse_state;
		struct parse_events_error *error = parse_state->error;

		parse_events_error__handle(error, (yylsp[0]).first_column,
					   strdup("Bad modifier"), NULL);
		free_list_evsel(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 1698 "util/parse-events-bison.c"
    break;

  case 11: /* group_def: PE_NAME '{' events '}'  */
#line 201 "util/parse-events.y"
{
	struct list_head *list = (yyvsp[-1].list_evsel);

	inc_group_count(list, _parse_state);
	parse_events__set_leader((yyvsp[-3].str), list, _parse_state);
	free((yyvsp[-3].str));
	(yyval.list_evsel) = list;
}
#line 1711 "util/parse-events-bison.c"
    break;

  case 12: /* group_def: '{' events '}'  */
#line 211 "util/parse-events.y"
{
	struct list_head *list = (yyvsp[-1].list_evsel);

	inc_group_count(list, _parse_state);
	parse_events__set_leader(NULL, list, _parse_state);
	(yyval.list_evsel) = list;
}
#line 1723 "util/parse-events-bison.c"
    break;

  case 13: /* events: events ',' event  */
#line 221 "util/parse-events.y"
{
	struct list_head *event = (yyvsp[0].list_evsel);
	struct list_head *list  = (yyvsp[-2].list_evsel);

	/* frees $3 */
	parse_events_update_lists(event, list);
	(yyval.list_evsel) = list;
}
#line 1736 "util/parse-events-bison.c"
    break;

  case 16: /* event_mod: event_name PE_MODIFIER_EVENT  */
#line 236 "util/parse-events.y"
{
	struct list_head *list = (yyvsp[-1].list_evsel);
	int err;

	/*
	 * Apply modifier on all events added by single event definition
	 * (there could be more events added for multiple tracepoint
	 * definitions via '*?'.
	 */
	err = parse_events__modifier_event(list, (yyvsp[0].str), false);
	free((yyvsp[0].str));
	if (err) {
		struct parse_events_state *parse_state = _parse_state;
		struct parse_events_error *error = parse_state->error;

		parse_events_error__handle(error, (yylsp[0]).first_column,
					   strdup("Bad modifier"), NULL);
		free_list_evsel(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 1763 "util/parse-events-bison.c"
    break;

  case 18: /* event_name: PE_EVENT_NAME event_def  */
#line 263 "util/parse-events.y"
{
	int err;

	err = parse_events_name((yyvsp[0].list_evsel), (yyvsp[-1].str));
	free((yyvsp[-1].str));
	if (err) {
		free_list_evsel((yyvsp[0].list_evsel));
		YYABORT;
	}
	(yyval.list_evsel) = (yyvsp[0].list_evsel);
}
#line 1779 "util/parse-events-bison.c"
    break;

  case 30: /* event_pmu: event_pmu_name opt_pmu_config  */
#line 291 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct parse_events_error *error = parse_state->error;
	struct list_head *list = NULL, *orig_terms = NULL, *terms= NULL;
	char *pattern = NULL;

#define CLEANUP_YYABORT					\
	do {						\
		parse_events_terms__delete((yyvsp[0].list_terms));		\
		parse_events_terms__delete(orig_terms);	\
		free(list);				\
		free((yyvsp[-1].str));				\
		free(pattern);				\
		YYABORT;				\
	} while(0)

	if (parse_events_copy_term_list((yyvsp[0].list_terms), &orig_terms))
		CLEANUP_YYABORT;

	if (error)
		error->idx = (yylsp[-1]).first_column;

	list = alloc_list();
	if (!list)
		CLEANUP_YYABORT;
	if (parse_events_add_pmu(_parse_state, list, (yyvsp[-1].str), (yyvsp[0].list_terms), false, false)) {
		struct perf_pmu *pmu = NULL;
		int ok = 0;

		if (asprintf(&pattern, "%s*", (yyvsp[-1].str)) < 0)
			CLEANUP_YYABORT;

		while ((pmu = perf_pmu__scan(pmu)) != NULL) {
			char *name = pmu->name;

			if (!strncmp(name, "uncore_", 7) &&
			    strncmp((yyvsp[-1].str), "uncore_", 7))
				name += 7;
			if (!perf_pmu__match(pattern, name, (yyvsp[-1].str)) ||
			    !perf_pmu__match(pattern, pmu->alias_name, (yyvsp[-1].str))) {
				if (parse_events_copy_term_list(orig_terms, &terms))
					CLEANUP_YYABORT;
				if (!parse_events_add_pmu(_parse_state, list, pmu->name, terms, true, false))
					ok++;
				parse_events_terms__delete(terms);
			}
		}

		if (!ok)
			CLEANUP_YYABORT;
	}
	parse_events_terms__delete((yyvsp[0].list_terms));
	parse_events_terms__delete(orig_terms);
	free(pattern);
	free((yyvsp[-1].str));
	(yyval.list_evsel) = list;
#undef CLEANUP_YYABORT
}
#line 1842 "util/parse-events-bison.c"
    break;

  case 31: /* event_pmu: PE_KERNEL_PMU_EVENT sep_dc  */
#line 351 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	err = parse_events_multi_pmu_add(_parse_state, (yyvsp[-1].str), NULL, &list);
	free((yyvsp[-1].str));
	if (err < 0)
		YYABORT;
	(yyval.list_evsel) = list;
}
#line 1857 "util/parse-events-bison.c"
    break;

  case 32: /* event_pmu: PE_KERNEL_PMU_EVENT opt_pmu_config  */
#line 363 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	/* frees $2 */
	err = parse_events_multi_pmu_add(_parse_state, (yyvsp[-1].str), (yyvsp[0].list_terms), &list);
	free((yyvsp[-1].str));
	if (err < 0)
		YYABORT;
	(yyval.list_evsel) = list;
}
#line 1873 "util/parse-events-bison.c"
    break;

  case 33: /* event_pmu: PE_PMU_EVENT_PRE '-' PE_PMU_EVENT_SUF '-' PE_PMU_EVENT_SUF2 sep_dc  */
#line 376 "util/parse-events.y"
{
	struct list_head *list;
	char pmu_name[128];
	snprintf(pmu_name, sizeof(pmu_name), "%s-%s-%s", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
	free((yyvsp[-5].str));
	free((yyvsp[-3].str));
	free((yyvsp[-1].str));
	if (parse_events_multi_pmu_add(_parse_state, pmu_name, NULL, &list) < 0)
		YYABORT;
	(yyval.list_evsel) = list;
}
#line 1889 "util/parse-events-bison.c"
    break;

  case 34: /* event_pmu: PE_PMU_EVENT_PRE '-' PE_PMU_EVENT_SUF sep_dc  */
#line 389 "util/parse-events.y"
{
	struct list_head *list;
	char pmu_name[128];

	snprintf(pmu_name, sizeof(pmu_name), "%s-%s", (yyvsp[-3].str), (yyvsp[-1].str));
	free((yyvsp[-3].str));
	free((yyvsp[-1].str));
	if (parse_events_multi_pmu_add(_parse_state, pmu_name, NULL, &list) < 0)
		YYABORT;
	(yyval.list_evsel) = list;
}
#line 1905 "util/parse-events-bison.c"
    break;

  case 35: /* event_pmu: PE_PMU_EVENT_FAKE sep_dc  */
#line 402 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	list = alloc_list();
	if (!list)
		YYABORT;

	err = parse_events_add_pmu(_parse_state, list, (yyvsp[-1].str), NULL, false, false);
	free((yyvsp[-1].str));
	if (err < 0) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 1926 "util/parse-events-bison.c"
    break;

  case 36: /* event_pmu: PE_PMU_EVENT_FAKE opt_pmu_config  */
#line 420 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	list = alloc_list();
	if (!list)
		YYABORT;

	err = parse_events_add_pmu(_parse_state, list, (yyvsp[-1].str), (yyvsp[0].list_terms), false, false);
	free((yyvsp[-1].str));
	parse_events_terms__delete((yyvsp[0].list_terms));
	if (err < 0) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 1948 "util/parse-events-bison.c"
    break;

  case 39: /* event_legacy_symbol: value_sym '/' event_config '/'  */
#line 445 "util/parse-events.y"
{
	struct list_head *list;
	int type = (yyvsp[-3].num) >> 16;
	int config = (yyvsp[-3].num) & 255;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_numeric(_parse_state, list, type, config, (yyvsp[-1].list_terms));
	parse_events_terms__delete((yyvsp[-1].list_terms));
	if (err) {
		free_list_evsel(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 1969 "util/parse-events-bison.c"
    break;

  case 40: /* event_legacy_symbol: value_sym sep_slash_slash_dc  */
#line 463 "util/parse-events.y"
{
	struct list_head *list;
	int type = (yyvsp[-1].num) >> 16;
	int config = (yyvsp[-1].num) & 255;

	list = alloc_list();
	ABORT_ON(!list);
	ABORT_ON(parse_events_add_numeric(_parse_state, list, type, config, NULL));
	(yyval.list_evsel) = list;
}
#line 1984 "util/parse-events-bison.c"
    break;

  case 41: /* event_legacy_symbol: PE_VALUE_SYM_TOOL sep_slash_slash_dc  */
#line 475 "util/parse-events.y"
{
	struct list_head *list;

	list = alloc_list();
	ABORT_ON(!list);
	ABORT_ON(parse_events_add_tool(_parse_state, list, (yyvsp[-1].num)));
	(yyval.list_evsel) = list;
}
#line 1997 "util/parse-events-bison.c"
    break;

  case 42: /* event_legacy_cache: PE_NAME_CACHE_TYPE '-' PE_NAME_CACHE_OP_RESULT '-' PE_NAME_CACHE_OP_RESULT opt_event_config  */
#line 486 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct parse_events_error *error = parse_state->error;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_cache(list, &parse_state->idx, (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str), error, (yyvsp[0].list_terms),
				     parse_state);
	parse_events_terms__delete((yyvsp[0].list_terms));
	free((yyvsp[-5].str));
	free((yyvsp[-3].str));
	free((yyvsp[-1].str));
	if (err) {
		free_list_evsel(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2022 "util/parse-events-bison.c"
    break;

  case 43: /* event_legacy_cache: PE_NAME_CACHE_TYPE '-' PE_NAME_CACHE_OP_RESULT opt_event_config  */
#line 508 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct parse_events_error *error = parse_state->error;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_cache(list, &parse_state->idx, (yyvsp[-3].str), (yyvsp[-1].str), NULL, error, (yyvsp[0].list_terms),
				     parse_state);
	parse_events_terms__delete((yyvsp[0].list_terms));
	free((yyvsp[-3].str));
	free((yyvsp[-1].str));
	if (err) {
		free_list_evsel(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2046 "util/parse-events-bison.c"
    break;

  case 44: /* event_legacy_cache: PE_NAME_CACHE_TYPE opt_event_config  */
#line 529 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct parse_events_error *error = parse_state->error;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_cache(list, &parse_state->idx, (yyvsp[-1].str), NULL, NULL, error, (yyvsp[0].list_terms),
				     parse_state);
	parse_events_terms__delete((yyvsp[0].list_terms));
	free((yyvsp[-1].str));
	if (err) {
		free_list_evsel(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2069 "util/parse-events-bison.c"
    break;

  case 45: /* event_legacy_mem: PE_PREFIX_MEM PE_VALUE '/' PE_VALUE ':' PE_MODIFIER_BP sep_dc  */
#line 550 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_breakpoint(list, &parse_state->idx,
					  (yyvsp[-5].num), (yyvsp[-1].str), (yyvsp[-3].num));
	free((yyvsp[-1].str));
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2090 "util/parse-events-bison.c"
    break;

  case 46: /* event_legacy_mem: PE_PREFIX_MEM PE_VALUE '/' PE_VALUE sep_dc  */
#line 568 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct list_head *list;

	list = alloc_list();
	ABORT_ON(!list);
	if (parse_events_add_breakpoint(list, &parse_state->idx,
					(yyvsp[-3].num), NULL, (yyvsp[-1].num))) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2108 "util/parse-events-bison.c"
    break;

  case 47: /* event_legacy_mem: PE_PREFIX_MEM PE_VALUE ':' PE_MODIFIER_BP sep_dc  */
#line 583 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_breakpoint(list, &parse_state->idx,
					  (yyvsp[-3].num), (yyvsp[-1].str), 0);
	free((yyvsp[-1].str));
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2129 "util/parse-events-bison.c"
    break;

  case 48: /* event_legacy_mem: PE_PREFIX_MEM PE_VALUE sep_dc  */
#line 601 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct list_head *list;

	list = alloc_list();
	ABORT_ON(!list);
	if (parse_events_add_breakpoint(list, &parse_state->idx,
					(yyvsp[-1].num), NULL, 0)) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2147 "util/parse-events-bison.c"
    break;

  case 49: /* event_legacy_tracepoint: tracepoint_name opt_event_config  */
#line 617 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct parse_events_error *error = parse_state->error;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	if (error)
		error->idx = (yylsp[-1]).first_column;

	err = parse_events_add_tracepoint(list, &parse_state->idx, (yyvsp[-1].tracepoint_name).sys, (yyvsp[-1].tracepoint_name).event,
					error, (yyvsp[0].list_terms));

	parse_events_terms__delete((yyvsp[0].list_terms));
	free((yyvsp[-1].tracepoint_name).sys);
	free((yyvsp[-1].tracepoint_name).event);
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2175 "util/parse-events-bison.c"
    break;

  case 50: /* tracepoint_name: PE_NAME '-' PE_NAME ':' PE_NAME  */
#line 643 "util/parse-events.y"
{
	struct tracepoint_name tracepoint;

	ABORT_ON(asprintf(&tracepoint.sys, "%s-%s", (yyvsp[-4].str), (yyvsp[-2].str)) < 0);
	tracepoint.event = (yyvsp[0].str);
	free((yyvsp[-4].str));
	free((yyvsp[-2].str));
	(yyval.tracepoint_name) = tracepoint;
}
#line 2189 "util/parse-events-bison.c"
    break;

  case 51: /* tracepoint_name: PE_NAME ':' PE_NAME  */
#line 654 "util/parse-events.y"
{
	struct tracepoint_name tracepoint = {(yyvsp[-2].str), (yyvsp[0].str)};

	(yyval.tracepoint_name) = tracepoint;
}
#line 2199 "util/parse-events-bison.c"
    break;

  case 52: /* event_legacy_numeric: PE_VALUE ':' PE_VALUE opt_event_config  */
#line 662 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_numeric(_parse_state, list, (u32)(yyvsp[-3].num), (yyvsp[-1].num), (yyvsp[0].list_terms));
	parse_events_terms__delete((yyvsp[0].list_terms));
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2218 "util/parse-events-bison.c"
    break;

  case 53: /* event_legacy_raw: PE_RAW opt_event_config  */
#line 679 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_add_numeric(_parse_state, list, PERF_TYPE_RAW, (yyvsp[-1].num), (yyvsp[0].list_terms));
	parse_events_terms__delete((yyvsp[0].list_terms));
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2237 "util/parse-events-bison.c"
    break;

  case 54: /* event_bpf_file: PE_BPF_OBJECT opt_event_config  */
#line 696 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_load_bpf(parse_state, list, (yyvsp[-1].str), false, (yyvsp[0].list_terms));
	parse_events_terms__delete((yyvsp[0].list_terms));
	free((yyvsp[-1].str));
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2258 "util/parse-events-bison.c"
    break;

  case 55: /* event_bpf_file: PE_BPF_SOURCE opt_event_config  */
#line 714 "util/parse-events.y"
{
	struct list_head *list;
	int err;

	list = alloc_list();
	ABORT_ON(!list);
	err = parse_events_load_bpf(_parse_state, list, (yyvsp[-1].str), true, (yyvsp[0].list_terms));
	parse_events_terms__delete((yyvsp[0].list_terms));
	if (err) {
		free(list);
		YYABORT;
	}
	(yyval.list_evsel) = list;
}
#line 2277 "util/parse-events-bison.c"
    break;

  case 56: /* opt_event_config: '/' event_config '/'  */
#line 731 "util/parse-events.y"
{
	(yyval.list_terms) = (yyvsp[-1].list_terms);
}
#line 2285 "util/parse-events-bison.c"
    break;

  case 57: /* opt_event_config: '/' '/'  */
#line 736 "util/parse-events.y"
{
	(yyval.list_terms) = NULL;
}
#line 2293 "util/parse-events-bison.c"
    break;

  case 58: /* opt_event_config: %empty  */
#line 740 "util/parse-events.y"
{
	(yyval.list_terms) = NULL;
}
#line 2301 "util/parse-events-bison.c"
    break;

  case 59: /* opt_pmu_config: '/' event_config '/'  */
#line 746 "util/parse-events.y"
{
	(yyval.list_terms) = (yyvsp[-1].list_terms);
}
#line 2309 "util/parse-events-bison.c"
    break;

  case 60: /* opt_pmu_config: '/' '/'  */
#line 751 "util/parse-events.y"
{
	(yyval.list_terms) = NULL;
}
#line 2317 "util/parse-events-bison.c"
    break;

  case 61: /* start_terms: event_config  */
#line 756 "util/parse-events.y"
{
	struct parse_events_state *parse_state = _parse_state;
	if (parse_state->terms) {
		parse_events_terms__delete ((yyvsp[0].list_terms));
		YYABORT;
	}
	parse_state->terms = (yyvsp[0].list_terms);
}
#line 2330 "util/parse-events-bison.c"
    break;

  case 62: /* event_config: event_config ',' event_term  */
#line 767 "util/parse-events.y"
{
	struct list_head *head = (yyvsp[-2].list_terms);
	struct parse_events_term *term = (yyvsp[0].term);

	if (!head) {
		parse_events_term__delete(term);
		YYABORT;
	}
	list_add_tail(&term->list, head);
	(yyval.list_terms) = (yyvsp[-2].list_terms);
}
#line 2346 "util/parse-events-bison.c"
    break;

  case 63: /* event_config: event_term  */
#line 780 "util/parse-events.y"
{
	struct list_head *head = malloc(sizeof(*head));
	struct parse_events_term *term = (yyvsp[0].term);

	ABORT_ON(!head);
	INIT_LIST_HEAD(head);
	list_add_tail(&term->list, head);
	(yyval.list_terms) = head;
}
#line 2360 "util/parse-events-bison.c"
    break;

  case 64: /* event_term: PE_RAW  */
#line 792 "util/parse-events.y"
{
	struct parse_events_term *term;

	ABORT_ON(parse_events_term__num(&term, PARSE_EVENTS__TERM_TYPE_CONFIG,
					NULL, (yyvsp[0].num), false, &(yylsp[0]), NULL));
	(yyval.term) = term;
}
#line 2372 "util/parse-events-bison.c"
    break;

  case 65: /* event_term: PE_NAME '=' PE_NAME  */
#line 801 "util/parse-events.y"
{
	struct parse_events_term *term;

	if (parse_events_term__str(&term, PARSE_EVENTS__TERM_TYPE_USER,
					(yyvsp[-2].str), (yyvsp[0].str), &(yylsp[-2]), &(yylsp[0]))) {
		free((yyvsp[-2].str));
		free((yyvsp[0].str));
		YYABORT;
	}
	(yyval.term) = term;
}
#line 2388 "util/parse-events-bison.c"
    break;

  case 66: /* event_term: PE_NAME '=' PE_VALUE  */
#line 814 "util/parse-events.y"
{
	struct parse_events_term *term;

	if (parse_events_term__num(&term, PARSE_EVENTS__TERM_TYPE_USER,
					(yyvsp[-2].str), (yyvsp[0].num), false, &(yylsp[-2]), &(yylsp[0]))) {
		free((yyvsp[-2].str));
		YYABORT;
	}
	(yyval.term) = term;
}
#line 2403 "util/parse-events-bison.c"
    break;

  case 67: /* event_term: PE_NAME '=' PE_VALUE_SYM_HW  */
#line 826 "util/parse-events.y"
{
	struct parse_events_term *term;
	int config = (yyvsp[0].num) & 255;

	if (parse_events_term__sym_hw(&term, (yyvsp[-2].str), config)) {
		free((yyvsp[-2].str));
		YYABORT;
	}
	(yyval.term) = term;
}
#line 2418 "util/parse-events-bison.c"
    break;

  case 68: /* event_term: PE_NAME  */
#line 838 "util/parse-events.y"
{
	struct parse_events_term *term;

	if (parse_events_term__num(&term, PARSE_EVENTS__TERM_TYPE_USER,
					(yyvsp[0].str), 1, true, &(yylsp[0]), NULL)) {
		free((yyvsp[0].str));
		YYABORT;
	}
	(yyval.term) = term;
}
#line 2433 "util/parse-events-bison.c"
    break;

  case 69: /* event_term: PE_VALUE_SYM_HW  */
#line 850 "util/parse-events.y"
{
	struct parse_events_term *term;
	int config = (yyvsp[0].num) & 255;

	ABORT_ON(parse_events_term__sym_hw(&term, NULL, config));
	(yyval.term) = term;
}
#line 2445 "util/parse-events-bison.c"
    break;

  case 70: /* event_term: PE_TERM '=' PE_NAME  */
#line 859 "util/parse-events.y"
{
	struct parse_events_term *term;

	if (parse_events_term__str(&term, (int)(yyvsp[-2].num), NULL, (yyvsp[0].str), &(yylsp[-2]), &(yylsp[0]))) {
		free((yyvsp[0].str));
		YYABORT;
	}
	(yyval.term) = term;
}
#line 2459 "util/parse-events-bison.c"
    break;

  case 71: /* event_term: PE_TERM '=' PE_VALUE  */
#line 870 "util/parse-events.y"
{
	struct parse_events_term *term;

	ABORT_ON(parse_events_term__num(&term, (int)(yyvsp[-2].num), NULL, (yyvsp[0].num), false, &(yylsp[-2]), &(yylsp[0])));
	(yyval.term) = term;
}
#line 2470 "util/parse-events-bison.c"
    break;

  case 72: /* event_term: PE_TERM  */
#line 878 "util/parse-events.y"
{
	struct parse_events_term *term;

	ABORT_ON(parse_events_term__num(&term, (int)(yyvsp[0].num), NULL, 1, true, &(yylsp[0]), NULL));
	(yyval.term) = term;
}
#line 2481 "util/parse-events-bison.c"
    break;

  case 73: /* event_term: PE_NAME array '=' PE_NAME  */
#line 886 "util/parse-events.y"
{
	struct parse_events_term *term;

	if (parse_events_term__str(&term, PARSE_EVENTS__TERM_TYPE_USER,
					(yyvsp[-3].str), (yyvsp[0].str), &(yylsp[-3]), &(yylsp[0]))) {
		free((yyvsp[-3].str));
		free((yyvsp[0].str));
		free((yyvsp[-2].array).ranges);
		YYABORT;
	}
	term->array = (yyvsp[-2].array);
	(yyval.term) = term;
}
#line 2499 "util/parse-events-bison.c"
    break;

  case 74: /* event_term: PE_NAME array '=' PE_VALUE  */
#line 901 "util/parse-events.y"
{
	struct parse_events_term *term;

	if (parse_events_term__num(&term, PARSE_EVENTS__TERM_TYPE_USER,
					(yyvsp[-3].str), (yyvsp[0].num), false, &(yylsp[-3]), &(yylsp[0]))) {
		free((yyvsp[-3].str));
		free((yyvsp[-2].array).ranges);
		YYABORT;
	}
	term->array = (yyvsp[-2].array);
	(yyval.term) = term;
}
#line 2516 "util/parse-events-bison.c"
    break;

  case 75: /* event_term: PE_DRV_CFG_TERM  */
#line 915 "util/parse-events.y"
{
	struct parse_events_term *term;
	char *config = strdup((yyvsp[0].str));

	ABORT_ON(!config);
	if (parse_events_term__str(&term, PARSE_EVENTS__TERM_TYPE_DRV_CFG,
					config, (yyvsp[0].str), &(yylsp[0]), NULL)) {
		free((yyvsp[0].str));
		free(config);
		YYABORT;
	}
	(yyval.term) = term;
}
#line 2534 "util/parse-events-bison.c"
    break;

  case 76: /* array: '[' array_terms ']'  */
#line 931 "util/parse-events.y"
{
	(yyval.array) = (yyvsp[-1].array);
}
#line 2542 "util/parse-events-bison.c"
    break;

  case 77: /* array: PE_ARRAY_ALL  */
#line 936 "util/parse-events.y"
{
	(yyval.array).nr_ranges = 0;
	(yyval.array).ranges = NULL;
}
#line 2551 "util/parse-events-bison.c"
    break;

  case 78: /* array_terms: array_terms ',' array_term  */
#line 943 "util/parse-events.y"
{
	struct parse_events_array new_array;

	new_array.nr_ranges = (yyvsp[-2].array).nr_ranges + (yyvsp[0].array).nr_ranges;
	new_array.ranges = realloc((yyvsp[-2].array).ranges,
				sizeof(new_array.ranges[0]) *
				new_array.nr_ranges);
	ABORT_ON(!new_array.ranges);
	memcpy(&new_array.ranges[(yyvsp[-2].array).nr_ranges], (yyvsp[0].array).ranges,
	       (yyvsp[0].array).nr_ranges * sizeof(new_array.ranges[0]));
	free((yyvsp[0].array).ranges);
	(yyval.array) = new_array;
}
#line 2569 "util/parse-events-bison.c"
    break;

  case 80: /* array_term: PE_VALUE  */
#line 961 "util/parse-events.y"
{
	struct parse_events_array array;

	array.nr_ranges = 1;
	array.ranges = malloc(sizeof(array.ranges[0]));
	ABORT_ON(!array.ranges);
	array.ranges[0].start = (yyvsp[0].num);
	array.ranges[0].length = 1;
	(yyval.array) = array;
}
#line 2584 "util/parse-events-bison.c"
    break;

  case 81: /* array_term: PE_VALUE PE_ARRAY_RANGE PE_VALUE  */
#line 973 "util/parse-events.y"
{
	struct parse_events_array array;

	ABORT_ON((yyvsp[0].num) < (yyvsp[-2].num));
	array.nr_ranges = 1;
	array.ranges = malloc(sizeof(array.ranges[0]));
	ABORT_ON(!array.ranges);
	array.ranges[0].start = (yyvsp[-2].num);
	array.ranges[0].length = (yyvsp[0].num) - (yyvsp[-2].num) + 1;
	(yyval.array) = array;
}
#line 2600 "util/parse-events-bison.c"
    break;


#line 2604 "util/parse-events-bison.c"

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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, _parse_state, scanner, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, _parse_state, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, _parse_state, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, _parse_state, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, _parse_state, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, _parse_state, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 989 "util/parse-events.y"


void parse_events_error(YYLTYPE *loc, void *parse_state,
			void *scanner __maybe_unused,
			char const *msg __maybe_unused)
{
	parse_events_evlist_error(parse_state, loc->last_column, "parser error");
}
