#include<stdio.h>
#include<stdio.h>
int main(){
	char ch[2010],t[2010],F[2010];
//	scanf("%s",F);
//	freopen(F,"r",stdin);
//    scanf("%s",ch);
//	FILE *fp =fopen(F,"r");
//	fscanf(fp,"%s",ch);
 //   fclose(stdin);
    scanf("%s",ch);
	int len=strlen(ch),top=-1,l,r,isEnd=0,i;
	int priority[7][7]={
	{1,1,-1,-1,-1,1,1},
	{1,1,-1,-1,-1,1,1},
	{1,1,1,-1,-1,1,1},
	{1,1,1,0,0,1,1},
	{-1,-1,-1,-1,-1,100,0},
	{1,1,1,0,0,1,1},
	{-1,-1,-1,-1,-1,0,0}
	};
	t[++top]='#';
	ch[len]='#';
	len++;
	for(i=0;i<len;i++){
		if(ch[i]=='#'&&i!=len-1){
			printf("E\n");
			return 0;
		}
		if(ch[i]=='+')
			r=0;
		else if(ch[i]=='-')
			r=1;
		else if(ch[i]=='*')
			r=2;
		else if(ch[i]=='i')
			r=3;
		else if(ch[i]=='(')
			r=4;
		else if(ch[i]==')')
			r=5;
		else if(ch[i]=='#')
			r=6;
		else{
			printf("E\n");
			return 0;	
		} 
		if(t[top-isEnd]=='+')
			l=0;
		else if(t[top-isEnd]=='-')
			l=1;
		else if(t[top-isEnd]=='*')
			l=2;
		else if(t[top-isEnd]=='i')
			l=3;
		else if(t[top-isEnd]=='(')
			l=4;
		else if(t[top-isEnd]==')')
			l=5;
		else if(t[top-isEnd]=='#')
			l=6;
		else{
			printf("E\n");
			return 0;	
		}
		if(l==6&&r==6)
		break;
		if(priority[l][r]==100){
			t[++top]=ch[i];
			printf("I%c\n",ch[i]);
			isEnd=0;
		}else if(priority[l][r]==1){
			if(t[top]=='i'){
				t[top]='E';
			}
			else if((top>=3&&t[top]=='E'&&t[top-2]=='E'&&t[top]=='E'&&(t[top-1]=='+'||t[top-1]=='*'))||(top>=3&&t[top]==')'&&t[top-2]=='('&&t[top-1]=='E')){
				top-=2;
				t[top]='E';
			}
			else{
				printf("RE\n");
				return 0;
			}
			isEnd=1;
			printf("R\n");
			i--;
			continue;
		}else if(priority[l][r]==0){
			if(i==len-1)
				printf("RE\n");
			else
				printf("E\n");	
			return 0;
		}else{
			t[++top]=ch[i];
			printf("I%c\n",ch[i]);
			isEnd=0;
		}
	}
	return 0; 
}
