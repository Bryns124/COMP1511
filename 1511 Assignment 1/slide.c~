// Slide
// slide.c
//
// This program was written by Bryan Le (z5361001)
// on 21/03/2021
//
// Version 1.0.0 (2021-03-08): Initial Assignment Release

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1
#define Y_TOP_ROW 0
#define Y_BOTTOM_ROW 14
#define X_LEFT_COL 0
#define X_RIGHT_COL 14
#define SHIFT 1
#define UP -1
#define DOWN 1
#define SHOOT 2
#define POWER 4
#define TNT_4 4
#define TNT_9 9
#define WIN 0
#define NO_WIN 1
#define SHIFT_LEFT 3
#define ROTATE 4
#define ROTATE_CLOCKWISE_90 1
#define ROTATE_ANTICLOCKWISE_90 2
#define GAME_END 0


void print_map(int map[SIZE][SIZE], int laser_y);
void scan_in_block(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], int laser_y);
int command_line(int laser_y, int x_coordinate, int y_coordinate, int map[SIZE][SIZE]); 
int move_laser(int laser_y, int command_direction);
void shoot_any_block(int laser_y, int x_coordinate, int y_coordinate, int map[SIZE][SIZE]);
int win_checker(int x_coordinate, int y_coordinate, int map[SIZE][SIZE]);
void shoot_tnt(int laser_y, int x_coordinate, int y_coordinate, int map[SIZE][SIZE]);
int shift_left(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], int laser_y);
void rotate_clockwise(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], int array_map_rotated[SIZE][SIZE]);
void rotate_anticlockwise(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], int array_map_rotated[SIZE][SIZE]);
double distance_from_centre(int x_centre, int x_coordinate, int y_centre, int y_coordinate);


int main (void) {

    int map[SIZE][SIZE] = {EMPTY};
    int laser_y = SIZE / 2;
    int x_coordinate = 0;
    int y_coordinate = 0;


    scan_in_block(y_coordinate, x_coordinate, map, laser_y);
    print_map(map, laser_y);
    if (command_line(laser_y, x_coordinate, y_coordinate, map) == GAME_END) {
        return GAME_END;
    }
    
}
// Print out the contents of the map array. 
// Also print out a > symbol to denote the current laser position.
void print_map(int map[SIZE][SIZE], int laser_y) {
    int i = 0;
    while (i < SIZE) {
        if (i == laser_y) {
            printf("> ");
        } else {
            printf("  ");
        }
        int j = 0;
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

//Ask how many blocks to scan in and scan in the number of blocks. Enter the
//blocks of the requested coordinates. The blocks will either be a STONE or
//TNT. If the value of the block_class is one then it is a STONE. If the value
//is between 4 and 9 inclusively, then it is a TNT block. 
void scan_in_block(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], int laser_y) {
    int num_blocks;
    printf("How many blocks? ");
    scanf("%d", &num_blocks);       
    int block_class;
    int blocks_input = 0;
    printf("Enter blocks: \n");
    while (blocks_input < num_blocks) {
        scanf("%d %d %d", &y_coordinate, &x_coordinate, &block_class);
        if (y_coordinate >= Y_TOP_ROW && y_coordinate <= Y_BOTTOM_ROW 
        && x_coordinate >= X_LEFT_COL && x_coordinate <= X_RIGHT_COL) {
            map[y_coordinate][x_coordinate] = (STONE);
        }
        if (y_coordinate >= Y_TOP_ROW && y_coordinate <= Y_BOTTOM_ROW 
        && x_coordinate >= X_LEFT_COL && x_coordinate <= X_RIGHT_COL 
        && block_class >= TNT_4 && block_class <= TNT_9) {
            map[y_coordinate][x_coordinate] = (block_class);
        }
        blocks_input++; 
    }
}

//Store the commands for the game.
//Enter integer between 1 to 4 inclusive to execute command.
int command_line(int laser_y, int x_coordinate, int y_coordinate, int map[SIZE][SIZE]) {
    int rotate_once = 0;
    int command;
    int command_direction;
    while (scanf("%d", &command) == 1) {
        if (command == SHIFT) {
            scanf("%d", &command_direction);
            laser_y = move_laser(laser_y, command_direction);
            
        }
        //Shooting tnt
        x_coordinate = 0;
        if (command == SHOOT) {
            shoot_any_block(laser_y, x_coordinate, y_coordinate, map);
        }
        //End conditions
        if (win_checker(x_coordinate, y_coordinate, map) == WIN) {
            print_map(map, laser_y);
            printf("Game Won!\n");
            return GAME_END;
        }
        //Shifting left
        if (command == SHIFT_LEFT) {
            if (shift_left(y_coordinate, x_coordinate, map, laser_y) == GAME_END) {
                return GAME_END;
            }
        }
        //Rotating clockwise and anticlockwise
        if (command == ROTATE) {
            int array_map_rotated[SIZE][SIZE] = {EMPTY};
            scanf("%d", &command_direction);
            if (command_direction == ROTATE_CLOCKWISE_90 && rotate_once < 1) {
                rotate_clockwise(y_coordinate, x_coordinate, map, array_map_rotated);
                rotate_once++;
                
            }
            if (command_direction == ROTATE_ANTICLOCKWISE_90 && rotate_once < 1) {
                rotate_anticlockwise(y_coordinate, x_coordinate, //nesting
                map, array_map_rotated);
                rotate_once++;
            
            }
        }
        print_map(map, laser_y);
    }
        
    return GAME_END;

}

//Move the laser up or down, depending on user input.
//The laser will move up when -1 is entered and down when 1 is entered.
//Input of any other number is valid and the laser will remain stationary. 
int move_laser(int laser_y, int command_direction) {
    if (command_direction == UP) {
        laser_y--;
        if (laser_y <= Y_TOP_ROW) {
            laser_y = Y_TOP_ROW;
        }
    }
    if (command_direction == DOWN) {
        laser_y++;
        if (laser_y >= SIZE - 1) {
            laser_y = SIZE - 1;
        }
    }
    return laser_y;
}

//Shoot the closest STONE or TNT block the laser is pointing at.
//If the block is a STONE that block and the next three blocks will be 
//destroyed and become EMPTY. If the block is already EMPTY, it will remain
//EMPTY. 
void shoot_any_block(int laser_y, int x_coordinate, int y_coordinate,
                     int map[SIZE][SIZE]) {
    int blocks_destroyed = 0;
    while (x_coordinate < SIZE - 1 && blocks_destroyed < POWER) {
        if (map[laser_y][x_coordinate] >= TNT_4 
        && map[laser_y][x_coordinate] <= TNT_9) {
            shoot_tnt(laser_y, x_coordinate, y_coordinate, map);
            //nesting
            blocks_destroyed = 4;
        }
        if (map[laser_y][x_coordinate] == (STONE)) {
            map[laser_y][x_coordinate] = (EMPTY);
            //nesting
            blocks_destroyed++;
        }
        x_coordinate++;    
    }
}

//Checks the conditions for the game to be won or lost.
//If every block has been checked and there appears to be at least one STONE,
//then the program will return NO_WIN and the game will continue. If every
//block has been checked and there appears to be no STONE left, the game will
//end and a message saying "Game Won!" will appear.
int win_checker(int x_coordinate, int y_coordinate, int map[SIZE][SIZE]) {
    y_coordinate = 0;
    while (y_coordinate < SIZE - 1) {
        x_coordinate = 0;
        while (x_coordinate < SIZE - 1) {
            if (map[y_coordinate][x_coordinate] != (EMPTY)) {
                return NO_WIN;
            }
            x_coordinate++;
        }
        y_coordinate++;
    }
    return WIN;
}

//Calculate the radial distance of the explosion from the TNT as the centre. 
double distance_from_centre(int v_counter, int u_counter, int x_centre, int y_centre) {
    double distance = sqrt(((v_counter - x_centre) * (v_counter - x_centre)) + 
    ((u_counter - y_centre) * (u_counter - y_centre)));
    return distance; 
}

//Contains the values of the TNT and shoots the TNT to create an explosion
//that will destroy surrounding STONEs.
//Area of effect is determined by the position of TNT and magnitude of TNT,
//from 4 to 9 inclusive. Distance of area of effect is calculated by function
//above. 
void shoot_tnt(int laser_y, int x_coordinate, int y_coordinate, int map[SIZE][SIZE]) {
    int x_centre;
    int y_centre;
    int u_counter = 0;
    x_centre = x_coordinate;
    y_centre = laser_y;
    while (u_counter < SIZE) {
        int v_counter = 0;
        while (v_counter < SIZE) {
            if (distance_from_centre(v_counter, u_counter, x_centre, y_centre) < 
            map[y_centre][x_centre] 
            && distance_from_centre(v_counter, u_counter, x_centre, y_centre) != 0) {
                map[u_counter][v_counter] = EMPTY;
            }
            v_counter++;
        }
        u_counter++;
    }
    map[y_centre][x_centre] = EMPTY;
}

//Shift the entire map to the left.
//Once a STONE or TNT block has reached the left-most position, the program
//will end and a message saying "Game Lost!" will appear.
int shift_left(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], int laser_y) {
    y_coordinate = 0;
    while (y_coordinate < SIZE - 1) {
        x_coordinate = 0;
        while (x_coordinate < SIZE - 1) {
            if (map[y_coordinate][x_coordinate + 1] == (STONE) || 
            (map[y_coordinate][x_coordinate + 1] >= 4 
            && map[y_coordinate][x_coordinate + 1] <= 9)) {
                map[y_coordinate][x_coordinate] = map[y_coordinate][x_coordinate + 1];
                map[y_coordinate][x_coordinate + 1] = (EMPTY);
            }
            x_coordinate++;
        }
        y_coordinate++;
        if (map[y_coordinate][0] >= (STONE) && map[y_coordinate][0] <= 9) {
            print_map(map, laser_y);
            printf("Game Lost!\n");
            return GAME_END;
        }
    }
    return 1;
}

//Rotate the map 90º in the anticlockwise direction and stops further rotation.
//A temporary array is created to store the rotated values which will then 
//be replaced back into the original array.
void rotate_clockwise(int y_coordinate, int x_coordinate, int map[SIZE][SIZE], 
                      int array_map_rotated[SIZE][SIZE]) {
    y_coordinate = 0;
    while (y_coordinate < SIZE) {
        x_coordinate = 0;
        while (x_coordinate < SIZE) {
            if (map[y_coordinate][x_coordinate] == (STONE)) {
                array_map_rotated[x_coordinate][SIZE - 1 - y_coordinate] = (STONE);
            }
            if (map[y_coordinate][x_coordinate] == (EMPTY)) {
                array_map_rotated[x_coordinate][SIZE - 1 - y_coordinate] = (EMPTY);
            }
            x_coordinate++;
        }
        y_coordinate++;
    }
    y_coordinate = 0;
    while (y_coordinate < SIZE) {
        x_coordinate = 0;
        while (x_coordinate < SIZE) {
            map[y_coordinate][x_coordinate] 
            = array_map_rotated[y_coordinate][x_coordinate];
            x_coordinate++;
        }
        y_coordinate++;
    }
}

//Rotate the map 90º in the anticlockwise direction and stops further rotation.
//A temporary array is created to store the rotated values which will then 
//be replaced back into the original array.
void rotate_anticlockwise(int y_coordinate, int x_coordinate, 
                          int map[SIZE][SIZE], int array_map_rotated[SIZE][SIZE]) {
    y_coordinate = 0;
    while (y_coordinate < SIZE) {
        x_coordinate = 0;
        while (x_coordinate < SIZE) {
            if (map[y_coordinate][x_coordinate] == (STONE)) {
                array_map_rotated[SIZE - 1 - x_coordinate][y_coordinate] = (STONE);
            }
            if (map[y_coordinate][x_coordinate] == (EMPTY)) {
                array_map_rotated[SIZE - 1 - x_coordinate][y_coordinate] = (EMPTY);
            }
            x_coordinate++;
        }
        y_coordinate++;
    }
    y_coordinate = 0;
    while (y_coordinate < SIZE) {
        x_coordinate = 0;
        while (x_coordinate < SIZE) {
            map[y_coordinate][x_coordinate] 
            = array_map_rotated[y_coordinate][x_coordinate];
            x_coordinate++;
        }
        y_coordinate++;
    }
}
