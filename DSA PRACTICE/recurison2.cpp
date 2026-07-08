#include<iostream>
using namespace std;

void one_N(int n,int i){
    if(i>n){
        return;
    }
    cout<<i;
    one_N(n,i+1);
}

void n_one(int n,int i){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    n_one(n,i-1);
}

//int mean_of_aaray(int n,int array[],int i){
    //int sum=0;
    //if (i>n-1){
        //return sum;
    //}
    //sum=sum+array[n-i-1];
    //return mean_of_aaray(n,array,i+1);
    //sum=sum/n;

//}

void static_var_recu(int n){
    
    if(n>0){
        cout<<n;
        static_var_recu(n-1);
        static_var_recu(n-1);
    } 
}


int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    //one_N(n,1);
    //n_one(n,n);

    //int array[n]={};
    //for(int i=0;i<n;i++){
        //cout<<"enter the number for array:";
        //cin>>array[i];
    //}

    static_var_recu(n);

    //for (int i = 0; i < n; i++)
    //{
    //    cout<<array[i]<<" ";
    //}
    
}
