#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct Football_Score_Str
{
    int Score_Left = 0;
    int Score_Up = 0;
};

void Manger_Football_Func();
void Input_Command_Count(int* Commands_Count);
void Input_Football_Mass(Football_Score_Str* Football_Mass, int Mass_Count);
void Output_Football_Mass_Triangle(Football_Score_Str* Football_Mass,int Commands_Count);

main()
{
    Manger_Football_Func();
}

void Manger_Football_Func()
{
    int Commands_Count = 0;
    Input_Command_Count(&Commands_Count);

    size_t Mass_Count = Commands_Count * (Commands_Count - 1) / 2 ;

    Football_Score_Str* Football_Mass = NULL;
    Football_Mass =(Football_Score_Str*) calloc(Mass_Count, sizeof(Football_Score_Str));
    assert(Football_Mass != NULL);

    Input_Football_Mass(Football_Mass, Mass_Count);

    Output_Football_Mass_Triangle(Football_Mass, Commands_Count);

    free(Football_Mass);

}

//-------------------------------------------------------------------------

void Input_Command_Count(int* Commands_Count)
{
    printf("Enter amount of teams\n");
    int Flag = scanf("%d", Commands_Count);
}

//-------------------------------------------------------------------------

void Input_Football_Mass(Football_Score_Str* Football_Mass, int Mass_Count)
{
    int Command_1, Command_2;
    int Count_Of_Imput = 1;
    int i = 0;
    while (Count_Of_Imput == 1 || i != Mass_Count  )
    {
        printf("Enter teams numbers\n");
        Count_Of_Imput = scanf("%d %d", &Command_1, &Command_2);

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
}

//-------------------------------------------------------------------------

void Output_Football_Mass_Triangle(Football_Score_Str* Football_Mass,int Commands_Count)
{
    int z = 0;
    printf("\nAll matches scores\n\n");
    printf("\t0\t1\t2\t3\t4\n0");
    int i = 0;
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
}


//куча и стек            \/
 //вывод треуг. таблицы  \/


