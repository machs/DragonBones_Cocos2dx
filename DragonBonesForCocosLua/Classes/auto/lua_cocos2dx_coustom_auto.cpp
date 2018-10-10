#include "lua_cocos2dx_coustom_auto.hpp"
#include "../../../runtime-src/Classes/DrageBones.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_cocos2dx_coustom_DrageBones_init(lua_State* tolua_S)
{
    int argc = 0;
    DrageBones* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DrageBones",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DrageBones*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_coustom_DrageBones_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_coustom_DrageBones_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DrageBones:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_coustom_DrageBones_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_coustom_DrageBones_SetDBFils(lua_State* tolua_S)
{
    int argc = 0;
    DrageBones* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DrageBones",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DrageBones*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_coustom_DrageBones_SetDBFils'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DrageBones:SetDBFils");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "DrageBones:SetDBFils");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "DrageBones:SetDBFils");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "DrageBones:SetDBFils");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_coustom_DrageBones_SetDBFils'", nullptr);
            return 0;
        }
        cobj->SetDBFils(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DrageBones:SetDBFils",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_coustom_DrageBones_SetDBFils'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_coustom_DrageBones_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DrageBones",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_coustom_DrageBones_create'", nullptr);
            return 0;
        }
        DrageBones* ret = DrageBones::create();
        object_to_luaval<DrageBones>(tolua_S, "DrageBones",(DrageBones*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DrageBones:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_coustom_DrageBones_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_coustom_DrageBones_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DrageBones)");
    return 0;
}

int lua_register_cocos2dx_coustom_DrageBones(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DrageBones");
    tolua_cclass(tolua_S,"DrageBones","DrageBones","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"DrageBones");
        tolua_function(tolua_S,"init",lua_cocos2dx_coustom_DrageBones_init);
        tolua_function(tolua_S,"SetDBFils",lua_cocos2dx_coustom_DrageBones_SetDBFils);
        tolua_function(tolua_S,"create", lua_cocos2dx_coustom_DrageBones_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DrageBones).name();
    g_luaType[typeName] = "DrageBones";
    g_typeCast["DrageBones"] = "DrageBones";
    return 1;
}
TOLUA_API int register_all_cocos2dx_coustom(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_coustom_DrageBones(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

