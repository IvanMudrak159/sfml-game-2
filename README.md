# 🧩 2D Modular Game Framework (C++17 + SFML)

This project is a **modular 2D game framework** written in **C++17** and powered by **SFML**.  
It provides a flexible, **component-based architecture**, making it easy to build gameplay systems such as physics, AI, rendering, and scripting.  
Designed for **extensibility**, **debugging visibility**, and **clean code structure**.

## Showcase




https://github.com/user-attachments/assets/5c52cd59-19fe-42ab-a627-2233b4ef655a


---

## ✨ Features

---

### ✅ **Component-Based Architecture**
**GameObject System**  
Every entity (player, enemy, tile, etc.) is represented as a `GameObject` that can be extended via attachable components.  
This enables clean composition, reuse, and modularity.

---

### ✅ **Physics System**
- **RigidBody & BoxCollider:**  
  Add physics behavior to any object:
  - Dynamic & static rigidbodies  
  - Force application  
  - Velocity integration  
  - Collision detection & response  
- **PhysicsSystem:**  
  Manages all physics-enabled objects, updates them, and resolves collisions.

---

### ✅ **Rendering System**
- **SpriteRenderer:**  
  Attach to any `GameObject` to render SFML sprites with texture handling and layer control.
- **Debug Renderers:**  
  Visualize physics bodies, AI grids, paths, and more directly in the game window.

---

### ✅ **AI System**
- **AgentAI:**  
  Provides autonomous control, movement logic, and decision-making.
- **Behavior Trees (BT):**  
  Modular system composed of:
  - `ActionNode`  
  - `ConditionNode`  
  - `SequenceNode`  
  - `SelectorNode`  
  Combine nodes freely to design complex agent behaviors.
- **A\* Pathfinding:**  
  Efficient grid-based navigation supporting obstacles and dynamic world changes.

---

### ✅ **Level & Tilemap System**
- **Level Management:**  
  Load, save, and switch between levels. Each level contains its own objects and tilemaps.
- **Tilemap:**  
  Provides optimized rendering, collision layers, and AI nav


  
