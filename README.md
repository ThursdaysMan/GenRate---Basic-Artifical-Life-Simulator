# GenRate -- Basic Artifical Life Simulator
C++ Artifical Life simulator using genetic algorithm

A basic genetic algorithm program using c++ to simulate "Denizens" of a 2D plane who can move in two dimensions and have a limited lifespan in which they can reproduce. This is very much a curiosity/passion project and will likely not be updated frequently.

Each Denizen consists of a genetic code of 7 integers from 1 to 9 which determine:
1. Movement magnitude to the right
2. Movement magnitude to the left
3. Movement magnitude up
4. Movement magnitude down
5. Reproductive chance
6. Chance of multiple offspring [NOT YET IMPLEMENTED] 
7. Life duration

Each Denizen that reproduces passes down part of their genetic structure determined by the RMS of their parents genes plus a random number to simulate mutation.

Each run of the program creates a log of Denizen position and activity in a csv file named "Generation" which is saved in the same folder as the executable.

PLEASE NOTE: RUNNING THIS PROGRAM WILL CREATE A CSV WHICH WILL LIKELY BE OF 40MB OR MORE IN SIZE
___________________________________________________________________

Planned features to add:
- User inputtable time steps
- User inputtable generation sizes
- Behaviours that are not directly linked to the values in the genetic code 
- New behaviours:
    - Chance of multiple offspring
    - Mimicry of seperate behaviours eg. movement
    - Communication 
- Import/export system for world states
- Visual interface for viewing simulations in real time

___________________________________________________________________

Version History
V1.0
  - Time for generations set to 10000 steps
  - Starting Denizens set at 100
  - Number of Denizens capped at 2000
  - Behaviours added:
    - Movement
    - Reproduction
    - Death
