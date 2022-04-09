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
    printf("                                  TP1 - Flexible Machine Shop Problem                                    \n");
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

struct Machine* CreateMachineOnFirstTime(Operation* newop)
{
   // setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
    //struct Machine* newMachine = NULL;
    Operation *newMachine = (Operation*)malloc(sizeof(Operation));

    if (newMachine != NULL) {

        int getmachines, getcycletime;
        int MachinesPerOp;

        printf("Quantas maquinas tera a operacao %d ?\n", 1);
        scanf("%d", &MachinesPerOp);
        if (MachinesPerOp > 8 || MachinesPerOp == 0) {

            return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
        }
        //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
        newMachine->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newMachine->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newMachine->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newMachine->numberofmachines = MachinesPerOp;
        newMachine->operation = 1;

        for (int x = 0; x < MachinesPerOp; x++) {

            printf("Qual a maquina associada %d ?\n", x + 1);
            scanf("%d", &getmachines);
            if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            newMachine->machine[x] = getmachines;
            printf("Qual o tempo de ciclo %d ?\n", x + 1);
            scanf("%d", &getcycletime);
            newMachine->cycletime[x] = getcycletime;
            newMachine->next = newop;
        }

        printf("Operacao criada com sucesso!\n");
        return newMachine;

        }
    else {
        printf("Alocacao de uma nova operacao falhou!!\n");
        return NULL;
    }
}

struct Machine* CreateMachineOnInit(Operation* newop)
{
    Operation* aux, * newMachine = (Operation*)malloc(sizeof(Operation));

    if (newMachine != NULL) {

        int getmachines, getcycletime;
        int MachinesPerOp;

        printf("Quantas maquinas tera a operacao %d ?\n", 1);
        scanf("%d", &MachinesPerOp);

        if (MachinesPerOp > 8 || MachinesPerOp == 0) {

            return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
        }
        
        //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
        newMachine->machine = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newMachine->cycletime = (int*)malloc(MachinesPerOp * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newMachine->operation = (int*)malloc(1 * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
        newMachine->numberofmachines = MachinesPerOp;
        newMachine->operation = 1;

        for (int x = 0; x < MachinesPerOp; x++) {

            printf("Qual a maquina associada %d ?\n", x + 1);
            scanf("%d", &getmachines);
            if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            newMachine->machine[x] = getmachines;
            printf("Qual o tempo de ciclo %d ?\n", x + 1);
            scanf("%d", &getcycletime);
            newMachine->cycletime[x] = getcycletime;
            newMachine->next = newop;
        }

        printf("Operacao criada com sucesso!\n");
        int counter = 0;
        aux = newMachine;
        while (newMachine !=NULL)
        {
            counter++;
            if(newMachine->next !=NULL) newMachine->next->operation += 1;
            newMachine = newMachine->next;
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


struct Machine* insertAtMid(Operation* newMachine, int pos)
{
    if (newMachine != NULL) {

        if (pos == 0)
        {
            return(CreateMachineOnInit(newMachine));
        }
         
 


      
        else {

            int getmachines, getcycletime;
            int MachinesPerOp, counter = 1, position = pos;

            printf("Quantas maquinas tera a operacao %d ?\n", pos + 1);
            scanf("%d", &MachinesPerOp);
            if (MachinesPerOp > 8 || MachinesPerOp == 0) {

                return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            }


            Operation* anterior = newMachine, * proximo = newMachine, * novo = (Operation*)malloc(sizeof(Operation));

            int indice = 0;
            int qt = quantidadeObjetos(newMachine);

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
            return(newMachine);

        }
    }

    else  return NULL;

}

struct Machine* CreateMachineOnEnd(Operation* newMachine, int* op, int* index)
{
    setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
    Operation* aux = newMachine, * novo = (Operation*)malloc(sizeof(Operation));
    if (novo != NULL)
    {
        if (aux == NULL) return(CreateMachineOnFirstTime(aux));
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
            return(newMachine);
        
        }
    }

    else {
    printf("Alocacao de uma nova operacao falhou!!\n");
    return NULL;
}
}

struct Machine* RemoveAList(Operation* newMachine, int pos)
{
    Operation* atual = newMachine, * proximo;

        if (newMachine == NULL) return(newMachine);
        else if (pos == 0) {
            newMachine = atual->next;
            free(atual);
            proximo = newMachine;
            while (proximo != NULL) {
                
                proximo->operation = proximo->operation - 1;
                proximo = proximo->next;
            }
            return newMachine;
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
               
                return newMachine ;
            }

            // O node atual->next é o que vai ser apagado
            // Apontadr para o proximo node do que foi apagado
            proximo = atual->next->next;

            // Unlink the node from linked list
            free(atual->next); // Free memory

            // Unlink the deleted node from list
            atual->next = proximo;

            while (proximo != NULL) {

                proximo->operation = proximo->operation - 1;
                proximo = proximo->next;
            }

            return(newMachine);

        }
        

}

struct Machine* ModifyAListMachine(Operation* newMachine, int* operation, int* newmachine, int pos)
{


    Operation* aux = (Operation*)malloc(sizeof(Operation));
    aux = newMachine;
    //aux = newMachine;
    while (newMachine !=NULL) {
        
        if (newMachine->operation != *operation) {
         newMachine = newMachine->next;
        continue;
        }
        else {

            newMachine->machine[pos] = *newmachine;
            //aux->next = newMachine;
            return aux;
        }

    }
    return NULL;
}

struct Machine* ModifyAListCycleTime(Operation* newMachine, int* operation, int* cycletime, int pos)
{
    Operation* aux = (Operation*)malloc(sizeof(Operation));
    aux = newMachine;
    while (newMachine != NULL) {

        if (newMachine->operation != *operation) { newMachine = newMachine->next; continue; }
        else {
            newMachine->cycletime[pos] = *cycletime;
            return aux;
        }

    }
    return NULL;
}

struct Machine* InvertStruct(Operation* newMachine)
{
  
        // Initialize current, previous and
        // next pointers
    Operation* current = newMachine,* prev = NULL, * next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        newMachine = prev;

        return newMachine;
}


void CheckOperations(Operation* newMachine)
{
    int qt = quantidadeObjetos(newMachine);
    if (qt == 0) { printf("ERROR\n"); printf("ERROR\n");
    printf("Numero de elementos de listas e nulo, tem de primeiro criar a nossa estrutura clicando 1!\n");
    printf("ERROR\n"); printf("ERROR\n");}

    else{
        printf("%s %s %s \n", "Operacao", "Maquina", "Tempo de ciclo");
        while (newMachine != NULL)
        {
     
          /*  for (int i = 0; i < newMachine->numberofmachines; i++)
            {
                printf("%p %d %d %d\n", newMachine, newMachine->operation, newMachine->machine[i], newMachine->cycletime[i]);
            }
            printf("%p\n", newMachine->next);
            newMachine = newMachine->next;*/
 
            for (int i = 0; i < newMachine->numberofmachines; i++)
            { 
                printf("   %d        %d          %d\n", newMachine->operation, newMachine->machine[i], newMachine->cycletime[i]);
            }
            newMachine = newMachine->next;
        }
    
        printf("\nQuantidade de listas = %d\n", qt );
    }
}

void LessTimeToComplete(Operation* newMachine)
{
    int minor_cycle, minor_machine, lastoperation,sumcycletime=0;
    system("cls");
    while (newMachine != NULL) {
        
        for(int i = 0; i < newMachine->numberofmachines;i++){
        
            if (i == 0) {
                minor_cycle = newMachine->cycletime[i];
                minor_machine = newMachine->machine[i];
                lastoperation = newMachine->operation;
            }
            
            else if (minor_cycle > newMachine->cycletime[i]) {
                minor_cycle = newMachine->cycletime[i];
                minor_machine = newMachine->machine[i];
                lastoperation = newMachine->operation;
            }
        }
        newMachine = newMachine->next;
        sumcycletime += minor_cycle;


        printf("Menor tempos na operação %d\n", lastoperation);
        printf("Máquina = %d, TempoCiclo = %d\n", minor_machine, minor_cycle);
       
    }
        printf("Soma do tempo minimo = %d\n", sumcycletime);
   
}

void LargerTimeToComplete(Operation* newMachine)
{
    int bigger_cycle, bigger_machine, lastoperation, sumcycletime = 0;
    system("cls");
    while (newMachine != NULL) {

        for (int i = 0; i < newMachine->numberofmachines; i++) {

            if (i == 0) {
                bigger_cycle = newMachine->cycletime[i];
                bigger_machine = newMachine->machine[i];
                lastoperation = newMachine->operation;
            }

            else if (bigger_cycle < newMachine->cycletime[i]) {
                bigger_cycle = newMachine->cycletime[i];
                bigger_machine = newMachine->machine[i];
                lastoperation = newMachine->operation;
            }
        }
        newMachine = newMachine->next;
        sumcycletime += bigger_cycle;


        printf("Maior tempos na operação %d\n", lastoperation);
        printf("Máquina = %d, TempoCiclo = %d\n", bigger_machine, bigger_cycle);

    }
    printf("Soma do tempo máximo = %d\n", sumcycletime);

}

void AllCombinations(Operation* newMachine)
{



    if (newMachine != NULL) {


        int First_Op_size, cycletime;
        float sum_average;
        while (newMachine != NULL) {

            First_Op_size = newMachine->numberofmachines;
            sum_average = 0;
            for (int i = 0; i < First_Op_size; i++)
            {
                 cycletime = newMachine->cycletime[i];                
                sum_average += cycletime;
                            
            }
            printf("Possibilidade %d ", newMachine->operation);
            printf("Média == %.2f\n", (sum_average/ First_Op_size));
            newMachine = newMachine->next;
        }
    }
    else return NULL;

}

struct Machine* AddMachine(Operation* newMachine,int* operation)
{
    if (newMachine != NULL) {
        Operation* aux = newMachine;
       

        while (aux !=NULL)
        {
            if (aux->operation == *operation) {

                int *array_aux_machine = (int*)malloc(aux->numberofmachines * sizeof(int));
                int *array_aux_cycle = (int*)malloc(aux->numberofmachines * sizeof(int));
                int numberofmachines = aux->numberofmachines + 1;
                int getmachines, getcycletime;
                for (int i = 0; i < aux->numberofmachines; i++) {

                    array_aux_machine[i] = aux->machine[i];
                    array_aux_cycle[i] = aux->cycletime[i];

                }
                free(aux->machine);
                free(aux->cycletime);
                aux->machine = (int*)malloc(numberofmachines * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
                aux->cycletime = (int*)malloc(numberofmachines * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
                aux->numberofmachines = numberofmachines;

                for (int i = 0; i < numberofmachines; i++) {
                    if(i!= numberofmachines-1){
                        aux->machine[i] = array_aux_machine[i];
                     aux->cycletime[i]= array_aux_cycle[i] ;
                    }
                    else {
                        printf("Qual a maquina associada %d ?\n", i + 1);
                        scanf("%d", &getmachines);
                        if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
                        aux->machine[i] = getmachines;
                        printf("Qual o tempo de ciclo %d ?\n", i + 1);
                        scanf("%d", &getcycletime);
                        aux->cycletime[i] = getcycletime;
                    }
                }

               
                return  newMachine;
            }
            aux = aux->next;

        }





    }
    else return NULL;
    



}

struct Machine* RemoveMachine(Operation* newMachine, int* operation)
{
    if (newMachine != NULL) {
        Operation* aux = newMachine;

        while (aux != NULL)
        {
            if (aux->operation == *operation) {
            

                int* array_aux_machine = (int*)malloc(aux->numberofmachines * sizeof(int));
                int* array_aux_cycle = (int*)malloc(aux->numberofmachines * sizeof(int));
                int numberofmachines = aux->numberofmachines - 1;
                int getmachines, getcycletime;          
                printf("Qual a posicao da maquina que pretende eliminar ?\n");
                scanf("%d", &getmachines);
                for (int i = 0; i < aux->numberofmachines; i++) {

                    if (i != getmachines) {
                        array_aux_machine[i] = aux->machine[i];
                        array_aux_cycle[i] = aux->cycletime[i];
                        //printf("Machine==== %d\n",array_aux_machine[i]);
                        //printf("Cycle==== %d\n", array_aux_cycle[i]);
                    }

                }
                free(aux->machine);
                free(aux->cycletime);
                aux->machine = (int*)malloc(numberofmachines * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
                aux->cycletime = (int*)malloc(numberofmachines * sizeof(int));//ocupar memoria para o nr de elementos que o utilizador pretende
                aux->numberofmachines = numberofmachines;
                for (int i = 0; i < numberofmachines; i++) {
                
                    aux->machine[i] = array_aux_machine[i];
                    aux->cycletime[i] = array_aux_cycle[i];
                }

                return  newMachine;
            }
            aux = aux->next;
        }
    }


    return NULL;
}

bool SaveStructToFile(Operation* newMachine)
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "w"); // w+ Open for  writing.
    
    if (FileToWrite == NULL || newMachine == NULL)
    {
        printf("Error!");
        return False;
        fclose(FileToWrite);
    }

    fprintf(FileToWrite, "Operação;Máquina;TempoCiclo\n");
    while (newMachine != NULL)
    {

        for (int i = 0; i < newMachine->numberofmachines; i++)
        {
            //printf("%p %d %d %d\n", newMachine, newMachine->operation, newMachine->machine[i], newMachine->cycletime[i]);
            fprintf(FileToWrite, "%d;%d;%d\n", newMachine->operation, newMachine->machine[i], newMachine->cycletime[i]);
        }
        //printf("%p\n", newMachine->next);
        newMachine = newMachine->next;

        
        
    }
    fclose(FileToWrite);
    return True;
}

struct Machine* ReadStructFromFile()
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .

    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }
    Operation* newMachine_fromfile = NULL,* newMachine = (Operation*)malloc(sizeof(Operation));
    int* MachinesPerOp = (int*)malloc(sizeof(int));
    MachinesPerOp = AuxReadFile(FileToWrite);
    fclose(FileToWrite);

     if (newMachine != NULL ) {

        int counter = 0;

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
       
            int prms_array = MachinesPerOp_aux[counter];
            if (prms_array > 100) {
                printf("ERRO AO LER FICHEIRO!!!!!\n"); 
                return NULL;
            }//DÁ MUITOS BUGS A LER ARRAY!

            printf("prms_array %d\n", prms_array);
            newMachine = AuxCreateStruct(prms_array, FileToWrite, newMachine_fromfile,i+1, NumberOfAtualOperation);//+1 , porque o primeiro valor é para saber o numero de listas..

            if(i!=0){
                NumberOfAtualOperation = &newMachine->operation;
                newMachine_fromfile = newMachine;
            }   
            counter++;

        }
     //fclose(FileToWrite_txt);//THIS
     fclose(FileToWrite);

     if (newMachine !=NULL){
         system("cls");
         newMachine =  InvertStruct(newMachine);
         CheckOperations(newMachine);
     }
     else {
         return NULL;
     }
 }
    
    return newMachine;
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

struct Machine* AuxCreateStruct(int Machines, FILE* FileToWrite, Operation* newMachine_fromfile,int Number_Line, int* NumberOfAtualOperation)
{


    Operation*aux = newMachine_fromfile, *newMachine = (Operation*)malloc(sizeof(Operation));
    //printf("MACHINE === %d\n" ,Machines);
    int Control_Cycle = Machines;
    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    int getmachines, getcycletime, count_string_space = 0, count_index = 0;
    int Number_Lines = Number_Line;// nr de linhas lidas
    int var_currenteOp=-1;

    if (newMachine != NULL) {

        newMachine->machine = (int*)malloc(Machines * sizeof(int));//ocupar memoria para o nr de elementos que o lemos pelo txt
        newMachine->cycletime = (int*)malloc(Machines * sizeof(int));//ocupar memoria para o nr de elementos que o lemos pelo txt
        newMachine->operation = (int*)malloc(1 * sizeof(int));

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
                            newMachine->operation = *NumberOfAtualOperation;
                            newMachine->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newMachine->operation; i++) {*/
                            if (count_string_space == 2) {
                                int aux = atoi(stdToCompare);
                                newMachine->machine[count_index] = aux;
                            }
                    }
                //}
                else if (*NumberOfAtualOperation == var_currenteOp && Number_Lines != 1 ) {

                        count_string_space++;
                        if (count_string_space == 1) {
                            int aux = atoi(stdToCompare);
                            NumberOfAtualOperation = &aux;
                            newMachine->operation = *NumberOfAtualOperation;
                            newMachine->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newMachine->operation; i++) {*/
                        if (count_string_space == 2) {
                            int aux = atoi(stdToCompare);
                            count_index++;
                            newMachine->machine[count_index] = aux;
                        }
                        //if (count_string_space == 3) {
                        //    newMachine->cycletime[count_index] = atoi(stdToCompare);
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
                            newMachine->operation = *NumberOfAtualOperation;
                            newMachine->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newMachine->operation; i++) {*/
                        if (count_string_space == 2) {
                            int aux = atoi(stdToCompare);
                            newMachine->machine[count_index] = aux;
                            var_currenteOp = *NumberOfAtualOperation;
                        }

                }
                }
                else if( strstr(stdToCompare, "\n") != NULL && Number_Lines!=1){
                 stdToCompare = strtok(stdToCompare, "\n");
                 int aux = atoi(stdToCompare);
                 newMachine->cycletime[count_index] = aux;
                 count_string_space = 0;
                 newMachine->next = newMachine_fromfile;
                 var_currenteOp = *NumberOfAtualOperation;
                 
                }
                else {

                    return newMachine;
                }
                //printf("%s;", pch);
                pch = strtok(NULL, ";");
             
            }
            Number_Lines++;
            Control_Cycle--;
            if (Number_Lines!=1 && Control_Cycle == 0) {

                return newMachine;
            }
        }
    }
else {
        return(newMachine);
    }
 
}