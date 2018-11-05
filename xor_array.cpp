#include<bits/stdc++.h>
using namespace std;

struct demo{
    int zo, on;
    demo* next[3];
    demo(){
        zo = 0, on = 0;
        next[0] = NULL;
        next[1] = NULL;
    }
} *head = NULL;


vector<int> store;
vector<int> fstore;
void againpass(){
    demo* curr = head;
    for(int i = 0; i<store.size(); i++){
        int idx = store[i];
        if(curr->next[idx] == NULL){
            curr->next[idx] = new demo();
        }
        curr = curr->next[idx];
    }

}
int check(int n){
    demo* curr = head;
    for(int i = 0; i<store.size(); i++){
        int idx = store[i];
        int ant = idx == 1 ? 0 : 1;
        if(curr->next[ant] != NULL){
            fstore.push_back(1);
            curr = curr->next[ant];
        }
        else{
            fstore.push_back(0);
            curr = curr->next[idx];
        }
    }
    reverse(fstore.begin(), fstore.end());
    int sum = 0;
    for(int i = 0; i<fstore.size(); i++){
        if(fstore[i] == 1){
            sum += pow(2, i);
        }
    }
    return sum;
}

void pass(int n){
    while(n != 0){
        int temp = n%2;
        store.push_back(temp);
        n /= 2;
    }
    int baki = 30 - store.size();
    for(int i = 1; i<=baki; i++)
        store.push_back(0);
    reverse(store.begin(), store.end());
}
int main(){
    int n;
    cin>>n;

    head = new demo();
    vector<int> num;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
        pass(temp);
        againpass();
        store.clear();
    }
    int res = 0;
    for(int i = 0; i<num.size(); i++){
        pass(num[i]);
        int temp = check(num[i]);
        store.clear();
        fstore.clear();
        res = max(res, temp);
    }
    cout<<res<<endl;
}
