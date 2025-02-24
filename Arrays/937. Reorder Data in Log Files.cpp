//
// Created by Suhas Reddy on 2/23/25.
//

class Solution {
public:
  vector<string> reorderLogFiles(vector<string>& logs)
  {
    auto cmp = [](const string& log1, const string& log2)
    {
      int pos1 = log1.find(' ');
      int pos2 = log2.find(' ');

      // Check whether the log is a digit-log or letter-log.
      bool isDigit1 = isdigit(log1[pos1 + 1]);
      bool isDigit2 = isdigit(log2[pos2 + 1]);

      // Both logs are letter-logs.
      if (!isDigit1 && !isDigit2) {
        // Compare the contents.
        string content1 = log1.substr(pos1 + 1);
        string content2 = log2.substr(pos2 + 1);
        if (content1 != content2)
          return content1 < content2;
        // If contents are the same, compare the identifiers.
        return log1.substr(0, pos1) < log2.substr(0, pos2);
      }

      // One log is a letter-log and the other is a digit-log.
      if (!isDigit1 && isDigit2)
        return true;  // Letter-log comes first.
      if (isDigit1 && !isDigit2)
        return false; // Digit-log comes after.

      // Both logs are digit-logs, so maintain original order.
      return false;
    };

    stable_sort(logs.begin(), logs.end(), cmp);

    vector<string>result(logs.begin(), logs.end());

    return result;
  }
};
