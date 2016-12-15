#include<iostream>
using namespace std;


int main(){
    int x[10]={1,2,3,4,5,6,7,8,9,10};   /*1D Array*/
    cout<<x[2]<<endl;    /*print the 3rd element of the array*/

    for(int i=0;i<10;i++){    /*print all the elements of the array*/
        cout<<x[i]<<endl;
    }

    int y[10][10];    /*initialise a 2D array(matrix) of size 10*10*/

    for(int i=0;i<10;i++){       /*initialising each element of the array*/
        int num=1;
        for(int j=0;j<10;j++){
            y[i][j]=num;
            num++;
        }
    }

    for(int i=0;i<10;i++){        /*printing the matrix y*/
        for(int j=0;j<10;j++){
            cout<<y[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}
