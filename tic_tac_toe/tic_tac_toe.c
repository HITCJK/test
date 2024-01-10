#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

int main()
{
    srand((unsigned)time(NULL));
    char chessBoard[3][3];
    while (1)
    {
        memset(chessBoard, ' ', sizeof(chessBoard));
        char choice[3];
        printf("请选择你的模式：\n1.简单模式\n2.大师模式（警告：你将无法获胜）\n");
        while (1)
        {
            fgets(choice, 3, stdin);
            if (strcmp(choice, "1\n") == 0)
            {
                play(chessBoard, simpleMode);
                break;
            }
            else if (strcmp(choice, "2\n") == 0)
            {
                play(chessBoard, masterMode);
                break;
            }
            else
            {
                printf("非法输入!请重新输入选择：\n");
                while (getchar() != '\n')
                    ;
            }
        }
        printf("\n是否继续?(Y/N)\n");
        while (1)
        {
            fgets(choice, 3, stdin);
            if (strcmp(choice, "y\n") == 0 || strcmp(choice, "Y\n") == 0)
            {
                break;
            }
            else if (strcmp(choice, "n\n") == 0 || strcmp(choice, "N\n") == 0)
            {
                system("pause");
                exit(0);
            }
            else
            {
                printf("非法输入!请重新输入选择：\n");
                while (getchar() != '\n')
                    ;
            }
        }
    }
    return 0;
}