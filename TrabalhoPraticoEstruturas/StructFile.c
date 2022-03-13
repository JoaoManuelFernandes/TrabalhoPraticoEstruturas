#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"

int MainFunction()
{
    int optionselected;
    setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites

    printf("\nM E N U\n");
    printf("\nPor favor selecione qual operação pretendida\n");
    printf("1 - Insercao de uma nova operação \n");
    printf("2 - Remover uma operação\n");
    printf("3 - Alterar uma operação\n");
    printf("4 - Deteminar quantidade de tempo minimo para completar um processo\n");
    printf("5 - Deteminar quantidade de tempo máxima para completar um processo\n");
    printf("6 - Armazenar a estrutura\n");
    printf("7 - Carregar o operações presente no ficheiro\n");
    printf("8 - Analisar a estrutura atual\n");
    printf("O - SAIR\n");

    do
    {
        scanf(" %d", &optionselected);
        system("cls");
        //clrscr();
    } while ((optionselected < 0) || (optionselected > 8));

    return(optionselected);

}


struct Job* CreateJob(Operation* newop,int * op,int *index)
{
    //struct Job* newjob = NULL;
    Operation* newjob = (Operation*)malloc(sizeof(Operation));

    if (newjob != NULL) {

        /*int* operation, * machine, * cycletime;*/
        int getmachines, getcycletime;
        //machine = malloc(*op * sizeof(int));
        //cycletime = malloc(*op * sizeof(int));


        const size_t MachinesPerOp;

        printf("Quantas máquinas terá a operação %d ?\n", *index + 1);
        scanf("%d", &MachinesPerOp);
        //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
        newjob->machine = (int*)malloc(MachinesPerOp * sizeof(int) );//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->numberofmachines = MachinesPerOp;
        int h = *index + 1;
        newjob->operation = h;


        for (int x = 0; x < MachinesPerOp; x++) {

                printf("Qual a máquina associada %d ?\n", x + 1);
                scanf("%d", &getmachines);
                newjob->machine[x] = getmachines;

                printf("Qual o tempo de ciclo %d ?\n", x + 1);
                scanf("%d", &getcycletime);
                newjob->cycletime[x] = getcycletime;

                newjob->next = newop;

            }



        printf("Processo foi criado com sucesso!\n");
        return newjob;
    }

    else {
        printf("Alocação de um novo processo falhou!!\n");
        return NULL;

    }
}

void CheckOperations(Operation* newjob)
{
    while (newjob != NULL)
    {
     
        for (int i = 0; i < newjob->numberofmachines; i++)//está estatistico!!
        {
            printf("%p %d %d %d\n", newjob, newjob->operation, newjob->machine[i], newjob->cycletime[i]);
        }
        printf("%p\n", newjob->next);
        newjob = newjob->next;
    }
}

bool SaveStructToFile(Operation* newjob)
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "w"); // w+ Open for  writing.
    
    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }

    fprintf(FileToWrite, "Operação;Máquina;TempoCiclo\n");
    while (newjob != NULL)
    {

        for (int i = 0; i < newjob->numberofmachines; i++)
        {
            printf("%p %d %d %d\n", newjob, newjob->operation, newjob->machine[i], newjob->cycletime[i]);
            fprintf(FileToWrite, "%d;%d;%d\n", newjob->operation, newjob->machine[i], newjob->cycletime[i]);
        }
        printf("%p\n", newjob->next);
        newjob = newjob->next;

        
        
    }
    fclose(FileToWrite);
    return True;
}

struct Job* ReadStructFromFile(Operation* newjob_fromfile)
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .

    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }
    Operation* newjob = (Operation*)malloc(sizeof(Operation));

    if (newjob != NULL) {
        int* MachinesPerOp = (int*)malloc(sizeof(int));
        MachinesPerOp = AuxReadFile(FileToWrite);

        FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .
        int reset = 0;
        int *NumberOfAtualOperation = &reset;
        for(int i = 0 ; i<3 ; i++){//um pouco estático porque nao sei o numero de elementos do array...
            newjob = AuxCreateStruct(&MachinesPerOp[i], FileToWrite, newjob_fromfile,i+1, NumberOfAtualOperation);
            if(i!=0){
            NumberOfAtualOperation = &newjob->operation;
            newjob_fromfile = newjob;
            }   
        }
     fclose(FileToWrite);
 }
    
    return True;
}

int* AuxReadFile(FILE* FileToWrite)
{
    //BASICAMENTE VAMOS LER O NUMERO DE MÁQUINAS POR OPERAÇÃO!

    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    char* aux = (char*)malloc(sizeof(char));
    int* MachinesPerOp = (int*)malloc(sizeof(int));
    int NumberOfAtualOperation = 0;
    int getmachines, getcycletime, count_fistline = 0, count_index = 0;
    int Number_Lines = 1;// nr de linhas lidas


    //enquanto o valor de retorno da função for diferente de nulo , ou seja ainda há "linhas no ficheiro"
    while (fgets(line, line_size, FileToWrite) != NULL) {

        char* pch; // apontador para guardar a "string" que iremos dar split..
        pch = strtok(line, ";");// subdividmos pelos caracter especificado e guardamos tudo no apontador

        while (pch != NULL)
        {

            stdToCompare = pch;

            if (strstr(stdToCompare, "\n") == NULL)//FUNÇÃO QUE RETORNA NULL SE NAO ENCONTRAR O PARAMETRO QUE LHE ENVIAMOS!
            {
                count_fistline++;
                if (Number_Lines == 2 && NumberOfAtualOperation == 0 && count_fistline == 1) {
                    NumberOfAtualOperation = atoi(stdToCompare);
                    MachinesPerOp[count_index] = 1;
                }
                else if (NumberOfAtualOperation == atoi(stdToCompare) && Number_Lines != 1 && count_fistline == 1) {
                    MachinesPerOp[count_index]++;
                }
                else if (NumberOfAtualOperation != atoi(stdToCompare) && Number_Lines != 1 && count_fistline == 1) {

                    NumberOfAtualOperation = atoi(stdToCompare);
                    //printf("Nr de maquinas ===%d\n", MachinesPerOp);//Para depois de tempo ciclo nao termos ";"
                    count_index++;
                    MachinesPerOp[count_index] = 1;
                }

                printf("%s;", pch);
                pch = strtok(NULL, ";");

            }
            else {
                count_fistline = 0;

                printf("%s", pch);//Para depois de tempo ciclo nao termos ";"
                pch = strtok(NULL, ";");
            }
        }

        Number_Lines++;
    }


    stdToCompare = 0;//senao estoura a dar free ... sera por ter \n??
    free(aux);
    free(stdToCompare);
    free(line);

    return MachinesPerOp;
}

struct Job* AuxCreateStruct(int *Machines, FILE* FileToWrite, Operation* newjob_fromfile,int Number_Line, int* NumberOfAtualOperation)
{
    Operation* newjob = (Operation*)malloc(sizeof(Operation));
    int i = *Machines;
    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    int getmachines, getcycletime, count_string_space = 0, count_index = 0;
    int Number_Lines = Number_Line;// nr de linhas lidas

    if (newjob != NULL) {

        newjob->machine = (int*)malloc(*Machines * sizeof(int));//ocupar memoria para o nr de elementos que o lemos pelo txt
        newjob->cycletime = (int*)malloc(*Machines * sizeof(int));//ocupar memoria para o nr de elementos que o lemos pelo txt
        newjob->operation = (int*)malloc(1 * sizeof(int));

        while (fgets(line, line_size, FileToWrite) != NULL) {

            char* pch; // apontador para guardar a "string" que iremos dar split..
            pch = strtok(line, ";");// subdividmos pelos caracter especificado e guardamos tudo no apontador

            while (pch != NULL)
            {
                stdToCompare = pch;

                if (strstr(stdToCompare, "\n") == NULL)//FUNÇÃO QUE RETORNA NULL SE NAO ENCONTRAR O PARAMETRO QUE LHE ENVIAMOS!
                {
                    if (Number_Lines == 2 ){
                        count_string_space++;
                        if (count_string_space == 1) {
                            NumberOfAtualOperation = atoi(stdToCompare);
                            newjob->operation = NumberOfAtualOperation;
                            newjob->numberofmachines = *Machines;
                        }/*
                        for (int i = 0; i < newjob->operation; i++) {*/
                            if (count_string_space == 2) {
                                int aux = atoi(stdToCompare);
                                newjob->machine[count_index] = aux;
                            }
                    }
                //}
                //else if (NumberOfAtualOperation == atoi(stdToCompare) && Number_Lines != 1) {
                //        count_string_space++;
                //        if (count_string_space == 1) {
                //            newjob->operation = atoi(stdToCompare);
                //        }/*
                //        for (int i = 0; i < newjob->operation; i++) {*/
                //        if (count_string_space == 2) {
                //            newjob->machine[Number_Lines-2] = atoi(stdToCompare);
                //        }
                //        if (count_string_space == 3) {
                //            newjob->cycletime[Number_Lines - 2] = atoi(stdToCompare);
                //            count_string_space = 1;
                //        }
                //        //}
                //}
                else if (*NumberOfAtualOperation != atoi(stdToCompare) && Number_Lines != 1 ) {
                        count_string_space++;
                        if (count_string_space == 1) {
                            int aux = atoi(stdToCompare);
                            NumberOfAtualOperation = &aux;
                            newjob->operation = *NumberOfAtualOperation;
                            newjob->numberofmachines = *Machines;
                        }/*
                        for (int i = 0; i < newjob->operation; i++) {*/
                        if (count_string_space == 2) {
                            int aux = atoi(stdToCompare);
                            newjob->machine[count_index] = aux;
                        }
                        if (count_string_space == 3) {
                            int aux = atoi(stdToCompare);
                            newjob->cycletime[count_index] = aux;
                            count_string_space = 1;
                        }
                }
                }
                else if( strstr(stdToCompare, "\n") != NULL && Number_Lines!=1){
                 stdToCompare = strtok(stdToCompare, "\n");
                 int aux = atoi(stdToCompare);
                 newjob->cycletime[count_index] = aux;
                 count_string_space = 1;
                 newjob->next = newjob_fromfile;
                }
                           
                printf("%s;", pch);
                pch = strtok(NULL, ";");
             
            }
            Number_Lines++;
            if (Number_Lines!=1) {
                return newjob;
            }
        }
    }
else {
        return(newjob);
    }
 
}