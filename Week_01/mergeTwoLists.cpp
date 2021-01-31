/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//方法一：递归
		/*
		if (l1 == NULL) {
		return l2;
		} else if (l2 == NULL) {
		return l1;
		} else if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next,l2);
		return l1;
		} else {
		l2->next = mergeTwoLists(l2->next,l1);
		return l2;
		}
		*/
		//方法二：迭代；

		if (l1 == NULL) {
			return l2;
		}
		else if (l2 == NULL) {
			return l1;
		}
		else {
			;
		}

		ListNode *prehead = new ListNode(-1);//定义一个前驱结点；
		ListNode *pre = prehead;

		while (l1 != NULL&&l2 != NULL) {
			if (l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next;
			}
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}

		//其中一个list为空，需要将指针指向另一个结点
		pre->next = l1 == NULL ? l2 : l1;
		return prehead->next;

	}
};
//递归法
//时间复杂度：O(l1.size()+l2.size())
//空间复杂度：O(l1.size()+l2.size())

//迭代吗
//时间复杂度：O(l1.size()+l2.size())
//空间复杂度：O(1)