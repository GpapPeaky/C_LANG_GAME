/**
 * @author GpapPeaky
 * 
 * @version 20/12/2023 
 * 
 * @brief A small C - Lang ga me
*/

#include "move.h"

char wall = 178;

char** map;

int coins = 0;

int rows;
int cols;

int random_beep(void){
    return BEEP_LOW_PITCH + rand() % BEEP_HIGH_PITCH;
}

char** map_gen(){

    srand(time(NULL));

    rows = rand() % MAX_SIZE_X + 5;
    cols = rand() % MAX_SIZE_Y + 5;

    printf("Generated y & x: %d,%d\n",cols,rows);

    char** map = malloc(rows * sizeof(char*));

    for(int i = 0 ; i < rows ; i++){
        map[i] = malloc(cols * sizeof(char));
    }

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                map[i][j] = wall;
            }else{
                map[i][j] = ' ';
            }
        }
    }

    return map;
}

void print_controls(void){

    printf("mov.C (A SMALL C - LANG GAME)\n");
    printf("\nCOLLECT COINS\nPRESS 'e' TO EXIT\nCOINS COLLECTED: %d\n",coins);
}

void update_map(char** map,player pl){

    map[pl.coords.x][pl.coords.y] = pl.move; /* Update the new cell */

    return;
}

void print_map(char** map){

    for(int j = 0 ; j < rows ; j++){
        for(int i = 0 ; i < cols ; i++){
            printf("%c",map[j][i]);
        }
        printf("\n");
    }

    return;
}

position mov(char** map,player pl){

    position output;
    output = pl.coords;

    char input = _getch();

    Beep(random_beep(),55); /* After each input, a beep is played */
    /* It also delays the output, which somehow makes it prettier... */

    map[pl.coords.x][pl.coords.y] = ' '; /* Reset the now empty cell */

    if(input == 'w' && output.x > 0 && map[output.x - 1][output.y] != wall){
        output.x--;
    }else if(input == 's' && output.x < rows && map[output.x + 1][output.y] != wall){
        output.x++;
    }else if(input == 'a' && output.y > 0 && map[output.x][output.y - 1] != wall){
        output.y--;
    }else if(input == 'd' && output.y < cols && map[output.x][output.y + 1] != wall){
        output.y++;
    }else if(input == 'e'){
        exit(EXIT_SUCCESS);
    }

    return output;
}

int main(void){

    player player;

    map = map_gen();

    player.move = 3;
    player.coords.x = 1;
    player.coords.y = 1;

    print_map(map);

    while(1){

        player.coords = mov(map,player);
        system("cls");
        update_map(map,player);
        print_map(map);
        print_controls();
    }

    return SUCCESS;
}
