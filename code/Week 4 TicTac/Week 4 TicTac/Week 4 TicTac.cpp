// Week 4 TicTac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdlib.h>

#define GRID_SIZE 3

using namespace std;

class Game
{
private:
    char grid[GRID_SIZE][GRID_SIZE];

public:

    void check_for_wins()
    {
        const char* winning_moves[8] = {
            "123",
            "456",
            "789",
            "147",
            "258",
            "369",
            "159",
            "753",
        };

        for (int i = 0; i < 8; i++)
        {
            bool winner = true;
            char previous_grid = '0';
            const char* winning_move = winning_moves[i];

            for (int index = 0; index < 3; index++)
            {
                char character = winning_move[index];
                
                int entered_number = character - '0';
                int grid_space = entered_number - 1;

                int row = grid_space / GRID_SIZE;
                int col = grid_space % GRID_SIZE;

                char grid_char = grid[row][col];
                
                if (previous_grid == '0')
                {
                    previous_grid = grid_char;
                }
                else if (previous_grid == grid_char)
                {
                    continue;
                }
                else
                {
                    winner = false;
                    break;
                }
            }

            if (winner)
            {
                puts("Winner");
                printf("Looks like %c won\n", previous_grid);

                exit(0);
            }
        }
        
    }

    void ask_turn()
    {
        string input;
        
        while (true)
        {
            puts("where you like to play?");
            getline(cin, input);

            if (input != "")
            {
                char entered = input.c_str()[0];

                if (entered >= '1' && entered <= '9')
                {
                    int entered_number = entered - '0';
                    int index = entered_number - 1;

                    int row = index / 3;
                    int col = index % 3;

                    char grid_position = grid[row][col];
                    if (grid_position == 'X' || grid_position == 'O')
                    {
                        puts("That grid position is taken!");
                    }
                    else 
                    {
                        grid[row][col] = 'X';
                        break;
                    }
                }
                else
                {
                    puts("You have to play 1-9");
                }
            }
            else
            {
                puts("You must enter something!");
            }
        }
    }

    void computer_player_turn()
    {
        while (true)
        {
            int computer_choice = (rand() % 9) + 1;

            int row = (computer_choice - 1) / 3;
            int col = (computer_choice - 1) % 3;

            char grid_position = grid[row][col];

            if (grid_position == 'X' || grid_position == '0')
            {
                continue;
            }
            else
            {
                printf("Computer play %d.\n", computer_choice);
                grid[row][col] = '0';
                break;
            }
        }
    }

    void generate_grid()
    {
        int number = 1;
        for (int x = 0; x < GRID_SIZE; x++)
        {
            for (int y = 0; y < GRID_SIZE; y++)
            {
                grid[x][y] = to_string(number).c_str()[0];
                number += 1;
            }
        }
    }

    void show_grid()
    {
        cout << "\n----------------\n";
        for (int x = 0; x < GRID_SIZE; x++)
        {
            cout << "  |  ";
            for (int y = 0; y < GRID_SIZE; y++)
            {
                printf("%c | ", grid[x][y]);
            }
            cout << "\n----------------\n";
        }
    }
    Game()
    {
        generate_grid();
        show_grid();
        check_for_wins();
        while (true)
        {
            ask_turn();
            show_grid();
            check_for_wins();
            computer_player_turn();

            show_grid();
            check_for_wins();
         
        }
        
    }

};


int main(int argc, char *argv[])
{
    Game game;
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
