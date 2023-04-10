/**********************************************/
/**  Developer : Abdulrahman Rashad Tahoun   **/
/**  Last Edit :       2/4/2023              **/
/**********************************************/

#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "Confg.h"

typedef unsigned short StudType;

typedef struct Student_Subject{
    StudType Key;
    StudType Score;
}Subject;

typedef struct treenode{
	Subject TreeEntry;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

typedef struct Student_Date{
    StudType day;
    StudType month;
    StudType year;
}Date;

typedef struct Student_Account{
    char StudName[NAME_LEN];
    char StudPhone[NUMBER_LEN];
    StudType StudID;
    Date Birthday;
    TreeNode* RootPtr;
}Student;

typedef struct node{
    Student entry;
    struct node *next;
    struct node *pre;
}Node;

typedef struct Stack{
    Node *top;
    unsigned long Size;
}Stack;

void Login(void);
static void Main_Menu(void);
static void CreateStack(Stack*);
static void New_Student(Student*, Stack*);
static short Get_Position(StudType, Stack*);
static void Delete_Student(signed short ,Student* , Stack*);
static void Swap(Node*, Stack*);
static void Student_List(Stack*);
static void Student_Edit(signed short , Stack*);
static void Rank_Student(Stack*);

static void CreateTree(Stack*);
static void InsertTree(Stack*, Subject*);
static void Student_ScoreTree(Stack*);
static void Delete_Tree(Node*);


#endif //APP_H
