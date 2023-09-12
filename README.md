# PAC_MAN-with-c-and-sfml

This project is an implementation of the classic Pac-Man game using C++ and the SFML library. It includes multiple maze levels, and this README provides an overview of the project structure and key components.

## Maze Levels

The project includes several maze levels represented by arrays:

1. **maze_level_one**
2. **maze_level_two**
3. **maze_level_three**

These variables store the Pac-Man maze layouts, where different numbers represent various elements within the maze:

- 0: Food
- 1: Wall
- 2: Empty cell
- 3: Pac-Man
- 4: Energy food

## Working Copies of Mazes

To facilitate maze manipulation without affecting the original maze, the project uses the following arrays:

4. **maze**: This array holds a copy of the maze corresponding to the current level.

5. **tmp_maze**: Used in the `findpath` function, this array is crucial for pathfinding operations.

## Pathfinding Components

The project utilizes various data structures and arrays for pathfinding:

6. **walk** and **target**: These structures are essential for the `findpath` function, which handles ghost movement.

7. **BFSArray_blinky**, **BFSArray_pinky**, **BFSArray_inky**, and **BFSArray_cludy** with their respective `walk_queue` counterparts: These vectors are employed in the `findpath` function to determine ghost paths.

## Rank Tracking

The project maintains a ranking system using the following data structures:

10. **_rank** (vector of pairs): Responsible for sorting and displaying player rankings based on scores.

11. **_rankq** (map): Ensures that player names are not repeated in the rank list.

## Moving Pac-Man

The project includes functions to control Pac-Man's movement:

- **moving_pacman**: This function moves Pac-Man based on the provided direction (1 for up, 2 for down, 3 for right, 4 for left) and updates the maze accordingly.

- **get_direction**: This function retrieves the user's input for Pac-Man's direction, ensuring that Pac-Man can only move when his position is divisible by 42 (the size of each maze element).

## Ghost Movement

The project uses AI to control the ghost movement, allowing them to chase Pac-Man:

- **gost_follow_pacman_using_ai**: This function is responsible for making Pac-Man lose a life if a ghost catches him. It also handles the AI-driven pathfinding for the ghosts.

Please refer to the source code for more details on the implementation of these functions and the overall structure of the Pac-Man game.

**Note**: This README provides an overview of the project's key components. Detailed explanations and code documentation can be found within the source code files. Enjoy playing Pac-Man!
