#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"

//Declarar fun��es
int MainFunction();
struct Job* GetValuesToInsertNewJob();
void CreateJob();

int MainFunction()
{
        int optionselected;
        setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites

        printf("\nM E N U\n");
        printf("\nPor favor selecione qual opera��o pretendida\n");
        printf("1 - Insercao de um novo cenario \n");
        printf("2 - Pesquisar um cenario pelo codigo\n");
        printf("3 - Listagem dos cenarios por ordem crescente\n");
        printf("4 - Alterar um cenario\n");
        printf("5 - Remover um cenario\n");
        printf("6 - Simular um cenario\n");
        printf("7 - Armazenar os cenarios\n");
        printf("8 - Carregar os cenarios\n");
        printf("O - SAIR\n");

        do
        {
            scanf(" %d", &optionselected);
            system("cls");
            //clrscr();
        } while ((optionselected < 0) || (optionselected > 8));

        return(optionselected);

}

//struct Job* GetValuesToInsertNewJob()
//{
//    struct Job* newjob;
//    newjob = (struct Job*)malloc(sizeof(struct Job));
//    int *operation, *machine, *cycletime,MachinesPerOp;
//
//    printf("Quantas opera��es ter�?\n");
//    scanf(" %d", &operation);
//
//    for (int i = 0; i < *operation; i++) {
//        machine = malloc(*operation * sizeof(int));
//        cycletime = malloc(*operation * sizeof(int));
//        printf("Quantas m�quinas ter� a opera��o %d ?\n", i+1);
//        scanf("Escreva � frente por favor : %d", &MachinesPerOp);
//        for (int x = 0; x < MachinesPerOp; x++) {
//            printf("Qual a m�quina associada %d ?\n", i + 1);
//            scanf("Escreva � frente por favor : %d", &machine[i]);
//            printf("Qual o tempo de ciclo %d ?\n", i + 1);
//            scanf("Escreva � frente por favor : %d", &cycletime[i]);
//        }
//    }
//
//    /* saber quantos "elementos" tem por machine */
//    //size_t length = sizeof(machine) / sizeof(machine[0]);
//
//    //for (int i = 0; i < *machine; i++) {
//
//    ////printf("Quantas opera��es ter�?\n");
//    ////scanf("Escreva � frente por favor :%d", &cycletime);
//
//    //}
//    return newjob;
//}

void CreateJob()
{
    struct Job* newjob;
    newjob = (struct Job*)malloc(sizeof(struct Job));


   

    int* operation, * machine, * cycletime, MachinesPerOp;
    int op;

    printf("Quantas opera��es ter�?\n");
    scanf("%d", &op);

    newjob->operation = &op;

    for (int i = 0; i < op; i++) {

        machine = malloc(*newjob->operation * sizeof(int));
        cycletime = malloc(*newjob->operation * sizeof(int));
        printf("Quantas m�quinas ter� a opera��o %d ?\n", i + 1);
        scanf("%d", &MachinesPerOp);

        for (int x = 0; x < MachinesPerOp; x++) {
            printf("Qual a m�quina associada %d ?\n", x + 1);
            scanf("%d", &newjob->machine[i]);
            printf("Qual o tempo de ciclo %d ?\n", x + 1);
            scanf("%d", &newjob->cycletime[i]);

        }
    }
    if (init == 0)
    {
        init= final = newjob;
        init->next = init;
        init->prev = init;
        // Atribuir os endere�os e guardar no init e no final(porque � a 1 vez)
    }
    else {

        final->next = newjob; // atribuir o novo valor
        newjob->prev = final; // ficar com o valor velho
        init->prev = newjob;// atribuir o proximo valor
        final = newjob; //


        //

    }
    newjob;
    // breakpoint para entender melhor esta fun��o do azevedo
}

int main() {

        init = 0;

        int optionselected;//operation, machine, cycletime;
        int flag; // garantir que nao se faz a mesma opera��o 2x
        do
        {
            optionselected = MainFunction();
    
            switch (optionselected)
            {
    
            case 1:
      
                while (optionselected == 1)
                {      
                   // flag = Same(optionselected);
    
                    //if (flag == 0)
                    //{
                        //struct Job *insertjob = GetValuesToInsertNewJob();
                        CreateJob();
                    //}
                    //else {
    
                    //    printf("C�digo do Cenario ja existe!!\n");
                    //}
    
    
                    printf("Continuar a Inserir ?\n");
                    printf("1-Sim 0-Nao\n");
                    scanf( "%d", &optionselected);
    
                }

            }
        } while (optionselected == 0);
        printf("Consola ir� encerrar\n");
        //sleep(1);
        exit(0);

}