//
// Created by Suhas Reddy on 3/2/25.
//

//O(m*n) time complexity
class Solution {
public:
  int strStr(string haystack, string needle)
  {
    int m = haystack.size(), n = needle.size();

    for(int i=0;i<=m-n; i++)
    {
      for(int j=0;j<n; j++)
      {
        if(needle[j]!=haystack[i+j])
          break;

        if(j==n-1)
          return i;
      }
    }
    return -1;
  }
};
