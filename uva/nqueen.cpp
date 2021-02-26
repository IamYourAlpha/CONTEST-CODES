using namespace std;
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define N 8


bool check_safty(int matrix[N][N],int row,int col)
{
 int i,j;
    for(i=0; i<col; i++)
        if(matrix[row][i]) return false;

    for( i=row, j=col; i>=0 && j>=0; i--,j--)
        if(matrix[i][j]) return false;
    for( i=row, j=col; j>=0 && i<N; i++,j--)
        if(matrix[i][j]) return false;
    return true;
}

bool solve( int matrix[N][N],int col )
{
    if(col>=N) return  true;
    for(int i=0; i<N; i++)
    {
        if( check_safty(matrix,i,col) )
        {
            matrix[i][col]=1;
            if( solve(matrix,col+1)==true )
                return true;
            matrix[i][col]=0;
        }
    }
    return false;
}

int main()
{

    //printf("pls enter the  dimension of the board \n");
    //cin>>N;
    //for(int i=0;i<N;i++)
     // for(int j=0;j<N;j++) matrix[i][j];
     int matrix[N][N]= {
    {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
     };
    if(solve( matrix,0 )== false )
        printf("no soln exist \n");
    else for(int i=0; i<N; i++){
           for(int j=0; j<N; j++){

               printf(" %d ",matrix[i][j]);
               //if(matrix[i][j]==1) printf("(%d ,%d) ",i,j);
           }
           printf("\n");
    }
    return  0;
        }
