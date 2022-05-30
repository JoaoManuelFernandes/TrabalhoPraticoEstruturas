#pragma once
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>



typedef struct Machine
{
    int operation; // 01,02,03,04,...
    int* machine; // 1,2,3,4,5,6,7,... // ver como posso sem ter o valor fixo de 100
    int* cycletime;

    int numberofmachines; // Para saber quantos elementos tenho no "array" // foi criado com apontadores!!!
    struct Machine* next;
}Operation;

typedef struct Job {

    int Number_Job;
    int Number_Operation_PerJob;
    struct Job* next;
    struct Job* behind;
    Operation* op;
}*Jobs;

//Nodo da árvore
typedef struct Tree {
    Jobs job;
    struct Tree* leftTree;
    struct Tree* rightTree;
}Tree, * PtrTree;


typedef enum { False, True } bool;

int MainFunction();
int quantidadeObjetos(Operation* obj);
struct Machine* CreateMachineOnFirstTime(Operation *newMachine);
struct Machine* CreateMachineOnInit(Operation *newMachine);
struct Machine* insertAtMid(Operation *newMachine, int pos);
struct Machine* CreateMachineOnEnd(Operation* newMachine, int* index);
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
struct Machine* AuxCreateStruct(int, FILE*, Operation *newMachine_fromfile,int,int*,int);
//vou criar 2 funçoes de ler do ficheiro
// 1º função apenas vai retornar quantas máquinas/tempo de ciclo existe por operação
//2º função , envio por paramentro esse valor e cria-se a lista a partir desse valor! e volta a ler os elementos e insere na lista//n esta feito!!



//fase 2
int MainFunctionFase2();
struct Job* CreateStructOfJobs(Jobs job_to_insert, Operation* op, int index,int numberofop_perjob);
struct Job* CreateStruct(Jobs job_to_insert);
struct Job* ReadStructFromFileToJobs();
struct Job* ReadStructFromFileToJobsSupport();
void SaveAJobatFile(Jobs job_to_save);
int* AuxReadFileToJobs(FILE*);
void PrintJobsFromFile(Jobs *job_to_print);
bool PrintJobs(Jobs *job_to_print);
bool PrintJustAjob(Jobs job_to_print);
struct Job* InvertStructJob(Jobs *job_to_invert);
int quantidadeJobs(Jobs job_to_count);
bool SaveStructOfJob(Jobs job_to_save);
bool SaveStructOfJobSuppport(Jobs job_to_save);

struct Job* InsertJobOnInit(Jobs*,int);
struct Job* InsertJobOnPos(Jobs*,int,int);
struct Job* InsertJobOnPos_FromOp(Jobs*,Jobs*, int);
struct Job* InsertJobOnEnd(Jobs*,int);
struct Job* RemoveAJob(Jobs*,int);
struct Job* InsertANewOp_Job(Jobs*, char *decision);
struct Job* SelectJob(Jobs job_to_work , int,int);
struct Job* RemoveANewOp_Job(Jobs*);
struct Job* Edit_Op_OnJob(Jobs* job_to_manipulate,char *decision, int number_of_operation,char *_decision);

struct Job* OrganizeMachines(Jobs* job_total); //Organiza as maquinas por ordem de crescente os tempo de ciclo!
int LowerTimeValuePerMachine(Jobs* job_total, int number_operation,int number_of_machine,int ** );
struct Tree* TreePerMachine(int** MachinesMatrix,int counter);


struct Tree* NewNode(Jobs* job);
struct Tree* AddNode(Tree* root, Jobs* job, int central_value, int current_value);
int Escalonamento(Tree* tree, bool checklastvalue, int** matrixfinal, int** matrixfinalOp, int* JobsRunning, int OperationNumber, int MachineNumber,int *TimePerMachineUsed);
bool checkjobfinish(Jobs* job,int numberofjob,int machine,int timer);
//void ShowTree(Tree* root);
