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

void exit_print(void){
printf("        GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     OOOOOOOOO     VVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR   \n");
printf("     GGG$$$$$$$$$$$$G              A$$$A              M$$$$$$$M             M$$$$$$$ME$$$$$$$$$$$$$$$$$$$$E   OO$$$$$$$$$OO   V$$$$$$V           V$$$$$$VE$$$$$$$$$$$$$$$$$$$$ER$$$$$$$$$$$$$$$$R  \n");
printf("   GG$$$$$$$$$$$$$$$G             A$$$$$A             M$$$$$$$$M           M$$$$$$$$ME$$$$$$$$$$$$$$$$$$$$E OO$$$$$$$$$$$$$OO V$$$$$$V           V$$$$$$VE$$$$$$$$$$$$$$$$$$$$ER$$$$$$RRRRRR$$$$$R \n");
printf("  G$$$$$GGGGGGGG$$$$G            A$$$$$$$A            M$$$$$$$$$M         M$$$$$$$$$MEE$$$$$$EEEEEEEEE$$$$EO$$$$$$$OOO$$$$$$$OV$$$$$$V           V$$$$$$VEE$$$$$$EEEEEEEEE$$$$ERR$$$$$R     R$$$$$R\n");
printf(" G$$$$$G       GGGGGG           A$$$$$$$$$A           M$$$$$$$$$$M       M$$$$$$$$$$M  E$$$$$E       EEEEEEO$$$$$$O   O$$$$$$O V$$$$$V           V$$$$$V   E$$$$$E       EEEEEE  R$$$$R     R$$$$$R\n");
printf("G$$$$$G                        A$$$$$A$$$$$A          M$$$$$$$$$$$M     M$$$$$$$$$$$M  E$$$$$E             O$$$$$O     O$$$$$O  V$$$$$V         V$$$$$V    E$$$$$E               R$$$$R     R$$$$$R\n");
printf("G$$$$$G                       A$$$$$A A$$$$$A         M$$$$$$$M$$$$M   M$$$$M$$$$$$$M  E$$$$$$EEEEEEEEEE   O$$$$$O     O$$$$$O   V$$$$$V       V$$$$$V     E$$$$$$EEEEEEEEEE     R$$$$RRRRRR$$$$$R \n");
printf("G$$$$$G    GGGGGGGGGG        A$$$$$A   A$$$$$A        M$$$$$$M M$$$$M M$$$$M M$$$$$$M  E$$$$$$$$$$$$$$$E   O$$$$$O     O$$$$$O    V$$$$$V     V$$$$$V      E$$$$$$$$$$$$$$$E     R$$$$$$$$$$$$$RR  \n");
printf("G$$$$$G    G$$$$$$$$G       A$$$$$A     A$$$$$A       M$$$$$$M  M$$$$M$$$$M  M$$$$$$M  E$$$$$$$$$$$$$$$E   O$$$$$O     O$$$$$O     V$$$$$V   V$$$$$V       E$$$$$$$$$$$$$$$E     R$$$$RRRRRR$$$$$R \n");
printf("G$$$$$G    GGGGG$$$$G      A$$$$$AAAAAAAAA$$$$$A      M$$$$$$M   M$$$$$$$M   M$$$$$$M  E$$$$$$EEEEEEEEEE   O$$$$$O     O$$$$$O      V$$$$$V V$$$$$V        E$$$$$$EEEEEEEEEE     R$$$$R     R$$$$$R\n");
printf("G$$$$$G        G$$$$G     A$$$$$$$$$$$$$$$$$$$$$A     M$$$$$$M    M$$$$$M    M$$$$$$M  E$$$$$E             O$$$$$O     O$$$$$O       V$$$$$V$$$$$V         E$$$$$E               R$$$$R     R$$$$$R\n");
printf(" G$$$$$G       G$$$$G    A$$$$$AAAAAAAAAAAAA$$$$$A    M$$$$$$M     MMMMM     M$$$$$$M  E$$$$$E       EEEEEEO$$$$$$O   O$$$$$$O        V$$$$$$$$$V          E$$$$$E       EEEEEE  R$$$$R     R$$$$$R\n");
printf("  G$$$$$GGGGGGGG$$$$G   A$$$$$A             A$$$$$A   M$$$$$$M               M$$$$$$MEE$$$$$$EEEEEEEE$$$$$EO$$$$$$$OOO$$$$$$$O         V$$$$$$$V         EE$$$$$$EEEEEEEE$$$$$ERR$$$$$R     R$$$$$R\n");
printf("   GG$$$$$$$$$$$$$$$G  A$$$$$A               A$$$$$A  M$$$$$$M               M$$$$$$ME$$$$$$$$$$$$$$$$$$$$E OO$$$$$$$$$$$$$OO           V$$$$$V          E$$$$$$$$$$$$$$$$$$$$ER$$$$$$R     R$$$$$R\n");
printf("     GGG$$$$$$GGG$$$G A$$$$$A                 A$$$$$A M$$$$$$M               M$$$$$$ME$$$$$$$$$$$$$$$$$$$$E   OO$$$$$$$$$OO              V$$$V           E$$$$$$$$$$$$$$$$$$$$ER$$$$$$R     R$$$$$R\n");
printf("        GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE     OOOOOOOOO                 VVV            EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR\n");
}

char** map_gen(){

    srand(time(NULL));

    rows = rand() % MAX_SIZE_X + 5;
    cols = rand() % MAX_SIZE_Y + 5;

    printf("Generated y & x$ %d,%d\n",cols,rows);

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
    printf("\nCOLLECT COINS\nPRESS 'e' TO EXIT\nCOINS COLLECTED$ %d\n",coins);
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

    /* It also delays the output, which somehow makes it prettier... */

    /* Make it so that whenever we click a coin we get a different sound! */

    map[pl.coords.x][pl.coords.y] = ' '; /* Reset the now empty cell */

    if(input == 'w' && output.x > 0 && map[output.x - 1][output.y] != wall){
        Beep(MOVE_BEEP,100); /* After each input, a beep is played */
        output.x--;
    }else if(input == 's' && output.x < rows && map[output.x + 1][output.y] != wall){
        Beep(MOVE_BEEP,100); /* After each input, a beep is played */
        output.x++;
    }else if(input == 'a' && output.y > 0 && map[output.x][output.y - 1] != wall){
        Beep(MOVE_BEEP,100); /* After each input, a beep is played */
        output.y--;
    }else if(input == 'd' && output.y < cols && map[output.x][output.y + 1] != wall){
        Beep(MOVE_BEEP,100); /* After each input, a beep is played */
        output.y++;
    }else if(input == 'e'){
        system("cls");
        exit_print();
        Beep(MOVE_BEEP,1000); /* After each input, a beep is played */
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
