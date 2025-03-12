//
// Created by Suhas Reddy on 3/6/25.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Card
{
  char suit;
  int figure;
};

// Function to perform BFS and find the longest sequence of cards
int bfs(const Card& startCard, const unordered_map<char, unordered_set<int>>& suitMap,
        const unordered_map<int, unordered_set<char>>& figureMap)
{
  queue<pair<Card, int>> q; // (current card, current length)
  unordered_set<string> visited;

  string startKey = string(1, startCard.suit) + to_string(startCard.figure);
  q.push({startCard, 1});
  visited.insert(startKey);

  int maxLength = 1;

  while (!q.empty())
  {
    auto [current, length] = q.front();
    q.pop();

    // Explore same suit cards
    for (int nextFigure : suitMap[current.suit])
    {
      string newKey = string(1, current.suit) + to_string(nextFigure);
      if (!visited.count(newKey))
      {
        visited.insert(newKey);
        q.push({{current.suit, nextFigure}, length + 1});
        maxLength = max(maxLength, length + 1);
      }
    }

    // Explore same figure cards
    for (char nextSuit : figureMap[current.figure])
    {
      string newKey = string(1, nextSuit) + to_string(current.figure);
      if (!visited.count(newKey))
      {
        visited.insert(newKey);
        q.push({{nextSuit, current.figure}, length + 1});
        maxLength = max(maxLength, length + 1);
      }
    }
  }
  return maxLength;
}

// Function to compute the maximum number of cards that can be picked
int maxCards(vector<Card>& cards)
{
  unordered_map<char, unordered_set<int>> suitMap;
  unordered_map<int, unordered_set<char>> figureMap;

  // Populate adjacency lists (using sets to remove duplicates)
  for (const auto& card : cards)
  {
    suitMap[card.suit].insert(card.figure);
    figureMap[card.figure].insert(card.suit);
  }

  int maxCount = 0;
  for (const auto& card : cards)
  {
    maxCount = max(maxCount, bfs(card, suitMap, figureMap));
  }
  return maxCount;
}

int main()
{
  vector<Card> cards = {{'H', 3}, {'H', 4}, {'S', 4}, {'D', 5}, {'D', 1}};
  cout << "Max number of cards that can be picked: " << maxCards(cards) << endl;
  return 0;
}
