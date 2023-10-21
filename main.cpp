#include <iostream>
#include "game_logic.h"


int main()
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

        if (is_draw(game_grid))
        {
            std::cout << "Empate !!!";
            char reset;
            std::cout << "Deseja continuar jogando ?(y/n): ";
            std::cin >> reset;
            if (reset == 'y')
            {
                system("cls");
                main();
            }
            std::cout << "\nObrigado por jogar, volte novamente !!!";
            return 0;
        }

        int change; // 1 = 'X'; 2 = 'O'
        int grid_position; // player position input
        
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

        int valid_inputs[9] = {1,2,3,4,5,6,7,8,9}; //verify if player input is valid
        bool valid_input = false;
        for (size_t i = 0; i < 9; i++)
        {
            if (grid_position == valid_inputs[i])
            {
                valid_input = true;
                break;
            } 
        }
        if (!valid_input) //if player input not find in valid_inputs
        {
            system("cls");
            std::cout << "Digite uma posicao entre 1 e 9 !!!" << std::endl;
            continue;
        }
        
        int couter = 1;
        bool position_occupied = false; //verify if grid_position is already occupied
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if (couter == grid_position){
                    if (game_grid[i][j] == 0)
                    {
                        game_grid[i][j] = change;
                        position_occupied = true;
                    }                    
                }
                couter++;               
            }
        }
        if (!position_occupied)
        {        
            system("cls");
            std::cout << "posicao ja foi jogada" << std::endl;
            continue;
        }

        if (is_winner(game_grid))
        {
            if (player_x)
            {
                system("cls");
                display_game_grid(game_grid);
                std::cout << "X Venceu !!!" << std::endl;

                char reset;
                std::cout << "Deseja continuar jogando ?(y/n): ";
                std::cin >> reset;
                if (reset == 'y')
                {
                    system("cls");
                    main();
                }
                
            }else
            {
                system("cls");
                display_game_grid(game_grid);
                std::cout << "O Venceu !!!" << std::endl;

                char reset;
                std::cout << "Deseja continuar jogando ?(y/n): ";
                std::cin >> reset;
                if (reset == 'y')
                {
                    system("cls");
                    main();
                }
            }
            std::cout << "\nObrigado por jogar, volte novamente !!!";
            return 0;
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
    }
    std::cout << "\nObrigado por jogar, volte novamente !!!";
    return 0;
}
