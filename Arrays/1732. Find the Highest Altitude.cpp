//
// Created by Suhas Reddy on 2/16/25.
//

class Solution {
public:
  int largestAltitude(vector<int>& gain)
  {
    int result=0;

    int curr_altitude=0;

    for(auto num:gain)
    {
      curr_altitude+=num;
      result = max(result, curr_altitude);
    }

    return result;
  }
};
