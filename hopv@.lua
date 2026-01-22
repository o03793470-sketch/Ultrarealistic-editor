-- hopv@.lua
-- Скрипт для 4D керування камерою через ноди

NodeCamera = {
    nodes = {},
    currentNode = 1,
    speed = 1.0
}

-- Додати нод
function NodeCamera:AddNode(x, y, z, w)
    table.insert(self.nodes, {x=x, y=y, z=z, w=w})
    print("Node added at (" .. x .. "," .. y .. "," .. z .. "," .. w .. ")")
end

-- Перейти до наступного нода
function NodeCamera:NextNode()
    if #self.nodes == 0 then
        print("No nodes defined!")
        return
    end

    self.currentNode = self.currentNode + 1
    if self.currentNode > #self.nodes then
        self.currentNode = 1
    end

    local n = self.nodes[self.currentNode]
    print("Camera moved to node: (" .. n.x .. "," .. n.y .. "," .. n.z .. "," .. n.w .. ")")
end

-- Рух камери між нодами з інтерполяцією
function NodeCamera:InterpolateToNext(dt)
    if #self.nodes < 2 then return end

    local current = self.nodes[self.currentNode]
    local nextNode = self.nodes[self.currentNode % #self.nodes + 1]

    current.x = current.x + (nextNode.x - current.x) * dt * self.speed
    current.y = current.y + (nextNode.y - current.y) * dt * self.speed
    current.z = current.z + (nextNode.z - current.z) * dt * self.speed
    current.w = current.w + (nextNode.w - current.w) * dt * self.speed
end
