//
//  Solution01.cpp
//  AlgorithmAnalyze
//
//  Created by 李柏林 on 2019/4/2.
//  Copyright © 2019 berlin. All rights reserved.
//
/*
 map： map内部实现了一个红黑树（红黑树是非严格平衡二叉搜索树，而AVL是严格平衡二叉搜索树），红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素。因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行的操作。map中的元素是按照二叉搜索树（又名二叉查找树、二叉排序树，特点就是左子树上所有节点的键值都小于根节点的键值，右子树所有节点的键值都大于根节点的键值）存储的，使用中序遍历可将键值按照从小到大遍历出来。
 unordered_map: unordered_map内部实现了一个哈希表（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的。哈希表详细介绍
 
 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数
 nums = [2, 7, 11, 15] target = 9
 
 nums[0] + nums[1] = 2 + 7 = 9;
 
 返回[0, 1]
 */
#include "Solution01.hpp"
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> sumTwo(vector<int> num, int target) {
    vector<int> res;
    unordered_map<int, int> map;
    
    for (int i = 0; i < num.size(); i++) {
        int t = target - num[i];
        
        // 检查t是否在map中，如果在，并且map[t] 不等于i,我们就找到了，下标为i 和map[t]这两个数相加等于target值
        if (map.count(t) && map[t] != i) {
            res.push_back(i);
            res.push_back(map[t]);
            break;
        }
        map[num[i]] = i;
    }

    return res;
}

void testSolution01() {
    int a[4] = {1, 7, 11, 2};
    // 从数组中获得初值
    vector<int> b(a, a + 4);

    vector<int> c = sumTwo(b, 9);
    
    // 从向量中读取元素  下标
    for (int i = 0; i <= c.size() - 1; i++) {
        cout << " index c = " << c[i] << endl;
    }

    // 遍历器读取
    for (vector<int> :: iterator it = b.begin(); it != b.end(); it++) {
        cout << *it << "" << endl;
    }
}
