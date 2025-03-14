//
// Created by Suhas Reddy on 2/25/25.
//

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
  ListNode* deleteDuplicates(ListNode* head)
  {
    ListNode* temp = new ListNode(0, head);
    ListNode* prev = temp;

    while(head!=nullptr)
    {
      if(head->next!=nullptr && head->val == head->next->val)
      {
        while(head->next!=nullptr && head->val==head->next->val)
        {
          head = head->next;
        }
        prev->next = head->next;
      }
      else
        prev = prev->next;

      head = head->next;
    }
    return temp->next;
  }
};
