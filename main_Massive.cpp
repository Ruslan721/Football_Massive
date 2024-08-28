#include <stdio.h>
#include <stdlib.h>

const int Commands_Count = 5;

struct Football_Score_Str
{
    int Score_Left = 0;
    int Score_Up = 0;
};

void Manger_Football_Func();

main()
{
    Manger_Football_Func();
}

void Manger_Football_Func()
{
      /*
    printf("Enter amount of teams\n");
    int Flag = scanf("%d", &Commands_Count); */

    size_t Mass_Count = Commands_Count * (Commands_Count - 1) / 2 ;    //иницил.;  maloc, caloc, free

    Football_Score_Str* Football_Mass =(Football_Score_Str*) calloc(Mass_Count, sizeof(Football_Score_Str));

    int Command_1, Command_2;
    int Flag2 = 1;
    int i = 0;
    while (Flag2 == 1 || i != Mass_Count  )
    {
        printf("Enter teams numbers\n");
        Flag2 = scanf("%d %d", &Command_1, &Command_2);

        if (Command_1 < Command_2)
        {                                           //меняем местами Command_1 и Command_2
            Command_1 = Command_1+Command_2;
            Command_2 = Command_1-Command_2;
            Command_1 = Command_1-Command_2;
        }

        printf("Enter score of match between teams %d %d:\n",Command_1, Command_2);
        int Match_Number = (Command_1-1)*Command_1/2 + Command_2;
        scanf("%d %d", &Football_Mass[Match_Number].Score_Left, &Football_Mass[Match_Number].Score_Up);
        i++;

    }

    int z = 0;
    printf("\n");
    printf("%d\n", Mass_Count);
    printf("All matches scores\n\n");
    printf("\t0\t1\t2\t3\t4\n0");
    i = 0;
    while (i < Commands_Count - 1)
    {

        printf("\n%d", i + 1);

        for (int j = 0; j <= i; j++)
        {
            printf("\t%d/%d ", Football_Mass[z+ i+j].Score_Left, Football_Mass[z+ i + j].Score_Up);

            if (j == i)
            {
                z += j;
            }
        }
        i++;

    }

free(Football_Mass);

}
//куча и стек            \/
 //вывод треуг. таблицы  \/

