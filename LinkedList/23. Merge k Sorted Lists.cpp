//
// Created by Suhas Reddy on 2/14/25.
//

//O(k) space and O(Nlogk) time complexity

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

//Using Divide and Conquer (Similar to Merge Sort)
class Solution2 {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return NULL;
    return mergeKListsHelper(lists, 0, lists.size()-1);
  }

  ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
    if(start>end) return NULL;
    if(start==end) return lists[start];

    int mid = start + (end-start)/2;
    ListNode* left = mergeKListsHelper(lists, start, mid);
    ListNode* right = mergeKListsHelper(lists, mid + 1, end);
    return merge(left, right);
  }

  ListNode* merge(ListNode* list1Head, ListNode* list2Head) {
    ListNode* dummyHead = new ListNode(-1);
    ListNode* dummyTail = dummyHead;

    while(list1Head!=NULL && list2Head!=NULL){
      if(list1Head->val < list2Head->val){
        dummyTail->next = list1Head;
        list1Head = list1Head->next;
      }else{
        dummyTail->next = list2Head;
        list2Head = list2Head->next;
      }
      dummyTail = dummyTail->next;
    }
    dummyTail->next = (list1Head != NULL) ? list1Head : list2Head;
    return dummyHead->next;
  }
};

//Iterative
class Solution3
{
  public:
  ListNode* mergeKLists(vector<ListNode*>& lists){
    int amount = lists.size();
    int interval = 1;
    while (interval < amount)
    {
      for (int i = 0; i < amount - interval; i += interval * 2)
        lists[i] = merge2Lists(lists[i], lists[i + interval]);
      interval *= 2;
    }
    return amount > 0 ? lists[0] : NULL;
  }

private:
  ListNode* merge2Lists(ListNode* l1, ListNode* l2)
  {
    ListNode head(0);
    ListNode* point = &head;

    while (l1 && l2)
    {
      if (l1->val <= l2->val)
      {
        point->next = l1;
        l1 = l1->next;
      }
      else
      {
        point->next = l2;
        l2 =l2->next;
      }
      point = point->next;
    }

    if (!l1)
    {
      point->next = l2;
    }
    else
    {
      point->next = l1;
    }
    return head.next;
  }
};
