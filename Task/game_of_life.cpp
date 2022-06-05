#include "game_of_life.h"
#include <iostream>
#include <ctime>

using namespace std;
void game_of_life::next_generation(vector<vector<int>>& matrix)
{
    vector<vector<int>> v;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> empty_vector;
        v.push_back(empty_vector);
        for (int j = 0; j < matrix.size(); j++)
        {
          v[i].push_back(0);
       
        }
    }
   
    
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            int adj = 0;
            if (i != 0)
            {
                if (j != 0)
                {
                    if (matrix[i - 1][j - 1] == 1)
                    {
                        adj++;
                    }
                }
                if (matrix[i - 1][j] == 1)
                {
                    adj++;
                }
                if (j != matrix.size() - 1)
                {
                    if (matrix[i - 1][j + 1] == 1)
                    {
                        adj++;
                    }
                }

            }

            if (j != 0)
            {
                if (matrix[i][j - 1] == 1)
                {
                    adj++;
                }
            }
            if (j != matrix.size() - 1)
            {
                if (matrix[i][j + 1] == 1)
                {
                    adj++;
                }
            }
            
            if (i != matrix.size() - 1)
            {
                if (j != 0)
                {
                    if (matrix[i + 1][j - 1] == 1)
                    {
                        adj++;
                    }
                }
                if (matrix[i + 1][j] == 1)
                {
                    adj++;
                }
                if (j != matrix.size() - 1)
                {
                    if (matrix[i + 1][j + 1] == 1)
                    {
                        adj++;
                    }
                }
            }
           
            // gamerules 
            if (matrix[i][j] == 1)
            {
                if (adj == 2 || adj == 3)
                {
                    v[i][j] = 1;
                }
                else
                {
                    v[i][j] = 0;
                }
            }
            if (matrix[i][j] == 0)
            {
                if (adj == 3)
                {
                    v[i][j] = 1;
                }
                else
                {
                    v[i][j] = 0;
                }
            }
        }
       
    }
    matrix = v;
}

void game_of_life::draw(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                cout << "#" << " ";
            }
            else if (matrix[i][j]== 0)
            {
                cout << " " << " ";
            }
        }

        cout << endl;

    }
}

vector<vector<int>> game_of_life::generateMatrix(int columns, int rows)
{
    srand(time(nullptr));
    vector<vector<int>> matrix;


    for (int i = 0; i < rows; i++)
    {
        vector<int> empty_vector;
        matrix.push_back(empty_vector);
        for (int j = 0; j < columns; j++)
        {
            int x = rand() % 100 + 1;
            if (x <= 25)
            {
                matrix[i].push_back(1);
            }
            else 
            {
                matrix[i].push_back(0);
            }
           
        }
    }
    return matrix;
}