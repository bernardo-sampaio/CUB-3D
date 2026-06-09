*This project was created as part of the 42 curriculum by ealbino, bsampaio.*

# Cub3D

## Description

Cub3D is a graphics programming project inspired by the classic game Wolfenstein 3D. Its goal is to introduce fundamental computer graphics concepts through the implementation of a pseudo-3D rendering engine using the **Raycasting** technique.

The program reads a map defined in a `.cub` file, generates a three-dimensional representation of the environment, and allows the player to navigate through the scene using keyboard controls. The project also includes texture rendering, collision detection, and event management through MiniLibX.

### Learning Objectives

* Understand the fundamentals of Raycasting.
* Work with real-time graphics using MiniLibX.
* Handle keyboard and window events.
* Implement configuration file parsing.
* Develop data structures for map representation.
* Apply vector mathematics and computational geometry concepts.

---

## Features

* Parsing and validation of `.cub` map files.
* Pseudo-3D rendering using Raycasting.
* Player movement.
* Camera rotation.
* Wall collision detection.
* Wall texture mapping.
* Program termination through the window close button or ESC key.

---

## Project Structure

```text
.
├── includes/
├── src/
├── textures/
├── maps/
├── libft/
├── minilibx-linux/
├── Makefile
└── README.md
```

---

## Instructions

### Requirements

* GCC
* Make
* MiniLibX
* Linux operating system

### Compilation

```bash
make
```

### Remove object files

```bash
make clean
```

### Full cleanup

```bash
make fclean
```

### Rebuild the project

```bash
make re
```

### Execution

```bash
./cub3D maps/map.cub
```

Replace `maps/map.cub` with the path to the desired map file.

### Controls

| Key | Action           |
| --- | ---------------- |
| W   | Move forward     |
| S   | Move backward    |
| A   | Move left        |
| D   | Move right       |
| ←   | Rotate left      |
| →   | Rotate right     |
| ESC | Exit the program |

---

## Technical Choices

### Raycasting

The rendering engine uses Raycasting to determine which walls are visible to the player and their respective distances, allowing the projection of a three-dimensional environment from a two-dimensional map.

### Parsing

The `.cub` file is validated before execution to ensure:

* Correct texture configuration.
* Valid floor and ceiling color definitions.
* Exactly one player starting position.
* A fully enclosed map surrounded by walls.

### Memory Management

All dynamically allocated resources are properly released before program termination to prevent memory leaks.

---

## Resources

### Documentation

* MiniLibX Documentation
  https://harm-smits.github.io/42docs/libs/minilibx

* Cub3D Guide
  https://harm-smits.github.io/42docs/projects/cub3d

* Lode's Raycasting Tutorial
  https://lodev.org/cgtutor/raycasting.html

* Permadi Raycasting Tutorial
  https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents

* Learn OpenGL (general graphics concepts)
  https://learnopengl.com

### Use of Artificial Intelligence

AI tools were used as educational support during the development of this project for:

* Understanding Raycasting concepts.
* Reviewing algorithms and data structures.
* Learning MiniLibX functions and usage.
* Assisting with documentation interpretation.
* Reviewing and improving project documentation.

No code was copied directly without analysis and adaptation by the authors. All implementation, integration, and validation decisions were made by the project contributors.
