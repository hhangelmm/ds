#include <stdio.h>
void print(int a[],int n){
	int i;
	for (i = 0; i < n; i++) {
		printf("%d",a[i]);
	}
	printf("\n");
}
int main(int argc, const char *argv[]) {
	int a[] = {1,2,3,4,5};
	int b[] = {1,3,5,1,5};
	int x[3]={0};
	int i,j,t,m;
	print(a,5);
	print(b,5);
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			if (a[i] == b[j]) {
				x[i-1] = j; 
				break;
			}
		}	
		if(j==4){for (m = j; m > 0; m--) {
			if(m != x[0] && m!=x[1] && m != x[2]){
				b[m] = a[i];
				for(t=0;t<3;t++){
					if(x[t] == 0){
						x[t] = m;
						break;
					}
				}
				break;
			}
		}

	}}
	print(x,3);
	print(b,5);
	return 0;
}
