#include<stdio.h>
#include<stdbool.h>
#define N 4

void print_sol(int [N][N]);
bool isSafe(int [N][N], int, int);
bool SolveNQUtil(int [N][N], int);
bool solveNQ();

void main()
{
    printf("Solution for 4-Queens problem : \n");

    solveNQ();
}

bool solveNQ()
{
    int board[N][N] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    if(SolveNQUtil(board, 0) == false)
    {
        printf("\nSolution Not Found\n");
        return false;
    }

    print_sol(board);
    return true;
}

bool SolveNQUtil(int board[N][N], int col)
{
    if(col >= N)
    {
        return true;
    }

    for(int i = 0 ; i < N ; i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;

            if(SolveNQUtil(board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

bool isSafe(int board[N][N], int row, int col)
{
    for(int i = 0 ; i < col ; i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }

    for(int i = row, j = col ; i >= 0 && j >= 0; i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }

    for(int i = row, j = col ; i < N && j >= 0; i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}

void print_sol(int board[N][N])
{
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(board[i][j])
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}