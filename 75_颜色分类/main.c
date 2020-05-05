#if 0
/* quick sort */
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quickSort(int* arr, int left, int right){
    if (left < right) {
        int lt = left;
        int index = left + 1;
        int gt = right;
        int pivotValue = arr[left];

        while (index <= gt) {
            if (arr[index] < pivotValue) swap(arr, lt++, index++);
            else if (arr[index] > pivotValue) swap(arr, index, gt--);
            else index++;
        }
        quickSort(arr, left, lt - 1);
        quickSort(arr, gt + 1, right);
    }
}
#endif
bool cmp(int *a, int *b)
{
    //return *a < *b; // 降序
    return *a > *b; // 升序
}
void sortColors(int* nums, int numsSize){
    //quickSort(nums, 0, numsSize - 1);
    qsort(nums, numsSize, sizeof(int), cmp);
}