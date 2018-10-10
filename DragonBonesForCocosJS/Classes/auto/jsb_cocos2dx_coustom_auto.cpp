#include "scripting/js-bindings/auto/jsb_cocos2dx_coustom_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "../DrageBones.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
JSClass  *jsb_DrageBones_class;
JSObject *jsb_DrageBones_prototype;

bool js_cocos2dx_coustom_DrageBones_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    DrageBones* cobj = (DrageBones *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_coustom_DrageBones_init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_coustom_DrageBones_init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_coustom_DrageBones_SetDBFils(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    DrageBones* cobj = (DrageBones *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_coustom_DrageBones_SetDBFils : Invalid Native Object");
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_coustom_DrageBones_SetDBFils : Error processing arguments");
        cobj->SetDBFils(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_coustom_DrageBones_SetDBFils : wrong number of arguments: %d, was expecting %d", argc, 5);
    return false;
}
bool js_cocos2dx_coustom_DrageBones_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    DrageBones* cobj = new (std::nothrow) DrageBones();

    js_type_class_t *typeClass = js_get_type_from_native<DrageBones>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "DrageBones"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_cocos2d_Layer_prototype;

void js_register_cocos2dx_coustom_DrageBones(JSContext *cx, JS::HandleObject global) {
    jsb_DrageBones_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_DrageBones_class->name = "DrageBones";
    jsb_DrageBones_class->addProperty = JS_PropertyStub;
    jsb_DrageBones_class->delProperty = JS_DeletePropertyStub;
    jsb_DrageBones_class->getProperty = JS_PropertyStub;
    jsb_DrageBones_class->setProperty = JS_StrictPropertyStub;
    jsb_DrageBones_class->enumerate = JS_EnumerateStub;
    jsb_DrageBones_class->resolve = JS_ResolveStub;
    jsb_DrageBones_class->convert = JS_ConvertStub;
    jsb_DrageBones_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("init", js_cocos2dx_coustom_DrageBones_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetDBFils", js_cocos2dx_coustom_DrageBones_SetDBFils, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_cocos2d_Layer_prototype);
    jsb_DrageBones_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_DrageBones_class,
        js_cocos2dx_coustom_DrageBones_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_DrageBones_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "DrageBones"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<DrageBones>(cx, jsb_DrageBones_class, proto, parent_proto);
}

void register_all_cocos2dx_coustom(JSContext* cx, JS::HandleObject obj) {
    // Get the global ns
    JS::RootedObject ns(cx, ScriptingCore::getInstance()->getGlobalObject());

    js_register_cocos2dx_coustom_DrageBones(cx, ns);
}

