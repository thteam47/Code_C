#include<stdio.h>
#include<math.h>
main(){
	// phan 1
	int n;
	float a[100];
	printf("moi nhap n : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("moi nhap phan tu thu %d : ",i+1);
		scanf("%f",&a[i]);
	}
	for(int i=0;i<n;i++){
		printf("\t%f",a[i]);
	}
	// phan 2
	float min=a[0]*a[1];
	float v1=a[0];
	float v2=a[1];
	for(int i=0;i<n-1;i++){
		if(min>(a[i]*a[i+1])){
			min=a[i]*a[i+1];
		}
	}
	for(int i=0;i<n-1;i++){
		if(min==(a[i]*a[i+1])){
			printf("\nbo 2 phan tu lien tiep co tich gia tri nho nhat la : %f va %f ",a[i],a[i+1]);
		}
	}


}
