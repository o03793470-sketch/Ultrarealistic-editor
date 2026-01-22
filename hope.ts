// hope.ts
// Створення 3D моделей людей за допомогою нодів

interface Joint {
    name: string;
    x: number;
    y: number;
    z: number;
}

interface HumanModel {
    name: string;
    joints: Joint[];
}

export class HumanBuilder {
    models: HumanModel[] = [];

    // Створити нового персонажа
    createHuman(name: string) {
        const human: HumanModel = { name, joints: [] };
        this.models.push(human);
        console.log(`Human model created: ${name}`);
    }

    // Додати суглоб/нод
    addJoint(humanName: string, jointName: string, x: number, y: number, z: number) {
        const human = this.models.find(h => h.name === humanName);
        if (human) {
            human.joints.push({ name: jointName, x, y, z });
            console.log(`Joint ${jointName} added to ${humanName} at (${x}, ${y}, ${z})`);
        } else {
            console.log(`Human ${humanName} not found!`);
        }
    }

    // Перемістити суглоб
    moveJoint(humanName: string, jointName: string, dx: number, dy: number, dz: number) {
        const human = this.models.find(h => h.name === humanName);
        if (human) {
            const joint = human.joints.find(j => j.name === jointName);
            if (joint) {
                joint.x += dx;
                joint.y += dy;
                joint.z += dz;
                console.log(`Joint ${jointName} of ${humanName} moved to (${joint.x}, ${joint.y}, ${joint.z})`);
            } else {
                console.log(`Joint ${jointName} not found!`);
            }
        }
    }

    // Видалити суглоб
    removeJoint(humanName: string, jointName: string) {
        const human = this.models.find(h => h.name === humanName);
        if (human) {
            human.joints = human.joints.filter(j => j.name !== jointName);
            console.log(`Joint ${jointName} removed from ${humanName}`);
        }
    }
                        }
