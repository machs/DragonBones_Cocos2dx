

> 由于项目需求需要接入骨骼动画,Cocos官方使用的是Spine,但是不符合现在项目的需求,所以接入了DragonBones龙骨。DragonBones官方只提供了CPP的runtime,我这边因为用的JS,所以对DragonBones封装了一下，顺带封装了一下Lua。其本质就是使用tojs和tolua进行bind一下。

### DragonBones For CocosLua

> Classes ==>直接放入到你当前的工程.
>
> res ==> 测试资源
>
> src  ==> 测试文件
>
> tolua/cocos2dx_coustom.ini ==>  toLua的配置文件,该文件可以无视，放这里主要是为了进行二          次bind的时候使用.



### DragonBones For CocosJS

>Classes ==>直接放入到你当前的工程.
>
>res ==> 测试资源
>
>src  ==> 测试文件
>
>tojs/cocos2dx_coustom.ini ==>  toLua的配置文件,该文件可以无视，放这里主要是为了进行二次bind的时候使用.

> 关于封装,可以参考Classes/DrageBones该类，因为我想买只需要使用动画就行，其他的不需要使用，所以我封装的很简单，只封装了一个方法。



### 关于打包

> ios可以直接无视，使用Xocde即可。
>
> android需要修改mk文件，按照正常添加CPP文件的方式即可。