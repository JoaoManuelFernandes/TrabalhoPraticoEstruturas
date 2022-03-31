#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"

int MainFunction()
{
    int optionselected;
    //setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites


    printf("\n=====================================================================================================");
    printf("\n                                  Joao Fernandes - a14333                                          \n");
    printf("                                  Eng. Eletrotecnica e de Computadores                               \n");
    printf("                                  Estrutura de dados avancadas                                       \n");
    printf("                                  TP1 - Flexible Job Shop Problem                                    \n");
    printf("=====================================================================================================\n");

    printf("\nPor favor selecione qual operação pretendida\n");
    printf("1 - Insercao de um novo processo \n");
    printf("2 - Inserir uma operação\n");
    printf("3 - Remover uma operação\n");
    printf("4 - Alterar uma operação\n");
    printf("5 - Deteminar quantidade de tempo minimo para completar um processo\n");
    printf("6 - Deteminar quantidade de tempo máxima para completar um processo\n");
    printf("7 - Determinar média de tempo entre máquinas da mesma operação\n");
    printf("8 - Armazenar a estrutura\n");
    printf("9 - Carregar o operações presente no ficheiro\n");
    printf("10 - Analisar a estrutura atual\n");
    printf("O - SAIR\n");

    do
    {
        //scanf(" %[^\n]d", &optionselected);

        scanf(" %d", &optionselected);
       system("cls");
        //clrscr();
    } while ((optionselected < 0) || (optionselected > 10));

    return(optionselected);

}

int quantidadeObjetos(Operation* obj)
{
    if (obj != NULL) return(1 + quantidadeObjetos(obj->next)); //recursiva exemplo do stor
    else return(0);
}

struct Job* CreateJobOnFirstTime(Operation* newop)
{
   // setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
    //struct Job* newjob = NULL;
    Operation *newjob = (Operation*)malloc(sizeof(Operation));

    if (newjob != NULL) {

        int getmachines, getcycletime;
        int MachinesPerOp;

        printf("Quantas maquinas tera a operacao %d ?\n", 1);
        scanf("%d", &MachinesPerOp);
        if (MachinesPerOp > 8 || MachinesPerOp == 0) {

            return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
        }
        //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
        newjob->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->numberofmachines = MachinesPerOp;
        newjob->operation = 1;

        for (int x = 0; x < MachinesPerOp; x++) {

            printf("Qual a maquina associada %d ?\n", x + 1);
            scanf("%d", &getmachines);
            if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            newjob->machine[x] = getmachines;
            printf("Qual o tempo de ciclo %d ?\n", x + 1);
            scanf("%d", &getcycletime);
            newjob->cycletime[x] = getcycletime;
            newjob->next = newop;
        }

        printf("Operacao criada com sucesso!\n");
        return newjob;

        }
    else {
        printf("Alocacao de uma nova operacao falhou!!\n");
        return NULL;
    }
}

struct Job* CreateJobOnInit(Operation* newop)
{
    Operation* aux, * newjob = (Operation*)malloc(sizeof(Operation));

    if (newjob != NULL) {

        int getmachines, getcycletime;
        int MachinesPerOp;

        printf("Quantas maquinas tera a operacao %d ?\n", 1);
        scanf("%d", &MachinesPerOp);

        if (MachinesPerOp > 8 || MachinesPerOp == 0) {

            return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
        }
        
        //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
        newjob->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newjob->numberofmachines = MachinesPerOp;
        newjob->operation = 1;

        for (int x = 0; x < MachinesPerOp; x++) {

            printf("Qual a maquina associada %d ?\n", x + 1);
            scanf("%d", &getmachines);
            if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            newjob->machine[x] = getmachines;
            printf("Qual o tempo de ciclo %d ?\n", x + 1);
            scanf("%d", &getcycletime);
            newjob->cycletime[x] = getcycletime;
            newjob->next = newop;
        }

        printf("Operacao criada com sucesso!\n");
        int counter = 0;
        aux = newjob;
        while (newjob !=NULL)
        {
            counter++;
            if(newjob->next !=NULL) newjob->next->operation += 1;
            newjob = newjob->next;
        }
         aux;
        return aux;

    }
    else {
        printf("Alocacao de uma nova operacao falhou!!\n");
        return NULL;
    }


    return NULL;
}  
// para quando já existe uma estrutura  , enquanto a outra é para uma estrutura nula!


struct Job* insertAtMid(Operation* newjob, int pos)
{
    if (newjob != NULL) {

        if (pos == 0)
        {
            return(CreateJobOnInit(newjob));
        }
         
 


      
        else {

            int getmachines, getcycletime;
            int MachinesPerOp, counter = 1, position = pos;

            printf("Quantas maquinas tera a operacao %d ?\n", pos + 1);
            scanf("%d", &MachinesPerOp);
            if (MachinesPerOp > 8 || MachinesPerOp == 0) {

                return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            }


            Operation* anterior = newjob, * proximo = newjob, * novo = (Operation*)malloc(sizeof(Operation));

            int indice = 0;
            int qt = quantidadeObjetos(newjob);

            novo->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            
            while (pos > 1) {
               // if (indice == 0) anterior = proximo; //porque precisamos que o anterior sai com o proximo e o primeiro aponte para o primiero do proximo!
                
                proximo = proximo->next;
                anterior = proximo;
                pos--;
     
            }
            for (int x = 0; x < MachinesPerOp; x++) {
                  proximo = proximo->next;
                 
                  novo->operation = position+1;
                  novo->numberofmachines = MachinesPerOp;
                  printf("Qual a maquina associada %d ?\n", x + 1);
                  scanf("%d", &getmachines);
                  novo->machine[x] = getmachines;
                  if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
                  printf("Qual o tempo de ciclo %d ?\n", x + 1);
                  scanf("%d", &getcycletime);
                  novo->cycletime[x] = getcycletime;
                  novo->next = proximo;
             }
            while (proximo !=NULL)
            {
                proximo->operation = proximo->operation +1;
                proximo = proximo->next;
            }

            anterior->next = novo;
            return(newjob);

        }
    }

    else  return NULL;

}



struct Job* CreateJobOnEnd(Operation* newjob, int* op, int* index)
{
    setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
    Operation* aux = newjob, * novo = (Operation*)malloc(sizeof(Operation));
    if (novo != NULL)
    {
        if (aux == NULL) return(CreateJobOnFirstTime(aux));
        else {

            while (aux->next != NULL)
            aux = aux->next;



            int getmachines, getcycletime;
           int MachinesPerOp;

            printf("Quantas maquinas tera a operacao %d ?\n", *index + 1);
            scanf("%d", &MachinesPerOp);
            if (MachinesPerOp > 8 || MachinesPerOp == 0) {
               return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            }
            //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
            novo->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
            novo->numberofmachines = MachinesPerOp;
            int h = *index + 1;
            novo->operation = h;

            for (int x = 0; x < MachinesPerOp; x++) {

                printf("Qual a maquina associada %d ?\n", x + 1);
                scanf("%d", &getmachines);
                if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
                novo->machine[x] = getmachines;

                printf("Qual o tempo de ciclo %d ?\n", x + 1);
                scanf("%d", &getcycletime);
                novo->cycletime[x] = getcycletime;
               
            }

            novo->next = NULL;
            aux->next = novo;
            printf("Operacao criada com sucesso!\n");
            return(newjob);
        
        }
    }

    else {
    printf("Alocacao de uma nova operacao falhou!!\n");
    return NULL;
}
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


    Operation* aux = (Operation*)malloc(sizeof(Operation));
    aux = newjob;
    //aux = newjob;
    while (newjob !=NULL) {
        
        if (newjob->operation != *operation) {
         newjob = newjob->next;
        continue;
        }
        else {

            newjob->machine[pos] = *newmachine;
            //aux->next = newjob;
            return aux;
        }

    }
    return NULL;
}

struct Job* ModifyAListCycleTime(Operation* newjob, int* operation, int* cycletime, int pos)
{
    Operation* aux = (Operation*)malloc(sizeof(Operation));
    aux = newjob;
    while (newjob != NULL) {

        if (newjob->operation != *operation) { newjob = newjob->next; continue; }
        else {
            newjob->cycletime[pos] = *cycletime;
            return aux;
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
    if (qt == 0) { printf("ERROR\n"); printf("ERROR\n");
    printf("Numero de elementos de listas e nulo, tem de primeiro criar a nossa estrutura clicando 1!\n");
    printf("ERROR\n"); printf("ERROR\n");}

    else{
        printf("%s %s %s \n", "Operacao", "Maquina", "Tempo de ciclo");
        while (newjob != NULL)
        {
     
          /*  for (int i = 0; i < newjob->numberofmachines; i++)
            {
                printf("%p %d %d %d\n", newjob, newjob->operation, newjob->machine[i], newjob->cycletime[i]);
            }
            printf("%p\n", newjob->next);
            newjob = newjob->next;*/
 
            for (int i = 0; i < newjob->numberofmachines; i++)
            { 
                printf("   %d        %d          %d\n", newjob->operation, newjob->machine[i], newjob->cycletime[i]);
            }
            newjob = newjob->next;
        }
    
        printf("\nQuantidade de listas = %d\n", qt );
    }
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


        printf("Maior tempos na operação %d\n", lastoperation);
        printf("Máquina = %d, TempoCiclo = %d\n", bigger_machine, bigger_cycle);

    }
    printf("Soma do tempo máximo = %d\n", sumcycletime);

}

void AllCombinations(Operation* newjob)
{



    if (newjob != NULL) {


        int First_Op_size, cycletime;
        float sum_average;
        while (newjob != NULL) {

            First_Op_size = newjob->numberofmachines;
            sum_average = 0;
            for (int i = 0; i < First_Op_size; i++)
            {
                 cycletime = newjob->cycletime[i];                
                sum_average += cycletime;
                            
            }
            printf("Possibilidade %d ", newjob->operation);
            printf("Média == %.2f\n", (sum_average/ First_Op_size));
            newjob = newjob->next;
        }
    }
    else return NULL;

}

bool SaveStructToFile(Operation* newjob)
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "w"); // w+ Open for  writing.
    
    if (FileToWrite == NULL || newjob == NULL)
    {
        printf("Error!");
        return False;
        fclose(FileToWrite);
    }

    fprintf(FileToWrite, "Operação;Máquina;TempoCiclo\n");
    while (newjob != NULL)
    {

        for (int i = 0; i < newjob->numberofmachines; i++)
        {
            //printf("%p %d %d %d\n", newjob, newjob->operation, newjob->machine[i], newjob->cycletime[i]);
            fprintf(FileToWrite, "%d;%d;%d\n", newjob->operation, newjob->machine[i], newjob->cycletime[i]);
        }
        //printf("%p\n", newjob->next);
        newjob = newjob->next;

        
        
    }
    fclose(FileToWrite);
    return True;
}

struct Job* ReadStructFromFile()
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .

    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }
    Operation* newjob_fromfile = NULL,* newjob = (Operation*)malloc(sizeof(Operation));
    int* MachinesPerOp = (int*)malloc(sizeof(int));
    MachinesPerOp = AuxReadFile(FileToWrite);
    fclose(FileToWrite);

     if (newjob != NULL ) {

        int counter = 0;

        //FILE* FileToWrite_txt;
        //FileToWrite_txt = fopen("NumberOfOperations.txt", "w"); // r Open for both reading .
        //for (int i = 0; i < MachinesPerOp[0] + 1; i++) {//+1 porque temos a a linha do operação..
        //    if (FileToWrite != NULL) {
        //    fprintf(FileToWrite_txt, "%d\n", MachinesPerOp[counter]);
        //    }
        //    counter++;
        //}//THIS

        //fclose(FileToWrite_txt);//THIS
        //FileToWrite_txt = fopen("NumberOfOperations.txt", "r"); // r Open for both reading .//THIS


        counter = 0;
        int auxiliar = 0;
        int numberofoperations = MachinesPerOp[0] + 1;

        int* MachinesPerOp_aux = (int*)malloc(numberofoperations*sizeof(int));
        int *NumberOfAtualOperation = &auxiliar;

        const size_t line_size = 5; // Limita o nr de caracteres a 75!
        char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!

        for (int i = 0; i < numberofoperations; i++) {//+1 porque temos a a linha do operação..
            MachinesPerOp_aux[i] = MachinesPerOp[i];
            printf("MachinesPerOp_aux %d\n", MachinesPerOp_aux[i]);
        }//POrque da problemas se nao for com um array com criado exatamente com o numero exato de elementos......




        FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .
        for(int i = 0 ; i< numberofoperations; i++){//+1 porque temos a a linha do operação..
            //fgets(line, line_size, FileToWrite_txt);
            //
            //line = strtok(line, "\n");// subdividmos pelos caracter especificado e guardamos tudo no apontador
            //int tosend_Machines = atoi(line);
            //if (i == 1) {
            //    counter = 0;
            //    newjob = NULL;
            //}//THIS
   
        
            
            int prms_array = MachinesPerOp_aux[counter];
            printf("prms_array %d\n", prms_array);
            newjob = AuxCreateStruct(prms_array, FileToWrite, newjob_fromfile,i+1, NumberOfAtualOperation);//+1 , porque o primeiro valor é para saber o numero de listas..

            if(i!=0){
                NumberOfAtualOperation = &newjob->operation;
                newjob_fromfile = newjob;
            }   
            counter++;

        }
     //fclose(FileToWrite_txt);//THIS
     fclose(FileToWrite);

     if (newjob !=NULL){
         system("cls");
         newjob =  InvertStruct(newjob);
         CheckOperations(newjob);
     }
     else {
         return NULL;
     }
 }
    
    return newjob;
}

int* AuxReadFile(FILE* FileToWrite)
{
    //BASICAMENTE VAMOS LER O NUMERO DE MÁQUINAS POR OPERAÇÃO!

    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    int* MachinesPerOp = (int*)malloc(sizeof(int));

    int getmachines, getcycletime, count_fistline = 0, count_index = 0, CounterOfLists = 0, Number_Lines = 1, NumberOfAtualOperation = 0;
   

    MachinesPerOp[count_index] = 0; //PORQUE DEPOIS VAI TOMAR O VALOR DE QUANTIDADE DE LISTAS!!!!!!



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
                    count_index++;
                    CounterOfLists++;
                    NumberOfAtualOperation = atoi(stdToCompare);
                    MachinesPerOp[count_index] = 1;

                }
                else if (NumberOfAtualOperation == atoi(stdToCompare) && Number_Lines != 1 && count_fistline == 1) {
                    MachinesPerOp[count_index]++;
                }
                else if (NumberOfAtualOperation != atoi(stdToCompare) && Number_Lines != 1 && count_fistline == 1) {
                    CounterOfLists++;
                    NumberOfAtualOperation = atoi(stdToCompare);
                    count_index++;
                    MachinesPerOp[count_index] = 1;

                }

                pch = strtok(NULL, ";");

            }
            else {
                count_fistline = 0;

                pch = strtok(NULL, ";");
            }
        }

        Number_Lines++;
    }
   
    MachinesPerOp[0] = CounterOfLists;
    stdToCompare = 0;//senao estoura a dar free ... sera por ter \n??
    free(stdToCompare);
    free(line);

    return MachinesPerOp;
}

struct Job* AuxCreateStruct(int Machines, FILE* FileToWrite, Operation* newjob_fromfile,int Number_Line, int* NumberOfAtualOperation)
{


    Operation*aux = newjob_fromfile, *newjob = (Operation*)malloc(sizeof(Operation));
    //printf("MACHINE === %d\n" ,Machines);
    int Control_Cycle = Machines;
    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    int getmachines, getcycletime, count_string_space = 0, count_index = 0;
    int Number_Lines = Number_Line;// nr de linhas lidas
    int var_currenteOp=-1;

    if (newjob != NULL) {

        newjob->machine = (int*)malloc(Machines * sizeof(int));//ocupar memoria para o nr de elementos que o lemos pelo txt
        newjob->cycletime = (int*)malloc(Machines * sizeof(int));//ocupar memoria para o nr de elementos que o lemos pelo txt
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
                            newjob->numberofmachines = Machines;
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
                            newjob->numberofmachines = Machines;
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
                            count_index = 0;
                            int aux = atoi(stdToCompare);
                            NumberOfAtualOperation = &aux;
                            newjob->operation = *NumberOfAtualOperation;
                            newjob->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newjob->operation; i++) {*/
                        if (count_string_space == 2) {
                            int aux = atoi(stdToCompare);
                            newjob->machine[count_index] = aux;
                            var_currenteOp = *NumberOfAtualOperation;
                        }

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
                //printf("%s;", pch);
                pch = strtok(NULL, ";");
             
            }
            Number_Lines++;
            Control_Cycle--;
            if (Number_Lines!=1 && Control_Cycle == 0) {

                return newjob;
            }
        }
    }
else {
        return(newjob);
    }
 
}