#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 102400

int total = 0;
int n1,n2;
char *s1,*s2;
FILE *fp;

int readf(FILE *fp)
{
	if((fp=fopen("emoji.txt", "r"))==NULL){
		printf("ERROR: can't open string.txt!\n");
		return 0;
	}
	s1=(char *)malloc(sizeof(char)*MAX);
	if(s1==NULL){
		printf("ERROR: Out of memory!\n");
		return -1;
	}
	s2=(char *)malloc(sizeof(char)*MAX);
	if(s2==NULL){
		printf("ERROR: Out of memory\n");
		return -1;
	}
	/*read s1 s2 from the file*/
	s1=fgets(s1, MAX, fp);
	s2=fgets(s2, MAX, fp);
	n1=strlen(s1);  /*length of s1*/
	n2=strlen(s2); /*length of s2*/

	//printf("n1 is: %d\n", n1);
	//printf("n2 is: %s, %d\n", s2, n2);

	if(s1==NULL || s2==NULL || n1<n2)  /*when error exit*/
		return -1;
	return 0;
}

int num_subEmojiString(void)
{
	int i,j,k;
	int count;

	for (i = 0; i <= (n1-n2); i++){   
		count=0;
		for(j = i,k = 0; k < n2; j++,k++){  /*search for the next string of size of n2*/  
			if (*(s1+j)!=*(s2+k)){
				break;
			}else{
				count++;
			}

			if(count==n2){  
				total++;		/*find a substring in this step*/   
			}                       
		}
	}
	return total;
}

int main(int argc, char *argv[])
{
	int count;
 
	readf(fp);
	count = num_subEmojiString();
 	printf("The number of substrings is: %d\n", count);
	return 1;
}





