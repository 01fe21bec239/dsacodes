//bubble sort
#include<stdio.h>
#include<time.h>
main()
{
int array[100000],c,d,swap;
time_t start,end;
double tc;
int n= malloc(sizeof(n));
printf("enter total elements");
scanf("%d",&n);
for(c=n;c>0;c--)
{
array[c]=c+1;
}
start=clock();
for(c=0;c<n-1;c++)
{
for(d=0;d<n-c-1;d++)
{
if(array[d]>array[d+1])
{
swap=array[d];
array[d]=array[d+1];
array[d+1]=swap;
}
}
}
end=clock();
tc=(difftime(end,start)/CLOCKS_PER_SEC);
printf("time efficiency is %lf",tc);
}
