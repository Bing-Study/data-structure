#include<stdio.h> 
#include<stdlib.h>
#include <string.h>


int lengthOfils(int num[],int n);		//求数组最大递增子序列长度(动态规划法)

int getmax(int a,int b);		//求最大值 
int getmin(int a,int b,int c);	//求三者最小值 

//int CompEditDistance(char *A,char *B,int m,int n);	//求最小编辑距离（动态规划法） 

int lengthOfils(int num[],int n)		//求数组最大递增子序列长度(动态规划法)
{
	int dp[n];
	int max = 1;
	for(int i = n-1; i >= 0; i--){
		dp[i] = 1;
		for(int j = i+1; j < n; j++){
			if(num[j] > num[i]){
				dp[i] = getmax(dp[i],dp[j]+1);
			}
		}		
		if(max < dp[i])
			max = dp[i];
		
	} 
	
	return max;

 }
 
 
int getmax(int a,int b)		//求最大值
{
 	if(a > b)
		return a;
	else 
		return b; 
} 


// 存在些许bug未改正 

//int CompEditDistance(char *A,char *B,int m,int n)	//求最小编辑距离（动态规划法）
//{
//	/***********************************************
//		(1)删除 代价为1 
//		(2)替换 代价为1 
//		(3)不变 代价为0
//		(4)插入一个字符 
//	************************************************/
//
//	int dp[m][n];
//	//该数组dp[i][j]表示为A[i-1]与B[j-1]两个字符之间的编辑距离 
//	int t;
//	for(int i = 1; i < m; i++)
//		dp[i][0] = i;
//	for(int j = 1; j < n; j++)
//		dp[0][j] = 0;
//		
//	for(int i = 1; i < m; i++){
//		for(int j = 1; j < n; j++){
//			t = (A[i] == B[j]) ? 0 : 1;
//			dp[i][j] = getmin(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1])+1;
//		}
//	} 
//	
//	for(int i = 1; i < m; i++){
//		for(int j = 1; j < n; j++)
//			printf("%2d ",dp[i][j]);
//		
//		printf("\n");
//	}
//		printf("\n");
//		printf("\n");
//		printf("\n");
//		printf("\n");
//}


int getmin(int a,int b,int c)	//求三者最小值
{
	int min;
	if(a > b)
		min = b;
	else min = a;
	if(min > c)
		min = c;
	return min; 
}
	
