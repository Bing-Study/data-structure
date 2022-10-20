
#include "Sort.h"

#define Maxsize 10

Elemtype NList[Maxsize] = {50,10,30,26,18,40,43,32,90,68};

int main(){

	
	
	printf("‘≠ ˝◊È£∫"); 
	print(NList,Maxsize);
	
	printf("\n");
	
//	printf("÷±Ω”≤Â»Î≈≈–Ú£∫");
//	InsertSort(NList,Maxsize);		//÷±Ω”≤Â»Î≈≈–Ú 
	

//	printf("œ£∂˚≈≈–Ú£∫");
//	ShellSort(NList,Maxsize);		//œ£∂˚≈≈–Ú

	printf("√∞≈›≈≈–Ú£∫");			//√∞≈›≈≈–Ú
	BubbleSort(NList,Maxsize);		 


	print(NList,Maxsize);
	return 0; 
} 
