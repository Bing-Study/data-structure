#include <stdio.h>
#include <string.h>
#define Maxsize 255

typedef char Elemtype;

typedef struct {
	Elemtype data[Maxsize];
	int length;
}SString;


bool InitStr(SString &T);	//初始化串 
bool StrAssign(SString &T,char *s); //将字符串s赋值给T
bool PrintStr(SString T);	//打印字符串 
bool StrEmpty(SString T);	//判空 
int StrCompare(SString &S,SString &T);	//比较S,T的大小; >0为S大 <0为T大 =0为相同大 
int StrLength(SString S);	//求串长 
int SubStr(SString S,char *arr);	//求子串 
void getnext(int *next);	//求KMP算法的next数组 
int KmpStr(SString &S,SString &T);	//KMP算法找子串 


int main(){
	SString S,T,s; 
	InitStr(S);
	InitStr(T);
	InitStr(s);
	char s1[9]="Abing123";
	char s2[9]="Abing123";
	char s3[7]="bing"; 
	printf("s1:%s\n",s1);
	StrAssign(S,s1);
	StrAssign(T,s2);
	StrAssign(s,s3);
/*	printf("T:");
	PrintStr(T);*/
	
	printf("s3:");
	PrintStr(s);


//	printf("Compare result:%d\n",StrCompare(T,S));

//	printf("strlen:%d  StrLength:%d\n",strlen(S.data),StrLength(S));


/*
	求子串 
*/
//朴素模式算法 
//	printf("s3 situate:%d",	SubStr(S,s3));

/*
	KMP算法 
*/ 
	printf("s3 situate:%d",	KmpStr(S,s));
	return 0;
}

bool InitStr(SString &T){	//初始化串 
	T.length=0; 
} 
bool StrAssign(SString &T,char *s) //将字符串s赋值给T 
{
	int i=1;
	int len=strlen(s);
	for(i=1;i<=len;i++,T.length++)
	{
		T.data[T.length]=s[i-1];
	}
	T.data[T.length]='\0';

} 

bool PrintStr(SString T)	//打印字符串 
{
	if(StrEmpty(T)){
		printf("The String is NULL!\n");
		return false;
	}
	printf("%s",T.data);
	printf("\n");
	
} 
bool StrEmpty(SString T)	//判空 
{
	if(T.length==0){
		return true;
	}
	else
		return false;
} 
int StrCompare(SString &S,SString &T)	//比较S,T的大小; >0为S大 <0为T大 =0为相同大 
{
	int i=0;
	if(S.length>T.length)
		return 1;
	else if(S.length<T.length)
		return -1;
	else{
		while(S.data[i]){
			if(S.data[i]<T.data[i])
				return 1;
			else if(S.data[i]>T.data[i])
				return -1;
			i++;
			}
		}
	return 0;
		
	}

int StrLength(SString S)	//求串长 
{
	int i=0;
	while(S.data[i]){
		i++;
	}
		
	return i;
} 
int SubStr(SString S,char *arr)	//模式匹配求子串
{
	int i=0;	//S当前匹配位置的指针 
	int j=0;	//arr的指针 
	int k=0;	// S与arr匹配的指针 
	int x=S.length+1-strlen(arr);  //匹配次数 
	for(i=0;i<x;i++){
		if(S.data[i+k]==arr[j]){
			printf("S.data[i+k]:%c arr[j]:%c\n",S.data[i+k],arr[j]);
			k++;
			j++;
			i--;	//在循环中,对比一次i+1,所以内容相等时,让i-1保持匹配 
		}
		else{
			k=0;
			j=0;
		}
		if(arr[j]=='\0'){
			return ++i;
		}
	}
	return -1;
} 

void getnext(SString S,int *next){	//求KMP算法的next数组 
	int i=1,j=0;
	next[1]=0;
	while(i<S.length){
		if(j == 0 || S.data[i]==S.data[j]){
			++i;
			++j;
			next[i]=j;
		}
		else{
			j = next[j];
		}
	}
	for(i=0;i<=S.length;i++){
		printf("i:%d   next[i]:%d\n",i,next[i]);
	} 
}

int KmpStr(SString &S,SString &T){	//KMP算法找子串 
	int next[T.length];
	int i=1,j=1;
	getnext(T,next);
	
	while(i<=S.length && j<=T.length){
		if(j == 0 || S.data[i] == T.data[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
		if(j>T.length){
			printf("i:%d  T.length:%d\n",i,T.length);
			return i-T.length;
		}
	}
	return -1;
}
