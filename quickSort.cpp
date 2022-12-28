#include <iostream>
using namespace std;

int pivotPlace(int arr[], int left, int right){
	int sag=right-1;
	int sol=left;	
	int pivot=arr[right];
	int pivot_index=right;
	
	while(sol<=right && sag>=left){	//stay in boundaries
		
		for(sol=left; arr[sol]<pivot && sol<right;  )// 
			sol++;

		for(sag=right-1; arr[sag]>pivot && sag>left; ) 
			sag--;

		if (sag<=sol){
			swap(arr[right],arr[sol]);
			pivot_index=sol;	
			return pivot_index;
		}
					
		swap(arr[sag], arr[sol]);	
		
		}
}

void quickSort(int arr[], int first, int last){
	//if(sag==first-1 && sol==last+1)
	if (first>=last)
		return;
	int pivotIndex=pivotPlace(arr, first, last );
	quickSort(arr, first, pivotIndex-1);
	quickSort(arr, pivotIndex+1, last);
	
}

int main(){
	int array[]={7, 8, 1, 3, 2, 9, 6, 5};
	int size=sizeof(array)/sizeof(array[0]);

	quickSort(array, 0, size-1);
	for (int i=0; i<size; i++){
		cout<<array[i]<<" ";
		}
	
return 0;
	
}
