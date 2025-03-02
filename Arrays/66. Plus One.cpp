//
// Created by Suhas Reddy on 2/25/25.
//

class Solution {
public:
  vector<int> plusOne(vector<int>& digits)
  {
    for(int i=digits.size()-1; i>=0; i--)
    {
      if(digits[i]==9)
        digits[i]=0;
      else
      {
        digits[i]++;
        return digits;//{ex 299->300}
      }
    }
    digits.insert(digits.begin(), 1); // {9->10 // 99->100}
    return digits;
  }
};