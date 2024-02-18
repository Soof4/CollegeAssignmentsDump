#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_maze(int n, int *ip) {
    int counter = 0;
    
    for (int i=0 ; i<n ; i++) {
        printf("\n");
        for (int j=0 ; j<n ; j++) {
            printf("%3d", *(ip + counter));
            counter++;
        }
    }
}


int main() {
    srand(time(NULL));
    int i, j;
    int n, current_f_lvl, lowest_f_lvl;
    bool is_there_level_one, is_game_ended, is_round_ended, is_end_reached;
    int lowest_f_coords[2];
    
    printf("N: ");
    scanf("%d", &n);
    
    int maze[n][n];
    int flood_levels[n][n];
    int new_flood_layer[n][n];
    
    is_game_ended = false;
    is_round_ended = true;
    
    // -------- Game logic
    while (!is_game_ended) {
        
        if (is_round_ended) {  // ------ Setup of the new round
            is_round_ended = false;
            is_end_reached = false;
            
            // ---- Create the maze
            for (i=0 ; i<n ; i++) {
                for (j=0 ; j<n ; j++) {
                    maze[i][j] = rand()%2;
                    flood_levels[i][j] = 0;  // set starting flood levels
                }
            }
            maze[0][0] = maze[n-1][n-1] = 1;  // set starting and ending point to 1
            flood_levels[0][0] = 1;  // set the starting point flood level to 1
            
            printf("\n\n\n Labirentin ilk hali:");
            print_maze(n, &maze[0][0]);
        }
        
        
        // ---- Flood the maze (only if there is level 1 flooded cell)
        for (i=0 ; i<n ; i++) {  // reset the new_flood_layer
            for (j=0 ; j<n ; j++) {
                new_flood_layer[i][j] = 0;
            }
        }
        
        for (i=0 ; is_there_level_one && i<n ; i++) {
            for (j=0 ; j<n ; j++) {
                if (maze[i][j] == 1 && flood_levels[i][j] > 0 ) {
                    new_flood_layer[i][j] = 1;  // increase itself
                    
                    // -- Spread
                    if (i+1<n && maze[i+1][j] == 1 && flood_levels[i+1][j] == 0) {
                        new_flood_layer[i+1][j] = 1;
                    }
                    if (j+1<n && maze[i][j+1] == 1 && flood_levels[i][j+1] == 0) {
                        new_flood_layer[i][j+1] = 1;
                    }
                    if (i>0 && maze[i-1][j] == 1 && flood_levels[i-1][j] == 0) {
                        new_flood_layer[i-1][j] = 1;
                    }
                    if (j>0 && maze[i][j-1] == 1 && flood_levels[i][j-1] == 0) {
                        new_flood_layer[i][j-1] = 1;
                    }
                }
            }
        }
        
        // ---- Apply new_flood_layer to flood_levels
        for (i=0 ; i<n ; i++) {
            for (j=0 ; j<n ; j++) {
                flood_levels[i][j] += new_flood_layer[i][j];
            }
        }
        
        // ---- Control if all connected paths are filled
        is_there_level_one = false;
        for (i=0 ; !is_there_level_one && i<n ; i++) {
            for (j=0 ; j<n ; j++) {
                if (flood_levels[i][j] == 1) {
                    is_there_level_one = true;
                    break;
                }
            }
        }
        // ---- Control if end point is reached
        if (flood_levels[n-1][n-1] == 2) {
            is_end_reached = true;
        }
        
        
        if (!is_there_level_one || is_end_reached) {  // if there is no cell left to be filled
        
            // ---- Find the cell with lowest flood level
            lowest_f_lvl = flood_levels[0][0];
            lowest_f_coords[0] = lowest_f_coords[1] = 0;
            
            for (i=0 ; i<n ; i++) {
                for (j=0 ; j<n ; j++) {
                    current_f_lvl = flood_levels[i][j];
                    if (current_f_lvl == 2) {
                        lowest_f_lvl = current_f_lvl;
                        lowest_f_coords[0] = i;
                        lowest_f_coords[1] = j;
                    }
                }
            }
            
            // ---- Calculate the new values
            i = lowest_f_coords[0];
            j = lowest_f_coords[1];
            int last_value = flood_levels[0][0];
            
            while (i+j != 0) {
                
                maze[i][j] = --last_value;
                
                // -- Check the surrounding cells for one higher level of flood
                if (i+1<n && flood_levels[i+1][j] == flood_levels[i][j]+1) {
                    i++;
                }
                else if (j+1<n && flood_levels[i][j+1] == flood_levels[i][j]+1) {
                    j++;
                }
                else if (i>0 && flood_levels[i-1][j] == flood_levels[i][j]+1) {
                    i--;
                }
                else if (j>0 && flood_levels[i][j-1] == flood_levels[i][j]+1) {
                    j--;
                }
            }
            
            printf("\n\n Labirentin son hali:");
            print_maze(n, &maze[0][0]);
            
            // ---- Check if the ending point is reached
            if (flood_levels[n-1][n-1] == 2) {
                printf("\n --> Basarili!\n--------------------");
                is_game_ended = true;
            }
            else {
                is_round_ended = true;
                printf("\n --> Basarisiz..\n--------------------");
            }   
        }
    }
}
