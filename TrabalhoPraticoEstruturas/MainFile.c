#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"




int main() {
        setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites
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
                        printf("Quantas operações terá?\n");
                        scanf("%d", &numberofop);
                        op = &numberofop;
                        int* index;
                        for(int i=0 ;i<*op;i++){
                             index = &i;
                             newjob = CreateJobOnEnd(newjob, op, index);
                             if (newjob == NULL) {
                               printf("Não criou uma nova operaçãoo , repetir ? Presse 1 para tal! \n");

                             }
                        }
                        printf("Continuar a Inserir ?\n");
                        printf("1-Sim 10-MenuPrincipal 0-Sair \n");
                        scanf( "%d", &optionselected);
                    }
                case 2:
                    while (optionselected == 2)
                    {
                        system("cls");
                      
                        
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        //CheckOperations(newjob_fromfile);
                        int qt = quantidadeObjetos(newjob_fromfile);

                        printf("Qual a operação que deseja eliminar?\n");
                        int aux;
                        scanf("%d", &aux);

                        newjob_fromfile = RemoveAList(newjob_fromfile, aux);
                        int qt_aux = quantidadeObjetos(newjob_fromfile);
                        if (qt != qt_aux){
                            system("cls");
                            SaveStructToFile(newjob_fromfile);
                        }
                        optionselected = 10;//para ir novamente para o mainfunction e pedir a nova opera��o
                        
                    }
                case 3:
                    while (optionselected == 3)
                    {
                        printf("Estrutura atual\n");
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        printf("Qual a operação que deseja alterar?\n");
                        int op, machine,pos, cycletime;
                        int *op_pointer = &op, *machine_pointer = &machine,*cycletime_pointer=&cycletime;
                        char decision[1];
                        scanf("%d", &op);
                        printf("Deseja alterar máquina ou tempo de ciclo?\n");
                        printf("Seleciona M para máquina ou T para temo de ciclo\n");
                        scanf("%s", decision);
                        if (strcmp(decision,"M") == 0) {
                            printf("Qual é a nova máquina que irá ser inserida?\n");
                            scanf("%d", &machine);
                            printf("Em que posição se encontra a máquina na lista? Veja pela estrutura!\n");
                            scanf("%d", &pos);
                            if ((machine>0 && machine<9) && (pos > 0 && pos < 9)){
                                printf("Máquina ou posição inválida!");
                            }
                            else {
                                newjob_fromfile = ModifyAListMachine(newjob_fromfile, op_pointer, machine_pointer, pos - 1);
                            }
                        }
                        else if (strcmp(decision, "T") == 0) {
                            printf("Qual é o novo tempo de ciclo que irá ser inserido?\n");
                            scanf("%d", &cycletime);
                            printf("Em que posição se encontra o novo tempo de ciclo  na lista? Veja pela estrutura!\n");
                            scanf("%d", &pos);

                            if ((machine > 0 && machine < 9) && (pos > 0 && pos < 9)) {
                                printf("Máquina ou posição inválida!");
                            }
                            else {
                                newjob_fromfile = ModifyAListMachine(newjob_fromfile, op_pointer, cycletime_pointer, pos - 1);
                            }
                            
                         }
                        else {
                            printf("Não é uma opção válida!!");
                            optionselected = 9;// para ir novamente para o mainfunction e pedir a nova opera��o
                            continue;
                        }
                        if(newjob_fromfile == NULL){
                            printf("Erro ao alterar lista!");
                        }
                        else {
                            CheckOperations(newjob_fromfile);
                        }
                     
                    optionselected = 9;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 4:
                    while (optionselected == 4)
                    {
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        LessTimeToComplete(newjob_fromfile);
                        optionselected = 10;//para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 5: 
                    while (optionselected == 5)
                {
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        LargerTimeToComplete(newjob_fromfile);
                        optionselected = 10;//para ir novamente para o mainfunction e pedir a nova opera��o

                }
                case 6:
                    while (optionselected == 6)
                    {
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        AllCombinations(newjob_fromfile);
                        optionselected = 10;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 7:
                    while (optionselected == 7)
                    {

                        SaveStructToFile(newjob);
                        optionselected = 10;// para ir novamente para o mainfunction e pedir a nova opera��o

                       
                    }
                case 8:
                    while (optionselected == 8)
                    {
                        //CRIAR STRUCT A PARTIR DO QUE SE LE NO FICHEIRO
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        optionselected = 10;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }

                case 9:
                    while (optionselected == 9)
                    {
                        CheckOperations(newjob);
                        optionselected = 10;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
               default:

                 optionselected = MainFunction();
                    
            }
        } while (optionselected != 0);
        printf("Consola irá encerrar\n");
        //sleep(1);
        exit(0);

}