#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void play(char chessBoard[3][3], void (*mode)(char chessBoard[3][3]))
{
    char choice[3];
    printf("\"X\"是你的棋子，\"O\"是程序的棋子\n请选择先手（X）或后手（H）：\n");
    while (1)
    {
        fgets(choice, 3, stdin);
        if (strcmp(choice, "x\n") == 0 || strcmp(choice, "X\n") == 0)
        {
            printf("你先手\n");
            while (1)
            {
                player(chessBoard);
                if (judgeWinner(chessBoard, 'X') == 1)
                {
                    printf("你赢了\n");
                    break;
                }
                if (judgeWinner(chessBoard, 'O') == 1)
                {
                    printf("程序赢了\n");
                    break;
                }
                if (heqi(chessBoard) == 1)
                {
                    printf("和棋\n");
                    break;
                }
                (*mode)(chessBoard);
                if (judgeWinner(chessBoard, 'X') == 1)
                {
                    printf("你赢了\n");
                    break;
                }
                if (judgeWinner(chessBoard, 'O') == 1)
                {
                    printf("程序赢了\n");
                    break;
                }
                if (heqi(chessBoard) == 1)
                {
                    printf("和棋\n");
                    break;
                }
            }
            break;
        }
        else if (strcmp(choice, "h\n") == 0 || strcmp(choice, "H\n") == 0)
        {
            printf("程序先手\n");
            while (1)
            {
                (*mode)(chessBoard);
                if (judgeWinner(chessBoard, 'X') == 1)
                {
                    printf("你赢了\n");
                    break;
                }
                if (judgeWinner(chessBoard, 'O') == 1)
                {
                    printf("程序赢了\n");
                    break;
                }
                if (heqi(chessBoard) == 1)
                {
                    printf("和棋\n");
                    break;
                }
                player(chessBoard);
                if (judgeWinner(chessBoard, 'X') == 1)
                {
                    printf("你赢了\n");
                    break;
                }
                if (judgeWinner(chessBoard, 'O') == 1)
                {
                    printf("程序赢了\n");
                    break;
                }
                if (heqi(chessBoard) == 1)
                {
                    printf("和棋\n");
                    break;
                }
            }
            break;
        }
        else
        {
            printf("非法输入!请重新输入选择：\n");
            while (getchar() != '\n')
                ;
        }
    }
}

int judgeWinner(char chessBoard[3][3], char P)
{
    for (int i = 0; i < 3; i++)
    {
        if ((chessBoard[i][0] == P && chessBoard[i][1] == P && chessBoard[i][2] == P) /*行检查*/ || (chessBoard[0][i] == P && chessBoard[1][i] == P && chessBoard[2][i] == P) /*列检查*/)
        {
            return 1;
        }
    }
    if ((chessBoard[0][0] == P && chessBoard[1][1] == P && chessBoard[2][2] == P) /*主对角线检查*/ || (chessBoard[0][2] == P && chessBoard[1][1] == P && chessBoard[2][0] == P) /*副对角线检查*/)
    {
        return 1;
    }
    return 0;
}

int heqi(char chessBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void simpleMode(char chessBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[i][j] == ' ')
            {
                chessBoard[i][j] = 'O';
                if (judgeWinner(chessBoard, 'O') == 1)
                {
                    listChessBoard(chessBoard);
                    printf("程序落子在(%d,%d)\n", i + 1, j + 1);
                    system("pause");
                    return;
                }
                else
                {
                    chessBoard[i][j] = ' ';
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[i][j] == ' ')
            {
                chessBoard[i][j] = 'X';
                if (judgeWinner(chessBoard, 'X') == 1)
                {
                    chessBoard[i][j] = 'O';
                    listChessBoard(chessBoard);
                    printf("程序落子在(%d,%d)\n", i + 1, j + 1);
                    system("pause");
                    return;
                }
                else
                {
                    chessBoard[i][j] = ' ';
                }
            }
        }
    }
    int location;
    do
    {
        location = rand() % 9;
    } while (chessBoard[location / 3][location % 3] != ' ');
    chessBoard[location / 3][location % 3] = 'O';
    listChessBoard(chessBoard);
    printf("程序落子在(%d,%d)\n", location / 3 + 1, location % 3 + 1);
    system("pause");
    return;
}

void masterMode(char chessBoard[3][3])
{
    int bestScore = -2;
    int bestRow;
    int bestColumn;
    int score;
    int randnum = rand() % 9;
    int i = randnum;
    do
    {
        if (chessBoard[i / 3][i % 3] == ' ')
        {
            chessBoard[i / 3][i % 3] = 'O';
            score = getscore(chessBoard, 'X', 2, -2);
            if (score > bestScore)
            {
                bestScore = score;
                bestRow = i / 3;
                bestColumn = i % 3;
            }
            chessBoard[i / 3][i % 3] = ' ';
        }
        i++;
        if (i == 9)
        {
            i = 0;
        }
    } while (i != randnum);
    chessBoard[bestRow][bestColumn] = 'O';
    listChessBoard(chessBoard);
    printf("程序落子在(%d,%d)\n", bestRow + 1, bestColumn + 1);
    system("pause");
}

void player(char chessBoard[3][3])
{
    int row, column;
    while (1)
    {
        printf("请输入落子的行数：");
        while ((!scanf("%d", &row)) || getchar() != '\n' || row > 3 || row < 1)
        {
            printf("非法输入!请重新输入：");
            while (getchar() != '\n')
                ;
        }
        printf("请输入落子的列数：");
        while ((!scanf("%d", &column)) || getchar() != '\n' || column > 3 || column < 1)
        {
            printf("非法输入!请重新输入：");
            while (getchar() != '\n')
                ;
        }
        if (chessBoard[row - 1][column - 1] == ' ')
        {
            break;
        }
        printf("这个位置已经有棋子了，请重新输入！\n");
    }
    chessBoard[row - 1][column - 1] = 'X';
    listChessBoard(chessBoard);
    printf("你落子在(%d,%d)\n", row, column);
    system("pause");
}

void listChessBoard(char chessBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", chessBoard[i][j]);
            if (j == 2)
            {
                printf("\n");
            }
            else
            {
                printf("*");
            }
        }
        if (i != 2)
        {
            printf("*****\n");
        }
    }
}

int getscore(char chessBoard[3][3], char player, int X, int O)
{
    int temp;
    int randnum = rand() % 9;
    if (judgeWinner(chessBoard, 'X') == 1)
    {
        return -1;
    }
    if (judgeWinner(chessBoard, 'O') == 1)
    {
        return 1;
    }
    if (heqi(chessBoard) == 1)
    {
        return 0;
    }
    if (player == 'X')
    {
        temp = X;
        int i = randnum;
        do
        {
            if (chessBoard[i / 3][i % 3] == ' ')
            {
                chessBoard[i / 3][i % 3] = 'X';
                temp = getscore(chessBoard, 'O', X, O);
                X = X > temp ? temp : X;
                chessBoard[i / 3][i % 3] = ' ';
            }
            if (X < O)
            {
                return X;
            }
            i++;
            if (i == 9)
            {
                i = 0;
            }
        } while (i != randnum);
        return X;
    }
    else
    {
        temp = O;
        int i = randnum;
        do
        {
            if (chessBoard[i / 3][i % 3] == ' ')
            {
                chessBoard[i / 3][i % 3] = 'O';
                temp = getscore(chessBoard, 'X', X, O);
                O = O < temp ? temp : O;
                chessBoard[i / 3][i % 3] = ' ';
            }
            if (X < O)
            {
                return O;
            }
            i++;
            if (i == 9)
            {
                i = 0;
            }
        } while (i != randnum);
        return O;
    }
}