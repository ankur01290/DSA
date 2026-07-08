#include<iostream>
using namespace std;

int main(){
    int arr[3][4]={{1,3,4,5},{2,3,6,8},{2,3,5,6}};
    

    int *b[3];
    b[1]= new int[3];
    b[2]=new int[3];
    b[3]=new int[3];

    b[3][3]=15;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    int **c;
    c=new int*[3];
    c[0]=new int[4];
    c[1]=new int[4];
    c[2]=new int[4];
    c[3][2]=15;
    

}