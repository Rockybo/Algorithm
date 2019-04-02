//
//  main.cpp
//  AlgorithmAnalyze
//
//  Created by 李柏林 on 2019/4/2.
//  Copyright © 2019 berlin. All rights reserved.
//

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
int main(int argc, const char * argv[]) {


    return 0;
}
