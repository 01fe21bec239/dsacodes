#include<stdio.h>
int main()
{
    int a[10],i;
    FILE *fp1,*fp2;
    fp1=fopen("array.txt","w");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }for(i=0;i<5;i++)
    {
        fprintf(fp1,"%d",a[i]);
    }
    fclose(fp1);
    return 0;


}
