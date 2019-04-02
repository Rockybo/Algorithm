//
//  Solution02.cpp
//  AlgorithmAnalyze
//
//  Created by 李柏林 on 2019/4/2.
//  Copyright © 2019 berlin. All rights reserved.
//

/*
 两数相加
 给定两个非空链表表示两个非负整数,位数按照逆序方式存储,它们的每个节点只存储单个数字,将两数相加返回一个新的链表.
 2->4->3 + 5->6->4 = 7->0->8
 342 + 465 = 807
 
 */
#include "Solution02.hpp"
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
ListNode * create() {
    ListNode *head, *p;
    head = new ListNode(0);
    p = head;
    
    int x, cycle = 1;
    while (cycle) {
        cout << "please input the data for single linker :";
        cin >> x;
        
        if (x != 0) {
            ListNode *s = new ListNode(0);
            s->val = x;
            cout << "Input data:" << x << endl;
            
            p->next = s;
            p = s;
        } else {
            cycle = 0;
            cout << "Input done !" << endl;
        }
    }
    
    head = head->next;
    p->next = NULL;
    return head;
    
}

ListNode * create(int a, int b, int c) {
    ListNode *head, *p;
    head = new ListNode(0);
    p = head;
    
    
    ListNode *listNode1 = new ListNode(a);
    p->next = listNode1;
    p = listNode1;
    
    ListNode *listNode2 = new ListNode(b);
    p->next = listNode2;
    p = listNode2;
    
    ListNode *listNode3 = new ListNode(c);
    p->next = listNode3;
    p = listNode3;
    
    head = head->next;
    p->next = NULL;
    return head;
    
}

void printL(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        cout << "Single linker data is=" << p ->val << endl;
        p = p ->next;
    }
    
}
/*
    思路：我们使用变量来跟踪进位，并从包含最低有效位的表头开始模拟逐位相加的过程。
 */
ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    
    // 将当期结点初始化为返回列表的哑结点
    ListNode *cur;
    
    // p和q分别w初始化为列表l1和l2的头部
    ListNode *p = l1;
    ListNode *q = l2;
    
    // 将进位carry初始化值为0
    int carry = 0;
    
    cur = head;
    
    // 遍历列表l1和l2直至到达他们的尾端
    while (p || q) {
        cur -> val = carry;
        
        // 结点的两数相加，两数相加可能出现的最大和为9+9+1 = 19
        if (p) {
            cur -> val += p ->val;
            p = p -> next;
        }
        if (q) {
            cur -> val += q ->val;
            q = q -> next;
        }
        
        // 更新进位的值
        carry = cur->val / 10;
        
        // 我们计算两个数字的和时可能会出现“溢出”。例如，5+7=12在这种情况下，我们会将当前位的数值设置为2，并将进位carry=1带入下一次迭代，进位carry必定是0或1
        cur->val %= 10;
        if (p || q) {
            // 创建一个数值为(val %= 10) 的新结点，并将其设置为当前结点的下一个结点，然后将当前结点前进到下一个结点
            cur -> next = new ListNode(0);
            cur = cur-> next;
        }
        
        // 然后p和q同时进行到下一个结点...
    }
    
    // 检查carry = 1是否成立，如果成立，则向返回列表追加一个含有数字1的新结点
    if (carry == 1) {
        cur -> next = new ListNode(1);
    }
    
    /*
        时间复杂度：O(max(m,n)) 假设m和n 分别表示l1和l2的长度，上面的算法最多重复max(m,n)次
        空间复杂度: O(max(m,n)) 新列表的长度最多为max(m, n) + 1
     */
    return head;
}
void testSolution02() {
    //    2->4->3  +   5->6->4 = 7->0->8
    //    342 + 465 = 807
    //    ListNode *listNode1 = new ListNode(2, 4);
    ListNode *listNode1 = create(9,9,9);
    ListNode *listNode2 = create(9,9,9);
    
    ListNode *listNode = addTwoNumbers(listNode1, listNode2);
    
    printL(listNode);
}
