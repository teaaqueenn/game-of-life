# Game of Life — C++ Implementation

This repository contains a C++ implementation of Conway's Game of Life. The primary objective of this project is to serve as a structured learning exercise in C++ programming, with a focus on object-oriented design, memory management, algorithm development, and modular architecture.

## Project Description

Conway's Game of Life is a well-known cellular automaton devised by mathematician John Conway. It consists of a two-dimensional grid of cells, each of which can be in one of two possible states: alive or dead. The state of each cell evolves over a series of discrete time steps according to a fixed set of rules based on the states of neighboring cells.

This implementation provides an opportunity to explore low-level programming constructs and design patterns within the context of a real-world simulation problem.

## Game Rules

The evolution of the grid follows these standard rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation).
2. Any live cell with two or three live neighbors survives.
3. Any live cell with more than three live neighbors dies (overpopulation).
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

## Objectives

The following objectives guide the development of this project:

- Implement the Game of Life logic using modern C++ (C++17 or later)
- Apply object-oriented principles and design patterns
- Manage dynamic memory safely and efficiently
- Separate interface, logic, and utility modules for clarity and reusability
- Introduce file I/O for loading and saving initial states
- (Optional) Provide a graphical or enhanced terminal interface for simulation display

## Technical Stack

- Language: C++
