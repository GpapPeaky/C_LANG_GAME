#include "PM_Move.hpp"

int main(void){

    player player;

    map = map_gen();

    player.move = '@'; /* Character to play */
    player.coords.x = 1;
    player.coords.y = 1;

    print_map(map);

    jigg(0);

    while(1){

        player.coords = mov(map,player);
        system("cls");
        update_map(map,player);
        print_map(map);
        print_controls();
    }

    return SUCCESS;
}