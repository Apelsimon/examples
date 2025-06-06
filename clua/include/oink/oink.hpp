#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#if defined(__GNUC__) || defined(__clang__)
    #define OINK_LIB_EXPORT __attribute__((visibility("default")))
#elif defined(_MSC_VER)
    #define OINK_LIB_EXPORT __declspec(dllexport)
#else
    #error "TODO: OINK_LIB_EXPORT"
#endif

int OINK_LIB_EXPORT luaopen_oink(lua_State* lua);

#ifdef __cplusplus
}
#endif // __cplusplus