#include "study.h"

int main(){
	int num[1000];
/*	for(int i = 0; i < 1000; i++){
		num[i] = rand()%1000;

	}
	
	printf("最长递增子序列长度为：%d",lengthOfils(num,1000));
*/

	char A[15];
	char B[15];
	
	strcpy(A,"I'm a student");
	strcpy(B,"I'm a teacher");
	
	CompEditDistance(A,B,15,15);
}
