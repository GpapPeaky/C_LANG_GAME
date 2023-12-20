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
#include <windows.h>

#define SUCCESS 0
#define FAILURE -1

#define BEEP_HIGH_PITCH 900
#define BEEP_LOW_PITCH 450

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

/*____________________________*/

extern int coins;

/*____________________________*/

extern int rows;
extern int cols;

/*____________________________*/

extern char** map;

/*____________________________*/

/**
 * @brief Makes A Random Beep
 * 
 * @returns A random beep noise, per input 
*/
int random_beep(void);

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
