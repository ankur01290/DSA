#include<iostream>
using namespace std;



int nested_recu(int n){
    if(n>100)
    {
        
        return n-10;
        /* code */
    }
    else{
        return nested_recu(nested_recu(n+11));
    }
    
}

int sum_of_natural_number(int n){
    static int sum=0;
    if(n<1){
        return sum;
    }
    sum=sum+n;
    return sum_of_natural_number(n-1);
}

int facto_number(int n){
    if(n==0){
        return 1;
    }
    return facto_number(n-1)*n;
}



int power(int m, int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return power(m*m,n/2);
    }
    else{
        return m*power(m*m,(n-1)/2);
    }
}



int main(){
    int n,m;
    cout<<"enter the number:";
    cin>>m;
    cout<<"enter the power of number:";
    cin>>n;
    //cout<<nested_recu(n);
    //cout<<sum_of_natural_number(n);
    cout<<power(m,n);
}