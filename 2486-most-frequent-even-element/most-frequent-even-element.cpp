class Solution {
public:
// hashing 
// single pass
    int mostFrequentEven(vector<int> &nums) {
		unordered_map<int, int> mp;
		int key = INT_MAX, maxFreq = 0;
		for (int &num : nums) {
			if (num % 2 == 0) {
				mp[num]++;
				if (mp[num] > maxFreq || (mp[num] == maxFreq && num < key)) {
					key = num;
					maxFreq = mp[num];
				}
			}
		}
		return maxFreq ? key : -1;
	}
};