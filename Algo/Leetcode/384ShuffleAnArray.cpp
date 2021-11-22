// O(n) space, O(n^2) time for shuffle
class Solution {
public:
    Solution(vector<int>& nums){
		for(int n:nums)
			initNums.push_back(n);
		ranNums.assign(initNums.begin(), initNums.end());
	}

	vector<int> reset(){
		ranNums.assign(initNums.begin(), initNums.end());
		return initNums;
	}

	vector<int> shuffle(){
		int n = initNums.size();
		vector<int> tmp(initNums);
		for(int i=0; i<n; i++){
			int ranIndex = rand() % tmp.size();
			ranNums[i] = tmp[ranIndex];
			tmp.erase(tmp.begin() + ranIndex);   // the time for erase here is O(n)
		}

		return ranNums;
	}

private:
	vector<int> initNums;
	vector<int> ranNums;
};

// O(n) time for shuffle. You do not need to erase the vector, but swap the random one to the last one
class Solution {
public:
    Solution(vector<int>& nums){
		for(int n:nums)
			initNums.push_back(n);
		ranNums.assign(initNums.begin(), initNums.end());
	}

	vector<int> reset(){
		ranNums.assign(initNums.begin(), initNums.end());
		return initNums;
	}

	vector<int> shuffle(){
		int n = initNums.size();
		for(int i=0; i<n-1; i++){
			int ranIndex = rand() % (n-i);
			swap(ranNums[ranIndex], ranNums[n-i-1]);  // O(n) here
		}
		return ranNums;
	}

private:
	vector<int> initNums;
	vector<int> ranNums;
};