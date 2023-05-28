#include <stdio.h>
#include <string.h>
void readstr(char string[10][30],int n);
void search(char string[10][30],int n);
int main()
{
	//Declare Variables
	char string[10][30];
	int n;
	printf("Enter number of strings to input\n");
	scanf("%d", &n);
	readstr(string,n);
	search(string,n);
	return 0;
}
void readstr(char string[10][30],int n)
{
    int i;
    printf("Enter Strings one by one: \n");
	for(i=0; i< n ; i++) {
		gets(string[i]);
	}

}
void search(char string[10][30],int n)
{
    int i,j,k;
    char w[5]="could";
    for(i=0;i<n;i++)
    {
        j=0;
        k=0;
        while(string[i][j]!='\0')
        {
            if(string[i][j]==w[k])
            {

            }
            j++;
            k++;
        }
    }
    printf("%s",w);
}
