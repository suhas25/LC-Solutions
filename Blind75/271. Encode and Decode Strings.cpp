//
// Created by Suhas Reddy on 2/15/25.
//

class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs)
  {
    string result;
    for(const auto& str:strs)
      result+=to_string(str.size())+"#"+str;

    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s)
  {
    vector<string> res;

    int i=0, j=0;
    while(i<s.size())
    {
      j=i;
      while(s[j]!='#')
        j++;

      int length = stoi(s.substr(i, j-i)); //now j points to "#"

      i=j+1;

      res.push_back(s.substr(i, length));

      i = i+length;
    }

    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
