//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto list : lists)
    {
      if (list)
        pq.push(list);
    }

    ListNode* head = new ListNode(0);
    ListNode* temp = head;

    while (!pq.empty())
    {
      temp->next = pq.top();
      pq.pop();
      temp = temp->next;
      if (temp->next)
        pq.push(temp->next);
    }

    return head->next;
  }
};
