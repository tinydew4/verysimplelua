//---------------------------------------------------------------------------
/*
** $Id: lua.h,v 1.325 2014/12/26 17:24:27 roberto Exp $
** Lua - A Scripting Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
*/

/*
** Translated to Delphi by Dennis D. Spreen <dennis@spreendigital.de>
** Notes:
    as lua_State is a not defined structure, it is not used as Plua_State
    LUA_VERSION suffixed by '_' for avoiding name collision
    lua_xmove parameter 'to' suffixed by '_' for avoiding name collision
    Comparison and arithmetic functions consts moved to constants
    garbage-collection function and options consts moved to constants
    compatibility macros for unsigned conversions not translated
    event codes consts moved to constants
    LUA_YIELD thread status suffixed by '_' for avoiding name collision
*/

/*
** Translated to C++Builder by Hur Jung-ju <tinydew4@gmail.com>
** Notes:
*/

#pragma hdrstop

#include "VerySimpleLuaLib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
