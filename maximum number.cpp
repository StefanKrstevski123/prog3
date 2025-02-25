#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> selectMaxSubarray(const vector<int>& nums, int k) {
    stack<int> s;
    int toRemove = nums.size() - k;
    
    for (int num : nums) {
        while (!s.empty() && s.top() < num && toRemove > 0) {
            s.pop();  
            toRemove--;
        }
        s.push(num);  
    }

    
    vector<int> result;
    while (!s.empty() && result.size() < k) {
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}


vector<int> maxNum(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> bestResult;
    
    
    for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
        vector<int> sub1 = selectMaxSubarray(nums1, i);         
        vector<int> sub2 = selectMaxSubarray(nums2, k - i);     
        
        
        vector<int> combined;
        combined.reserve(k);
        
        int p1 = 0, p2 = 0;
        while (p1 < sub1.size() || p2 < sub2.size()) {
            if (p1 < sub1.size() && (p2 >= sub2.size() || sub1[p1] > sub2[p2])) {
                combined.push_back(sub1[p1++]);
            } else {
                combined.push_back(sub2[p2++]);
            }
        }
        
      
        if (combined > bestResult) {
            bestResult = combined;
        }
    }
    
    return bestResult;
}

int main() {
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;
    
    vector<int> result = maxNum(nums1, nums2, k);
    
    for (int num : result) {
        cout << num;
    }
    return 0;
}