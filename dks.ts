// dks.ts
// Управління 3D сценою через ноди

interface Node3D {
    x: number;
    y: number;
    z: number;
    name: string;
}

export class SceneNodes {
    nodes: Node3D[] = [];

    // Додати нод
    addNode(x: number, y: number, z: number, name: string) {
        this.nodes.push({ x, y, z, name });
        console.log(`Node added: ${name} at (${x}, ${y}, ${z})`);
    }

    // Рух нода
    moveNode(name: string, dx: number, dy: number, dz: number) {
        const node = this.nodes.find(n => n.name === name);
        if (node) {
            node.x += dx;
            node.y += dy;
            node.z += dz;
            console.log(`Node ${name} moved to (${node.x}, ${node.y}, ${node.z})`);
        } else {
            console.log(`Node ${name} not found!`);
        }
    }

    // Видалення нода
    removeNode(name: string) {
        this.nodes = this.nodes.filter(n => n.name !== name);
        console.log(`Node ${name} removed`);
    }
}
