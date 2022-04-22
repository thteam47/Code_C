#include<stdio.h>
#include<math.h>
main(){
	// phan 1
	int m,n,i,j;
	int a[100][100];
	printf("moi ban nhap n : ");
	scanf("%d", &n);
	printf("moi ban nhap m: ");
	scanf("%d", &m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("moi ban nhap hang %d cot %d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("\t%d",a[i][j]);
		}
	printf("\n");
	}
	// phan 2
	int d=0;
	int c=0;
	int max = a[0][0];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]>max){
				max = a[i][j];
				d = i;
				c = j;
			}
		}
	}

    printf("\nPhan tu lon nhat cua ma tran la: %d tai vi tri (%d, %d)",max,d+1,c+1 );
	// phan 3
	int tich = 1;
	for (int j=0; j<m; j++) {
        int cot=1;
        if (j%2 != 0) {
            for (int i=0; i<n; i++) {
            cot*=a[i][j];
        }
        }
        tich *= cot;
    }
    printf("\nTich cac phan tu cot le la: %d",tich );
}

