#pragma once
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
//#include <conio.h>/*for clrscr()*/


typedef struct Machine
{
    int operation; // 01,02,03,04,...
    int* machine; // 1,2,3,4,5,6,7,... // ver como posso sem ter o valor fixo de 100
    int* cycletime;

    int numberofmachines; // Para saber quantos elementos tenho no "array" // foi criado com apontadores!!!
    struct Machine* next;
}Operation;


typedef enum { False, True } bool;

int MainFunction();
int quantidadeObjetos(Operation* obj);
struct Machine* CreateMachineOnFirstTime(Operation* newMachine);
struct Machine* CreateMachineOnInit(Operation* newMachine);
struct Machine* insertAtMid(Operation* newMachine, int pos);
struct Machine* CreateMachineOnEnd(Operation* newMachine, int* op, int* index);
struct Machine* RemoveAList(Operation* newMachine , int pos);
struct Machine* ModifyAListMachine(Operation* newMachine, int *operation,int *machine, int pos);
struct Machine* ModifyAListCycleTime(Operation* newMachine, int* operation, int* cycletime, int pos);
struct Machine* InvertStruct(Operation* newMachine);
void CheckOperations(Operation* newMachine);
void LessTimeToComplete(Operation* newMachine);
void LargerTimeToComplete(Operation* newMachine);
void AllCombinations(Operation* newMachine);

struct Machine* AddMachine(Operation* newMachine,int *operation);
struct Machine* RemoveMachine(Operation* newMachine, int* operation);


bool SaveStructToFile(Operation* newMachine);
struct Machine* ReadStructFromFile();

int* AuxReadFile(FILE*);

struct Machine* AuxCreateStruct(int, FILE*, Operation* newMachine_fromfile,int,int*);


//vou criar 2 funçoes de ler do ficheiro
// 1º função apenas vai retornar quantas máquinas/tempo de ciclo existe por operação
//2º função , envio por paramentro esse valor e cria-se a lista a partir desse valor! e volta a ler os elementos e insere na lista//n esta feito!!
