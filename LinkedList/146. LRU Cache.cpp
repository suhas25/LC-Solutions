//
// Created by Suhas Reddy on 2/20/25.
//

class LRUCache {
public:
  int capacity;

  unordered_map<int, list<pair<int, int>>::iterator>map;
  list<pair<int, int>> lru;

  LRUCache(int capacity)
  {
    this->capacity=capacity;
  }

  int get(int key)
  {
    if(map.find(key)==map.end())
      return -1;

    auto it = map[key];
    auto val = it->second;

    //now push node to front and update iterator in map
    lru.push_front({key, val});
    lru.erase(it);
    map[key]=lru.begin();

    return val;
  }

  void put(int key, int value)
  {
    //insert if it do not exists.
    if(map.find(key)==map.end())
    {
      lru.push_front({key, value});
      map[key]=lru.begin();
    }

    //update key's value it exists and move node to front
    else
    {
      auto it = map[key];
      lru.erase(it);

      lru.push_front({key, value});
      map[key]=lru.begin();
    }
    //delete last node from lru and dictionary if exceeds capacity.
    if(map.size()>capacity)
    {
      auto key =map.find(lru.rbegin()->first);
      map.erase(key);
      lru.pop_back();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */