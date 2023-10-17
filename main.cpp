#include <iostream>


int display_game_grid(int game_grid[3][3])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (game_grid[i][j] == 1)
            {
                std::cout << "X";
                std::cout << " | ";
            }else if (game_grid[i][j] == 2)
            {
                std::cout << "O";
                std::cout << " | ";
            }else
            {
                std::cout << " ";
                std::cout << " | ";
            }            
        }
        std::cout << std::endl;
    }
}


int main(int argc, char const *argv[])
{   
    int game_grid[3][3] = {
        {0, 0, 0}, //[0][x] linha 0
        {0, 0, 0}, //[1][x] linha 1
        {0, 0, 0}  //[2][x] linha 2
    };
    
    bool playing = true;

    bool player_x = true;
    bool player_o = false;

    while(playing)
    {
        
        display_game_grid(game_grid);
        
        int change; // 1 = 'X'; 2 = 'O'
        int grid_position;
        
        if (player_x)
        {
            std::cout << "Turno do X: ";
            std::cin >> grid_position;
            change = 1;
        }else if (player_o)
        {
            std::cout << "Turno do O: ";
            std::cin >> grid_position;
            change = 2;
        }

        if (grid_position > 9)
        {
            system("cls");
            std::cout << "Digite uma posicao entre 1 e 9 !!!" << std::endl;
            continue;
        }
        
        //int total_elements = sizeof(game_grid) / sizeof(game_grid[0][0]);
        
        int couter = 1;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if (couter == grid_position){
                    if (game_grid[i][j] == 0)
                    {
                        game_grid[i][j] = change;                        
                    }else
                    {
                        system("cls");
                        std::cout << "posicao ja foi jogada" << std::endl;
                        goto try_again;
                    }
                }
                couter++;               
            }
        }

        if (player_x)
        {
            player_o = true;
            player_x = false;
        }else
        {
            player_o = false;
            player_x = true;            
        }
        system("cls");
        try_again:
            continue;
    }
    return 0;
}

