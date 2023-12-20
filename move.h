/**
 * @author GpapPeaky
 * 
 * @version 14/12/2023 
 * 
 * @brief A small C - Lang game
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define SUCCESS 0
#define FAILURE -1

#define MAX_SIZE_X 15
#define MAX_SIZE_Y 25

#ifndef MOVE
#define MOVE

/**
 * @brief Struct that contains a list of maps
*/
typedef struct maps{
    char** map;
    struct maps* next;
}maps;

/**
 * @brief Struct for the character's position
*/
typedef struct position{
    int x;
    int y;
}position;

/**
 * @brief Struct for the player
*/
typedef struct player{
    char move;
    position coords;
}player;

extern int coins;

extern int rows;
extern int cols;

extern char** map;

/**
 * @brief Generates the map
*/
char** map_gen(void);

/**
 * @brief Small control's menu
*/
void print_controls(void);

/**
 * @brief Funtion that updates the map depending on the player's position
 * 
 * @param map Map of the game
 * @param pl Player 
*/
void update_map(char** map,player pl);

/**
 * @brief Prints the map
 * 
 * @param map Map of the game
*/
void print_map(char** map);

/**
 * @brief Reads the players move (from keyboard)
 * 
 * @param map Map of the game
 * @param pl Player (record movements)
 * 
 * @returns The new player coordinates depending of the input
*/
position mov(char** map,player pl);

#endif
