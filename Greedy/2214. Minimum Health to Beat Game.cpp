//
// Created by Suhas Reddy on 2/20/25.
//

// Use the armor to protect against the maximum damage.

class Solution {
public:
  long long minimumHealth(vector<int>& damage, int armor)
  {
    long long total_damage=0;
    int max_damage=0;

    for(auto d:damage)
    {
      total_damage+=d;
      max_damage = max(d, max_damage);
    }

    return total_damage-min(armor, max_damage) +1;
  }
};