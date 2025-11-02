
#include <stdio.h>
int mylist[5];
int tos = -1;

void push(int newitem){
    if (tos == sizeof(mylist) - 1){
        printf("stack is full");
    }else{
        tos = tos + 1;
        mylist[tos] = newitem;
        printf("item is added to stack..\n");
    }
}
void pop(){
    if (tos == -1){
        printf("stack is empty..\n");
    }else{
        printf("%d\n", mylist[tos]);
        mylist[tos] = 0;
        tos = -1;
        printf("item is popped\n");
    }
}
void peek(){
    printf("%d", tos);
}
void display(){
    for (int i = 0; i < 5; i++){
        printf("%d |", mylist[i]);
    }
}
int main() {
    int choice;
    int nitem;
    int select = 1;
    while (select != 0){
    printf("what you want to do; 1,2,3,4, or 5?\n");
    printf(" 1. Push\n 2. Pop\n 3. Peek\n 4.Display\n 5. Exit\n Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("enter number to push: ");
            scanf("%d", &nitem);
            push(nitem);
            printf("another task? enter 1 for yes or 0 for no \n");
            printf("choice: ");
            scanf("%d", &select);
            
        break;
        case 2:
            pop();
            printf("another task? enter 1 for yes or 0 for no \n");
            printf("choice: ");
            scanf("%d", &select);
        break;
        case 3:
            peek();
            printf("another task? enter 1 for yes or 0 for no \n");
            printf("choice: ");
            scanf("%d", &select);
        break;
        case 4:
            display();
            printf("another task? enter 1 for yes or 0 for no \n");
            printf("choice: ");
            scanf("%d", &select);
        break;
        case 5:
            printf("your tasks have been done..\n ");
            select = 0;
        break;
            
    }
    }

    return 0;
}