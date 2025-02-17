//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  bool isPalindrome(string s)
  {
    int left = 0, right = s.size()-1;

    while(left<right)
    {
      while(left<right && !isalnum(s[left]))
        left++;

      while(right>left && !isalnum(s[right]))
        right--;

      if(tolower(s[left])!=tolower(s[right]))
        return false;
      left++, right--;
    }

    return true;
  }
};
