#include <stdio.h>
int main(){
	int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int b[4][3];
	//输入矩阵的值
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
	}
	//
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++) b[i][j] = a[j][i];
	}
	//
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++) printf("%d ",b[i][j]);
		printf("\n");
	}

}
