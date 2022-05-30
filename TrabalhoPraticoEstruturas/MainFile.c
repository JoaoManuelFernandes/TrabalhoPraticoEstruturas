#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"

int main() {
        setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
        Operation* newMachine = NULL; // Lista ligada vazia
        int optionselected = 0;//operation, machine, cycletime;
        int flag; // garantir que nao se faz a mesma opera��o 2x
                                //CRIAR STRUCT A PARTIR DO QUE SE LE NO FICHEIRO
        Jobs TotalJobs = NULL, Job = NULL, * TotalJobsAux = (Jobs)malloc(sizeof(struct Job));
        do
        {
            if (optionselected == 0){
                optionselected = MainFunctionFase2();
               
            }//s� faz a 1� vez aqui , depois faz no default!

            switch (optionselected)
            {
                case 0:
                    printf("Consola ira encerrar\n");
                    exit(0);
                case 1:
                    while (optionselected == 1)
                    {

                        //CRIAR STRUCT!
                        TotalJobs = CreateStruct(TotalJobs); //criar estrutura deB jobs 
                        //TotalJobs = InvertStructJob(TotalJobs);
          
                        if (TotalJobs == NULL ) {
                               printf("Não criou um novo Process Plan, repita o processo\n");
                              optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                               break;
                             }
                       

                        if (TotalJobs != NULL ) {
                            printf("\n=============================\n");
                            printf("Process Plan criado com sucesso!");
                            printf("Execute oepracao 3 para guardar em ficheiro!");
                            printf("\n=============================\n");
                           optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }
                    }
                case 2:
                    while (optionselected == 2)
                    {
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        PrintJobsFromFile(&TotalJobs); // printar jobs  
                        optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                    }
                case 3:
                    while (optionselected == 3)
                    {
                        *TotalJobsAux = TotalJobs;
                        bool  res = False;
                        if (TotalJobs != NULL) {
                             res = SaveStructOfJob(*TotalJobsAux);
                        }
                      
                        if (res == False) {
                            printf("Nao foi possivel gravar ficheiro pois este é nulo!!!\n"); 
                            printf("Criou em primeira instancia o Process Plan (operacao 1!)\n");
                            printf("Repita por favor!\n");
                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            break;
                           
                        }

                        else{
                            printf("\n=============================\n");
                            printf("Process Plan guardado com sucesso!");
                            printf("\n=============================\n");
                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }
                        
                    }
                case 4:
                    while (optionselected == 4)
                    {

                        int pos = 0;
                        int numberofop = 0;



                        char decision[1];
                        printf("Estrutura atual\n");

                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        if (TotalJobs == NULL) return(0);
                        if (TotalJobs == NULL) {
                            printf("ERRO AO LER FICHEIRO !!!\n"); break;optionselected = 11;
                        }
                        PrintJobsFromFile(&TotalJobs); // printar jobs  

                        


                        printf("Onde pretende adicionar o novo Job?\n [I]-Adicionar no inicio da estrutura atual");
                        printf("[M]-Adicionar no meio da estrutura atual [F]-Adicionar no fim da estrutura atual\n");
                        scanf("%s", decision);


                        if (strcmp(decision, "I") == 0) {
                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();
                             
                            printf("Quantas operacoes tera o novo job ?\n");
                            scanf("%d", &numberofop);

                            TotalJobs = InvertStructJob(&TotalJobs);
                            TotalJobs = InsertJobOnInit(&TotalJobs, numberofop);//inserir no inicio

                            optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }

                        else if (strcmp(decision, "M") == 0) {
                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();

                            printf("Qual a posicao para o novo job ?\n");
                            scanf("%d", &pos);
                            printf("Quantas operacoes tera o novo job ?\n");
                            scanf("%d", &numberofop);
                        
                            TotalJobs = InvertStructJob(&TotalJobs);
                            TotalJobs = InsertJobOnPos(&TotalJobs, pos - 1, numberofop);//inserir na posição x

                           optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }

                        else if (strcmp(decision, "F") == 0) {

                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();
                            TotalJobs = InvertStructJob(&TotalJobs);
                            printf("Quantas operacoes tera o novo job ?\n");
                            scanf("%d", &numberofop);
                            TotalJobs = InsertJobOnEnd(&TotalJobs, numberofop);//inserir no fim


                           optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }

                        else
                        {
                            printf("Nao e uma opcao valida!!");
                           optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                            continue;

                        }



                        if (TotalJobs == NULL) {
                            printf("Erro ao alterar lista!");
                        }
                        else {

                            *TotalJobsAux = TotalJobs;
                            bool  resposta =  SaveStructOfJob(*TotalJobsAux);

                            if (resposta == False) { printf("Nao gravou ficheiro!!!\n"); break;optionselected = 11; }
                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();

                            if (TotalJobs == NULL) {
                                printf("Nova Estrutura === !!!\n");
                                TotalJobs = ReadStructFromFileToJobs();
                                PrintJobsFromFile(&TotalJobs); // printar jobs  
                            }
                        }
                    }
                case 5:
                    while (optionselected == 5)
                    {         
                        int pos_job = 0,pos_op = 0;
                        int numberofop = 0;

                     
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        int qt = quantidadeJobs(TotalJobs);
                        PrintJobsFromFile(&TotalJobs); // printar jobs  

                        //TotalJobs = NULL;
                        //TotalJobs = ReadStructFromFileToJobs();
                        printf("Em qual Job esta a operacao que pretende alterar?\n");
                        scanf("%d", &pos_job);
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        TotalJobs = InvertStructJob(&TotalJobs);

                        *TotalJobsAux = TotalJobs;
                        Job = SelectJob(*TotalJobsAux, pos_job, qt);

                        bool res = PrintJustAjob(Job);
                        if (res == False) return 0;

                        char decision[1];
                        char _decision[1];
                        printf("Estrutura atual\n");

                       /* TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();*/

                        if (TotalJobs == NULL) {
                            printf("ERRO AO LER FICHEIRO !!!\n"); break; optionselected = 11;
                        }
                        //PrintJobsFromFile(TotalJobs); // printar jobs  

                     
                        printf("Qual a operacao que pretende alterar?\n");
                        scanf("%d", &pos_op);


                        printf("O que pretende efetuar?\n [A]-Alterar um valor ");
                        printf("[R]-Remover uma maquina de uma operacao [N]-Adicionar uma nova maquina na operacao\n");
                        scanf("%s", decision);

                        if (strcmp(decision, "A") == 0) {
                            printf("Deseja alterar maquina ou tempo de ciclo?\n");
                            printf("Seleciona M para maquina ou T para temo de ciclo\n");
                            scanf("%s", _decision);
                            Jobs TotalJobs_temp = NULL;
                            TotalJobs = ReadStructFromFileToJobs();
                            TotalJobs = InvertStructJob(&TotalJobs);
                            TotalJobs_temp = RemoveAJob(&TotalJobs, pos_op);
                            Job = Edit_Op_OnJob(&Job, decision, pos_op, _decision);

                            TotalJobs = InsertJobOnPos_FromOp(&TotalJobs_temp, &Job, pos_job - 1);
                        }

                        else if (strcmp(decision, "R") == 0) {
                            TotalJobs = ReadStructFromFileToJobs();
                            TotalJobs = InvertStructJob(&TotalJobs);
                            TotalJobs = RemoveAJob(&TotalJobs, pos_job);
                            Job = Edit_Op_OnJob(&Job, decision, pos_op, "");
                            if (Job == NULL)
                            {
                                return 0;
                                optionselected = 11;
                            }
                            TotalJobs = InsertJobOnPos_FromOp(&TotalJobs, &Job, pos_job - 1);

                        }

                        else if (strcmp(decision, "N") == 0) {
                            TotalJobs = ReadStructFromFileToJobs();
                            TotalJobs = InvertStructJob(&TotalJobs);
                            TotalJobs = RemoveAJob(&TotalJobs, pos_job);
                            Job = Edit_Op_OnJob(&Job, decision, pos_op, "");
                            if (Job == NULL)
                            {
                                optionselected = 11;
                                return 0;
                                
                            }

                            TotalJobs = InsertJobOnPos_FromOp(&TotalJobs, &Job, pos_job - 1);
                        }

                        else
                        {
                            printf("Opcao inválida!!\n Recomece tudo de novo!");
                            optionselected = 11;
                            break;
                        }

                    
                        if (TotalJobs != NULL) {
                                *TotalJobsAux = TotalJobs;
                               bool  res = SaveStructOfJob(*TotalJobsAux);
                               if (res =True)
                               {
                                   printf("\n=============================\n");
                                   printf("Novo Process Plan alterado e guardado com sucesso!");
                                   printf("\n=============================\n");
                                   optionselected = 11;
                               }
                               else
                               {
                                   printf("ERRO AO GRAVAR PARA FICHEIRO !!!\n"); break; optionselected = 11;
                               }

                        }

                        else
                        {
                            printf("ERRO AO EDITAR O PROCESS PLAN !!!\n"); break; optionselected = 11;
                        }
                    }
                case 6:
                    while (optionselected == 6)
                    {
                        int pos_job = 0, pos = 0;

                        //Remover op from struct

                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        PrintJobsFromFile(&TotalJobs); // printar jobs  
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        printf("Qual o numero do job que pretende remover uma nova operacao?\n");
                        scanf("%d", &pos_job);
                        TotalJobs = InvertStructJob(&TotalJobs);
                        int qt = quantidadeJobs(TotalJobs);
                        *TotalJobsAux = TotalJobs;
                        Job = SelectJob(*TotalJobsAux, pos_job,qt);
                         qt = quantidadeObjetos(Job);
                        bool res = PrintJustAjob(Job);
                        if (res != False) {

                            Job = RemoveANewOp_Job(&Job);

                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();

                            TotalJobs = InvertStructJob(&TotalJobs);
                            //Analisar a partir daqui 
                            //Basicamente tenho de enviar o job total e remover o que esta na posição que utilizador escolheu!
                            TotalJobs = RemoveAJob(&TotalJobs, pos_job);




                            TotalJobs = InsertJobOnPos_FromOp(&TotalJobs, &Job, pos_job - 1);
                            
                        }
                        bool  resposta = False;
                        *TotalJobsAux = TotalJobs;
                        if(TotalJobs != NULL){
                            resposta = SaveStructOfJob(*TotalJobsAux);
                        

                            system("cls");
                            
                         
                            if (resposta == False) {
                                printf("Nao foi possivel gravar ficheiro!\n");
                            }
                            else
                            {
                                printf("\n=============================\n");
                                printf("Process Plan com operacao removida guardado com sucesso!");
                                printf("\n=============================\n");
                            }
                           optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                        }
                        else
                        {
                            printf("Nao foi possivel remover a operacao pretendida!\n");
                            printf("Repita o processo!!\n");
                           optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o

                        }
                        


                    }
                case 7: 
                    while (optionselected == 7)
                {
                       
                        //Função de adicionar uma nova operação
                        //Basicamente, 1º pergunto qual o job pretendido , depois vou a uma função que me retorna apenas esse job
                        //3º vou a uma função que vai adicionar uma nova operação no job(no inicio, meio ou fim) e retorna o job manipulado
                        //4º remover o job da posição do job inicial e noutra função adiciono o novo job!
                        int pos_job = 0;
                        bool res =False;
                        TotalJobs = ReadStructFromFileToJobs();
                        PrintJobsFromFile(&TotalJobs); // printar jobs  
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        printf("Qual o numero do job que pretende adicionar uma nova operacao?\n");
                        scanf("%d", &pos_job);
                        TotalJobs = InvertStructJob(&TotalJobs);
                        int qt = quantidadeJobs(TotalJobs);
                        *TotalJobsAux = TotalJobs;
                        Job = SelectJob(*TotalJobsAux, pos_job,qt);
                        res = PrintJustAjob(Job);
                        if (res != False) {

                            char decision[1];
                            printf("Onde pretende adicionar o novo Job?\n [I]-Adicionar no inicio da estrutura atual");
                            printf("[M]-Adicionar no meio da estrutura atual [F]-Adicionar no fim da estrutura atual\n");
                            scanf("%s", decision);

                            Job = InsertANewOp_Job(&Job, decision);

                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();
                            TotalJobs = InvertStructJob(&TotalJobs);
                            //Analisar a partir daqui 
                            //Basicamente tenho de enviar o job total e remover o que esta na posição que utilizador escolheu!
                            TotalJobs = RemoveAJob(&TotalJobs, pos_job);
                            //aqui tenho de adicionar á lista o novo job já criado na posição escolhida!
                           // TotalJobs = InvertStructJob(TotalJobs);
                            TotalJobs = InsertJobOnPos_FromOp(&TotalJobs, &Job, pos_job - 1);
                            *TotalJobsAux = TotalJobs;
                            if (*TotalJobsAux !=NULL)
                            {
                                SaveStructOfJob(*TotalJobsAux);
                                printf("Adicionado nova operacao e guardado com sucesso!");
                            }
                            else
                            {
                                printf("Não foi possivel gravar o ficheiro pois este era nulo!");
                            }
                            
                        }

                       optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o

                }
                case 8:
                    while (optionselected == 8)
                    {
                        int pos_job = 0, pos = 0;

                        //Remover op from struct

                        TotalJobs = ReadStructFromFileToJobs();
                        PrintJobsFromFile(&TotalJobs); // printar jobs  
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        printf("Qual o numero do job que pretende remover?\n");
                        scanf("%d", &pos_job);
                        TotalJobs = InvertStructJob(&TotalJobs);
                        int qt = quantidadeJobs(TotalJobs);
                        *TotalJobsAux = TotalJobs;
                        Job = SelectJob(*TotalJobsAux, pos_job,qt);
                        bool res = PrintJustAjob(Job);
                        if (res != False) {

                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();
                            TotalJobs = InvertStructJob(&TotalJobs);
                            //Analisar a partir daqui 
                            //Basicamente tenho de enviar o job total e remover o que esta na posição que utilizador escolheu!
                            TotalJobs = RemoveAJob(&TotalJobs, pos_job);
                            *TotalJobsAux = TotalJobs;
                            if (*TotalJobsAux != NULL)
                            {
                                SaveStructOfJob(*TotalJobsAux);
                            }
                            else
                            {
                                printf("Nao foi possivel gravar as alteracoes , algo correu mal!!\n");
                            }
                           

                        }
                        optionselected = 11;// para ir novamente para o mainfunction e pedir a nova opera��o
                    }                  
                case 9:
                    while (optionselected == 9)
                    {
                        *TotalJobsAux = TotalJobs;
                        bool  res = False;
                        if (TotalJobs != NULL) {
                            res = SaveStructOfJobSuppport(*TotalJobsAux);
                        }
                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobsSupport();
                        *TotalJobsAux = TotalJobs;
                        PrintJobs(TotalJobsAux);

                        TotalJobs = ReadStructFromFileToJobsSupport();
                        optionselected = 11;
                    }
                case 10:
                    while (optionselected == 10)
                    {
                        Tree* node1 = NULL,*node2 = NULL, * node3 = NULL, * node4 = NULL, * node5 = NULL, * node6 = NULL, * node7 = NULL, * node8 = NULL;
                        int ** Machine1 = malloc(9 * sizeof* Machine1);
                        int** Machine2 = malloc(9 * sizeof * Machine2);
                        int** Machine3 = malloc(9 * sizeof * Machine3);
                        int** Machine4 = malloc(9 * sizeof * Machine4);
                        int** Machine5 = malloc(9 * sizeof * Machine5);
                        int** Machine6 = malloc(9 * sizeof * Machine6);
                        int** Machine7 = malloc(9 * sizeof * Machine7);
                        int** Machine8 = malloc(9 * sizeof * Machine8);
                        int ** matrixfinal = malloc(100 * sizeof * Machine8);
                        int** matrixfinalop = malloc(100 * sizeof * Machine8);
                        int timer = 0;
                        int machinerunning = 0, cyclenumber = 0;
                        bool _allDone = False;
                        int JobsRunning[] = { 0,0,0,0,0,0,0,0 };
                        int TimePerMachineUsed[8] = { 0,0,0,0,0,0,0,0 };

                        for (int i = 0; i < 100; i++)
                        {
                            matrixfinal[i] = malloc(2 * sizeof * matrixfinal[i]);
                            matrixfinalop[i] = malloc(2 * sizeof * matrixfinalop[i]);
                        }

                        int counter;
                        Tree arrayoftrees[8];

                        for (int i = 0; i < 8; i++)
                        {
                            Machine1[i] = malloc(2 * sizeof * Machine1[i]);
                            Machine2[i] = malloc(2 * sizeof * Machine2[i]);
                            Machine3[i] = malloc(2 * sizeof * Machine3[i]);
                            Machine4[i] = malloc(2 * sizeof * Machine4[i]);
                            Machine5[i] = malloc(2 * sizeof * Machine5[i]);
                            Machine6[i] = malloc(2 * sizeof * Machine6[i]);
                            Machine7[i] = malloc(2 * sizeof * Machine7[i]);
                            Machine8[i] = malloc(2 * sizeof * Machine8[i]);
                        }

                        TotalJobs = NULL;
                        TotalJobs = ReadStructFromFileToJobs();
                        if (TotalJobs == NULL) {
                            optionselected = 10;
                            break;
                        }
                        TotalJobs = InvertStructJob(&TotalJobs);
                        OrganizeMachines(&TotalJobs);
                        *TotalJobsAux = TotalJobs;
                        bool  res = SaveStructOfJob(*TotalJobsAux);
                        if (res == True)
                        {
                            printf("\n=============================\n");
                            printf("Novo Process Plan alterado e guardado com sucesso!");
                            printf("\n=============================\n");

                        }
                        else
                        {
                            printf("ERRO AO GRAVAR PARA FICHEIRO !!!\n"); break; optionselected = 11;
                        }
                        int qtJobs = quantidadeJobs(TotalJobs);


                        for (int j = 0; j < qtJobs; j++) {
                            _allDone = False;
                            //Reset ao arrays com maquinas a serem utilizadas
                            for (int h = 0; h < 8; h++) {
                                JobsRunning[h] = 0;
                            }
                            counter = 0;

                            TotalJobs = NULL;
                            TotalJobs = ReadStructFromFileToJobs();
                            if (TotalJobs == NULL)  {
                                optionselected = 10;
                                break;
                            }
                            TotalJobs = InvertStructJob(&TotalJobs);
                            counter =  LowerTimeValuePerMachine(&TotalJobs,j+1,1, Machine1);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                                continue;;
                            }
                            node1 = TreePerMachine(Machine1, counter);
                            arrayoftrees[0] = *node1;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 2, Machine2);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node2 = TreePerMachine(Machine2, counter);
                            arrayoftrees[1] = *node2;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 3, Machine3);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node3 = TreePerMachine(Machine3, counter);
                            arrayoftrees[2] = *node3;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 4, Machine4);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node4 = TreePerMachine(Machine4, counter);
                            arrayoftrees[3] = *node4;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 5, Machine5);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node5 = TreePerMachine(Machine5, counter);
                            arrayoftrees[4] = *node5;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 6, Machine6);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node6 = TreePerMachine(Machine6, counter);
                            arrayoftrees[5] = *node6;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 7, Machine7);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node7 = TreePerMachine(Machine7, counter);
                            arrayoftrees[6] = *node7;
                            counter = LowerTimeValuePerMachine(&TotalJobs, j + 1, 8, Machine8);
                            if (counter == -1) {
                                printf("Alguma coisa correu mal , volte a refazer o processo!");
                                optionselected = 11;//para ir novamente para o mainfunction e pedir a nova opera��o
                            }
                            node8 = TreePerMachine(Machine8, counter);
                            arrayoftrees[7] = *node8;

                            cyclenumber = 0;
                            for (int i = 0; i < 8; i++) {
                                machinerunning =  Escalonamento(&arrayoftrees[cyclenumber], _allDone, matrixfinal, matrixfinalop, JobsRunning, j+1, cyclenumber + 1, TimePerMachineUsed);
                                printf("Machine = %d, TimerPerMachine = =%d\n",cyclenumber+1, TimePerMachineUsed[cyclenumber]);
                               
                                //int  valoraprintar = matrixfinal[][];
                                //while (valoraprintar > 0 && valoraprintar < 9) {
                                //    printf("Job_%d_Op_%d;", matrixfinalJob[i][j], matrixfinalOp[i][j]);
                                //}
                                if(machinerunning !=0)  JobsRunning[cyclenumber] = machinerunning;
                               
                                cyclenumber++;
                            }
                            //_allDone = True;

                            //Escalonamento(&arrayoftrees[cyclenumber], _allDone, matrixfinal, matrixfinalop, JobsRunning, 0, 0, TimePerMachineUsed);
                        }


                            _allDone = True;

                            Escalonamento(&arrayoftrees[cyclenumber], _allDone, matrixfinal, matrixfinalop, JobsRunning, 0, 0, TimePerMachineUsed);
                            optionselected = 11;

                        }

                   
               default:

                 optionselected = MainFunctionFase2();
                    
            }

        }while (optionselected != 0);

} 

