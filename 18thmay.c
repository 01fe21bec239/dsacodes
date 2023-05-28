#include<stdio.h>

int main()
{
    int r,c;
    printf("Enter the size of the matrix: ");
    scanf("%d %d",&r,&c);
    if(r!=c)
        printf("The given matrix is not a square matrix and hence symmetry cannot be determined\n");
    else
    {
        int matrix[r][c];
        int i,j,status=1;
        printf("Enter the matrix\n");
        for(i=0;i<r;i++)

        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
        for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
        {
            if (matrix[i][j]!=matrix[j][i])
            {
            status=0;
            }
        }
        }
        if(status==1)
        printf("The given matrix is symmetric\n");
        else
        printf("The given matrix is not symmetric\n");
    }
    return 0;
}
