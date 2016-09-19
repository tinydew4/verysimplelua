//---------------------------------------------------------------------------
#ifndef VerySimpleLuaLibH
#define VerySimpleLuaLibH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.IOUtils.hpp>
#include <System.SysUtils.hpp>

/*************************************
 * Microsoft Windows declarations
 *************************************/
#if defined(_Windows)
#include <Winapi.Windows.hpp>
const String LUA_LIBRARY = "lua5.3.0.dll"; // Do not Localize

/*************************************
 * MacOS & iOS declarations
 *************************************/
#elif defined(__APPLE__)
#include <Posix.SysTypes.hpp>
#if defined(__arm__) || defined(__arm64__)
    // NOTE! If you can distinguish whether the current opeartion on the
    // simulator, change the following conditional expression.
    #if 1
        const String LUA_LIBRARY = "liblua.a"; // Do not Localize
    #else
        const String LUA_LIBRARY = "liblua_sim.a"; // Do not Localize
    #endif
#else
    const String LUA_LIBRARY = "liblua5.3.0.dylib"; // Do not Localize
#endif

/*************************************
 * Android declarations
 *************************************/
#elif defined(__ANDROID__)
#include <Posix.SysTypes.hpp>
const String LUA_LIBRARY = "liblua.so"; // Do not Localize
#endif

/*
 * luaconf.h
 */
const LUA_IDSIZE = 60;
const LUAI_FIRSTPSEUDOIDX = -1001000;

/*
 * lua.h
 */
const String LUA_VERSION_MAJOR = "5";
const String LUA_VERSION_MINOR = "3";
const LUA_VERSION_NUM = 503;
const String LUA_VERSION_RELEASE = "0";

const String LUA_VERSION_ = "Lua " + LUA_VERSION_MAJOR + "." + LUA_VERSION_MINOR;
const String LUA_RELEASE = LUA_VERSION_ + "." + LUA_VERSION_RELEASE;
const String LUA_COPYRIGHT = LUA_RELEASE + "  Copyright (C) 1994-2015 Lua.org, PUC-Rio";
const String LUA_AUTHOR = "R. Ierusalimschy, L. H. de Figueiredo, W. Celes";

// mark for precompiled code ('<esc>Lua')
const String LUA_SIGNATURE = "\x1bLua";

// option for multiple returns in 'lua_pcall' and 'lua_call'
const LUA_MULTRET = -1;

/*
 * pseudo-indices
 */
const LUA_REGISTRYINDEX = LUAI_FIRSTPSEUDOIDX;

/*
 * thread status
 */
const LUA_OK        = 0;
const LUA_YIELD     = 1;
const LUA_ERRRUN    = 2;
const LUA_ERRSYNTAX = 3;
const LUA_ERRMEM    = 4;
const LUA_ERRGCMM   = 5;
const LUA_ERRERR    = 6;

/*
 * basic types
 */
const LUA_TNONE          = (-1);
const LUA_TNIL           = 0;
const LUA_TBOOLEAN       = 1;
const LUA_TLIGHTUSERDATA = 2;
const LUA_TNUMBER        = 3;
const LUA_TSTRING        = 4;
const LUA_TTABLE         = 5;
const LUA_TFUNCTION      = 6;
const LUA_TUSERDATA      = 7;
const LUA_TTHREAD        = 8;

const LUA_NUMTAGS        = 9;

// minimum Lua stack available to a C function
const LUA_MINSTACK = 20;

// predefined values in the registry
const LUA_RIDX_MAINTHREAD = 1;
const LUA_RIDX_GLOBALS    = 2;
const LUA_RIDX_LAST       = LUA_RIDX_GLOBALS;

/*
 * Comparison and arithmetic functions
 */
const LUA_OPADD  = 0; // ORDER TM, ORDER OP
const LUA_OPSUB  = 1;
const LUA_OPMUL  = 2;
const LUA_OPMOD  = 3;
const LUA_OPPOW  = 4;
const LUA_OPDIV  = 5;
const LUA_OPIDIV = 6;
const LUA_OPBAND = 7;
const LUA_OPBOR  = 8;
const LUA_OPBXOR = 9;
const LUA_OPSHL  = 10;
const LUA_OPSHR  = 11;
const LUA_OPUNM  = 12;
const LUA_OPBNOT = 13;

const LUA_OPEQ = 0;
const LUA_OPLT = 1;
const LUA_OPLE = 2;

/*
 * garbage-collection function and options
 */
const LUA_GCSTOP       = 0;
const LUA_GCRESTART    = 1;
const LUA_GCCOLLECT    = 2;
const LUA_GCCOUNT      = 3;
const LUA_GCCOUNTB     = 4;
const LUA_GCSTEP       = 5;
const LUA_GCSETPAUSE   = 6;
const LUA_GCSETSTEPMUL = 7;
const LUA_GCISRUNNING  = 9;

/*
 * Event codes
 */
const LUA_HOOKCALL     = 0;
const LUA_HOOKRET      = 1;
const LUA_HOOKLINE     = 2;
const LUA_HOOKCOUNT    = 3;
const LUA_HOOKTAILCALL = 4;

/*
 * Event masks
 */
const LUA_MASKCALL  = (1 << LUA_HOOKCALL);
const LUA_MASKRET   = (1 << LUA_HOOKRET);
const LUA_MASKLINE  = (1 << LUA_HOOKLINE);
const LUA_MASKCOUNT = (1 << LUA_HOOKCOUNT);

/*
 * lualib.h
 */
const String LUA_COLIBNAME   = "coroutine";
const String LUA_TABLIBNAME  = "table";
const String LUA_IOLIBNAME   = "io";
const String LUA_OSLIBNAME   = "os";
const String LUA_STRLIBNAME  = "string";
const String LUA_UTF8LIBNAME = "utf8";
const String LUA_BITLIBNAME  = "bit32";
const String LUA_MATHLIBNAME = "math";
const String LUA_DBLIBNAME   = "debug";
const String LUA_LOADLIBNAME = "package";

/*
 * lauxlib.h
 */
const LUAL_NUMSIZES = sizeof(NativeInt) * 16 + sizeof(Double);

// pre-defined references
const LUA_NOREF  = -2;
const LUA_REFNIL = -1;

/*
 * LAUL_BUFFERSIZE is the buffer size used by the lauxlib buffer system.
 * CHANGE it if it uses too much C=stack space.
 */
const LUAL_BUFFERSIZE = Integer(0x80 * sizeof(Pointer) * sizeof(NativeInt));

const String LUA_FILEHANDLE = "FILE*";

typedef Pointer lua_State;
typedef NativeInt ptrdiff_t;

// type of numbers in Lua
typedef Double lua_Number;

// type for integer functions
typedef __int64 lua_Integer; // NativeInt

// unsigned integer type
typedef unsigned __int64 lua_Unsigned; // NativeUInt

// type for continuation-function contexts
typedef ptrdiff_t lua_KContext;

/*
 * Type for C functions registered with Lua
 */
typedef int __cdecl (*lua_CFunction)(lua_State L);

/*
 * Type for continuation functions
 */
typedef int __cdecl (*lua_KFunction)(lua_State L, Integer status, lua_KContext ctx);

/*
 * Type for functions that read/write blocks when loading/dumping Lua chunks
 */
typedef Pointer __cdecl (*lua_Reader)(lua_State L, Pointer ud, size_t* sz);
typedef Pointer __cdecl (*lua_Writer)(lua_State L, Pointer p, size_t sz);

/*
 * Type for memory-allocation functions
 */
typedef Pointer __cdecl (*lua_Alloc)(Pointer ud, Pointer: ptr, size_t osize, size_t nsize);

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
