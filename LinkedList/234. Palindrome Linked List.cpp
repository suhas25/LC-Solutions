//
// Created by Suhas Reddy on 2/22/25.
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

ListNode* get_first_half_end(ListNode* head)
{
  auto slow = head;
  auto fast = head;

  while(fast->next!=nullptr && fast->next->next!=nullptr)
  {
    slow = slow->next;
    fast=fast->next->next;
  }
  return slow;
}

ListNode* reverse_list(ListNode* node)
{
  ListNode* prev = nullptr;
  auto curr=node;
  while(curr!=nullptr)
  {
    auto actual_next = curr->next;
    curr->next=prev;
    prev=curr;
    curr = actual_next;
  }
  return prev;
}

class Solution {
public:
  bool isPalindrome(ListNode* head)
  {
    if(head==nullptr)
      return true;

    auto first_half_end = get_first_half_end(head);
    auto second_half_start = reverse_list(first_half_end->next);

    auto p1=head, p2=second_half_start;
    bool result=true;

    while(p2!=nullptr && result)
    {
      if(p1->val!=p2->val)
        result=false;
      p1=p1->next;
      p2=p2->next;
    }

    first_half_end->next = reverse_list(second_half_start);

    return result;
  }
};
