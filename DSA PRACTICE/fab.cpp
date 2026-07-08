#include<iostream>
using namespace std;

int fab(int n){
    if(n<=1){
        return n;
    }
    return fab(n-2)+fab(n-1);
    
}

int f[10];
int fib(int n){
    if(n<=1){
        f[n]=n;
        return n;
    }
    else{
        if(f[n-2]==-1){
            f[n-2]=fib(n-2);
        }
        if(f[n-1]==-1){
            f[n-1]=fib(n-1);
        }
        return f[n-2]+f[n-1];
    }
}

int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    for(int i=0;i<n;i++){
        f[i]=-1;
    }

    cout<<fib(n);
}

