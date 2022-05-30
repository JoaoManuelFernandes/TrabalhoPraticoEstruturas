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

int quantidadeObjetos(Operation *obj)
{
    if (obj != NULL) return(1 + quantidadeObjetos(obj->next)); //recursiva exemplo do stor
    else return(0);
}

struct Machine* CreateMachineOnFirstTime(Operation *newop)
{
   // setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
    //struct Machine* newMachine = NULL;
    Operation* newMachine = (Operation*)malloc(sizeof(Operation));
    Operation *temp = newop;

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
        bool _res = False;
        int last_id = 0;
        for (int x = 0; x < MachinesPerOp; x++) {
            if (last_id != x && _res == True)
            {
                continue;
            }
            printf("Qual a maquina associada %d ?\n", x + 1);
            scanf("%d", &getmachines);
            if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!

            if(temp !=NULL){
                for (int i = 0; i < x; i++) {
                        if (getmachines == newMachine->machine[i]) {
                            printf("Máquina já existente!, Terá de reiniciar esta operação!\n");
                            last_id = x;
                            x = -1;
                            _res = True;
                            break;
                        }
                        else
                        {
                            _res = False;
                         /*   last_id = x;*/
                        }
                    }
                }

                if (_res != True)
                {
                    newMachine->machine[x] = getmachines;
                    printf("Qual o tempo de ciclo %d ?\n", x + 1);
                    scanf("%d", &getcycletime);
                    newMachine->cycletime[x] = getcycletime;
                    newMachine->next = newop;
                    temp = newMachine;
                }
        }

        printf("Operacao criada com sucesso!\n");
        return newMachine;

        }
    else {
        printf("Alocacao de uma nova operacao falhou!!\n");
        return NULL;
    }
}

struct Machine* CreateMachineOnInit(Operation *newop)
{
    Operation *aux,  *newMachine = (Operation*)malloc(sizeof(Operation));
    Operation* temp = newop;
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

        bool _res = False;
        int last_id = 0;
        for (int x = 0; x < MachinesPerOp; x++) {
            if (last_id != x && _res == True)
            {
                continue;
            }
            printf("Qual a maquina associada %d ?\n", x + 1);
            scanf("%d", &getmachines);
            if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!

            if (temp != NULL) {
                for (int i = 0; i < x; i++) {
                    if (getmachines == newMachine->machine[i]) {
                        printf("Máquina já existente!, Terá de reiniciar esta operação!\n");
                        last_id = x;
                        x = -1;
                        _res = True;
                        break;
                    }
                    else
                    {
                        _res = False;
                        /*   last_id = x;*/
                    }
                }
            }

            if (_res != True)
            {
                newMachine->machine[x] = getmachines;
                printf("Qual o tempo de ciclo %d ?\n", x + 1);
                scanf("%d", &getcycletime);
                newMachine->cycletime[x] = getcycletime;
                newMachine->next = newop;
                temp = newMachine;
            }
        }

        //for (int x = 0; x < MachinesPerOp; x++) {

        //    printf("Qual a maquina associada %d ?\n", x + 1);
        //    scanf("%d", &getmachines);
        //    if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
        //    newMachine->machine[x] = getmachines;
        //    printf("Qual o tempo de ciclo %d ?\n", x + 1);
        //    scanf("%d", &getcycletime);
        //    newMachine->cycletime[x] = getcycletime;
        //    newMachine->next = newop;
        //}

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
            Operation* temp = newMachine;
            int getmachines, getcycletime;
            int MachinesPerOp, counter = 1, position = pos;

            printf("Quantas maquinas tera a operacao %d ?\n", pos + 1);
            scanf("%d", &MachinesPerOp);
            if (MachinesPerOp > 8 || MachinesPerOp == 0) {

                return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            }


            Operation *anterior = newMachine,*  proximo = newMachine,* novo = (Operation*)malloc(sizeof(Operation));

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
            bool _res = False;
            int last_id = 0;
            for (int x = 0; x < MachinesPerOp; x++) {
                if (last_id != x && _res == True)
                {
                    continue;
                }
                printf("Qual a maquina associada %d ?\n", x + 1);
                scanf("%d", &getmachines);
                if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!

                if (temp != NULL) {
                    for (int i = 0; i < x; i++) {
                        if (getmachines == novo->machine[i]) {
                            printf("Máquina já existente!, Terá de reiniciar esta operação!\n");
                            last_id = x;
                            x = -1;
                            _res = True;
                            break;
                        }
                        else
                        {
                            _res = False;
                            /*   last_id = x;*/
                        }
                    }
                }

                if (_res != True)
                {
                    novo->machine[x] = getmachines;
                    printf("Qual o tempo de ciclo %d ?\n", x + 1);
                    scanf("%d", &getcycletime);
                    novo->cycletime[x] = getcycletime;
                    //newMachine->next = newMachine;
                    temp = novo;
                }
            }

            //for (int x = 0; x < MachinesPerOp; x++) {
       
            //     
            //      novo->operation = position+1;
            //      novo->numberofmachines = MachinesPerOp;
            //      printf("Qual a maquina associada %d ?\n", x + 1);
            //      scanf("%d", &getmachines);
            //      novo->machine[x] = getmachines;
            //      if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            //      printf("Qual o tempo de ciclo %d ?\n", x + 1);
            //      scanf("%d", &getcycletime);
            //      novo->cycletime[x] = getcycletime;
            //     
            // }
            proximo = proximo->next; // porque em cima posicao vem com -1 , logo fica desfasado .. o ciclo while nao coloca a apontar para a op correta..logo faço +1 next!
            novo->next = proximo;
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

struct Machine* CreateMachineOnEnd(Operation *newMachine,  int* index)
{
    setlocale(LC_ALL, "portuguese");// caracteres portugues aceites
    Operation* aux = newMachine, *novo = (Operation*)malloc(sizeof(Operation));
    Operation* temp = newMachine;
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
            novo->operation = *index + 1;
            bool _res = False;
            int last_id = 0;
            for (int x = 0; x < MachinesPerOp; x++) {
                if (last_id != x && _res == True)
                {
                    continue;
                }
                printf("Qual a maquina associada %d ?\n", x + 1);
                scanf("%d", &getmachines);
                if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!

                if (temp != NULL) {
                    for (int i = 0; i < x; i++) {
                        if (getmachines == novo->machine[i]) {
                            printf("Máquina já existente!, Terá de reiniciar esta operação!\n");
                            last_id = x;
                            x = -1;
                            _res = True;
                            break;
                        }
                        else
                        {
                            _res = False;
                            /*   last_id = x;*/
                        }
                    }
                }

                if (_res != True)
                {
                    novo->machine[x] = getmachines;
                    printf("Qual o tempo de ciclo %d ?\n", x + 1);
                    scanf("%d", &getcycletime);
                    novo->cycletime[x] = getcycletime;
                    //novo->next = newMachine;
                    temp = novo;
                }
            }

            //for (int x = 0; x < MachinesPerOp; x++) {

            //    printf("Qual a maquina associada %d ?\n", x + 1);
            //    scanf("%d", &getmachines);
            //    if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
            //    novo->machine[x] = getmachines;

            //    printf("Qual o tempo de ciclo %d ?\n", x + 1);
            //    scanf("%d", &getcycletime);
            //    novo->cycletime[x] = getcycletime;
            //   
            //}

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

struct Machine* RemoveAList(Operation *newMachine, int pos)
{
    Operation *atual = newMachine, * proximo;

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

struct Machine* ModifyAListCycleTime(Operation *newMachine, int* operation, int* cycletime, int pos)
{
    Operation *aux = (Operation*)malloc(sizeof(Operation));
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

struct Machine* InvertStruct(Operation *newMachine)
{
  
        // Initialize current, previous and
        // next pointers
    Operation *current = newMachine,* prev = NULL,  *next = NULL;

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


void CheckOperations(Operation *newMachine)
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

void AllCombinations(Operation *newMachine)
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
        Operation *aux = newMachine;
       
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
                        printf("Qual sera a maquina_%d ?\n", i + 1);
                        scanf("%d", &getmachines);
                        if (getmachines > 8 || getmachines == 0) return NULL;//SO PERMITE 8 MÁQUINAS!!!!!!
                        aux->machine[i] = getmachines;
                        printf("Qual o tempo de ciclo associado a maquina_%d ?\n", i + 1);
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

struct Machine* RemoveMachine(Operation *newMachine, int* operation)
{
    if (newMachine != NULL) {
        Operation *aux = newMachine;

        while (aux != NULL)
        {
            if (aux->operation == *operation) {
            

                int* array_aux_machine = (int*)malloc(aux->numberofmachines * sizeof(int));
                int* array_aux_cycle = (int*)malloc(aux->numberofmachines * sizeof(int));
                int numberofmachines = aux->numberofmachines - 1;
                int getmachines, getcycletime;          
                printf("Qual a posicao da maquina que pretende eliminar ?\n");
                scanf("%d", &getmachines);
                int index = 0;
                for (int i = 0; i < aux->numberofmachines; i++) {

                    if ((i+1) != getmachines) {
                        array_aux_machine[index] = aux->machine[i];
                        array_aux_cycle[index] = aux->cycletime[i];
                        index++;
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

                aux = aux->next;
                while (aux !=NULL)
                {
                    for (int i = 0; i < aux->numberofmachines; i++) {
                        int x = aux->operation;
                        aux->operation = x - 1;
                 
                            printf("%d", x);
                            printf("         %d", aux->operation);
                        

                    }
                    aux = aux->next;
                }


                return  newMachine;
            }
            aux = aux->next;
        }
    }

    return NULL;
}

bool SaveStructToFile(Operation *newMachine)
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
    FileToWrite = fopen("EstruturaDeDadosFile_OnlyAJob.csv", "r"); // r Open for both reading .

    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }
    Operation *newMachine_fromfile = NULL,* newMachine = (Operation*)malloc(sizeof(Operation));
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




        FileToWrite = fopen("EstruturaDeDadosFile_OnlyAJob.csv", "r"); // r Open for both reading .
        for(int i = 0 ; i< numberofoperations; i++){//+1 porque temos a a linha do operação..
       
            int prms_array = MachinesPerOp_aux[counter];
            if (prms_array > 100) {
                printf("ERRO AO LER FICHEIRO!!!!!\n"); 
                return NULL;
            }//DÁ MUITOS BUGS A LER ARRAY!

            printf("prms_array %d\n", prms_array);
            newMachine = AuxCreateStruct(prms_array, FileToWrite, newMachine_fromfile,i+1, NumberOfAtualOperation,0);//+1 , porque o primeiro valor é para saber o numero de listas..

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

struct Machine* AuxCreateStruct(int Machines, FILE* FileToWrite, Operation *newMachine_fromfile,int Number_Line, int* NumberOfAtualOperation,int index_of_job)
{
    Operation *aux = newMachine_fromfile,* newMachine = (Operation*)malloc(sizeof(Operation));
    //printf("MACHINE === %d\n" ,Machines);
    int Control_Cycle = Machines;
    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    int getmachines, getcycletime, count_string_space = 0, count_index = 0;
    int Number_Lines = Number_Line;// nr de linhas lidas
    int var_currenteOp=-1;
    if (Machines < 0 || Machines > 100) { 
        return NULL;
    }
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
                if (index_of_job !=0) {
                    Number_Lines++;
                    index_of_job = 0;
                } // porque a meio nao temos as palavras job, operação, entao tenho de manipular..


                if (strstr(stdToCompare, "\n") == NULL)//FUNÇÃO QUE RETORNA NULL SE NAO ENCONTRAR O PARAMETRO QUE LHE ENVIAMOS!
                {
                    if (Number_Lines == 2 ){
                        count_string_space++;
                        if (count_string_space == 2) {
                            int aux = atoi(stdToCompare);
                            NumberOfAtualOperation = &aux;
                            newMachine->operation = *NumberOfAtualOperation;
                            newMachine->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newMachine->operation; i++) {*/
                            if (count_string_space == 3) {
                                int aux = atoi(stdToCompare);
                                newMachine->machine[count_index] = aux;
                            }
                    }
                //}
                else if (*NumberOfAtualOperation == var_currenteOp && Number_Lines != 1 ) {

                        count_string_space++;
                        if (count_string_space == 2) {
                            int aux = atoi(stdToCompare);
                            NumberOfAtualOperation = &aux;
                            newMachine->operation = *NumberOfAtualOperation;
                            newMachine->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newMachine->operation; i++) {*/
                        if (count_string_space == 3) {
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
                        if (count_string_space == 2) {
                            count_index = 0;
                            int aux = atoi(stdToCompare);
                            NumberOfAtualOperation = &aux;
                            newMachine->operation = *NumberOfAtualOperation;
                            newMachine->numberofmachines = Machines;
                        }/*
                        for (int i = 0; i < newMachine->operation; i++) {*/
                        if (count_string_space == 3) {
                            int aux = atoi(stdToCompare);
                            /*printf("%d\n",count_index);*/
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

int MainFunctionFase2()
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
    printf("1 - Insercao de um conjunto de jobs \n");
    printf("2 - Leitura do process plan a partir de um ficheiro .csv\n");
    printf("3 - Gravar process plan num ficheiro .csv\n");
    printf("4 - Adicionar um novo job\n");
    printf("5 - Alterar uma operação de um job\n");
    printf("6 - Remover uma operação de um job\n");
    printf("7 - Adicionar uma nova operação num determinado job\n");
    printf("8 - Remover um determinado job\n");
    printf("9 - Analisar a estrutura atual\n");
    printf("10 - Proposta de escalonamento com  estrutura atual\n");
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

struct Job* CreateStructOfJobs(Jobs job_to_insert, Operation *op,int index,int numberofop_perjob)
{
    Jobs newjob_aux = job_to_insert,  newjob = (Jobs)malloc(sizeof(struct Job));
    if (newjob != NULL) {
        newjob->Number_Job = index;
        newjob->Number_Operation_PerJob = numberofop_perjob;
        newjob->op = op;
        newjob->behind = NULL;
        newjob->next = newjob_aux;
        if (newjob_aux != NULL) newjob_aux->behind = newjob;
        job_to_insert = newjob;

    }
    
    return job_to_insert;
}

struct Job* CreateStruct(Jobs job_to_insert)
{
    int job_index = 1,number_of_jobscreate;
    Operation *op = NULL;
    int* index, *aux_numberofop;
    
    printf("Digite na consola o numero de jobs que pretende criar!\n");
    scanf("%d",&number_of_jobscreate);

    for(int i = 0; i< number_of_jobscreate ; i++){
         op = NULL;
         int numberofop;
         printf("Quantas operacoes tera o job numero %d?\n",i+1);
         scanf("%d", &numberofop);
         aux_numberofop = &numberofop;


         for(int i=0 ;i< numberofop;i++){
             index = &i;
             op = CreateMachineOnEnd(op, index);
             if (op == NULL) {
                 printf("Não criou uma nova operacao, repita o processo com valores diferentes de 0 oou 9 para o numero de maquinas!! \n");
                 break;
             }
         }

        if (op != NULL) {
            printf("\n=============================\n");
            printf("Processo criado com sucesso!");
            printf("\n=============================\n");
        }

        job_to_insert = CreateStructOfJobs(job_to_insert,op,job_index,*aux_numberofop);
        job_index++;
    }

    return job_to_insert;
}

struct Job* ReadStructFromFileToJobs()
{
    FILE* FileToWrite, * InfoJobs;
    const size_t line_size = 75;
    char* line_infojobs = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!


    FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .


    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }
    Operation *newOperation_fromfile = NULL, *newOperation = (Operation*)malloc(sizeof(Operation));
    Jobs newJob_fromfile = NULL,  newJob = (Jobs)malloc(sizeof(struct Job));
    int* MachinesPerOp = (int*)malloc(sizeof(int));
    MachinesPerOp = AuxReadFileToJobs(FileToWrite);
    fclose(FileToWrite);

    if (newOperation != NULL) {

        int counter = 0;
        int auxiliar = 0;
        int prms_array;
        int numberofoperations = MachinesPerOp[1] + 1;
        int numberofjobs = MachinesPerOp[0];

        int* MachinesPerOp_aux = (int*)malloc(numberofoperations * sizeof(int));
        int* NumberOfAtualOperation = &auxiliar;

        //Const size_t line_size = 5; // Limita o nr de caracteres a 75!
        //char* line = malloc(line_size * sizeof(char));// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!

        for (int i = 0; i < numberofoperations+1; i++) {//+1 porque temos a a linha do operação..
            MachinesPerOp_aux[i] = MachinesPerOp[i];
            //printf("MachinesPerOp_aux %d\n", MachinesPerOp_aux[i]);
        }//POrque da problemas se nao for com um array com criado exatamente com o numero exato de elementos......

        FileToWrite = fopen("EstruturaDeDadosFile.csv", "r"); // r Open for both reading .
        InfoJobs = fopen("InfoJobs.dat", "r");
        for(int j = 0 ;j < numberofjobs;j++){

            fgets(line_infojobs, line_size, InfoJobs);
            numberofoperations = atoi(line_infojobs);
            if (j == 0) {
                numberofoperations++;
            }
           
            newOperation = NULL;
            newOperation_fromfile = NULL;
            *NumberOfAtualOperation = 0;

            for (int i = 0; i < numberofoperations; i++) {//+1 porque temos a a linha do operação..

                if (i == 1 && newJob_fromfile == NULL) {

                    counter = 0; // porque a primeira linha é de texto entao tenho que dar reset a isto , no entanto, é so quando o 1º job!
                }
                prms_array = MachinesPerOp_aux[counter+2];

                if (prms_array > 100) {
                    printf("ERRO AO LER FICHEIRO!!!!!\n");
                    return NULL;
                }//DÁ MUITOS BUGS A LER ARRAY!

                //printf("prms_array %d\n", prms_array); 



                newOperation = AuxCreateStruct(prms_array, FileToWrite, newOperation_fromfile, i + 1, NumberOfAtualOperation,j);//+1 , porque o primeiro valor é para saber o numero de listas..
                if (newOperation == NULL ) {
                    return NULL;
                }
                if (i != 0 || j != 0) {
                    *NumberOfAtualOperation = newOperation->operation;
                    newOperation_fromfile = newOperation;
                }
                counter++;
            }
            if (newOperation != NULL) {
                /*system("cls");*/
                newOperation = InvertStruct(newOperation);
                /*CheckOperations(newOperation);*/
            }

        newJob_fromfile = CreateStructOfJobs(newJob_fromfile, newOperation,(j+1), atoi(line_infojobs)); //construção do job
        
        }


        fclose(InfoJobs);
        fclose(FileToWrite);
        //PrintJobs(newJob_fromfile);
    }


    return newJob_fromfile;
}

struct Job* ReadStructFromFileToJobsSupport()
{
    FILE* FileToWrite, * InfoJobs;
    const size_t line_size = 75;
    char* line_infojobs = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!


    FileToWrite = fopen("EstruturaDeDadosFileSupport.csv", "r"); // r Open for both reading .


    if (FileToWrite == NULL)
    {
        printf("Error!");
        return False;
    }
    Operation* newOperation_fromfile = NULL, * newOperation = (Operation*)malloc(sizeof(Operation));
    Jobs newJob_fromfile = NULL, newJob = (Jobs)malloc(sizeof(struct Job));
    int* MachinesPerOp = (int*)malloc(sizeof(int));
    MachinesPerOp = AuxReadFileToJobs(FileToWrite);
    fclose(FileToWrite);

    if (newOperation != NULL) {

        int counter = 0;
        int auxiliar = 0;
        int prms_array;
        int numberofoperations = MachinesPerOp[1] + 1;
        int numberofjobs = MachinesPerOp[0];

        int* MachinesPerOp_aux = (int*)malloc(numberofoperations * sizeof(int));
        int* NumberOfAtualOperation = &auxiliar;

        //Const size_t line_size = 5; // Limita o nr de caracteres a 75!
        //char* line = malloc(line_size * sizeof(char));// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!

        for (int i = 0; i < numberofoperations + 1; i++) {//+1 porque temos a a linha do operação..
            MachinesPerOp_aux[i] = MachinesPerOp[i];
            //printf("MachinesPerOp_aux %d\n", MachinesPerOp_aux[i]);
        }//POrque da problemas se nao for com um array com criado exatamente com o numero exato de elementos......

        FileToWrite = fopen("EstruturaDeDadosFileSupport.csv", "r"); // r Open for both reading .
        InfoJobs = fopen("InfoJobs.dat", "r");
        for (int j = 0; j < numberofjobs; j++) {

            fgets(line_infojobs, line_size, InfoJobs);
            numberofoperations = atoi(line_infojobs);
            if (j == 0) {
                numberofoperations++;
            }

            newOperation = NULL;
            newOperation_fromfile = NULL;
            *NumberOfAtualOperation = 0;

            for (int i = 0; i < numberofoperations; i++) {//+1 porque temos a a linha do operação..

                if (i == 1 && newJob_fromfile == NULL) {

                    counter = 0; // porque a primeira linha é de texto entao tenho que dar reset a isto , no entanto, é so quando o 1º job!
                }
                prms_array = MachinesPerOp_aux[counter + 2];

                if (prms_array > 100) {
                    printf("ERRO AO LER FICHEIRO!!!!!\n");
                    return NULL;
                }//DÁ MUITOS BUGS A LER ARRAY!

                //printf("prms_array %d\n", prms_array); 



                newOperation = AuxCreateStruct(prms_array, FileToWrite, newOperation_fromfile, i + 1, NumberOfAtualOperation, j);//+1 , porque o primeiro valor é para saber o numero de listas..

                if (i != 0 || j != 0) {
                    *NumberOfAtualOperation = newOperation->operation;
                    newOperation_fromfile = newOperation;
                }
                counter++;
            }
            if (newOperation != NULL) {
                /*system("cls");*/
                newOperation = InvertStruct(newOperation);
                /*CheckOperations(newOperation);*/
            }

            newJob_fromfile = CreateStructOfJobs(newJob_fromfile, newOperation, (j + 1), atoi(line_infojobs)); //construção do job

        }


        fclose(InfoJobs);
        fclose(FileToWrite);
        //PrintJobs(newJob_fromfile);
    }


    return newJob_fromfile;
}

void SaveAJobatFile(Jobs job_to_save)
{
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "w"); // w+ Open for  writing.

    if (FileToWrite == NULL || job_to_save == NULL)
    {
        printf("Error!");
        return False;
        fclose(FileToWrite);
    }

    fprintf(FileToWrite, "Job;Operação;Máquina;TempoCiclo\n");
    while (job_to_save != NULL)
    {
        
        for (int i = 0; i < job_to_save->op->numberofmachines; i++)
        {
            //printf("%p %d %d %d\n", newMachine, newMachine->operation, newMachine->machine[i], newMachine->cycletime[i]);
            fprintf(FileToWrite, "%d;%d;%d;%d\n", job_to_save->Number_Job,job_to_save->op->operation, job_to_save->op->machine[i], job_to_save->op->cycletime[i]);
        }
        //printf("%p\n", newMachine->next);
        job_to_save->op = job_to_save->op->next;



    }
    fclose(FileToWrite);
    return True;
}

int* AuxReadFileToJobs(FILE* FileToWrite)
{
    //BASICAMENTE VAMOS LER O NUMERO DE MÁQUINAS POR OPERAÇÃO!

    const size_t line_size = 75; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!
    char* stdToCompare = (char*)malloc(sizeof(char));
    char converted_tochar[100];
    int* MachinesPerOp = (int*)malloc(sizeof(int));

    int getmachines, getcycletime, count_fistline = 0, count_index = 0, CounterOfLists = 0,CounterOfJobs = 0, Number_Lines = 1, NumberOfAtualOperation = 0;
    int lastjob = 0,last_lastjob = 0;
    int number_of_list_per_jobs = 0, number_of_list_per_jobs_last = 0;
    MachinesPerOp[count_index] = 0; //PORQUE DEPOIS VAI TOMAR O VALOR DE QUANTIDADE DE JOBS!!!!!!
    MachinesPerOp[count_index++] = 0; //PORQUE DEPOIS VAI TOMAR O VALOR DE QUANTIDADE DE LISTAS!!!!!!

    //enquanto o valor de retorno da função for diferente de nulo , ou seja ainda há "linhas no ficheiro"
    FILE* InfoJobs;

    InfoJobs = fopen("InfoJobs.dat", "w");



    while (fgets(line, line_size, FileToWrite) != NULL) {

        char* pch; // apontador para guardar a "string" que iremos dar split..
        pch = strtok(line, ";");// subdividmos pelos caracter especificado e guardamos tudo no apontador

        while (pch != NULL)
        {

            stdToCompare = pch;

            if (strstr(stdToCompare, "\n") == NULL)//FUNÇÃO QUE RETORNA NULL SE NAO ENCONTRAR O PARAMETRO QUE LHE ENVIAMOS!
            {
                count_fistline++;



                if (Number_Lines != 1 && count_fistline == 1) {

                    if (CounterOfJobs == 0) {
                        lastjob = atoi(stdToCompare);
                        last_lastjob = lastjob;
                        CounterOfJobs++;
                    }
                    else if (atoi(stdToCompare)!=lastjob){
                        number_of_list_per_jobs_last = CounterOfLists - number_of_list_per_jobs;
                        number_of_list_per_jobs += number_of_list_per_jobs_last;
                        sprintf(converted_tochar, "%d", number_of_list_per_jobs_last); // put the int into a string
                        fputs(converted_tochar, InfoJobs);
                        fputs("\n",InfoJobs);
                        CounterOfJobs++;
                        last_lastjob = lastjob;
                        lastjob = atoi(stdToCompare);
                    }
                }//ler os jobs


                else if (Number_Lines == 2 && NumberOfAtualOperation == 0 && count_fistline == 2) {
                    count_index++;
                    CounterOfLists++;
                    NumberOfAtualOperation = atoi(stdToCompare);
                    MachinesPerOp[count_index] = 1; 
                    //count_index++;
                    //MachinesPerOp[count_index] = 1; // armazena nr de operações total

                }
                else if (NumberOfAtualOperation == atoi(stdToCompare) && Number_Lines != 1 && count_fistline == 2) {
                       
                    MachinesPerOp[count_index]++;                  
                }
                //
                else if (NumberOfAtualOperation != atoi(stdToCompare) && Number_Lines != 1 && count_fistline == 2 ) {
                    CounterOfLists++;
                    NumberOfAtualOperation = atoi(stdToCompare);
                    count_index++;
                    MachinesPerOp[count_index] = 1;
                    //last_lastjob = lastjob;
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
    //para a ultima vez....
    number_of_list_per_jobs_last = CounterOfLists - number_of_list_per_jobs;
    number_of_list_per_jobs += number_of_list_per_jobs_last;
    sprintf(converted_tochar, "%d", number_of_list_per_jobs_last); // put the int into a string
    fputs(converted_tochar, InfoJobs);
    fputs("\n", InfoJobs);
    fclose(InfoJobs);


   /* printf("Numero de jobs: %d\n\n",CounterOfJobs);*/
    MachinesPerOp[0] = CounterOfJobs;
    MachinesPerOp[1] = CounterOfLists;
    stdToCompare = 0;//senao estoura a dar free ... sera por ter \n??


    free(stdToCompare);
    free(line);


    //Retorna array com o indice 0 a conter o numero de jobs , indice 1 retorna o numero total de listas, e depois cada indice retorna o numero de maquinas por operação..
    return MachinesPerOp;
}

void PrintJobsFromFile(Jobs *job_to_print)
{

    Jobs temp = *job_to_print;
    
    system("cls");
    FILE* InfoJobs;
    InfoJobs = fopen("InfoJobs.dat", "r");
    int numberofoperations;
    Operation* operation;

    const size_t line_size = 5; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!


    int qt = quantidadeJobs(temp);

    temp = InvertStructJob(&temp);
    if (qt == 0) {
        printf("ERROR\n"); printf("ERROR\n");
        printf("Numero de jobs e nulo, tem de primeiro criar a nossa estrutura clicando 1!\n");
        printf("ERROR\n"); printf("ERROR\n");
    }

    else {
       /* Operation current = temp->op;*/
        printf("%s %s %s %s \n","Job", "Operacao", "Maquina", "Tempo de ciclo");
        while (temp != NULL)
        {
            for(int j =0; j < qt ; j++){//quantidade de jobs

                fgets(line, line_size, InfoJobs);
                numberofoperations = atoi(line);// UNICA DIF É AQUI , OU SEJA , LÊ DO FICHEIRO EM VEZ DE LER O VALOR QUE ESTA NA STRUCT DO JOB!
                operation = (*temp).op;
                for(int x = 0 ; x < numberofoperations ; x++){

                    for (int i = 0; i < operation->numberofmachines; i++)
                    {
                        printf(" %d       %d         %d         %d\n", (*temp).Number_Job, operation->operation, operation->machine[i], operation->cycletime[i]);
                    }
               
                    operation = operation->next;
                }
                temp = (*temp).next;
            }

        }
        printf("\nQuantidade de listas = %d\n", qt);
    }
    fclose(InfoJobs);
}

bool PrintJobs(Jobs *job_to_print)
{
    Jobs temp = *job_to_print;  /*aux = (Jobs)malloc(sizeof(struct Job));*/
    Operation* operation;
    system("cls");
    FILE* InfoJobs;
    InfoJobs = fopen("InfoJobs.dat", "r");
    int numberofoperations;

    const size_t line_size = 5; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!


    int qt = quantidadeJobs(temp);
    temp = InvertStructJob(&temp);
    if (qt == 0) {
        printf("ERROR\n"); printf("ERROR\n");
        printf("Numero de jobs e nulo, tem de primeiro criar a nossa estrutura clicando 1!\n");
        printf("ERROR\n"); printf("ERROR\n");
    }

    else {
        Operation *current = (Operation*)malloc(sizeof(Operation));
        printf("%s %s %s %s \n", "Job", "Operacao", "Maquina", "Tempo de ciclo");
       /* aux = temp;*/
        while (temp != NULL)
        {
            for (int j = 0; j < qt; j++) {//quantidade de jobs
          
                operation = (*temp).op;
                fgets(line, line_size, InfoJobs);
                numberofoperations = atoi(line);//ERRO AQUI 

                for (int x = 0; x < (*temp).Number_Operation_PerJob; x++) {
                  
                    //operation = (*temp).op;
                    for (int i = 0; i < operation->numberofmachines; i++)
                    {
                        printf(" %d       %d         %d         %d\n", (*temp).Number_Job, operation->operation, operation->machine[i], operation->cycletime[i]);
                    }

                    operation = operation->next;
                }
                temp = (*temp).next;
            }

        }
        printf("\nQuantidade de Jobs = %d\n", qt);
    }
    fclose(InfoJobs);
    return True;
}

bool PrintJustAjob(Jobs job_to_print)
{
    if (job_to_print == NULL)
    {
        printf("Impossivel printar job pois este é vazio!");
        return False;
    }
    Jobs temp = job_to_print, aux = (Jobs)malloc(sizeof(struct Job));
    //Operation* current = (Operation*)malloc(sizeof(Operation));

    printf("%s %s %s %s \n", "Job", "Operacao", "Maquina", "Tempo de ciclo");
    *aux = *temp;
    //current = aux->op;//para nao manipular diretamente na memoria...
  for (int j = 0; j < 1; j++) {//quantidade de jobs

      for (int x = 0; x < temp->Number_Operation_PerJob; x++) {

          for (int i = 0; i < aux->op->numberofmachines; i++)
          {
              printf(" %d       %d         %d         %d\n", aux->Number_Job, aux->op->operation, aux->op->machine[i], aux->op->cycletime[i]);
          }

          aux->op = aux->op->next;
      }

  }

    return True;
}

struct Job* InvertStructJob(Jobs *job_to_invert)
{
    if (*job_to_invert == NULL) {
        return NULL;
    }
    Jobs *temp = (Jobs)malloc(sizeof(struct Job));
    Jobs current = *job_to_invert;

    /* swap next and prev for all nodes of
      doubly linked list */
    /*troca os "next" e os "behinds" para todos os nos da lista duplamente ligada!*/
    while (current != NULL)
    {
        *temp = (*current).behind;
        (*current).behind = (*current).next;
        current->next = *temp;
        current = (*current).behind;
    }

    /* Before changing head, check for the cases like empty
       list and list with only one node */
    /* antes de mudar o no de entrada , ve se todas as verifica os casos como vazio
        lista e lista com apenas um nó */
    if (temp != NULL)
        current = (* temp)->behind;

    return current;
}

int quantidadeJobs(Jobs job_to_count)
{
    if (job_to_count != NULL) return(1 + quantidadeJobs(job_to_count->next)); //recursiva exemplo do stor
    else return(0);
}

bool SaveStructOfJob(Jobs job_to_save)
{
    Jobs *TotalJobsAux = (Jobs)malloc(sizeof(struct Job));
    *TotalJobsAux = job_to_save;
    system("cls");
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFile.csv", "w"); // w+ Open for  writing.
    if (FileToWrite == NULL)
    {
        printf("Error openning the file!");
        return False;
    }
   

    int numberofoperations;

    const size_t line_size = 5; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!


    int qt = quantidadeJobs(*TotalJobsAux);
    //PrintJobs(*TotalJobsAux);
    /**TotalJobsAux = InvertStructJob(*TotalJobsAux);*/
    //PrintJobs(*TotalJobsAux);
    if (qt <= 0) {
        printf("ERROR\n"); printf("ERROR\n");
        printf("Numero de jobs e nulo, tem de primeiro criar a nossa estrutura clicando 1!\n");
        printf("ERROR\n"); printf("ERROR\n");
    }

    else {
       /* Operation* current = temp->op;*/
        fprintf(FileToWrite,"%s;%s;%s;%s \n", "Job", "Operacao", "Maquina", "Tempo de ciclo");
        while (*TotalJobsAux != NULL)
        {
            for (int j = 0; j < qt; j++) {//quantidade de jobs
                int* Number_Operation_PerJob = &(*TotalJobsAux)->Number_Operation_PerJob;
                for (int x = 0; x < *Number_Operation_PerJob; x++) {

                    int *numberofop = &(*TotalJobsAux)->op->numberofmachines;
                    for (int i = 0; i < *numberofop; i++)
                    {
                        fprintf(FileToWrite, "%d;%d;%d;%d\n", (*TotalJobsAux)->Number_Job, (*TotalJobsAux)->op->operation, (*TotalJobsAux)->op->machine[i], (*TotalJobsAux)->op->cycletime[i]);
                       // printf(" %d       %d         %d         %d\n", job_to_save->Number_Job, job_to_save->op->operation, job_to_save->op->machine[i], job_to_save->op->cycletime[i]);
                    }

                    (*TotalJobsAux)->op = (*TotalJobsAux)->op->next;
                }
                (*TotalJobsAux) = (*TotalJobsAux)->next;
            }

        }
       // printf("\nQuantidade de listas = %d\n", qt);
    }
    fclose(FileToWrite);
    return True;
}

bool SaveStructOfJobSuppport(Jobs job_to_save)
{
    Jobs* TotalJobsAux = (Jobs)malloc(sizeof(struct Job));
    *TotalJobsAux = job_to_save;
    system("cls");
    FILE* FileToWrite;
    FileToWrite = fopen("EstruturaDeDadosFileSupport.csv", "w"); // w+ Open for  writing.
    if (FileToWrite == NULL)
    {
        printf("Error openning the file!");
        return False;
    }
    //if (*TotalJobsAux == NULL) {
    //    printf("Job to save is null!");
    //    return False;
    //}

    int numberofoperations;

    const size_t line_size = 5; // Limita o nr de caracteres a 75!
    char* line = malloc(line_size);// cria variavel dinamica com o tamanho que dimensionamos para o nr de caracteres a ler!


    int qt = quantidadeJobs(*TotalJobsAux);
    //PrintJobs(*TotalJobsAux);
    /**TotalJobsAux = InvertStructJob(*TotalJobsAux);*/
    //PrintJobs(*TotalJobsAux);
    if (qt <= 0) {
        printf("ERROR\n"); printf("ERROR\n");
        printf("Numero de jobs e nulo, tem de primeiro criar a nossa estrutura clicando 1!\n");
        printf("ERROR\n"); printf("ERROR\n");
    }

    else {
        /* Operation* current = temp->op;*/
        fprintf(FileToWrite, "%s;%s;%s;%s \n", "Job", "Operacao", "Maquina", "Tempo de ciclo");
        while (*TotalJobsAux != NULL)
        {
            for (int j = 0; j < qt; j++) {//quantidade de jobs
                int* Number_Operation_PerJob = &(*TotalJobsAux)->Number_Operation_PerJob;
                for (int x = 0; x < *Number_Operation_PerJob; x++) {

                    int* numberofop = &(*TotalJobsAux)->op->numberofmachines;
                    for (int i = 0; i < *numberofop; i++)
                    {
                        fprintf(FileToWrite, "%d;%d;%d;%d\n", (*TotalJobsAux)->Number_Job, (*TotalJobsAux)->op->operation, (*TotalJobsAux)->op->machine[i], (*TotalJobsAux)->op->cycletime[i]);
                        // printf(" %d       %d         %d         %d\n", job_to_save->Number_Job, job_to_save->op->operation, job_to_save->op->machine[i], job_to_save->op->cycletime[i]);
                    }

                    (*TotalJobsAux)->op = (*TotalJobsAux)->op->next;
                }
                (*TotalJobsAux) = (*TotalJobsAux)->next;
            }

        }
        // printf("\nQuantidade de listas = %d\n", qt);
    }
    fclose(FileToWrite);
    return True;
}

struct Job* InsertJobOnInit(Jobs *job_to_add, int numberofop)
{
    Jobs aux = *job_to_add,  newJob = (Jobs)malloc(sizeof(struct Job));
    Operation* newMachine = NULL;
    int job_index = 1;
    int* index, * aux_numberofop;




    if (newJob != NULL) {
        int counter = 0;


        aux_numberofop = &numberofop;


        for (int i = 0; i < numberofop; i++) {
            index = &i;
            newMachine = CreateMachineOnEnd(newMachine, index);

            if (newMachine == NULL) {
                printf("Não criou uma nova operacao, repita o processo com valores diferentes de 0 oou 9 para o numero de maquinas!! \n");
                break;
            }
        }
        newJob = CreateStructOfJobs(newJob, newMachine, 1, *aux_numberofop);

        if (newJob != NULL)
        {

            newJob->next =  aux;
            newJob->behind = NULL;
            
            if (aux != NULL) {
                aux->behind = newJob;
            }

            *job_to_add = aux->behind;
       
    }
        aux = *job_to_add;
        while (aux!=NULL)
        {
            if (counter != 0) {
                aux->Number_Job += 1;
            }
            counter++;
            aux = aux->next;
        }

        return *job_to_add;
}
    return NULL;
}

struct Job* InsertJobOnPos(Jobs* job_to_add,int position,int numberofop)
{
    Jobs aux = *job_to_add, newJob = (Jobs)malloc(sizeof(struct Job));
    Jobs temp2 = NULL;
    Operation* newMachine = NULL;
    int job_index = 1;
    int* index, * aux_numberofop;

    //Verificar se valor da posição dita não excede o nr de Jobs
    int qt = quantidadeJobs(aux);
    if (position > qt-1) { printf("Nr invalido da posicao que deseja!"); return NULL; }
    //se for posição inicial!
    if (position == 0) {  aux = InsertJobOnInit(aux, numberofop); return aux;}
    //se for posição final!
   // if (position == qt-1) { aux = InsertJobOnFinal(aux); return aux; }


    if (newJob != NULL) {
        int counter = 1;


        aux_numberofop = &numberofop;


        for (int i = 0; i < numberofop; i++) {
            index = &i;
            newMachine = CreateMachineOnEnd(newMachine, index);

            if (newMachine == NULL) {
                printf("Não criou uma nova operacao, repita o processo com valores diferentes de 0 oou 9 para o numero de maquinas!! \n");
                break;
            }
        }
        newJob = CreateStructOfJobs(newJob, newMachine, position+1, *aux_numberofop);
        newJob->next = NULL;

        while (--position) {
            aux = aux->next;
        }
        temp2 = aux->next;
        newJob->next = aux->next;
        newJob->behind = aux;
        aux->next = newJob;
        temp2->behind = newJob;

    }
    *job_to_add = temp2;
    while (temp2 !=NULL)
    {
        temp2->Number_Job += 1;
        temp2 = temp2->next;
    }
    while (( * job_to_add)->behind != NULL)
    {
        (*job_to_add) = (*job_to_add)->behind;
    }
        return *job_to_add;
}

struct Job* InsertJobOnPos_FromOp(Jobs* Job_total, Jobs* job_to_Add, int position)
{

    //VER MELHOR!!!!!!
    Jobs aux_total = *Job_total;
    Jobs aux_jo_toAdd = *job_to_Add, newJob = (Jobs)malloc(sizeof(struct Job));
    Jobs temp2 = NULL;
    Operation* newMachine = NULL;
    int job_index = 1, numberofop;
    int* index, * aux_numberofop;

    //Verificar se valor da posição dita não excede o nr de Jobs
    int qt = quantidadeJobs(aux_total);
    if (position > qt) { printf("Nr invalido da posicao que deseja!"); return NULL; }



    if (newJob != NULL) {
        int counter = 1;
        int position_aux = position;
        newJob = CreateStructOfJobs(newJob, aux_jo_toAdd->op, position + 1, aux_jo_toAdd->Number_Operation_PerJob);
        newJob->next = NULL;

        if (position_aux == 0) {

            newJob->next = aux_total;
            newJob->behind = NULL;

            if (aux_total != NULL) {
                aux_total->behind = newJob;
            }

            *Job_total = aux_total->behind;


            aux_total = *Job_total;
            while (aux_total != NULL)
            {
                if (counter != 1) {
                    aux_total->Number_Job += 1;
                }
                counter++;
                aux_total = aux_total->next;
            }

            return *Job_total;

        }
            while (--position) {
                aux_total = aux_total->next;
            }

            if (position_aux == qt) {
                while (aux_total->next != NULL) {
                    aux_total = aux_total->next;
                }
                aux_total->next = newJob;
                newJob->behind = aux_total;
                return *Job_total;
            }
            else{
                temp2 = aux_total->next;
                newJob->next = aux_total->next;
                newJob->behind = aux_total;
                aux_total->next = newJob;
                temp2->behind = newJob;
                *job_to_Add = temp2;
                while (temp2 != NULL)
                {
                    temp2->Number_Job += 1;
                    temp2 = temp2->next;
                }
                while ((*job_to_Add)->behind != NULL)
                {
                    (*job_to_Add) = (*job_to_Add)->behind;
                }
                return *job_to_Add;
            }
    }
    return NULL;
}

struct Job* InsertJobOnEnd(Jobs* job_to_add,int numberofop)
{
    Jobs aux = *job_to_add, newJob = (Jobs)malloc(sizeof(struct Job));
    Operation* newMachine = NULL;
    int job_index = 1;
    int* index, * aux_numberofop;
    int qt = quantidadeJobs(aux);




    if (newJob != NULL) {
        int counter = 0;


        aux_numberofop = &numberofop;


        for (int i = 0; i < numberofop; i++) {
            index = &i;
            newMachine = CreateMachineOnEnd(newMachine, index);

            if (newMachine == NULL) {
                printf("Não criou uma nova operacao, repita o processo com valores diferentes de 0 oou 9 para o numero de maquinas!! \n");
                break;
            }
        }
        newJob = CreateStructOfJobs(newJob, newMachine, qt+1, *aux_numberofop);

     


        newJob->next = NULL;

        if (*job_to_add == NULL) { aux = InsertJobOnInit(aux, numberofop); return aux; }


        while (aux->next != NULL){
            aux = aux->next;
        }

        aux->next = newJob;
        newJob->behind = aux;


        return *job_to_add;
    }
    return NULL;
}

struct Job* RemoveAJob(Jobs* job_to_remove,int position_job)
{
    Jobs aux = *job_to_remove, newJob = (Jobs)malloc(sizeof(struct Job));
    int job_index = 1, numberofop;
    int* index, * aux_numberofop;
    int qt = quantidadeJobs(aux);
    int counter = 0;


    if (qt  < position_job) { printf("O job que pretende eliminar nao existe!\n"); return NULL; }

    if (newJob != NULL) {

        while (counter !=position_job-1)
        {
            aux = aux->next;
            counter++;
        }

        //se for o no inicial que se prentende eliminar!
        if (*job_to_remove == aux)  *job_to_remove = aux->next;


        //se não for o ultimo no a eliminar! Muda o "next" se o no a ser eliminado nao for o ultimo!
        if (aux->next != NULL)
            aux->next->behind = aux->behind;

        //muda o "behund" se o no a ser eliminado nao for o primeiro no!
        /* Change prev only if node to be deleted is NOT the first node */
        if (aux->behind != NULL)
            aux->behind->next = aux->next;

        // Libertar memoria ocupado pelo node a ser eliminado!
        free(aux);
        aux = *job_to_remove;
        counter = 1;
        while (aux!=NULL)
        {
            if (counter >position_job-1){
            aux->Number_Job -= 1;
 
            }
            counter++;
            aux = aux->next;
        }
        return *job_to_remove;
    }

    return NULL;
}

struct Job* InsertANewOp_Job(Jobs* job_to_manipulate, char *decision)
{
    
    Jobs aux = *job_to_manipulate, newjob = NULL;
    Operation* newMachine_fromfile = NULL; // Lista ligada vazia
    newMachine_fromfile = aux->op;
    //char pos_op[2];
    //printf("Onde quer inserir a nova operacao? \n[I]- Incio [M]-Meio [F]-Fim\n");
    //scanf("%s", &pos_op);
  
    if (strcmp(decision, "I") == 0) {
        newMachine_fromfile = CreateMachineOnInit(aux->op);//Struct nula,numero de operaçoes, posição.. 
        if (newMachine_fromfile == NULL) {
        printf("Valor inserido invalido!");
        return NULL;
        }
        newjob = CreateStructOfJobs(aux, newMachine_fromfile, aux->Number_Job, aux->Number_Operation_PerJob + 1);
        *job_to_manipulate = newjob;
        return *job_to_manipulate;
    }
    else if (strcmp(decision, "F") == 0) {
         int qt = quantidadeObjetos(newMachine_fromfile);
         int* index =  &qt;
         newMachine_fromfile = CreateMachineOnEnd(aux->op, (index));
         if (newMachine_fromfile == NULL) {
         printf("Valor inserido invalido!");
         return NULL;
         }
    newjob = CreateStructOfJobs(aux, newMachine_fromfile, aux->Number_Job, aux->Number_Operation_PerJob + 1);
    *job_to_manipulate = newjob;
    return *job_to_manipulate;
    }
    else if (strcmp(decision, "M") == 0) {
         int pos = 0;
         printf("qual posicao que pretende?\n");
         scanf("%d", &pos);
         newMachine_fromfile = insertAtMid(aux->op, pos-1);//POS -1 PARA UM CORRETA INSERÇÃO!
         if (newMachine_fromfile == NULL) {
             printf("Valor inserido invalido!");
             return NULL;
         }
         newjob = CreateStructOfJobs(aux, newMachine_fromfile, aux->Number_Job, aux->Number_Operation_PerJob + 1);
         *job_to_manipulate = newjob;
         return *job_to_manipulate;
    }
    else
    {
        printf("Tem de colocar os caracteres que estao disponiveis! [I]- Incio [F]-Fim\n");
        printf("Repita o processo!\n");
        return NULL;
    }        

}

struct Job* SelectJob(Jobs job, int number_job,int qt)
{


    Jobs* TotalJobsAux = (Jobs)malloc(sizeof(struct Job));
    *TotalJobsAux = job;

    int counter = 1;

    if (qt < number_job) { printf("Numero de job pretendido nao existe!"); return NULL; }

    if (*TotalJobsAux != NULL) {
        while (*TotalJobsAux != NULL)
        {
            if (counter == number_job) {
                
                (*TotalJobsAux)->behind = NULL;
                (*TotalJobsAux)->next = NULL;
               // return NULL;
                return *TotalJobsAux;
            }
            counter++;
            (*TotalJobsAux) = (*TotalJobsAux)->next;
        }
    }
    else
    {
        return NULL;
    }

}

struct Job* RemoveANewOp_Job(Jobs* job_to_manipulate)
{

    Jobs aux = *job_to_manipulate, newjob = NULL;
    Operation* newMachine_fromfile = NULL; // Lista ligada vazia
    newMachine_fromfile = aux->op;

    printf("Qual a operacao que deseja eliminar?\n");
    int aux_position;
    scanf("%d", &aux_position);
    newMachine_fromfile = RemoveAList(newMachine_fromfile, aux_position -1);

    newjob = CreateStructOfJobs(aux, newMachine_fromfile, aux->Number_Job, aux->Number_Operation_PerJob - 1);
    *job_to_manipulate = newjob;
    return *job_to_manipulate;

}

struct Job* Edit_Op_OnJob(Jobs* job_to_manipulate, char *decision, int number_of_operation,char *_decision)
{
    (*job_to_manipulate)->next = NULL;
    Jobs aux = *job_to_manipulate, newjob = NULL;
    Operation* newop = NULL; // Lista ligada vazia
    newop = aux->op;
    //Verificar se valor da posição dita não excede o nr de Jobs
    int qt = quantidadeObjetos(newop);
    if (number_of_operation > qt) { printf("Numero de operacao selecionada não existe!"); return NULL; }

    if (strcmp(decision, "A") == 0) {

        int op, machine, pos, cycletime;
        int* op_pointer = &number_of_operation, * machine_pointer = &machine, * cycletime_pointer = &cycletime;


        if (strcmp(_decision, "M") == 0) {

            printf("Qual e a nova maquina que ira ser inserida?\n");
            scanf("%d", &machine);
            printf("Em que posicao se encontra a maquina na lista? Veja pela estrutura!\n");
            scanf("%d", &pos);
            if ((machine < 0) || (pos < 0)) {
                printf("Maquina ou posicao invalida!");
            }
            else {
                newop = ModifyAListMachine(newop, op_pointer, machine_pointer, pos - 1);
            }
        }

        else if (strcmp(_decision, "T") == 0) {
            printf("Qual e o novo tempo de ciclo que ira ser inserido?\n");
            scanf("%d", &cycletime);
            printf("Em que posicao se encontra o novo tempo de ciclo  na lista? Veja pela estrutura!\n");
            scanf("%d", &pos);

            if ((machine > 0 && machine < 9) && (pos > 0 && pos < 9)) {
                printf("Maquina ou posicao invalida!");
            }
            else {
                newop = ModifyAListCycleTime(newop, op_pointer, cycletime_pointer, pos - 1);
            }
        }

        else {
            printf("Nao e uma opcao valida!!");
            return NULL;
        }
        return *job_to_manipulate;
    }

    else if (strcmp(decision, "R") == 0) {
        int* op_pointer = &number_of_operation;
        newop = RemoveMachine(newop, op_pointer);
        if (newop == NULL) return NULL;
        return *job_to_manipulate;
    }

    else if (strcmp(decision, "N") == 0) {
        int* op_pointer = &number_of_operation;
        newop = AddMachine(newop, op_pointer);
        if (newop == NULL) return NULL;
       
        return *job_to_manipulate;
    }

    else
    {
        printf("Nao e uma opcao valida!!");
        return NULL;

    }
    return NULL;
}

struct Job* OrganizeMachines(Jobs* job_total)
{
    Jobs aux = *job_total, newjob = NULL;
    Operation *newop = NULL, *aux_op = NULL; // Lista ligada vazia
    int counter = 0,counter_aux =1 ;
    int auxiliar, machinestorun; 
    int index,first_index= 0;
    while (aux !=NULL)
    {
        newop = aux->op;
        machinestorun = newop->numberofmachines;
        while (newop != NULL)
        {

            for (int i = 0; i < newop->numberofmachines; i++) {
               /* printf("\n Job == %d --- Operation______%d\n", aux->Number_Job,newop->operation);*/
                machinestorun = newop->numberofmachines;
                if (newop->operation != 1) { index = first_index + 1; }
                else { index = 1; }

                while (counter_aux < newop->numberofmachines)
                {
                    int first_cycletime = newop->cycletime[first_index];

                    int first_machine = newop->machine[first_index];

                    int second_cycletime = newop->cycletime[index];

                    int second_machine = newop->machine[index];

                    if (counter < newop->numberofmachines) {

                        if (first_cycletime > second_cycletime) {
                            newop->cycletime[first_index] = newop->cycletime[index];
                            newop->cycletime[index] = first_cycletime;


                            newop->machine[first_index] = newop->machine[index];
                            newop->machine[index] = first_machine;
                        }
                    }

                        counter++;
                        index++;

                     if (counter + 1 == machinestorun) {
                    
                        counter_aux++;
                        machinestorun--;
                        counter = 0;
                        first_index++;
                        index = first_index + 1;
                    }
                }

               /* printf("Maquina_%d == %d  TempoCiclo == %d \n", i + 1, newop->machine[i], newop->cycletime[i]);*/
            }

            counter_aux = 1;
            first_index = 0;
            newop = newop->next;
           
        }

        aux = aux->next;

    }
       



   return *job_total;
}

int LowerTimeValuePerMachine(Jobs* job_total, int number_operation, int number_of_machine,int ** Machine1)
{
    Jobs aux = *job_total, newjob = NULL;
    if (aux == NULL) {
        printf("Job to manipulate is null!");
        return -1;
    }

    Operation* operation = (*aux).op;


    int timecycle = 0;
    //ir a arvore buscar o job + a esquerda pois é o que tem menor valor!


    int index_matrix = 0,number_of_machines= 0,counter = 0 ;

        while (aux !=NULL)

        {
           
                while (operation != NULL)
                {
                    if (operation->operation == number_operation) {
                        for (int i = 0; i < operation->numberofmachines; i++)
                        {
                            if (operation->machine[i] == number_of_machine) {
                                Machine1[index_matrix][0] = (*aux).Number_Job;
                                Machine1[index_matrix][1] = operation->cycletime[i];
                                number_of_machines++;
                                index_matrix++;
                                continue;
                            }

                        }
                    }
                    operation = operation->next;
                }
                aux = (*aux).next;

                if (aux != NULL) {
                    operation = (*aux).op;
                }
        }
       /* printf("Machine == %d\n", number_of_machine);*/

        for (int row = 0; row < 8; row++)
        {
            for (int columns = 0; columns < 2; columns++)
            {
                if (row >= number_of_machines)
                {
                    counter++;
                    Machine1[row][0] = 0;
                    Machine1[row][1] = 0;

                }
                /*printf("%d     ", Machine1[row][columns]);*/
            }
          /*  printf("\n");*/
        }

       /* printf("\n");*/
        return counter/2;
}

struct Tree* TreePerMachine(int** MachinesMatrix, int counter)
{
    Jobs  OnlyAJob = NULL, TotalJobs = NULL;
    Jobs* TotalJobsAux = (Jobs)malloc(sizeof(struct Job));
    Tree* node = NULL;
    //Organizar Matrix

    int TimeOfJob = MachinesMatrix[0][1], TimeOfJob_2 = 0, Save_Job = 0,Save_Time= 0;
    double middle_index_double = 0;// middle_index_test = 1;



    //organizar matriz para inserir na arvore + facil!
    for (int i = 1; i < 7; i++) {
         TimeOfJob_2 = MachinesMatrix[i][1];


        if (TimeOfJob > TimeOfJob_2 && TimeOfJob_2 != 0) {
            Save_Job = MachinesMatrix[i - 1][0];
            Save_Time = MachinesMatrix[i - 1][1];
            MachinesMatrix[(i - 1)][0] = MachinesMatrix[i][0];
            MachinesMatrix[(i - 1)][1] = MachinesMatrix[i][1];
            MachinesMatrix[i][0] = Save_Job;
            MachinesMatrix[i][1] = Save_Time;
            i = 1;

        }

        TimeOfJob = MachinesMatrix[i][1];
    }




    for (int row = 0; row < 8; row++)
    {
        for (int columns = 0; columns < 2; columns++)
        {
         /*   printf("%d     ", MachinesMatrix[row][columns]);*/

        }

        if (MachinesMatrix[row][1] != 0) {
            middle_index_double++;
        }
        /*printf("\n");*/
    }


        middle_index_double = middle_index_double / 2;
   /* }*/
    int middle_index = (int)middle_index_double;

    //para o root ser o valor do meio!
    TotalJobs = ReadStructFromFileToJobs();
    if (TotalJobs == NULL) {
        TotalJobs = ReadStructFromFileToJobs(); //mt bugs n sei pq..
    }

    TotalJobs = InvertStructJob(&TotalJobs);
    *TotalJobsAux = TotalJobs;
    int qt = quantidadeJobs(*TotalJobsAux);
    //só faz esta ´lógica do valor médio apenas se a matrix tiver mais que um valor!
    if(counter < 7){

        OnlyAJob = SelectJob(*TotalJobsAux, MachinesMatrix[middle_index -1][0], qt);
       /* printf("\nCENTRALJob== %d; ", MachinesMatrix[middle_index - 1][0]);*/
        node = AddNode(node, OnlyAJob, MachinesMatrix[middle_index - 1][0], MachinesMatrix[0][0]);

        for (int i = 0; i < 8; i++) {
            if (MachinesMatrix[i][0] == 0) {
                break;
            }

            TotalJobs = ReadStructFromFileToJobs();
            if (TotalJobs == NULL) {
                TotalJobs = ReadStructFromFileToJobs(); //mt bugs n sei pq..
            }

            TotalJobs = InvertStructJob(&TotalJobs);
            *TotalJobsAux = TotalJobs;
            int qt = quantidadeJobs(*TotalJobsAux);

           /* printf("\nJob== %d; time == %d\n", MachinesMatrix[i][0], MachinesMatrix[i][1]);*/
            if (i != middle_index - 1) {
                int xpto = MachinesMatrix[i][0];
                OnlyAJob = SelectJob(*TotalJobsAux, MachinesMatrix[i][0], qt);
                //printf("\nCENTRALJob== %d; ", MachinesMatrix[middle_index - 1][0]);
                node = AddNode(node, OnlyAJob, MachinesMatrix[middle_index - 1][1], MachinesMatrix[i][1]);
            }

        }
    }
    else
    {
        OnlyAJob = SelectJob(*TotalJobsAux, MachinesMatrix[0][0], qt);
        //printf("\nCENTRALJob== %d; ", MachinesMatrix[middle_index - 1][0]);
        node = AddNode(node, OnlyAJob, MachinesMatrix[0][1], MachinesMatrix[0][1]);
    }

    if (node != NULL){
        return node;
    }
    else
    {
        return NULL;
    }
}

Tree* NewNode(Jobs* job) {
    Tree* node = (Tree*)malloc(sizeof(Tree));
    if (node == NULL) return NULL;	//problemas ao criar espaço em memória	
    node->job = job;
    node->leftTree = NULL;
    node->rightTree = NULL;
    return node;
}

Tree* AddNode(Tree* root, Jobs* job, int central_value,int current_value) {

    //Organizei de forma a adicionar sempre na direita da arvore!!
    if (root == NULL) {
        root = NewNode(job);
        return root;
    }
    //else {
    //    root->rightTree = AddNode(root->rightTree, job);
    //}

    if (central_value > current_value) {
        root->leftTree = AddNode(root->leftTree, job, central_value, current_value);
    }
    else
    { 
        root->rightTree = AddNode(root->rightTree, job, central_value, current_value);

    }

    return root;
}

int Escalonamento(Tree* tree, bool checklastvalue, int** matrixfinalJob, int** matrixfinalOp, int* JobsRunning, int OperationNumber, int MachineNumber,int* TimePerMachineUsed)
{
    if (checklastvalue == True ) {
        FILE* FileToWrite;


        FileToWrite = fopen("Escalonamento.csv", "w"); // r Open for both reading .


        int j;
        for (int i = 0; i < 8; i++) {
            j = 0;
            printf("Maq_%d -- ", i+1);
            fprintf(FileToWrite, "Maq_%d -- ", i + 1);
            //martelanço para saber se o espaço de memoria tem algo lá dentro...
           /* int valoraprintar = matrixfinalJob[i][j];
            int tempomachine = TimePerMachineUsed[i];*/
            for(int x = 0 ;  x < TimePerMachineUsed[i]; x++){
                /*
            while (valoraprintar > 0 && valoraprintar < 9) {*/
                fprintf(FileToWrite, "Job_%d_Op_%d;", matrixfinalJob[i][j], matrixfinalOp[i][j]);
                printf("Job_%d_Op_%d;", matrixfinalJob[i][j], matrixfinalOp[i][j]);
                j++;
            /*    valoraprintar = matrixfinalJob[i][j];*/
            }
            printf("\n");
            fprintf(FileToWrite, "\n");
        
        }
        fclose(FileToWrite);
        return 0;
        
    }

    if (tree->job->Number_Job == 0) return 0;
    Tree *treetemp = tree;

        int timecycle  = 0;
    //ir a arvore buscar o job + a esquerda pois é o que tem menor valor!
        while ((*treetemp).leftTree != NULL) {
            treetemp = (*treetemp).leftTree;
        }

        //No entanto tenho de comparar se este job já foi feito 
           ////ciclo que nos garante que nao vamos refazer o job
        int counter = 1,current_job = (*treetemp).job->Number_Job;
        for (int i = 0; i < 8; i++) {

                if ((*treetemp).job->Number_Job == JobsRunning[i]) {
                
                    treetemp = tree;
                    while (current_job != (*treetemp).job->Number_Job) {
                        if ((*treetemp).leftTree != NULL) {
                            treetemp = (*treetemp).leftTree;
                        }
                        else
                        {
                            treetemp = (*treetemp).rightTree;
                        }
                    }
                    //para ficar no da esquerda final!
                    if((*treetemp).rightTree !=NULL){
                        treetemp = (*treetemp).rightTree; // anda 1 para a direita e compara!
                    }
                    else
                    {
                        return 0; //não ha mais possibilidades retorna 0!
                    }
                    
                    current_job = (*treetemp).job->Number_Job;
                    i = -1;

                }
            }


        int _return = (*treetemp).job->Number_Job;
    

        
    //ciclo que compara com o array das maquinas ja a serem utilizadas!
        bool Onrun = False;
        int indextocompare = 0;

        //colocar o job a apontar para a operação pretendida!
        while ((*treetemp).job->op->operation != OperationNumber)
        {
            (*treetemp).job->op = (*treetemp).job->op->next;
        }   

            for (int i = 0; i < (*treetemp).job->op->numberofmachines; i++)
            {
                if ((*treetemp).job->op->machine[i] == MachineNumber) {
                    timecycle = (*treetemp).job->op->cycletime[i];
                }
            }
            for (int i = 0; i < timecycle; i++) {
                matrixfinalJob[MachineNumber -1][i+(TimePerMachineUsed[MachineNumber - 1])] = (*treetemp).job->Number_Job;
                matrixfinalOp[MachineNumber - 1][i + (TimePerMachineUsed[MachineNumber - 1])] = OperationNumber;
            }
            TimePerMachineUsed[MachineNumber - 1] += timecycle;
        return  (*treetemp).job->Number_Job;;
}

//int FinalVisualization(Tree* tree, int* JobsRunning, int OperationNumber, int MachineNumber)
//{
//    FILE* FileToWrite;
//    FileToWrite = fopen("Escalonamento.csv", "w+"); // w+ Open for  writing.
//    int timecycle = 0;
//    int matrix[8][25];
//  
//    //Buscar o Job +esquerda(tem o menor tempo) e adicionar ao array , no entanto verificar se este nao já esta já a ser utilizado!
//
//    while (tree->leftTree != NULL) {
//        tree = tree->leftTree;
//    }
//
//
//    bool Onrun = False;
//
//    for (int i = 0; i < 8; i++) {
//
//        if (tree->job->Number_Job == JobsRunning[i]) {
//            Onrun == True;
//        }
//    }
//
//    if (Onrun == False) {
//
//
//        while (tree->job->op->operation != OperationNumber)
//        {
//            tree->job->op = tree->job->op->next;
//        }
//
//        for (int i = 0; i < tree->job->op->numberofmachines; i++)
//        {
//            if (tree->job->op->machine[i] == MachineNumber) {
//                timecycle = tree->job->op->cycletime[i];
//            }
//        }
//
//        char job[25] = "Job__";
//        char operation[] = "Op_;";
//        //+"_Operation_" + ;
//        job[7] = tree->job->Number_Job + '0';
//        operation[2] = tree->job->op->operation + '0';
//
//        strcat(job,operation);
//        printf("%stimes== %d\n", job, timecycle);
//
//        //int qql = 0;
//
//        //int ArrayPerTimeSheet [2];
//
//
//        //for(int i = 0 ; i <timecycle ; i++){
//
//        //    ArrayPerTimeSheet[0] = tree->job->Number_Job;
//        //    ArrayPerTimeSheet[1] = tree->job->op->operation;
//
//        //    matrix[MachineNumber - 1][i] = ArrayPerTimeSheet;
//        //    
//        //    ArrayPerTimeSheet = matrix[MachineNumber - 1][i];
//
//        //    //fseek(FileToWrite, qql, SEEK_SET);
//        //    //fputs("JOB_1_OP_1;",FileToWrite);
//        //    ////fwrite("JOB_1_OP_1;", 1, 11, FileToWrite);
//        //    ////fwrite(job, 1, 9, FileToWrite);
//
//        //    printf("%s\n", job);
//        //    qql += 11;
//        //
//        ////fprintf(FileToWrite, "\n");
//        //}
//    }
//    fclose(FileToWrite);
//    //free(job);
//
//    return tree->job->Number_Job;
//} //old
//

bool checkjobfinish(Jobs* job, int numberofjob, int machine,int timer)
{
    Jobs  TotalJob = *job;

    while (TotalJob->Number_Job != numberofjob) {
        TotalJob = TotalJob->next;
    }

    int timer_temp = 0;

    for (int i = 0; i < TotalJob->op->numberofmachines; i++) {
        if (TotalJob->op->machine[i] == machine) {
            timer_temp = TotalJob->op->cycletime[i];
        }
    }

    if (timer == timer_temp) {
        //fazer algo que remova o job do array!!!
    }

    return False;
}



