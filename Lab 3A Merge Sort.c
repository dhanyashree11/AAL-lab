#include <stdio.h>
#include <stdlib.h>

int merge(left,right){
	int a=len(left);
	int b=len(right);
	int n=a+b;
	int arr[n];
	int i=0,j=0,k=0;
	while (i<a && j<b){
		if (left[i]<right[j]){
			arr[k]=left[i];
			i++;
			k++;
		}
		else{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	int x,y;
	for (x=i;x<len(left);x++){
		arr[k]=left[x];
		k++;
	}	
	for (y=j;y<len(right);y++){
		arr[k]=right[y];
		k++;
	}
}
int merge_sort(arr){
	if (len(arr)<=1)
		return arr;
	mid=int(arr/2);
	sortedleft=merge_sort(arr[:mid]);
	sortedright=merge_sort(arr[mid:]);
	return merge(sortedleft,sortedright);
}
int main(int argc, char *argv[]) {
	
	return 0;
}
