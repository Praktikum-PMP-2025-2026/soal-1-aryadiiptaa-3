#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push_front(int data){
    struct Node *baru = malloc(sizeof(struct Node));
    baru->data=data;
    baru->next=head;
    head = baru;
}

void push_back(int data){
    struct Node *baru = malloc(sizeof(struct Node));
    baru->data=data;
    baru->next=NULL;
    if(head == NULL){
        head = baru;
    }
    else{
        struct Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=baru;
    }
}

void delete(int data){
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=data){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL){
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } 
    else {
        prev->next = temp->next;
    }
    free(temp);
}

void find(int data) {
    struct Node* temp = head;
    int a = 0;
    while (temp!=NULL) {
        if (temp->data==data) {
            printf("FOUND %d\n", a);
            return;
        }
        temp = temp->next;
        a++;
    }
    printf("NOT FOUND\n");
}

void tampilin(){
    struct Node *temp = head;
    if(temp==NULL){
        printf("LIST EMPTY");
        return;
    }
    printf("LIST");
    while(temp!=NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int main(){
    int M,N,data;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &N, &data);
        if(N==1){
            push_front(data);
        }
        else if(N==2){
            push_back(data);
        }
        else if(N==3){
            delete(data);
        }
        else if(N==4){
            find(data);
        }
    }
    tampilin();
    return 0;
}
