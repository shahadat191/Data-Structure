#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};
node *head = NULL;
node *tail = NULL;

void recursive(node* curr){
    if(curr->next == NULL){
        head = curr;
        return;
    }
    recursive(curr->next);
    node* temp = curr->next;
    temp->next = curr;
    curr->next = NULL;
}

void add(int n){
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        node* temp1 = tail;
        tail = temp;
        temp1->next = tail;
    }

}

void addo(int n){
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else{
        node* curr = head;
        while(curr->next!= NULL)
            curr = curr->next;
        curr->next = temp;
    }
}

void show(){
    node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
void del(int n){

    node* curr = head;
    if(n == 1){
        head = curr->next;
        free(curr);
    }
    else{
        for(int i = 2; i<n; i++)
            curr = curr->next;
        node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}

void inse(int pos, int n){
    node* temp = new node();
    temp->data = n;
    temp->next = NULL;

    if(pos == 1){
        temp->next = head;
        head = temp;
    }
    else{
        node* curr = head;
        for(int i = 2; i<pos; i++)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
    }
}
void rev(){
    node* curr = head;
    node* prev = NULL;

    while(curr->next!= NULL){
        node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = curr;
}
int main(){
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        add(temp);
    }
    int pos, val;
    cin>>pos>>val;
    inse(pos, val);
    //recursive(head);
    show();
}
