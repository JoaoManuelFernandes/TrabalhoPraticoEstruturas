#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"




int main() {
        setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
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
                case 0:
                    printf("Consola ira encerrar\n");
                    exit(0);
                case 1:
                    while (optionselected == 1)
                    {
                        int numberofop, *op;
                     //   setlocale(LC_ALL, "pt");// caracteres portugues aceites
                        printf("Quantas operacoes tera?\n");
                        scanf("%d", &numberofop);
                        op = &numberofop;
                        int* index;
                        for(int i=0 ;i<*op;i++){
                             index = &i;
                             newjob = CreateJobOnEnd(newjob, op, index);
                             if (newjob == NULL) {
                               printf("Não criou uma nova operacao, repita o processo com valores diferentes de 0 oou 9 para o numero de maquinas!! \n");
                               optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                               break;
                             }
                        }
                        if (newjob != NULL) {
                            printf("\n=============================\n");
                            printf("Processo criado com sucesso!");
                            printf("\n=============================\n");
                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }
                    }
                case 2:
                    while (optionselected == 2)
                    {
                        char decision[1];
                        //   setlocale(LC_ALL, "pt");// caracteres portugues aceites
                        printf("Onde quer inserir a nova operacao? \n[I]- Incio [M]-Meio [F]-Fim\n");
                        scanf("%s", decision);
 
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);

                        if (strcmp(decision, "I") == 0) {
                            newjob_fromfile = CreateJobOnInit(newjob_fromfile);//Struct nula,numero de operaçoes, posição.. 
                            if (newjob_fromfile == NULL) {
                                printf("Valor inserido invalido!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                                break;
                            }
                         
                        }
                        else if (strcmp(decision, "F") == 0) {                          
                            int qt = quantidadeObjetos(newjob_fromfile);

                            int *pointer = &qt;

                            newjob_fromfile = CreateJobOnEnd(newjob_fromfile, 1, pointer);
                            if (newjob_fromfile == NULL) {
                                printf("Valor inserido invalido!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o

                            }

                        }
                        else if (strcmp(decision, "M") == 0) {
                            int pos = 0;
                            printf("qual posicao que pretende?\n");
                            scanf("%d", &pos);
                            newjob_fromfile = insertAtMid(newjob_fromfile, pos-1);//POS -1 PARA UM CORRETA INSERÇÃO!
                            

                            if (newjob_fromfile == NULL) {
                                printf("Valor inserido invalido!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                                break;

                            }
                        }
                        else
                        {
                            printf("Tem de colocar os caracteres que estao disponiveis! [I]- Incio [F]-Fim\n");
                            printf("Repita o processo!\n");
                            //sleep(100);
                            
                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            break;
                        }
                        if (newjob_fromfile != NULL) {


                            bool  resposta = SaveStructToFile(newjob_fromfile);
                            if (resposta == False){ printf("Nao gravou ficheiro!!!\n"); break; optionselected = 11;  }
                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            ReadStructFromFile(newjob_fromfile);
                            printf("\n=============================\n");
                            printf("Operacao criada e guardada com sucesso!");
                            printf("\n=============================\n");
                        }
                    }
                case 3:
                    while (optionselected == 3)
                    {
                        system("cls");
                      
                        
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        //CheckOperations(newjob_fromfile);
                        int qt = quantidadeObjetos(newjob_fromfile);

                        printf("Qual a operacao que deseja eliminar?\n");
                        int aux;
                        scanf("%d", &aux);

                        newjob_fromfile = RemoveAList(newjob_fromfile, aux-1);
                        int qt_aux = quantidadeObjetos(newjob_fromfile);
                        if (qt != qt_aux){
                            system("cls");
                            bool  resposta = SaveStructToFile(newjob_fromfile);
                            if (resposta == False) {
                                printf("Nao gravou ficheiro!!!\n"); break; 
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }

                        }

                        printf("\n=============================\n");
                        printf("Operacao removida e guardada com sucesso!");
                        printf("\n=============================\n");
                        optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        
                    }
                case 4:
                    while (optionselected == 4)
                    {
                        char decision[1];
                        printf("Estrutura atual\n");
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        if (newjob_fromfile == NULL) {
                            printf("ERRO AO LER FICHEIRO !!!\n"); break; optionselected = 11;
                        }


                        printf("Qual e a operacao que pretende efetuar?\n [A]-Alterar um valor ");
                        printf("[R]-Remover uma maquina de uma operacao [N]-Adicionar uma nova maquina na operacao\n");
                        scanf("%s", decision);


                        if (strcmp(decision, "A") == 0) {
                            printf("Qual a operacao que deseja alterar?\n");
                            int op, machine,pos, cycletime;
                            int *op_pointer = &op, *machine_pointer = &machine,*cycletime_pointer=&cycletime;
                            char decision[1];
                            scanf("%d", &op);
                            printf("Deseja alterar maquina ou tempo de ciclo?\n");
                            printf("Seleciona M para maquina ou T para temo de ciclo\n");
                            scanf("%s", decision);

                            if (strcmp(decision,"M") == 0) {

                                printf("Qual e a nova maquina que ira ser inserida?\n");
                                scanf("%d", &machine);
                                printf("Em que posicao se encontra a maquina na lista? Veja pela estrutura!\n");
                                scanf("%d", &pos);
                                if ((machine<0) && (pos < 0)){
                               printf("Maquina ou posicao invalida!");
                                }
                             else {
                                 newjob_fromfile = ModifyAListMachine(newjob_fromfile, op_pointer, machine_pointer, pos - 1);
                                }
                            }

                            else if (strcmp(decision, "T") == 0) {
                                printf("Qual e o novo tempo de ciclo que ira ser inserido?\n");
                                scanf("%d", &cycletime);
                                printf("Em que posicao se encontra o novo tempo de ciclo  na lista? Veja pela estrutura!\n");
                                scanf("%d", &pos);

                               if ((machine > 0 && machine < 9) && (pos > 0 && pos < 9)) {
                                printf("Maquina ou posicao invalida!");
                               }
                               else {
                                 newjob_fromfile = ModifyAListCycleTime(newjob_fromfile, op_pointer, cycletime_pointer, pos - 1);
                                }
                               }

                               else {
                               printf("Nao e uma opcao valida!!");
                               optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                               continue;
                                }
                        }

                        else if(strcmp(decision, "R") == 0){
                            int operation;
                            printf("Qual e a operacao que pretende que tenha uma nova maquina ?\n");
                            scanf("%d", &operation);
                            newjob_fromfile = RemoveMachine(newjob_fromfile, &operation);
                            CheckOperations(newjob_fromfile);

                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }

                        else if (strcmp(decision, "N") == 0) {
                            int operation;
                            printf("Qual e a operacao que pretende que tenha uma nova maquina ?\n");
                            scanf("%d", &operation);
                            newjob_fromfile = AddMachine(newjob_fromfile, &operation);
                            CheckOperations(newjob_fromfile);

                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }

                        else
                        {
                            printf("Nao e uma opcao valida!!");
                            optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                            continue;

                        }



                    if(newjob_fromfile == NULL){
                            printf("Erro ao alterar lista!");
                    }
                    else {
                           bool  resposta = SaveStructToFile(newjob_fromfile);
                           if (resposta == False) {printf("Nao gravou ficheiro!!!\n"); break; optionselected = 11; }
                           ReadStructFromFile(newjob_fromfile);
                            if (strcmp(decision, "N") == 0) {
                               printf("\n=============================\n");
                               printf("Nova maquina adicionada e guardada com sucesso!");
                               printf("\n=============================\n");
                           }
                            if (strcmp(decision, "R") == 0) {
                                printf("\n=============================\n");
                                printf("Nova maquina removida e guardada com sucesso!");
                                printf("\n=============================\n");
                            }

                    }
                     
                    optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 5:
                    while (optionselected == 5)
                    {
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        LessTimeToComplete(newjob_fromfile);
                        optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 6: 
                    while (optionselected == 6)
                {
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        LargerTimeToComplete(newjob_fromfile);
                        optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o

                }
                case 7:
                    while (optionselected == 7)
                    {
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        AllCombinations(newjob_fromfile);
                        optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 8:
                    while (optionselected == 8)
                    {
                        bool res;
                        res = SaveStructToFile(newjob);
                        if (res == True) printf("\nProcesso guardado com sucesso!\n");
                        else {printf("\nErro ao gravar novo processo para ficheiro!\n"); break; optionselected = 11;}
                        optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o

                    }
                case 9:
                    while (optionselected == 9)
                    {
                        //CRIAR STRUCT A PARTIR DO QUE SE LE NO FICHEIRO
                        Operation* newjob_fromfile = NULL; // Lista ligada vazia
                        newjob_fromfile = ReadStructFromFile(newjob_fromfile);
                        if (newjob_fromfile == NULL) {
                            printf("ERRO A LER DO FICHEIRO!");
                            optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                        }
                        optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }

                case 10:
                    while (optionselected == 10)
                    {
                        CheckOperations(newjob);
                        optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }
               default:

                 optionselected = MainFunction();
                    
            }
        } while (optionselected != 0);
}