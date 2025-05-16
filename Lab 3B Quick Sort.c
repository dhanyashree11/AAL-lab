#include<stdio.h>
void quicksort(int a[],int p,int q){
	if(p<q){
	    int pivot=a[p];
		int i=p+1;
		int j=q;
		while(i<=j){
			while(i<=q && a[i]<pivot) i++;
			while(j>=p && a[j]> pivot) j--;
			if(i<j){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		int temp2=a[p];
		a[p]=a[j];
		a[j]=temp2;
		int pi=j;
		quicksort(a,p,pi-1);
		quicksort(a,pi+1,q);
	}	
}
void main(){
	int i,n,a[100];
	printf("Enter size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter element:");
		scanf("%d",&a[i]);	
	}
	quicksort(a,0,n-1);
	printf("Sorted array");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}

OUTPUT:
Enter size of array:5

Enter element:9

Enter element:11

Enter element:5

Enter element:3

Enter element:1

Sorted array
1	3	5	9	11	

