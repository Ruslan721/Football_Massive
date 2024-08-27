#include <stdio.h>

const int Commands_Count = 5;

void Manger_Football_Func();

main()
{
    Manger_Football_Func();
}

void Manger_Football_Func()
{


    /*printf("Enter amount of teams\n");
    int Flag = scanf("%d", &Commands_Count); */

    int Mass_Count = Commands_Count * (Commands_Count - 1) / 2 ;

    int Football_Mass[Mass_Count][2];           //иницил.;  maloc, caloc, free

    int Command_1, Command_2;
    int Flag2 = 1;
    int i = 0;
    while (Flag2 == 1 || i != Mass_Count  )
    {
        printf("Enter teams numbers\n");
        Flag2 = scanf("%d %d", &Command_1, &Command_2);

        if (Command_1 < Command_2)
        {
            Command_1 = Command_1+Command_2;
            Command_2 = Command_1-Command_2;
            Command_1 = Command_1-Command_2;
        }

        printf("Enter score of match between teams %d %d:\n",Command_1, Command_2);
        int Match_Number = Command_1 + Command_2 - 1;
        scanf("%d %d", &Football_Mass[Match_Number][1], &Football_Mass[Match_Number][2]);
        i++;

    }
    printf("\n");
    printf("%d\n", Mass_Count);
    printf("All matches scores\n\n");
    printf("\t0\t1\t2\t3\t4\n0");
    i = 0;
    while (i != Commands_Count - 1)
    {

        printf("\n%d", i + 1);

        for (int j = 0; j <= i; j++)
        {
            printf("\t%d/%d ", Football_Mass[i + j][1], Football_Mass[i + j][2]);
        }
        i++;

    }

}
//куча и стек
 //вывод треуг. таблицы
