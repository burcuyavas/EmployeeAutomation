#include <stdio.h>

int Show_Menu(){
    int choice;
    printf("========= MENU =========\n");
    printf("1--> Insert a new ID\n");
    printf("2--> Find an ID\n");
    printf("3--> Show all IDs\n");
    printf("4--> Exit\n");
    printf("Select an option (1,2,3,4)\n");
    scanf("%d",&choice);
    if(choice == 1 || choice ==2 || choice ==3 || choice ==4)
        return choice;
    else return -1;
}

int Insert(int A[ ], int ID){
    int index = 101,loopControl=0;
    if(ID>0 && ID<1000000){
        index = ID % 100;
    }
    else{
        printf("The ID must be between 0 and 1000000\n");
        return 505;
    }
    for(;index<100;index++){
            if(A[index] == -1){
                A[index] = ID;
                printf("The ID : %d is inserted into the array.\n",ID);
                return index;
                break;
            }
            if(index==99 && loopControl==0){
                index=-1;
                loopControl++;
            }
    }

    return -2;
}
int Search(int A[ ], int ID){
    int index=0;
    //Linear Search Algorithm - (Best performance with unsorted arrays)
    for(;index<100;index++){
        if(A[index]==ID){
            printf("The ID : %d has been found into index %d.\n",ID,index);
            return index;
        }
    }

    return -2;

}
void Show_All_IDs(int A[ ]){
    printf("The List of IDs");
    int idsNumberControl=100;
    for(int i=0;i<100;i++){
        if(A[i]!=-1){
            if(idsNumberControl==100){
                printf(":\n");
            }
            printf("A[%d] : %d\n",i,A[i]);
            idsNumberControl--;
        }
    }
    if(idsNumberControl==100){
        printf(" is empty.\n");
    }
    else{
        printf("Total number of employees: %d\n",100-idsNumberControl);
    }

}
int main()
{
    // The ID must be between [1-999999]
    int A[100],ID,choice;
    for(int i=0;i<100;i++){
        A[i]=-1;
    }

    do{
      choice = Show_Menu();
      switch(choice){
            case 1:
                printf("Enter the ID to be stored: ");
                scanf("%d",&ID);
                if(Insert(A,ID)==-2){
                    printf("The ID is not inserted because the array is full.\n");
                }
                break;
            case 2:
                printf("Enter the ID to be found: ");
                scanf("%d",&ID);
                if(Search(A, ID)==-2){
                    printf("The ID is not found.\n");
                }
                break;
            case 3:Show_All_IDs(A);
                break;
            case 4:
                break;
            default:
            printf("Please enter from given options.\n");
        }
    }while(choice != 4);

    return 0;
}
