#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"




int main() {

        Operation* newjob = NULL; // Lista ligada vazia
        int optionselected = 0;//operation, machine, cycletime;
        int flag; // garantir que nao se faz a mesma opera��o 2x
        do
        {
            if (optionselected == 0){
                optionselected = MainFunction();
            }//s� faz a 1� vez aqui , depois faz no default!
            switch (optionselected)
            {
    
                case 1:
      
                    while (optionselected == 1)
                    {
                        int numberofop, *op;
                        printf("Quantas opera��es ter�?\n");
                        scanf("%d", &numberofop);
                        op = &numberofop;
                        int* index;
                        for(int i=0 ;i<*op;i++){
                             index = &i;
                             newjob = CreateJob(newjob, op, index);
                             if (newjob == NULL) {
                               printf("N�o criou uma nova opera��o , repetir ? Presse 1 para tal! \n");

                             }
                        }
                        printf("Continuar a Inserir ?\n");
                        printf("1-Sim 9-MenuPrincipal 0-Sair \n");
                        scanf( "%d", &optionselected);
                    }
                case 2:
                    while (optionselected == 2)
                    {
                        
                    }
                case 3:
                    while (optionselected == 3)
                    {
                    }
                case 4:
                    while (optionselected == 4)
                    {
                    }
                case 5: 
                    while (optionselected == 5)
                {
                }
                case 6:
                    while (optionselected == 6)
                    {
                        SaveStructToFile(newjob);
                        optionselected = 9;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 7:
                    while (optionselected == 7)
                    {
                        //CRIAR STRUCT A PARTIR DO QUE SE LE NO FICHEIRO
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        optionselected = 9;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 8:
                    while (optionselected == 8)
                    {
                        CheckOperations(newjob);
                        optionselected = 9;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
               default:

                 optionselected = MainFunction();
                    
            }
        } while (optionselected != 0);
        printf("Consola ir� encerrar\n");
        //sleep(1);
        exit(0);

}