/**********************************************/
/**  Developer : Abdulrahman Rashad Tahoun   **/
/**  Last Edit :       2/4/2023              **/
/**********************************************/

#include "App.h"

void Login(void)
{
    char UserPass[PASS_LEN];
    char Iteration = 0, Counter = 0, Flag = 0;

    while(Iteration < 3)
    {
        if(1 == Flag)
        {
            Flag = 0;
            printf("\t\t\t\t\tEnter your Password again : ");
            gets(UserPass);
            printf("\n");
        }
        else
        {
            printf("\n\t\t\t\t\tEnter your Password : ");
            gets(UserPass);
            printf("\n");
        }

        printf("\t\t\t\t\tplease wait");
        for(Counter = 0; Counter < 15; Counter++)
        {
            printf(".");
            Sleep(50);
        }
        printf("\n\n");

        if(0 == strcmp(UserPass, "0000"))
        {
            break;
        }
        else
        {
            Flag = 1;
        }

        if(1 == Flag)
        {
            Iteration++;
            printf("\t\t\t\t\tInvalid Password!! \n\n");
        }
        else{}
    }

    if(3 == Iteration)
    {
        printf("\t\t\t\t\tYou are not valid to try again\n");
    }
    else
    {
        Main_Menu();
    }
}

static void Main_Menu(void)
{
    char CheckYN = 'n';
    StudType State = 1, MainChoice, ID;
    Stack MyStack;
    Student PopStud;
    Subject MySubject;

    CreateStack(&MyStack);

    /* Creating Student Account before Run-time*/
    Student MyStud = {
         "ali",
         "01150560340",
         1,
         16,
         12,
         1998,
    };
    /*strcpy(MyStud.StudName, "ali");
    strcpy(MyStud.StudPhone, "01150560340");
    MyStud.StudID = 1;
    MyStud.Birthday.day = 16;
    MyStud.Birthday.month = 12;
    MyStud.Birthday.year = 1998;*/
    New_Student(&MyStud, &MyStack);
    CreateTree(&MyStack);
    MySubject.Key = 2;
    MySubject.Score = 70;
    InsertTree(&MyStack, &MySubject);
    MySubject.Key = 1;
    MySubject.Score = 60;
    InsertTree(&MyStack, &MySubject);
    MySubject.Key = 3;
    MySubject.Score = 80;
    InsertTree(&MyStack, &MySubject);
    /* End from creating */

    printf("\n\t\t\t\t----------------------Welcome---------------------\n\n"
           "\t\t\t\tPress any key to continue...........");
    getch();
    system("CLS");

    printf("\n\t\t\t\t-------This is a School Management System---------\n");

    while(State)
    {
        if('n' == CheckYN)
        {
            printf("\n\t\t\t\t***************************************************\n"
                   "\t\t\t\t* Please select your function :-                  *\n"
                   "\t\t\t\t* Enter 1 to create a new student account.        *\n"
                   "\t\t\t\t* Enter 2 to delete a student account.            *\n"
                   "\t\t\t\t* Enter 3 to view the students information.       *\n"
                   "\t\t\t\t* Enter 4 to edit a particular student account.   *\n"
                   "\t\t\t\t* Enter 5 to view students Computer Science Rank. *\n"
                   "\t\t\t\t* Enter 6 to update all students grades.          *\n"
                   "\t\t\t\t* Enter 7 to Exit the program.                    *\n"
                   "\t\t\t\t***************************************************\n");
            printf("_______________________________________________________________________\n");

            printf("Enter your choice here: ");
            fflush(stdin);
            while(scanf("%hd", &MainChoice) != 1)
            {
                printf("Please Enter a Number : ");
                while(getchar() != '\n');
            }

            switch(MainChoice)
            {
            case 1 :
                /* Creating Student Account at Run-time*/
                printf("\nCreating a student account :- \n");
                fflush(stdin);
                printf("Enter Student Name : ");
                gets(MyStud.StudName);
                printf("Enter Student ID : ");
                while(scanf("%hu", &(MyStud.StudID)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }

                fflush(stdin);
                printf("Enter Student Phone Number : ");
                gets(MyStud.StudPhone);
                printf("Enter Student Birthday\nDay : ");
                while(scanf("%hu", &(MyStud.Birthday.day)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                printf("Month : ");
                while(scanf("%hu", &(MyStud.Birthday.month)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                printf("Year : ");
                while(scanf("%hu", &(MyStud.Birthday.year)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }

                New_Student(&MyStud, &MyStack);

                CreateTree(&MyStack);
                printf("Enter Student grades : \n");
                MySubject.Key = 2;
                printf("Computer science : ");
                while(scanf("%hu", &MySubject.Score) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                InsertTree(&MyStack, &MySubject);
                MySubject.Key = 1;
                printf("Automatic Control : ");
                while(scanf("%hu", &MySubject.Score) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                InsertTree(&MyStack, &MySubject);
                MySubject.Key = 3;
                printf("Embedded Systems : ");
                while(scanf("%hu", &MySubject.Score) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                InsertTree(&MyStack, &MySubject);
                printf("\n--->The account has been added successfully\n\n");
                printf("Do you want to insert another account (y/n)? ");
                fflush(stdin);
                scanf("%c", &CheckYN);
                if('n' == CheckYN)
                {
                    system("CLS");
                }
                break;

            case 2:
                printf("\nDeleting a student account :- \n");
                if(MyStack.top != NULL)
                {
                    printf("Enter Student ID : ");
                    while(scanf("%hu", &ID) != 1)
                    {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                    }
                    Delete_Student(ID, &PopStud, &MyStack);
                    if(MyStack.top == NULL)
                    {
                        printf("--->There are no accounts now\n");
                        printf("\n\n\t\t\tPress any key to return to main menu.....");
                        getch();
                        system("CLS");
                    }
                    else
                    {
                        printf("Do you want to delete another account (y/n)? ");
                        fflush(stdin);
                        scanf("%c", &CheckYN);
                        if('n' == CheckYN)
                        {
                            system("CLS");
                        }
                    }
                }
                else
                {
                    printf("--->There are no accounts to delete\n");
                    printf("\n\n\t\t\tPress any key to return to main menu.....");
                    getch();
                    system("CLS");
                }
                break;

            case 3:

                Student_List(&MyStack);
                printf("\n\n\t\t\tPress any key to return to main menu.....");
                getch();
                printf("\n\n\n");
                break;

            case 4:
                printf("\nEditing student accounts :- \n");
                if(MyStack.top == NULL)
                {
                    printf("--->There are no accounts to edit\n\n");
                    printf("\n\n\t\t\tPress any key to return to main menu.....");
                    getch();
                    system("CLS");
                }
                else
                {
                    printf("Enter Student ID : ");
                    while(scanf("%hu", &ID) != 1)
                    {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                    }
                    Student_Edit(ID, &MyStack);
                    printf("Do you want to edit another account (y/n)? ");
                    fflush(stdin);
                    scanf("%c", &CheckYN);
                    if('n' == CheckYN)
                    {
                        system("CLS");
                    }
                }
                break;

            case 5:
                Rank_Student(&MyStack);
                printf("\n\n\t\t\tPress any key to return to main menu.....");
                getch();
                break;

            case 6:
                printf("\nUpdating all students grades :- \n");
                Student_ScoreTree(&MyStack);
                printf("\n\n\t\t\tPress any key to return to main menu.....");
                getch();
                system("CLS");
                break;
            case 7:
                printf("\n\t\t\t----------------------Thank you--------------------\n");
                State = 0;
                break;

            default:
                printf("Invalid Choice, Please Enter a number between 1 and 7\n");
                printf("Press any key to return to main menu.....");
                getch();
                system("CLS");
                break;
            }
        }
        else if('y' == CheckYN)
        {
            switch(MainChoice)
            {
            case 1 :
                /* Creating Student Account at Run-time*/
                fflush(stdin);
                printf("Enter Student Name : ");
                gets(MyStud.StudName);
                printf("Enter Student ID : ");
                while(scanf("%hu", &(MyStud.StudID)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }

                fflush(stdin);
                printf("Enter Student Phone Number : ");
                gets(MyStud.StudPhone);
                printf("Enter Student Birthday\nDay : ");
                while(scanf("%hu", &(MyStud.Birthday.day)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                printf("Month : ");
                while(scanf("%hu", &(MyStud.Birthday.month)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                printf("Year : ");
                while(scanf("%hu", &(MyStud.Birthday.year)) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }

                New_Student(&MyStud, &MyStack);

                CreateTree(&MyStack);
                printf("Enter Student grades : \n");
                MySubject.Key = 2;
                printf("Computer science : ");
                while(scanf("%hu", &MySubject.Score) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                InsertTree(&MyStack, &MySubject);
                MySubject.Key = 1;
                printf("Automatic Control : ");
                while(scanf("%hu", &MySubject.Score) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                InsertTree(&MyStack, &MySubject);
                MySubject.Key = 3;
                printf("Embedded Systems : ");
                while(scanf("%hu", &MySubject.Score) != 1)
                {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                }
                InsertTree(&MyStack, &MySubject);
                printf("\n--->The account has been added successfully\n\n");
                printf("Do you want to insert another account (y/n) : ");
                fflush(stdin);
                scanf("%c", &CheckYN);
                if('n' == CheckYN)
                {
                    system("CLS");
                }
                break;

            case 2:
                if(MyStack.top != NULL)
                {
                    printf("Enter Student ID : ");
                    while(scanf("%hu", &ID) != 1)
                    {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                    }
                    Delete_Student(ID, &PopStud, &MyStack);
                    if(MyStack.top == NULL)
                    {
                        printf("--->There are no accounts now\n");
                        printf("\n\n\t\t\tPress any key to return to main menu.....");
                        getch();
                        system("CLS");
                    }
                    else
                    {
                        printf("Do you want to delete another account (y/n)? ");
                        fflush(stdin);
                        scanf("%c", &CheckYN);
                        if('n' == CheckYN)
                        {
                            system("CLS");
                        }
                    }
                }
                else
                {
                    printf("--->There are no accounts to delete\n");
                    printf("\n\n\t\t\tPress any key to return to main menu.....");
                    getch();
                    system("CLS");
                }
                break;

            case 4:
                if(MyStack.top == NULL)
                {
                    printf("--->There are no accounts to edit\n\n");
                    printf("\n\n\t\t\tPress any key to return to main menu.....");
                    getch();
                    system("CLS");
                }
                else
                {
                    printf("Enter Student ID : ");
                    while(scanf("%hu", &ID) != 1)
                    {
                    printf("Invalid Input, Please Enter a Number : ");
                    while(getchar() != '\n');
                    }
                    Student_Edit(ID, &MyStack);
                    printf("Do you want to update another account (y/n)? ");
                    fflush(stdin);
                    scanf("%c", &CheckYN);
                    if('n' == CheckYN)
                    {
                        system("CLS");
                    }
                }
                break;

            default:

                break;
            }

        }
        else
        {
            printf("Wrong input, Please enter (y) or (n) : ");
            fflush(stdin);
            scanf("%c", &CheckYN);
            if('n' == CheckYN)
            {
                system("CLS");
            }
        }
    }
}

static void CreateStack(Stack *StackPtr)
{
    StackPtr->top = NULL;
    StackPtr->Size = 0;
}

static void New_Student(Student* StudentPtr, Stack* StackPtr)
{
    Node *NewPtr = (Node*)malloc(sizeof(Node));

    NewPtr->entry = *StudentPtr;
    NewPtr->next = StackPtr->top;
    NewPtr->pre = NULL;
    if(NULL != StackPtr->top)
    {
        StackPtr->top = NewPtr;
        StackPtr->top->next->pre = NewPtr;
    }
    else
    {
        StackPtr->top = NewPtr;
    }
    StackPtr->Size++;
}

static signed short Get_Position(StudType StudentID, Stack* StackPtr)
{
    StudType Counter;
    Node *GetPtr = StackPtr->top;

    /* Linear Search to get the student account position */
    if(NULL == StackPtr->top)
    {
        return -2;
    }
    else
    {
        for(Counter = 0; Counter <= StackPtr->Size-1; Counter++)
        {
            if(StudentID == GetPtr->entry.StudID)
            {
                return Counter;
            }
            else
            {
                GetPtr = GetPtr->next;
            }
        }
    }
    return -1;
}

static void Delete_Student(signed short StudentID,Student* SaveStud, Stack* StackPtr)
{
    StudType Counter;
    signed short Position ;
    Node *DeletePtr = StackPtr->top;
    Node *DeleteTemp = NULL;

    Position = Get_Position(StudentID, StackPtr);

    /* Deleting the student account */
    if (0 == Position)
    {
        if(NULL == StackPtr->top->next) /* In this condition memory have only one student account */
        {
            Delete_Tree(StackPtr->top);
            free(StackPtr->top);
            StackPtr->top = NULL;
            StackPtr->Size--;
            printf("--->The account has been deleted successfully\n\n");
        }
        else
        {
            Delete_Tree(StackPtr->top);
            DeleteTemp = StackPtr->top->next;
            StackPtr->top->next->pre = NULL;
            free(StackPtr->top);
            StackPtr->top = DeleteTemp;
            StackPtr->Size--;
            printf("--->The account has been deleted successfully\n\n");
        }
    }
    else if(-1 == Position)
    {
        printf("--->This ID doesn't exist, Please Enter your ID again or Enter (-1) to Return Back : ");
		while(1 != scanf("%hi", &StudentID))
        {
			printf("Invalid Input, Please Enter a Number : ");
			while('\n' != getchar());
        }
		
        if(-1 != StudentID)
        {
            Delete_Student(StudentID, SaveStud, StackPtr);
        }
        else {}
    }
    else if (-2 == Position)
    {
        printf("--->There are no accounts to delete\n");
    }
    else
    {
        DeletePtr = StackPtr->top;
        for(Counter=0; Counter < Position-1; Counter++)
        {
            DeletePtr = DeletePtr->next;
        }
        *SaveStud = DeletePtr->next->entry;
        Delete_Tree(DeletePtr->next);
        DeleteTemp = DeletePtr->next->next;
        free(DeletePtr->next);
        DeletePtr->next = DeleteTemp;
        StackPtr->Size--;
        printf("--->The account has been deleted successfully\n\n");
    }
}

static void Swap(Node* FirstNode, Stack* StackPtr)
{
    Node* ListTemp1 = NULL;
    Node* ListTemp2 = NULL;
    Node* ListTemp3 = NULL;

    if((NULL == FirstNode->pre) && (NULL == FirstNode->next->next))
    {
        FirstNode->next->next = FirstNode;
        ListTemp1 = FirstNode->next;
        FirstNode->next = NULL;
        StackPtr->top = ListTemp1;

        ListTemp1->pre = NULL;
        FirstNode->pre = ListTemp1;
    }
    else if(NULL == FirstNode->pre)
    {
        ListTemp1 = FirstNode->next->next;
        FirstNode->next->next = FirstNode;
        ListTemp2 = FirstNode->next;
        FirstNode->next = ListTemp1;
        StackPtr->top = ListTemp2;

        FirstNode->pre = ListTemp2;
        ListTemp2->pre = NULL;
    }
    else if(NULL == FirstNode->next->next)
    {
        FirstNode->next->next = FirstNode;
        FirstNode->pre->next = FirstNode->next;
        ListTemp1 = FirstNode->next;
        FirstNode->next = NULL;

        ListTemp1->pre = FirstNode->pre;
        FirstNode->pre = ListTemp1;
    }
    else
    {
        ListTemp1 = FirstNode->next->next;
        FirstNode->next->next = FirstNode;
        ListTemp2 = FirstNode->next;
        FirstNode->next = ListTemp1;
        FirstNode->pre->next = ListTemp2;

        ListTemp3 = FirstNode->pre;
        FirstNode->pre = ListTemp2;
        ListTemp2->pre = ListTemp3;
        ListTemp1->pre = FirstNode;
    }

}

static void Student_List(Stack* StackPtr)
{
    StudType Counter1, Counter2, Counter3;
    Node* ListPtr = NULL;

    if(NULL == StackPtr->top)
    {
        printf("--->There are no accounts to view\n");
    }
    else if(NULL == StackPtr->top->next)
    {
        printf("\n\n*************************Students information list****************************\n\n");
        printf("Name\tID\tPhone\t\tBirth\t\tControl\tCompSc\tEmbedded\n");
        printf("%s\t%hd\t%s\t%hd/%hd/%hd\t%hd\t%hd\t%hd",
               StackPtr->top->entry.StudName,StackPtr->top->entry.StudID, StackPtr->top->entry.StudPhone,
               StackPtr->top->entry.Birthday.day,StackPtr->top->entry.Birthday.month,StackPtr->top->entry.Birthday.year,
               StackPtr->top->entry.RootPtr->left->TreeEntry.Score, StackPtr->top->entry.RootPtr->TreeEntry.Score,
               StackPtr->top->entry.RootPtr->right->TreeEntry.Score);
    }
    else
    {
        for(Counter1 = 0; Counter1 <= StackPtr->Size-2; Counter1++)
        {
            ListPtr = StackPtr->top;

            for(Counter2 = 0; Counter2 <= StackPtr->Size-2-Counter1; Counter2++)
            {
                Counter3 = 0;

                while(ListPtr->entry.StudName[Counter3] != '\0')
                {
                    if(ListPtr->entry.StudName[Counter3] > ListPtr->next->entry.StudName[Counter3])
                    {
                        Swap(ListPtr, StackPtr);
                        break;
                    }
                    else if(ListPtr->entry.StudName[Counter3] < ListPtr->next->entry.StudName[Counter3])
                    {
                        ListPtr = ListPtr->next;
                        break;
                    }
                    else
                    {
                        Counter3++;
                    }
                }
            }
        }

        ListPtr = StackPtr->top;
        printf("\n\n*************************Students information list****************************\n\n");
        printf("Name\tID\tPhone\t\tBirth\t\tControl\tCompSc\tEmbedded\n");
        for(Counter1 = 0; Counter1 <= StackPtr->Size-1; Counter1++)
        {
            printf("%s\t%hd\t%s\t%hd/%hd/%hd\t%hd\t%hd\t%hd", ListPtr->entry.StudName, ListPtr->entry.StudID,
                   ListPtr->entry.StudPhone, ListPtr->entry.Birthday.day, ListPtr->entry.Birthday.month,
                   ListPtr->entry.Birthday.year, ListPtr->entry.RootPtr->left->TreeEntry.Score,
                   ListPtr->entry.RootPtr->TreeEntry.Score, ListPtr->entry.RootPtr->right->TreeEntry.Score);
            printf("\n");
            ListPtr = ListPtr->next;
        }
    }
}

static void Student_Edit(signed short StudentID, Stack* StackPtr)
{
    StudType Counter;
    signed short Position ;
    StudType EditChoice;
    Node *EditPtr = NULL;

    Position = Get_Position(StudentID, StackPtr);
    if(-1 == Position)
    {
        printf("--->This ID doesn't exist, Please Enter your ID again or Enter (-1) to Return Back : ");
        while(1 != scanf("%hi", &StudentID))
        {
			printf("Invalid Input, Please Enter a Number : ");
			while('\n' != getchar());
        }
		
        if(-1 != StudentID)
        {
            Student_Edit(StudentID, StackPtr);
        }
        else {}
    }
    else if(-2 == Position)
    {
        printf("--->There are no accounts to Edit\n");
    }
    else
    {
        EditPtr = StackPtr->top;
        for(Counter = 0; Counter < Position; Counter++)
        {
            EditPtr = EditPtr->next;
        }

        printf("___________________________________________\n\n");
        printf("Enter 1 to edit all student information.\nEnter 2 to edit student name.\n"
               "Enter 3 to edit student ID.\nEnter 4 to edit student phone number.\n"
               "Enter 5 to edit student birthday.\nEnter 6 to edit student grades.\nEnter 7 to do nothing.\n");

        printf("___________________________________________\n");
        printf("Enter your edit choice : ");
        fflush(stdin);
        while(1 != scanf("%hu", &EditChoice))
        {
            printf("Invalid Input, Please enter a number : ");
            while('\n' != getchar());
        }

        switch(EditChoice)
        {
        case 1 :
            fflush(stdin);
            printf("Enter new student name : ");
            gets(EditPtr->entry.StudName);
            printf("Enter new student ID : ");
            while(1 != scanf("%hu", &(EditPtr->entry.StudID)))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            fflush(stdin);
            printf("Enter new Student Phone Number : ");
            gets(EditPtr->entry.StudPhone);
            printf("Enter new Student Birthday \nDay : ");
            while(1 != scanf("%hu", &EditPtr->entry.Birthday.day))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
                printf("Month : ");
                while(1 != scanf("%hu", &EditPtr->entry.Birthday.month))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("Year : ");
             while(1 != scanf("%hu", &EditPtr->entry.Birthday.year))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }

            printf("Enter new student grades \nEnter new Automatic Control Grade : ");
            while(1 != scanf("%hu", &EditPtr->entry.RootPtr->left->TreeEntry.Score))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("Enter new Computer Science Grade : ");
            while(1 != scanf("%hu", &EditPtr->entry.RootPtr->TreeEntry.Score))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("Enter new Embedded systems Grade : ");
            while(1 != scanf("%hu", &EditPtr->entry.RootPtr->right->TreeEntry.Score))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("The account has been updated successfully\n\n");
            break;

        case 2:
            fflush(stdin);
            printf("Enter new student name : ");
            gets(EditPtr->entry.StudName);
            printf("The account has been updated successfully\n\n");
            break;

        case 3:
            printf("Enter new student ID : ");
            while(1 != scanf("%hu", &(EditPtr->entry.StudID)))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("The account has been updated successfully\n\n");
            break;

        case 4:
            fflush(stdin);
            printf("Enter new Student Phone Number : ");
            gets(EditPtr->entry.StudPhone);
            printf("The account has been updated successfully\n\n");
            break;

        case 5:
            printf("Enter new Student Birthday \nDay : ");
            while(1 != scanf("%hu", &EditPtr->entry.Birthday.day))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
                printf("Month : ");
                while(1 != scanf("%hu", &EditPtr->entry.Birthday.month))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("Year : ");
             while(1 != scanf("%hu", &EditPtr->entry.Birthday.year))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("The account has been updated successfully\n\n");
            break;

        case 6:
            printf("Enter new student grades \nEnter new Automatic Control Grade : ");
            while(1 != scanf("%hu", &EditPtr->entry.RootPtr->left->TreeEntry.Score))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("Enter new Computer Science Grade : ");
            while(1 != scanf("%hu", &EditPtr->entry.RootPtr->TreeEntry.Score))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("Enter new Embedded systems Grade : ");
            while(1 != scanf("%hu", &EditPtr->entry.RootPtr->right->TreeEntry.Score))
            {
                printf("Invalid Input, Please enter a number : ");
                while('\n' != getchar());
            }
            printf("The account has been updated successfully\n\n");
            break;

        case 7:

            break;

        default:
           // printf("Wrong Edit Choice\n");
            printf("Invalid Choice, Please Enter a number between 1 and 7\n");
            printf("Press any key to return back.....");
            getch();
            printf("\n");
            break;
        }
    }
}

static void Rank_Student(Stack* StackPtr)
{
    StudType Counter1, Counter2;
    Node *RankPtr = NULL;
    if(NULL == StackPtr->top)
    {
        printf("--->There are no accounts to view\n");
    }
    else if(NULL == StackPtr->top->next)
    {
        printf("\n\n*****Students Rank*******\n");
        printf("Name\tID\tCompSc\n%s\t%hu\t%hu\n", StackPtr->top->entry.StudName, StackPtr->top->entry.StudID,
               StackPtr->top->entry.RootPtr->TreeEntry.Score);
    }
    else
    {

        for(Counter1 = 0; Counter1 <= StackPtr->Size-2; Counter1++)
        {
            RankPtr = StackPtr->top;

            for(Counter2 = 0; Counter2 <= StackPtr->Size-2-Counter1; Counter2++)
            {
                if(RankPtr->entry.RootPtr->TreeEntry.Score < RankPtr->next->entry.RootPtr->TreeEntry.Score)
                {
                    Swap(RankPtr, StackPtr);
                }
                else if(RankPtr->entry.RootPtr->TreeEntry.Score > RankPtr->next->entry.RootPtr->TreeEntry.Score)
                {
                    RankPtr = RankPtr->next;
                }
                else
                {
                    RankPtr = RankPtr->next;
                }
            }

        }
        RankPtr = StackPtr->top;
        printf("\n\n*****Students Rank*******\n");
        printf("Name\tID\tCompSc\n");
        for(Counter1 = 0; Counter1 <= StackPtr->Size-1; Counter1++)
        {
            printf("%s\t%hd\t%hd\n", RankPtr->entry.StudName, RankPtr->entry.StudID, RankPtr->entry.RootPtr->TreeEntry.Score);
            RankPtr = RankPtr->next;
        }
    }
}

static void CreateTree(Stack* StackPtr)
{
    Node* CreatePtr = StackPtr->top;
    CreatePtr->entry.RootPtr = NULL;
}

static void InsertTree(Stack* StackPtr, Subject* SubjectPtr)
{
    Node* InsertPtr = StackPtr->top;

    if (NULL == InsertPtr->entry.RootPtr)
    {

        InsertPtr->entry.RootPtr = (TreeNode*)malloc(sizeof(TreeNode));
        InsertPtr->entry.RootPtr->TreeEntry = *SubjectPtr;
        InsertPtr->entry.RootPtr->left = NULL;
        InsertPtr->entry.RootPtr->right = NULL;
    }
    else if (SubjectPtr->Key < InsertPtr->entry.RootPtr->TreeEntry.Key)
    {

        InsertPtr->entry.RootPtr->left = (TreeNode*)malloc(sizeof(TreeNode));
        InsertPtr->entry.RootPtr->left->TreeEntry = *SubjectPtr;
        InsertPtr->entry.RootPtr->left->left = NULL;
        InsertPtr->entry.RootPtr->left->right = NULL;
    }
    else
    {
        InsertPtr->entry.RootPtr->right = (TreeNode*)malloc(sizeof(TreeNode));
        InsertPtr->entry.RootPtr->right->TreeEntry = *SubjectPtr;
        InsertPtr->entry.RootPtr->right->left = NULL;
        InsertPtr->entry.RootPtr->right->right = NULL;
    }
}

static void Student_ScoreTree(Stack* StackPtr)
{
    char RetBack;
    Node* ScorePtr = StackPtr->top;

    if(NULL == StackPtr->top)
    {
        printf("--->There are no accounts to update\n");
    }

    while(NULL != ScorePtr)
    {
        if(ScorePtr->entry.RootPtr)
        {
            printf("\n****New grades for student %s****\n", ScorePtr->entry.StudName);
            printf("--->Enter (y) to continue or Press any key to Return Back : ");
            fflush(stdin);
            scanf("%c", &RetBack);
            if('y' == RetBack)
            {
                if(ScorePtr->entry.RootPtr->left)
                {
                    printf("Automatic Control : ");
                    while(1 != scanf("%hd", &ScorePtr->entry.RootPtr->left->TreeEntry.Score))
                    {
                        printf("Invalid Input, Please enter a number : ");
                        while('\n' != getchar());
                    }
                    printf("Computer Science : ");
                    while(1 != scanf("%hd", &ScorePtr->entry.RootPtr->TreeEntry.Score))
                    {
                        printf("Invalid Input, Please enter a number : ");
                        while('\n' != getchar());
                    }
                }
                else
                {
                    printf("Computer Science : ");
                    while(1 != scanf("%hd", &ScorePtr->entry.RootPtr->TreeEntry.Score))
                    {
                        printf("Invalid Input, Please enter a number : ");
                        while('\n' != getchar());
                    }
                }

                if(ScorePtr->entry.RootPtr->right)
                {
                    printf("Embedded Systems : ");
                    while(1 != scanf("%hd", &ScorePtr->entry.RootPtr->right->TreeEntry.Score))
                    {
                        printf("Invalid Input, Please enter a number : ");
                        while('\n' != getchar());
                    }
                }
                ScorePtr = ScorePtr->next;
            }
            else
            {
                break;
            }
        }
    }
}

void Delete_Tree(Node* StackPtr)
{
    TreeNode* DeleteTemp1 = NULL;
    TreeNode* DeleteTemp2 = NULL;

    DeleteTemp1 = StackPtr->entry.RootPtr;
    free(StackPtr->entry.RootPtr->left);
    DeleteTemp2 = DeleteTemp1;
    free(DeleteTemp1->right);
    free(DeleteTemp2);
}
