# MazeGeneratorSolver

The goal of this project is to generate mazes (in a reasonable amount of time) and solve them (in a reasonable amount of time)

This project contains three different folders:
  - generator (maze generator)
  - solver (maze solver)
  - csfml (maze solver using the CSFML library)

## Maze generator

<img src="https://i.postimg.cc/XJ0VdNzJ/generator-map.png" alt="alt text" width="25%">

## Maze solver

<img src="https://i.postimg.cc/5tz4XQpT/solver-map.png" alt="alt text">

## CSFML Maze solver

<img src="https://i.postimg.cc/k4F7cr0y/csfml-solver-menu.png" alt="alt text">

<img src="https://i.postimg.cc/7hHwtsDr/csfml-solver-gameplay.png" alt="alt text">

<img src="https://i.postimg.cc/W1Cppwm0/csfml-solved-gameplay.png" alt="alt text">

### Linux Installer

Clone the repository:

    git clone https://github.com/MayaHill/MazeGeneratorSolver.git

Install CSFML

    sudo apt-get install libcsfml-dev libcsfml-doc

To compile (Generator / Solver):

    make
    
To compile (CSFML):

    cd csfml/
    make

## How to play (CSFML)

    ./solver -h

## Launch the game

Generator:

    ./generator/generator [width] [height] [perfect]
    
    (Example: ./generator/generator 10 10 perfect)
    
Solver:

    ./solver/solver [map file]
    
    (Example: ./solver/solver maps/25x25_unsolved_map1.txt)
    
CSFML Solver:

    ./solver [map file]
    
    (Example: ./solver ../maps/25x25_unsolved_map1.txt)

Check you are in the csfml/ folder before trying to launch the CSFML version.

    cd csfml/
