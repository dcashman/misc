//mergesort, take in an array, and a function for comparing two values, and output it as a sorted array

/*
 *merge
 */
void mergeArray(char[] array, int (*cmp)(char a, char b), int start1, int start2, int end1, int end2){
  //go through the elements and arrange them
  int iter1, iter2, current, temp;
  (start1<start2) ? iter1=start1, iter2=start2 : iter2=start1, iter1=start2;
  current=iter1;  
  char scratch[end2-start1];
  for(int i=0; i<


/*
 *mergesort
 */
void mergesortArray(char[] arry, int (*cmp)(char a, char b), int start, int end){
  //divide the array in half, and recursively sort each
  if(end-start<=1){
    return;
  }else{
    //break it up in half and sort each half 
    int start1=start;
    int start2=start+((end-start)/2)+1;
    int end1 = start+((end-start)/2));
    int end2 = end;
    mergeSortArray(arry, cmp, start1, end1);
    mergeSortArray(arry, cmp, start2, end2);
    mergeArray(arry, cmp, start1, start2, end1, end2);
    return;
}



int main(int argc, char* argv[]){
