#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// leetcode 18. 4Sum

vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    int lo = start, hi = nums.size() - 1;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            ++lo;
        else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            --hi;
        else
            res.push_back({ nums[lo++], nums[hi--]});
    }
    return res;
}

vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}

int* input(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
    return array;
}

void output(vector<vector<int>> ans) {
    cout << "[";
    int ansSize = 0;
    for (auto vec : ans) {
        ++ansSize;
        cout << "[";
        int vecSize = 0;
        for (auto num : vec) {
            ++vecSize;
            cout << num;
            if (vecSize < vec.size()) {
                cout << ", ";
            }
        }
        cout << "]";
        if (ansSize < ans.size()) {
            cout << ", ";
        }
    }
    cout << "]";
}

/*
    test case

    case 1 :
        input : 6
                1 0 -1 0 -2 2
                0
        output : [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

    case 2:
        input : 7
                1 6 3 8 4 0 2
                14
        output : [[0, 2, 4, 8], [1, 2, 3, 8], [1, 3, 4, 6]]
    
    case 3:
        input : 1
                1
                2
        output : []
*/

int main() {
    int size, target;
    cin >> size;
    int* array = input(size);
    cin >> target;
    vector<int> vec(array, array + size);
    vector<vector<int>> answer = fourSum(vec, target);
    output(answer);
	return 0;
}

