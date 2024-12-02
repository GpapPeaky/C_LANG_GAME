/**
 * @author GpapPeaky
 * 
 * @version 24/12/2023 
 * 
 * @brief A small C - Lang game
*/

/* TODO: ADD ENEMIES ( NUMBERS RANDOMLY AT GENERATED POSITIONS IN THE MAP ) */

#include <iostream>
#include <cstdlib>
#include <time.h>
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

/*____________________________*/

#define SUCCESS 0
#define FAILURE -1

/*____________________________*/

#define MOVE_BEEP 700 /* Move beep c: */

/*____________________________*/

#define MAX_SIZE_X 15
#define MAX_SIZE_Y 25

#ifndef MOVE
#define MOVE

/**
 * @brief Struct that contains a list of maps (TODO)
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

extern int enemy;

/*____________________________*/

extern int rows;
extern int cols;

/*____________________________*/

extern char** map;

/*____________________________*/

/**
 * @brief Generates the enemies
*/
void enemy_gen(void);

/**
 * @brief Intro Jiggle
 * 
 * @param msg 0 INTRO
 *           -1 OUTRO
*/
void jigg(int msg);

/**
 * @brief Exit print
*/
void exit_print(void);

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
