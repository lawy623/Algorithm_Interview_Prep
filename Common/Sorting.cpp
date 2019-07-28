// 1. Bubble Sort
int len = nums.size()
int temp = 0;
for (int i = 0; i < len - 1; i++) {
	for (int j = 0; j < len - 1 - i; j++) {
		if (nums[j] > nums[j+1]) {
			temp = nums[j+1];
			nums[j+1] = nums[j];
			nums[j] = temp;
		}
	}
}

// 2. Selection Sort
int minIndex=0, temp=0;
int len = nums.size()
for (int i = 0; i < len - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < len; j++) {
        if (nums[j] < nums[minIndex]) {
            minIndex = j;
        }
    }
    temp = nums[i];
    nums[i] = nums[minIndex];
    nums[minIndex] = temp;
}

// 3. Insertion Sort.
int key = 0;
int j = 0;
for(int i=1; i<nums.size(); i++){
	key = nums[i];
	j = i-1;
	while(j>0 && nums[j]>key){
		nums[j+1]=nums[j];
		j--;
	}
	nums[j+1] = key;
}

// 4. quicksort.
void quickSort(vector<int>& nums){
	quickSort(nums,0,nums.size());
}
void quickSort(vecotr<int>& nums, int low, int high){
	if(low<high){
		int p = partition(nums,low,high);
		quickSort(nums,low,p-1);
		quickSort(nums,p,high);
	}
}
int partition(vector<int>& nums,int low, int high){
	int pivot = nums[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(nums[j]<=pivot){
			swap(nums[++i],nums[j]);
		}
	}
	swap(nums[++i],nums[high]);
	return i;
}

// 5. MergeSort.
void merge(vector<int>& arr, int first, int mid, int last){
	vector<int> l,r;
	for(int i=first;i<mid;i++) l.push_back(arr[i]);
	for(int i=mid+1;i<last;i++) r.push_back(arr[i]);
		int a=0,b=0;
	for(int k=first;k<last;k++){
		if(b==r.size()) {arr[k]=l[a++];}
		else if (a==l.size()) rr[k]=r[b++];
		else if(l[a]<=r[b]){arr[k]=l[a++];}
		else{arr[k]=r[b++];}
	}
}
void mergeSort(vector<int>& arr, int first, int last){
	if(first<last){
		int mid = (first + last) /2
		mergeSort(arr,first,mid);
		mergeSort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
}
