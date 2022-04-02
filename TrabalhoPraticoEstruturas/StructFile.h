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
int quantidadeObjetos(Operation* obj);
struct Job* CreateJobOnFirstTime(Operation* newjob);
struct Job* CreateJobOnInit(Operation* newjob);
struct Job* insertAtMid(Operation* newjob, int pos);
struct Job* CreateJobOnEnd(Operation* newjob, int* op, int* index);
struct Job* RemoveAList(Operation* newjob , int pos);
struct Job* ModifyAListMachine(Operation* newjob, int *operation,int *machine, int pos);
struct Job* ModifyAListCycleTime(Operation* newjob, int* operation, int* cycletime, int pos);
struct Job* InvertStruct(Operation* newjob);
void CheckOperations(Operation* newjob);
void LessTimeToComplete(Operation* newjob);
void LargerTimeToComplete(Operation* newjob);
void AllCombinations(Operation* newjob);

struct Job* AddMachine(Operation* newjob,int *operation);
struct Job* RemoveMachine(Operation* newjob, int* operation);


bool SaveStructToFile(Operation* newjob);
struct Job* ReadStructFromFile();

int* AuxReadFile(FILE*);

struct Job* AuxCreateStruct(int, FILE*, Operation* newjob_fromfile,int,int*);


//vou criar 2 funçoes de ler do ficheiro
// 1º função apenas vai retornar quantas máquinas/tempo de ciclo existe por operação
//2º função , envio por paramentro esse valor e cria-se a lista a partir desse valor! e volta a ler os elementos e insere na lista//n esta feito!!
