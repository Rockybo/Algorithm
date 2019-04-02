//
//  Solution03.cpp
//  AlgorithmAnalyze
//
//  Created by 李柏林 on 2019/4/2.
//  Copyright © 2019 berlin. All rights reserved.
//

#include "Solution03.hpp"

/**
 题目：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 示例1：
 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 
 示例 2:
 输入: "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 
 示例 3:
 输入: "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
 
 
 C++ 11标准中加入了unordered系列的容器。unordered_map记录元素的hash值，根据hash值判断元素是否相同。map相当于java中的TreeMap，unordered_map相当于HashMap。无论从查找、插入上来说，unordered_map的效率都优于hash_map，更优于map；而空间复杂度方面，hash_map最低，unordered_map次之，map最大。
 
 C++知识点：
 当使用iterator时，iterator的first指向key，second指向value
 
 判断所有key中是否包含某key
 首先是使用iterator来判断的方法。假设我们要检验 'B' 是否在我们刚刚声明的map中，可以用unordered_map的成员函数：find()函数和end()函数。注意这里find()和end()所返回的数据类型均为iterator。在unordered_map中，如果find()没找到要找的key，就返回和end()一样的iterator值。
 if(map.find('B') == map.end()) { //此时'B'不存在于map的键(key)中
 // do something
 }
 
 
 string:
 1、 string::npos
 npos可以表示string的结束位子，是string::type_size 类型的，也就是find（）返回的类型。find函数在找不到指定值得情况下会返回string::npos。举例如下（计算字符串中含有的不同字符的个数）：
 2、string::npos作为string的成员函数的一个长度参数时，表示“直到字符串结束（until the end of the string）”。例如：
 tmpname.replace(idx+1, string::npos, suffix);
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
static auto x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int lenthOfLongestSubstring(string s) {
    int subStringStart = 0, maxLength = 0;
    string subString;
    size_t occPos;
    
    for (int subStringEnd = 0; subStringEnd < s.length(); subStringEnd++) {
        // 查找subStringStart位置之后是否有插入的字符
        occPos = subString.find(s[subStringEnd], subStringStart);
        // 如果subString中已有带插入字符，将子串中已有字符的位置(occpos)
        // 下一位置(occPos+1)设置为无重复子串的开始位置，即向右移动滑窗
        // 不断调整无重复子字符串的开始位置
        if (occPos != string::npos) {
            subStringStart = (int)occPos + 1;
        }
        // 依次将S中的元素插入subString中，同时不断计算最长子字符串长度并更新
        subString.push_back(s[subStringEnd]);
        maxLength = max(maxLength, subStringEnd - subStringStart + 1);
    }
    
    return maxLength;
}

int lengthOfLongestSubstring2(string s) {
    if (s == "") {
        return 0;
    }
    unordered_map<char, int> hmap;
    int left = 0, right = 0, max = 0;
    
    for (int i = 0; i < s.size(); i++) {
        
        auto it = hmap.find(s[i]);
        
        // 判断是否包含字符s[i]的key 相等就是不包含
        if (it != hmap.end()) {
            
            // s[i]存在hamp中
            // 用right下标 - 之前存储的小标值=间距。然后判断这个间距是否比max值大
            if (right - left > max) {
                max = right - left;
            }
            
            // 取出"存在"map中元素的value值
            int itSecond = it -> second;
            // itSecond + 1 跟left比较
            if (itSecond + 1 > left) {
                
                left = itSecond + 1;
            }
            
            // 确定left的z数值和map的数值，不在map，保持不变
        }
        // 记录i值
        right = i;
        
        // s[i] 作为key  i作为value
        hmap[s[i]] = i;
        cout <<"left = " << left << "\t right = " << right << "\t max = " << max <<endl;
    }
    
    if (right - left > max) {
        max = right - left;
    }
    return max + 1;
}

void testSolution03() {
    
    int length = lenthOfLongestSubstring("pwiwkew");
    int length1 = lengthOfLongestSubstring2("pwiwkew");
    cout << length << endl;
    cout << length1 << endl;
}
