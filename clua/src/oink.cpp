#include "oink/oink.hpp"

#include <stdio.h>

static int ok(lua_State* L)
{
    (void)L;
    printf("Oink Oink! Everything is Oinkay! :-)\n");
    return 0;
}

static int subOk(lua_State* L)
{
    (void)L;
    printf("Oink Oink! Everything is oinkay here as well! :-)\n");
    return 0;
}

static const struct luaL_Reg oinkLib [] = {
    {"ok", ok},
    {nullptr, nullptr}  /* sentinel */
};

static const struct luaL_Reg oinkSubLib [] = {
    {"ok", subOk},
    {nullptr, nullptr}  /* sentinel */
};

int luaopen_oink(lua_State* L)
{
    luaL_newlib(L, oinkLib);

    luaL_newlib(L, oinkSubLib);
    lua_setfield(L, -2, "sub");

    return 1;
}
