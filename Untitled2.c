#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int break_num(int num,int* a,int* b,int* c,int* d,int* max,int* min){
	int prim=2,count=0,is_negative=0,range=0;
	int arry[100]={1,1,1,1};
	if(num<0){
		is_negative=1;
		num*=-1;
		}//deal with negative condition
	if(num==1||num==0){
		count=1;
		arry[0]=num;
	}//deal with special condition
	while(num>=prim){
		if(num%prim==0){
			arry[count]=prim;
			count++;
			num=num/prim;
		}
		else{
			prim++;
		}
	}
	while(count>4){
		if(range==4)	range=0;
		arry[range]*=arry[count-1];
		count--;
		range++;//cut the length to 4
	}
	for(int i=0;i<4;i++){
		if(arry[i]>*max)	*max=arry[i];
		if(arry[i]<*min) *min=arry[i];
	}
	if(is_negative){
		arry[0]*=-1;
	} 
	*a=arry[0];
	*b=arry[1];
	*c=arry[2];
	*d=arry[3];
	return 0;
}

int main(){
	srand((unsigned)time(NULL));
	int a,b,c,d,num,max=0,min=1000;
	int matrix[4][4]={0};
	printf("please input a integer: ");
	scanf("%d",&num);
	break_num(num,&a,&b,&c,&d,&max,&min);
	matrix[0][0]=a;
	matrix[1][1]=b;
	matrix[2][2]=c;
	matrix[3][3]=d;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			matrix[i][j]=rand()%(max-min)+min;
		}
	}//generate random number to the matrix

	
	for(int i=1;i<4;i++){
		int size=rand()%5+1;
		for(int j=0;j<4;j++){
			matrix[i][j]+=(matrix[0][j]*size);
			if(i>1){
			matrix[i][j]+=matrix[1][j];
			}
			if(i>2){
			matrix[i][j]+=matrix[2][j];	
			}
		}
	}
	
	printf("\n");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%-3d ",matrix[i][j]);
		}
		printf("\n");
	}//print the matrix
}

