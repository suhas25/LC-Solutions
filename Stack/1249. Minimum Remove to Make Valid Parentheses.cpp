//
// Created by Suhas Reddy on 3/2/25.
//


/*
- 1. we need to keep track of closing parenthesis which appears unbalanced. ie (when count of '(' becomes more than count of ')' at any given time). we remove them
- 2. with help of open count ( we get all the open parenthesis count). Balance refers to number of unbalanced open parenthesis after removing closing parenthesis.
- 3 now target is to remove opencount-balance no of open parenthesis in reverse order from end to start of string.

O(n) time and space complexity
 */

class Solution2 {
public:
  string minRemoveToMakeValid(string s)
  {
    int balance=0, open_count=0;
    string temp_string, result;

    for(int i=0;i<s.size(); i++)
    {
      if(s[i]=='(')
        balance++, open_count++;
      else if(s[i]==')')
      {
        if(balance==0) // this closing parenthesis needs to be removed. dont add it to result.
          continue;
        balance--;
      }
      temp_string+=s[i];
    }

    //balance is technically the number of open counts to be removed from the right to make string valid.
    open_count=open_count-balance;

    for(int i=0;i<temp_string.size(); i++)
    {
      if(temp_string[i]=='(')
      {
        open_count--;
        if(open_count<0)
          continue;
      }
      result+=(temp_string[i]);
    }

    return result;
  }
};

//inplace solution

class Solution {
public:
  string minRemoveToMakeValid(string s)
  {
    int balance=0, open_count=0;
    string temp_string, result;

    int j=0;

    for(int i=0;i<s.size(); i++)
    {
      char ch = s[i];
      if(ch=='(')
        balance++, open_count++;
      else if(ch==')')
      {
        if(balance==0) // this closing parenthesis needs to be removed. dont add it to result.
          continue;
        balance--;
      }
      s[j++]=ch;
    }

    int len=j;
    j=0;
    open_count=open_count-balance;

    for(int i=0;i<len; i++)
    {
      auto ch = s[i];
      if(ch=='(')
      {
        open_count--;
        if(open_count<0)
          continue;
      }
      s[j++]=ch;
    }

    return s.substr(0,j);
  }
};

//variant containing  std::string s = "[lee(t(c)o))))d[[e)(({{}}}";
class Solution3
{
  std::string delete_least_parentheses(std::string& s) {
    std::unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    std::unordered_map<char, int> extra_opens;
    std::unordered_map<char, int> total_opens;
    std::string temp;
    for (char ch : s) {
      if (mapping.contains(ch)) { // Closing parentheses
        if (extra_opens[mapping[ch]] == 0)
          continue;
        extra_opens[mapping[ch]]--;
        temp.push_back(ch);
      }
      else if (std::isalnum(ch)) { // 'a' or '3'
        temp.push_back(ch);
      }
      else { // Opening parentheses
        extra_opens[ch]++;
        total_opens[ch]++;
        temp.push_back(ch);
      }
    }

    std::unordered_map<char, int> keep;
    for (auto [open, _] : total_opens) {
      keep[open] = total_opens[open] - extra_opens[open];
    }
    std::string result;
    for (char ch : temp) {
      if (total_opens.contains(ch)) { // Opening parentheses
        if (keep[ch] == 0)
          continue;
        keep[ch]--;
        result.push_back(ch);
      }
      else {
        result.push_back(ch);
      }
    }
    return result;
  }
};
