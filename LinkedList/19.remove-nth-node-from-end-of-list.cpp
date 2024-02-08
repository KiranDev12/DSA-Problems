/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removePos(ListNode *head, int pos)
    {
        if (head == NULL)
            return head;
        if (pos == 1)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int cnt = 0;
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            cnt++;

            if (cnt == pos)
            {
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
    int lengthOfLL(ListNode *head)
    {

        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int pos = lengthOfLL(head) - n + 1;
        head = removePos(head, pos);
        return head;
    }
};
// @lc code=end
