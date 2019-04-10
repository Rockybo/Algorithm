//
//  main.cpp
//  AlgorithmAnalyze
//
//  Created by 李柏林 on 2019/4/2.
//  Copyright © 2019 berlin. All rights reserved.
//

#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
    if (i >= nums1.size()) return nums2[j + k - 1];
    if (j >= nums2.size()) return nums1[j + k - 1];
    if (k == 1) return min(nums1[i], nums2[j]);
    int midval1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1]:INT_MAX;
    // 某个数组没有k/2个元素，把他的中值置为最大，在接下来的判断中排除另一个数组中的前k/2个元素
    int midval2 = (j + k / 2 - 1 < nums2.size()) ?nums2[j + k / 2 - 1]:INT_MAX;
    
    if (midval1 < midval2) {
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    } else {
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
}


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = (int)nums1.size(), n = (int)nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
    // 求中位数的小技巧,总数奇偶数通用
    return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    
    double mid = findMedianSortedArrays(nums1, nums2);
    cout << mid << endl;
    
    return 0;
}
