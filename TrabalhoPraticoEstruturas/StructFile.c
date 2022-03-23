#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"

int MainFunction()
{
    int optionselected;
    //setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites

    printf("\nM E N U\n");
    printf("\nPor favor selecione qual operação pretendida\n");
    printf("1 - Insercao de uma nova operação \n");
    printf("2 - Remover uma operação\n");
    printf("3 - Alterar uma operação\n");
    printf("4 - Deteminar quantidade de tempo minimo para completar um processo\n");
    printf("5 - Deteminar quantidade de tempo máxima para completar um processo\n");
    printf("6 - Determinar todas as combinações entre máquinas\n");
    printf("7 - Armazenar a estrutura\n");
    printf("8 - Carregar o operações presente no ficheiro\n");
    printf("9 - Analisar a estrutura atual\n");
    printf("O - SAIR\n");

    do
    {
        scanf(" %d", &optionselected);
        system("cls");
        //clrscr();
    } while ((optionselected < 0) || (optionselected > 8));

    return(optionselected);

}

int quantidadeObjetos(Operation* obj)
{
    if (obj != NULL) return(1 + quantidadeObjetos(obj->next)); //recursiva exemplo do stor
    else return(0);
}

struct Job* CreateJobOnInit(Operation* newop,int * op,int *index)
{
    //struct Job* newjob = NULL;
    Operation* newjob = (Operation*)malloc(sizeof(Operation));

    if (newjob != NULL) {
        int getmachines, getcycletime;
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

struct Job* CreateJobOnEnd(Operation* newjob, int* op, int* index)
{
    Operation* aux = newjob, * novo = (Operation*)malloc(sizeof(Operation));
    if (novo != NULL)
    {
        if (aux == NULL) return(CreateJobOnInit(aux, op,index));
        else {

            while (aux->next != NULL)
            aux = aux->next;



            int getmachines, getcycletime;
            const size_t MachinesPerOp;

            printf("Quantas máquinas terá a operação %d ?\n", *index + 1);
            scanf("%d", &MachinesPerOp);
            //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
            novo->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->numberofmachines = MachinesPerOp;
            int h = *index + 1;
            novo->operation = h;

            for (int x = 0; x < MachinesPerOp; x++) {

                printf("Qual a máquina associada %d ?\n", x + 1);
                scanf("%d", &getmachines);
                novo->machine[x] = getmachines;

                printf("Qual o tempo de ciclo %d ?\n", x + 1);
                scanf("%d", &getcycletime);
                novo->cycletime[x] = getcycletime;
               
            }

            novo->next = NULL;
            aux->next = novo;
            return(newjob);
        
        }
    }
    else return(newjob);
}

struct Job* RemoveAList(Operation* newjob, int pos)
{
    Operation* atual = newjob, * proximo = newjob;

        if (newjob == NULL) return(newjob);
        else if (pos == 0) {
            newjob = atual->next;
            free(atual);
            return newjob;
        }

        else {
            // encontrar o no que se pretende apagar
            for (int i = 0; atual != NULL && i < pos - 1; i++)
                atual = atual->next;

            // se a variavel pos for maior que o numero de nodes existentes
            if (atual == NULL || atual->next == NULL){

                system("cls");
                setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites
                printf("Posição excede numero de operações disponiveis.\n");
               
                return newjob ;
            }

            // O node atual->next é o que vai ser apagado
            // Apontadr para o proximo node do que foi apagado
            proximo = atual->next->next;

            // Unlink the node from linked list
            free(atual->next); // Free memory

            // Unlink the deleted node from list
            atual->next = proximo;
            return(newjob);

        }
        

}

struct Job* ModifyAListMachine(Operation* newjob, int* operation, int* newmachine, int pos)
{
    while (newjob !=NULL) {
   
        if (newjob->operation != *operation) {
            newjob = newjob->next; 
            continue;
        }
        else {
            newjob->machine[pos] = *newmachine;
            return newjob;
        }

    }
    return NULL;
}

struct Job* ModifyAListCycleTime(Operation* newjob, int* operation, int* cycletime, int pos)
{
    while (newjob != NULL) {

        if (newjob->operation != *operation) { newjob = newjob->next; continue; }
        else {
            newjob->machine[pos] = *cycletime;
            return newjob;
        }

    }
    return NULL;
}

struct Job* InvertStruct(Operation* newjob)
{
  
        // Initialize current, previous and
        // next pointers
    Operation* current = newjob,* prev = NULL, * next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        newjob = prev;

        return newjob;
}


void CheckOperations(Operation* newjob)
{
    int qt = quantidadeObjetos(newjob);
    while (newjob != NULL)
    {
     
        for (int i = 0; i < newjob->numberofmachines; i++)
        {
            printf("%p %d %d %d\n", newjob, newjob->operation, newjob->machine[i], newjob->cycletime[i]);
        }
        printf("%p\n", newjob->next);
        newjob = newjob->next;
    }

    printf("Quantidade de listas = %d\n", qt );
}

void LessTimeToComplete(Operation* newjob)
{
    int minor_cycle, minor_machine, lastoperation,sumcycletime=0;
    system("cls");
    while (newjob != NULL) {
        
        for(int i = 0; i < newjob->numberofmachines;i++){
        
            if (i == 0) {
                minor_cycle = newjob->cycletime[i];
                minor_machine = newjob->machine[i];
                lastoperation = newjob->operation;
            }
            
            else if (minor_cycle > newjob->cycletime[i]) {
                minor_cycle = newjob->cycletime[i];
                minor_machine = newjob->machine[i];
                lastoperation = newjob->operation;
            }
        }
        newjob = newjob->next;
        sumcycletime += minor_cycle;


        printf("Menor tempos na operação %d\n", lastoperation);
        printf("Máquina = %d, TempoCiclo = %d\n", minor_machine, minor_cycle);
       
    }
        printf("Soma do tempo minimo = %d\n", sumcycletime);
   
}

void LargerTimeToComplete(Operation* newjob)
{
    int bigger_cycle, bigger_machine, lastoperation, sumcycletime = 0;
    system("cls");
    while (newjob != NULL) {

        for (int i = 0; i < newjob->numberofmachines; i++) {

            if (i == 0) {
                bigger_cycle = newjob->cycletime[i];
                bigger_machine = newjob->machine[i];
                lastoperation = newjob->operation;
            }

            else if (bigger_cycle < newjob->cycletime[i]) {
                bigger_cycle = newjob->cycletime[i];
                bigger_machine = newjob->machine[i];
                lastoperation = newjob->operation;
            }
        }
        newjob = newjob->next;
        sumcycletime += bigger_cycle;


        printf("Menor tempos na operação %d\n", lastoperation);
        printf("Máquina = %d, TempoCiclo = %d\n", bigger_machine, bigger_cycle);

    }
    printf("Soma do tempo minimo = %d\n", sumcycletime);

}

void AllCombinations(Operation* newjob)
{
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

    if (newjob != NULL ) {

        int* MachinesPerOp = (int*)malloc(sizeof(int));
        MachinesPerOp = AuxReadFile(FileToWrite);

        FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .
        int reset = 0;
        int *NumberOfAtualOperation = &reset;
        for(int i = 0 ; i<4 ; i++){//um pouco estático porque nao sei o numero de elementos do array...
             if (i == 1) {
                reset = 0;
                newjob = NULL;
            }
            
            newjob = AuxCreateStruct(&MachinesPerOp[reset], FileToWrite, newjob_fromfile,i+1, NumberOfAtualOperation);
            if(i!=0){
                NumberOfAtualOperation = &newjob->operation;
                newjob_fromfile = newjob;
            }   
            reset++;

        }
     fclose(FileToWrite);
     system("cls");
     newjob =  InvertStruct(newjob);
     CheckOperations(newjob);
 }
    
    return newjob;
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
    Operation*aux = newjob_fromfile, *newjob = (Operation*)malloc(sizeof(Operation));
    int i = *Machines;
    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    int getmachines, getcycletime, count_string_space = 0, count_index = 0;
    int Number_Lines = Number_Line;// nr de linhas lidas
   long int var_currenteOp=-1;

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
                    }
                //}
                else if (*NumberOfAtualOperation == var_currenteOp && Number_Lines != 1 ) {

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
                            count_index++;
                            newjob->machine[count_index] = aux;
                        }
                        //if (count_string_space == 3) {
                        //    newjob->cycletime[count_index] = atoi(stdToCompare);
                        //    count_string_space = 1;
                        //}
                        //}
                }
                else if (*NumberOfAtualOperation != var_currenteOp && Number_Lines != 1 ) {

                        
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
                            var_currenteOp = *NumberOfAtualOperation;
                        }
                        //if (count_string_space == 3) {
                        //    int aux = atoi(stdToCompare);
                        //    newjob->cycletime[count_index] = aux;
                        //    count_string_space = 1;
                        //}
                }
                }
                else if( strstr(stdToCompare, "\n") != NULL && Number_Lines!=1){
                 stdToCompare = strtok(stdToCompare, "\n");
                 int aux = atoi(stdToCompare);
                 newjob->cycletime[count_index] = aux;
                 count_string_space = 0;
                 newjob->next = newjob_fromfile;
                 var_currenteOp = *NumberOfAtualOperation;
                }
                else {
                    return newjob;
                }
                printf("%s;", pch);
                pch = strtok(NULL, ";");
             
            }
            //if (Number_Lines == 1 ) {
            //    Number_Lines++;
            //    return newjob;
            //}
            Number_Lines++;
            i--;
            if (Number_Lines!=1 && i == 0) {
                return newjob;
            }
        }
    }
else {
        return(newjob);
    }
 
}