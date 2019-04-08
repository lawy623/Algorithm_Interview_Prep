//1.Two index iterator two array to the half. Consider edge cases.
// O((m+n)/2). 32ms.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if(size==0) return 0.0;
          
        int i=0,j=0;
        while(i+j<(size-1)/2){  //Here, totally iterate (n-1)/2 nums. current i,j will be ok to find next.
            if(i>=nums1.size()){j++;continue;}
            if(j>=nums2.size()){i++;continue;}
            if(nums1[i]<=nums2[j]) i++;
            else j++;
        }        
        if(i==nums1.size()) return (size%2==1)?nums2[j]:(nums2[j]+nums2[j+1])/2.0;
        if(j==nums2.size()) return (size%2==1)?nums1[i]:(nums1[i]+nums1[i+1])/2.0;
        
        if(size%2==1) return double( min(nums1[i],nums2[j]) );
        else{
            if(nums1[i]==nums2[j]) return double(nums1[i]);
            else if(nums1[i]>nums2[j]) 
                return (j+1==nums2.size())?(nums1[i]+nums2[j])/2.0:((nums2[j+1]<nums1[i])?(nums2[j]+nums2[j+1])/2.0:((nums1[i]+nums2[j])/2.0));
            else 
                return (i+1==nums1.size())?(nums1[i]+nums2[j])/2.0:((nums1[i+1]<nums2[j])?((nums1[i+1]+nums1[i])/2.0):((nums1[i]+nums2[j])/2.0));
        }
    }
};

//2.二分法找中点 O(log(min(m,n)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if (m > n) { // to ensure m<=n
            vector<int> temp(A); A = B; B = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j-1] > A[i]){
                iMin = i + 1; // i is too small
            }
            else if (i > iMin && A[i-1] > B[j]) {
                iMax = i - 1; // i is too big
            }
            else { // i is perfect
                int maxLeft = 0;
                if (i == 0) { maxLeft = B[j-1]; }
                else if (j == 0) { maxLeft = A[i-1]; }
                else { maxLeft = max(A[i-1], B[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = B[j]; }
                else if (j == n) { minRight = A[i]; }
                else { minRight = min(B[j], A[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

//3. More easy to understand.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int total = m+n;
        if(total % 2 ==0 ) 
            return (find_kth(A.begin(),m,B.begin(),n, total/2) + find_kth(A.begin(),m,B.begin(),n, total/2+1) )/2.0;
        else return find_kth(A.begin(),m,B.begin(),n, total/2+1);
    }        
             
private:
    static int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k){
        if(m>n) return find_kth(B,n,A,m,k);
        if(m==0) return *(B+k-1);
        if(k==1) return min(*A,*B);
        
        int ia = min(k/2,m), ib = k-ia;
        if(*(A+ia-1) < *(B+ib-1)) return find_kth(A+ia,m-ia,B,n,k-ia); //Just ignore all this k/2 nums.
        else if(*(A+ia-1) > *(B+ib-1)) return find_kth(A,m,B+ib,n-ib,k-ib);
        else return *(A+ia-1);   //if equal, these two are the (k-1)th and kth num.
    }
};