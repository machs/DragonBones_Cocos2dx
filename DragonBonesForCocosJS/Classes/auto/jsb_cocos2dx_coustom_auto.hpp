#include "base/ccConfig.h"
#ifndef __cocos2dx_coustom_h__
#define __cocos2dx_coustom_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_DrageBones_class;
extern JSObject *jsb_DrageBones_prototype;

bool js_cocos2dx_coustom_DrageBones_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_coustom_DrageBones_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_coustom_DrageBones(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_coustom(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_coustom_DrageBones_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_coustom_DrageBones_SetDBFils(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_coustom_DrageBones_DrageBones(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __cocos2dx_coustom_h__
