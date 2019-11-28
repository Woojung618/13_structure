#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_whitespace(char c){
	if (c==' '||c=='\t'||c=='\n'||c=='('||c=='\r')
		return 1;
	
	return 0;
}

int fget_word(FILE* fp, char *word){
	char c;
	int cnt;
	while ((c=fgetc(fp))!=EOF){
		if (is_whitespace(c)==0)
			break;
		}
		if (c==EOF)
			return 0;
		
		cnt =0;
		word[cnt++]=c;
		word[cnt]='\0';
		
	
		while((word[cnt]=fgetc(fp)) !=EOF){
			if (is_whitespace(word[cnt])==1){
				word[cnt]='\0';
				break;
			}
			cnt++;
		}
		return cnt;
}




int main(void) {
	FILE *fp;
	char filepath[100];
	char word;
	
	//file open
	printf("input the file path:");
	scanf("%s",filepath);
	fp=fopen(filepath,"r");
	
	if (fp==NULL){
		printf("file path is wrong - %s\n",filepath);
		return -1;
	}
	

	
	
	//word reading and analysis
	//C:\Codes\13_structure
	
	while(fget_word(fp,word)!=0){
		printf("%s\n",word);
	}
	
	//output
	
	fclose(fp);
	
	return 0;
}
