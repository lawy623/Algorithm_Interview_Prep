vector<int> nums;

//1. Insertion Sort. O(N^2). Stable.
if(nums.size()<=1) return nums;
for(int i=1; i <nums.size(); i++){
	int key = nums[i];
	int j = i-1;
	while(i>0 && nums[i]>key){
		nums[i+1]=nums[i];
		i--;
	}
	A[i+1] = key;
}

//2. MergeSort. O(NlogN). Stable.
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

//3. quicksort. O(NlgN). Worest case could be O(N^2). Unstable.
void quickSort(vector<int>& nums){
	quickSort(nums,0,nums.size());
}
void quickSort(vecotr<int>& nums, int low, int high){
	if(low<high){
		p = partition(nums,low,high);
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
