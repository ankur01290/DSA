#include<iostream>
using namespace std;

void One_To_N(int n,int i){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    One_To_N(n,i+1);

}

void N_To_One(int n,int i){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    N_To_One(n,i-1);
} 

void reverse_number(int n,int a[],int i){
    if(i>=n/2){
        return;
    }
    swap(a[i],a[n-i-1]);
    reverse_number(n,a,i+1);

}
int sum_of_number(int i){
    if(i<0){
        return 0;
    }
    
    return i + sum_of_number(i-1);
    

}

int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    //One_To_N(n,1);
    //N_To_One(n,n);

    //int a[n]={};
    //for(int i=0;i<n;i++){
    //    cout<<"storing numbers int array:";
    //    cin>>a[i];
    //}
    //reverse_number(n,a,0);

    //for(int i=0;i<n;i++){
    //    cout<<a[i]<<" ";
    //}
    cout<<sum_of_number(n);



}