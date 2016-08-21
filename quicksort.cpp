/*
 * QuickSort implementation
 * Author: Shruti Kapoor
 * 
 */

// @params left: first index of array, 
//			right: last index of array
void quickSort(int dataArray[], int left, int right) { 
	int i = left; 
	int j = right;
	int temp; 

	int pivot = dataArray[ (left + right) / 2 ] ; //select the middle element as the pivot of the array

	//partition 
	while (i < j ) {
		while (dataArray[i] < pivot ) {
			i++ ;  // make sure left side is less than the pivot
		}
		while (dataArray[j] > pivot ){
			j-- ; // make sure right side is greater than the pivot
		}
		if (i <= j ) {
			// you found the first element on left which is greater than pivot. 
			// first element on right which is less than pivot.
			//SWAP
			temp = dataArray[i];
			dataArray[i] = dataArray[j];
			dataArray[j] = temp;
			i++;
			j--; 
		}

	}

	//call quicksort on sub-arrays
	if (left < j ) quickSort(dataArray, left, j );

	if (i < right) quickSort(dataArray, i, right);

}