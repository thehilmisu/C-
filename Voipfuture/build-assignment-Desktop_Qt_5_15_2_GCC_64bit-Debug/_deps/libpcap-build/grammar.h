/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_PCAP_HOME_THEHILMISU_DESKTOP_WORKDIR_VOIPFUTURE_BUILD_ASSIGNMENT_DESKTOP_QT_5_15_2_GCC_64BIT_DEBUG_DEPS_LIBPCAP_BUILD_GRAMMAR_H_INCLUDED
# define YY_PCAP_HOME_THEHILMISU_DESKTOP_WORKDIR_VOIPFUTURE_BUILD_ASSIGNMENT_DESKTOP_QT_5_15_2_GCC_64BIT_DEBUG_DEPS_LIBPCAP_BUILD_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int pcap_debug;
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
    DST = 258,                     /* DST  */
    SRC = 259,                     /* SRC  */
    HOST = 260,                    /* HOST  */
    GATEWAY = 261,                 /* GATEWAY  */
    NET = 262,                     /* NET  */
    NETMASK = 263,                 /* NETMASK  */
    PORT = 264,                    /* PORT  */
    PORTRANGE = 265,               /* PORTRANGE  */
    LESS = 266,                    /* LESS  */
    GREATER = 267,                 /* GREATER  */
    PROTO = 268,                   /* PROTO  */
    PROTOCHAIN = 269,              /* PROTOCHAIN  */
    CBYTE = 270,                   /* CBYTE  */
    ARP = 271,                     /* ARP  */
    RARP = 272,                    /* RARP  */
    IP = 273,                      /* IP  */
    SCTP = 274,                    /* SCTP  */
    TCP = 275,                     /* TCP  */
    UDP = 276,                     /* UDP  */
    ICMP = 277,                    /* ICMP  */
    IGMP = 278,                    /* IGMP  */
    IGRP = 279,                    /* IGRP  */
    PIM = 280,                     /* PIM  */
    VRRP = 281,                    /* VRRP  */
    CARP = 282,                    /* CARP  */
    ATALK = 283,                   /* ATALK  */
    AARP = 284,                    /* AARP  */
    DECNET = 285,                  /* DECNET  */
    LAT = 286,                     /* LAT  */
    SCA = 287,                     /* SCA  */
    MOPRC = 288,                   /* MOPRC  */
    MOPDL = 289,                   /* MOPDL  */
    TK_BROADCAST = 290,            /* TK_BROADCAST  */
    TK_MULTICAST = 291,            /* TK_MULTICAST  */
    NUM = 292,                     /* NUM  */
    INBOUND = 293,                 /* INBOUND  */
    OUTBOUND = 294,                /* OUTBOUND  */
    IFINDEX = 295,                 /* IFINDEX  */
    PF_IFNAME = 296,               /* PF_IFNAME  */
    PF_RSET = 297,                 /* PF_RSET  */
    PF_RNR = 298,                  /* PF_RNR  */
    PF_SRNR = 299,                 /* PF_SRNR  */
    PF_REASON = 300,               /* PF_REASON  */
    PF_ACTION = 301,               /* PF_ACTION  */
    TYPE = 302,                    /* TYPE  */
    SUBTYPE = 303,                 /* SUBTYPE  */
    DIR = 304,                     /* DIR  */
    ADDR1 = 305,                   /* ADDR1  */
    ADDR2 = 306,                   /* ADDR2  */
    ADDR3 = 307,                   /* ADDR3  */
    ADDR4 = 308,                   /* ADDR4  */
    RA = 309,                      /* RA  */
    TA = 310,                      /* TA  */
    LINK = 311,                    /* LINK  */
    GEQ = 312,                     /* GEQ  */
    LEQ = 313,                     /* LEQ  */
    NEQ = 314,                     /* NEQ  */
    ID = 315,                      /* ID  */
    EID = 316,                     /* EID  */
    HID = 317,                     /* HID  */
    HID6 = 318,                    /* HID6  */
    AID = 319,                     /* AID  */
    LSH = 320,                     /* LSH  */
    RSH = 321,                     /* RSH  */
    LEN = 322,                     /* LEN  */
    IPV6 = 323,                    /* IPV6  */
    ICMPV6 = 324,                  /* ICMPV6  */
    AH = 325,                      /* AH  */
    ESP = 326,                     /* ESP  */
    VLAN = 327,                    /* VLAN  */
    MPLS = 328,                    /* MPLS  */
    PPPOED = 329,                  /* PPPOED  */
    PPPOES = 330,                  /* PPPOES  */
    GENEVE = 331,                  /* GENEVE  */
    ISO = 332,                     /* ISO  */
    ESIS = 333,                    /* ESIS  */
    CLNP = 334,                    /* CLNP  */
    ISIS = 335,                    /* ISIS  */
    L1 = 336,                      /* L1  */
    L2 = 337,                      /* L2  */
    IIH = 338,                     /* IIH  */
    LSP = 339,                     /* LSP  */
    SNP = 340,                     /* SNP  */
    CSNP = 341,                    /* CSNP  */
    PSNP = 342,                    /* PSNP  */
    STP = 343,                     /* STP  */
    IPX = 344,                     /* IPX  */
    NETBEUI = 345,                 /* NETBEUI  */
    LANE = 346,                    /* LANE  */
    LLC = 347,                     /* LLC  */
    METAC = 348,                   /* METAC  */
    BCC = 349,                     /* BCC  */
    SC = 350,                      /* SC  */
    ILMIC = 351,                   /* ILMIC  */
    OAMF4EC = 352,                 /* OAMF4EC  */
    OAMF4SC = 353,                 /* OAMF4SC  */
    OAM = 354,                     /* OAM  */
    OAMF4 = 355,                   /* OAMF4  */
    CONNECTMSG = 356,              /* CONNECTMSG  */
    METACONNECT = 357,             /* METACONNECT  */
    VPI = 358,                     /* VPI  */
    VCI = 359,                     /* VCI  */
    RADIO = 360,                   /* RADIO  */
    FISU = 361,                    /* FISU  */
    LSSU = 362,                    /* LSSU  */
    MSU = 363,                     /* MSU  */
    HFISU = 364,                   /* HFISU  */
    HLSSU = 365,                   /* HLSSU  */
    HMSU = 366,                    /* HMSU  */
    SIO = 367,                     /* SIO  */
    OPC = 368,                     /* OPC  */
    DPC = 369,                     /* DPC  */
    SLS = 370,                     /* SLS  */
    HSIO = 371,                    /* HSIO  */
    HOPC = 372,                    /* HOPC  */
    HDPC = 373,                    /* HDPC  */
    HSLS = 374,                    /* HSLS  */
    LEX_ERROR = 375,               /* LEX_ERROR  */
    OR = 376,                      /* OR  */
    AND = 377,                     /* AND  */
    UMINUS = 378                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DST 258
#define SRC 259
#define HOST 260
#define GATEWAY 261
#define NET 262
#define NETMASK 263
#define PORT 264
#define PORTRANGE 265
#define LESS 266
#define GREATER 267
#define PROTO 268
#define PROTOCHAIN 269
#define CBYTE 270
#define ARP 271
#define RARP 272
#define IP 273
#define SCTP 274
#define TCP 275
#define UDP 276
#define ICMP 277
#define IGMP 278
#define IGRP 279
#define PIM 280
#define VRRP 281
#define CARP 282
#define ATALK 283
#define AARP 284
#define DECNET 285
#define LAT 286
#define SCA 287
#define MOPRC 288
#define MOPDL 289
#define TK_BROADCAST 290
#define TK_MULTICAST 291
#define NUM 292
#define INBOUND 293
#define OUTBOUND 294
#define IFINDEX 295
#define PF_IFNAME 296
#define PF_RSET 297
#define PF_RNR 298
#define PF_SRNR 299
#define PF_REASON 300
#define PF_ACTION 301
#define TYPE 302
#define SUBTYPE 303
#define DIR 304
#define ADDR1 305
#define ADDR2 306
#define ADDR3 307
#define ADDR4 308
#define RA 309
#define TA 310
#define LINK 311
#define GEQ 312
#define LEQ 313
#define NEQ 314
#define ID 315
#define EID 316
#define HID 317
#define HID6 318
#define AID 319
#define LSH 320
#define RSH 321
#define LEN 322
#define IPV6 323
#define ICMPV6 324
#define AH 325
#define ESP 326
#define VLAN 327
#define MPLS 328
#define PPPOED 329
#define PPPOES 330
#define GENEVE 331
#define ISO 332
#define ESIS 333
#define CLNP 334
#define ISIS 335
#define L1 336
#define L2 337
#define IIH 338
#define LSP 339
#define SNP 340
#define CSNP 341
#define PSNP 342
#define STP 343
#define IPX 344
#define NETBEUI 345
#define LANE 346
#define LLC 347
#define METAC 348
#define BCC 349
#define SC 350
#define ILMIC 351
#define OAMF4EC 352
#define OAMF4SC 353
#define OAM 354
#define OAMF4 355
#define CONNECTMSG 356
#define METACONNECT 357
#define VPI 358
#define VCI 359
#define RADIO 360
#define FISU 361
#define LSSU 362
#define MSU 363
#define HFISU 364
#define HLSSU 365
#define HMSU 366
#define SIO 367
#define OPC 368
#define DPC 369
#define SLS 370
#define HSIO 371
#define HOPC 372
#define HDPC 373
#define HSLS 374
#define LEX_ERROR 375
#define OR 376
#define AND 377
#define UMINUS 378

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 321 "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-build/grammar.y"

	int i;
	bpf_u_int32 h;
	char *s;
	struct stmt *stmt;
	struct arth *a;
	struct {
		struct qual q;
		int atmfieldtype;
		int mtp3fieldtype;
		struct block *b;
	} blk;
	struct block *rblk;

#line 328 "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-build/grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int pcap_parse (void *yyscanner, compiler_state_t *cstate);

#endif /* !YY_PCAP_HOME_THEHILMISU_DESKTOP_WORKDIR_VOIPFUTURE_BUILD_ASSIGNMENT_DESKTOP_QT_5_15_2_GCC_64BIT_DEBUG_DEPS_LIBPCAP_BUILD_GRAMMAR_H_INCLUDED  */
