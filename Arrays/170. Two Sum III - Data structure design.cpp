//
// Created by Suhas Reddy on 2/18/25.
//

class TwoSum {
private:
  unordered_map<long long, int> num_counts;

public:
  TwoSum() {}

  void add(int number)
  {
    num_counts[number]++;
  }

  bool find(int value)
  {
    for (const auto &entry : num_counts)
    {
      long long complement = static_cast<long long>(value) - entry.first;
      if (complement != entry.first)
      {
        if(num_counts.count(complement))
          return true;
      }
      else
      {
        if (entry.second > 1) return true;
      }
    }
    return false;
  }
};