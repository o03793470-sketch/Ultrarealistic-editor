-- SDP.lua
-- Скрипт для керування камерою: приближення, удалення, 2-е та 3-е лице

Camera = {
    position = {x=0, y=2, z=5},
    target = {x=0, y=0, z=0},
    mode = "third_person", -- "third_person" або "second_person"
    fov = 60
}

-- Змінити режим камери
function Camera:SetMode(mode)
    if mode == "third_person" or mode == "second_person" then
        self.mode = mode
        print("Camera mode set to: " .. mode)
    else
        print("Invalid camera mode!")
    end
end

-- Приблизити камеру
function Camera:ZoomIn(amount)
    self.fov = self.fov - amount
    if self.fov < 20 then self.fov = 20 end
    print("Camera FOV: " .. self.fov)
end

-- Віддалити камеру
function Camera:ZoomOut(amount)
    self.fov = self.fov + amount
    if self.fov > 120 then self.fov = 120 end
    print("Camera FOV: " .. self.fov)
end

-- Перемістити камеру
function Camera:Move(dx, dy, dz)
    self.position.x = self.position.x + dx
    self.position.y = self.position.y + dy
    self.position.z = self.position.z + dz
    print("Camera moved to: (" .. self.position.x .. "," .. self.position.y .. "," .. self.position.z .. ")")
end
