#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 *swap
 */
void swap(int array[], int l, int r){
  int temp=array[l];
  array[l]=array[r];
  array[r]=temp;
}


/*
 * quicksort - a simple in-place implementation of quick-sort
 *             assumed to be integers, which are sorted from smallest to largest
 */
void quicksort(int array[], int size){
  if(size==1){
    return;
  }
  //pick a pivot number (do this randomly, but for now just choose last one despite worst-case n^2 time
  int pivot = array[size-1]; //there are size elements and size-1 is the last index
  //iterate through array from left and from right, making sure that elements on the left are less than pivot and right are more
  int l=0;
  int r=size-2;  //pivot not included
  while(l<=r){
    if(array[l]<pivot){
      l++;
    }else if(array[r]<pivot){
      swap(array, l, r);
      l++;
    }else{  //either both array[l] and array[r] are greater than or equal to pivot, so move r down one and try agani
      r--;
    }
  }
  swap(array, l, size-1);
  if(l>1){
      quicksort(array, l);
  }
  if((size-(l+1))>1){
      quicksort(array+(l+1), size-(l+1));  //make better to include groups of same number when pivot
  }
  return;
}
      
int main(int argc, char* argv[]){

  int buffy[9]={12, 8, 7, 15, 2, 2, 11, 3, 6};
  quicksort(buffy, 9);
  for(int i=0; i<9; i++){
    printf("%d, ", buffy[i]);
    printf("\n");
  }
  return 0;
}


