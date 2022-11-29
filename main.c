#include <stdio.h>
#include "my_mat.h"
int main()
{
    int arrFW[10][10] = {0};
    int arr[10][10] = {0};
    int i;
    int j;

    char c;

    scanf("%c", &c);

    while (c != 'D')
    {
        if(c == 'A')
        {
            enterNumbers(arr,arrFW);
            
        }
            
        else if(c == 'B')
        {
            scanf("%d", &i);
            scanf("%d", &j);
            isPath(arrFW, i,j);
        }
        
        else if(c == 'C')
        {
            scanf("%d", &i);
            scanf("%d", &j);

            shortestPath(arrFW ,i , j);
        }
            
        if(c == 'D')
        {
            break;
        }
        
        scanf("%c" , &c);

    }
    return 0;
}