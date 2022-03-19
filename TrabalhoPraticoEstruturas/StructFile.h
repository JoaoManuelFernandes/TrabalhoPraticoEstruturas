#pragma once
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
//#include <conio.h>/*for clrscr()*/


typedef struct Job
{
    int operation; // 01,02,03,04,...
    int* machine; // 1,2,3,4,5,6,7,... // ver como posso sem ter o valor fixo de 100
    int* cycletime;

    int numberofmachines; // Para saber quantos elementos tenho no "array" // foi criado com apontadores!!!
    struct Job* next;
}Operation;

typedef enum { False, True } bool;

int MainFunction();
struct Job* CreateJob(Operation* newjob, int* op, int* index);
void CheckOperations(Operation* newjob);

bool SaveStructToFile(Operation* newjob);
struct Job* ReadStructFromFile(Operation* newjob_fromfile);

int* AuxReadFile(FILE*);

struct Job* AuxCreateStruct(int*, FILE*, Operation* newjob_fromfile,int,int*);


//vou criar 2 fun�oes de ler do ficheiro
// 1� fun��o apenas vai retornar quantas m�quinas/tempo de ciclo existe por opera��o
//2� fun��o , envio por paramentro esse valor e cria-se a lista a partir desse valor! e volta a ler os elementos e insere na lista//n esta feito!!
