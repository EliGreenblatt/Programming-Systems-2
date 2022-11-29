#include <stdio.h>

void changeToInfinity(int arrFW [10][10]);
void implementFloydW(int arr [10][10], int arrFW [10][10]);
void printM(int arrFW [10][10]);
int min(int a,int b);

//function takes input from user into a two dimensional array
//and then implements the Floyd-Warshall algorithm 

void enterNumbers(int arr [10][10],int arrFW[10][10]) 
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &arr[i][j]);
        } 

    }  


    changeToInfinity(arr); // changes no path values to infinity
    implementFloydW(arr,arrFW); // implements the Floyd-Warshall algorithm
}

int min(int a,int b) //returns minimum from two ints
{
    if(a < b)
    {
        return a;
    }

    else 
    {
        return b;
    } 
}

//find where value is 0 for no path Besides the diagonal , and change to infinity
void changeToInfinity(int arr[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 0 && i != j)
            {
                arr[i][j] = 1000;
            }   
        }    
    }
    
}

void implementFloydW(int arr[10][10],int arrFW[10][10])
{
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
            }
            
        }
        
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arrFW[i][j] = arr[i][j];
        }
        
    }    
}

//prints true or false based on if there is a path from i to j. after implementing
//the Floyd-Marshall algorithm
void isPath (int arrFW[10][10] ,int i,int j)
{
    if (arrFW[i][j] != 1000 && arrFW[i][j] != 0)
    {
        printf("True\n");
        return;
    }

    printf("False\n");
}

//prints -1 if there is no path , otherwise prints the weight of path from i to j
void shortestPath(int arrFW [10][10] , int i, int j)
{
    if(arrFW[i][j] == 1000 || arrFW[i][j] == 0)
    {
        printf("-1\n");
        return;
    }
    printf ("%d\n" ,arrFW[i][j]);
}