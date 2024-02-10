/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        iostream::sync_with_stdio(false);
        cin.tie(NULL);
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
        return head;
    }
};
// @lc code=end
