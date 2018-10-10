
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)

    -- add HelloWorld label
    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
        :move(display.cx, display.cy + 200)
        :addTo(self)

    local aa = DrageBones:create()
    aa:SetDBFils("mecha_1002_101d_show_ske.dbbin","mecha_1002_101d_show_tex.json","Armautre","newAnimation")
    self:addChild(aa)
    aa:setPosition(cc.p(500,200))
end

return MainScene
