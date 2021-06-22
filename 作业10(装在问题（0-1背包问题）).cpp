#include<stdio.h>
int c1,c2,n,w[100];
int load()
{
	int a[100][100]={0},i,j,sum=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=c1;j++){
			if(w[i]<=j){
				a[i][j]= (w[i]+a[i-1][j-w[i]]>a[i-1][j])?(w[i]+a[i-1][j-w[i]]):a[i-1][j];
			}
			else a[i][j]=a[i-1][j];
		}
	}
	for(i=1;i<=n;i++){
		sum+=w[i];
	}
	if(sum-a[n][c1]<=c2) return 1;
	else return 0;
}
int main(){
	while(1){
		scanf("%d%d%d",&c1,&c2,&n);
		if(n==0) return 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}
		if(load) printf("Yes\n");
		else printf("No\n");
	}
}