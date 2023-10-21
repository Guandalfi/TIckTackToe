#include <iostream>
#include "game_logic.h"


void display_game_grid(int game_grid[3][3])
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


bool is_draw(int game_grid[3][3])
{
    int places_taken = 0;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (game_grid[i][j] != 0)
            {
                places_taken += 1;
            }
            if (places_taken == 9)
            {
                return true;
            }
            
        }
        
    }
    return false;
}


bool is_winner(int game_grid[3][3])
{
    // verify if winner in horizontal lines    
    for (size_t i = 0; i < 3; i++)
    {
        int row[3] = {0,0,0};
        for (size_t j = 0; j < 3; j++)
        {
            if (game_grid[i][j] != 0)
            {
                row[j] = game_grid[i][j];
            }
        }

        for (size_t k = 0; k < 3; k++)
        {
            if (row[0] != 0 && row[0] == row[1] && row[0] == row[2])
            {
                return true;
            }
        }
    }
    
    // verify if winner in vertical lines
    for (size_t i = 0; i < 3; i++)
    {
        int column[3] = {0,0,0};
        for (size_t j = 0; j < 3; j++)
        {
            if (game_grid[j][i] != 0)
            {
                column[j] = game_grid[j][i];
            }
        }

        for (size_t k = 0; k < 3; k++)
        {
            if (column[0] != 0 && column[0] == column[1] && column[0] == column[2])
            {
                return true;
            }
        }
    }

    // verify winner in diagonal line left to right
    for (size_t i = 0; i < 3; i++)
    {
        int diagonal[3];
        if (game_grid[i][i] != 0)
        {
            diagonal[i] = game_grid[i][i];
        }
        for (size_t k = 0; k < 3; k++)
        {
            if (diagonal[0] != 0 && diagonal[0] == diagonal[1] && diagonal[0] == diagonal[2])
            {
                return true;
            }
        }
    }
    
    // verify winner in diagonal line right to left
    int column_pos = 2;
    for (size_t i = 0; i < 3; i++)
    {
        int diagonal[3];
        if (game_grid[i][column_pos] != 0)
        {
            diagonal[i] = game_grid[i][column_pos];
            column_pos--;
        }
        for (size_t k = 0; k < 3; k++)
        {
            if (diagonal[0] != 0 && diagonal[0] == diagonal[1] && diagonal[0] == diagonal[2])
            {
                return true;
            }
        }
    }

    return false;
}