using namespace std;
#include<bits/stdc++.h>

int q[10000];
int sz;

int front_ = -1;
int rear = -1;

int PoP() {
    if(front_ == -1) return -999;
    else {
        int node = q[front_];
        if(front_ == rear) front_ = -1, rear = -1;
        front_ = (front_+1)%sz;
        return node;
    }
}

int Push(int node) {
    if(front_ == (rear+1) || (front_ ==0  && rear == sz-1 ) ) {
        cout << " overflow" << endl;
        return 0;
    } else {
        if( front_ == 0 ) front_ = -1;
            rear = (rear+ 1)%sz;
            q [ rear ] = node;
            return 1;
        }
}

int main() {
    int n;
    cin >> sz;
    int opt;
    cin >> opt;
    if(opt==1) {
        int num;
        cin >> num;
        if(Push(num)==1) cout << "success push !!" << endl;
        cout << " here " << endl;
    } else {
        int ans = PoP();
        if(ans != -999) cout << "the popped element is " <<  ans << endl;
        else cout << " underflow" << endl;
    }
    return 0;
}
