//
// Created by Suhas Reddy on 3/8/25.
//

struct Trade {
  string stockSymbol;
  int volume;
  long long timestamp; // Unix timestamp in milliseconds
};

class StockBrokerageSystem {
private:
  //{stock ->trade volume}
  unordered_map<string, int> stockVolume;
  deque<Trade> tradeWindow; // Stores trades in the last 1 hour
  long long TIME_WINDOW = 3600000; // 1 hour in milliseconds

public:
  void addTrade(string stockSymbol, int volume)
  {
    long long currentTime = chrono::duration_cast<chrono::milliseconds>(
                                chrono::system_clock::now().time_since_epoch())
                                .count();

    // Add new trade and update volume
    Trade newTrade = {stockSymbol, volume, currentTime};
    tradeWindow.push_back(newTrade);
    stockVolume[stockSymbol] += volume;

    // Remove outdated trades (more than 1 hour old)
    while (!tradeWindow.empty() && tradeWindow.front().timestamp < currentTime - TIME_WINDOW)
    {
      Trade oldTrade = tradeWindow.front();
      tradeWindow.pop_front();

      stockVolume[oldTrade.stockSymbol] -= oldTrade.volume;

      if (stockVolume[oldTrade.stockSymbol] <= 0)
        stockVolume.erase(oldTrade.stockSymbol);

    }
  }

  vector<pair<string, int>> getTopNStocks(int N)
  {
    // Min-heap to get top N stocks
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> minHeap;

    for (auto& entry : stockVolume)
    {
      minHeap.push({entry.second, entry.first});
      if (minHeap.size() > N)
        minHeap.pop();
    }

    // Retrieve the top N stocks
    vector<pair<string, int>> topStocks;
    while (!minHeap.empty())
      topStocks.push_back(minHeap.top()); minHeap.pop();


    // Reverse to get highest first
    reverse(topStocks.begin(), topStocks.end());
    return topStocks;
  }
};

int main() {
  StockBrokerageSystem system;

  // Simulating trades
  system.addTrade("AAPL", 500);
  system.addTrade("GOOG", 700);
  system.addTrade("TSLA", 400);
  system.addTrade("AAPL", 300);
  system.addTrade("AMZN", 800);
  system.addTrade("TSLA", 600);

  // Fetch top 3 traded stocks
  vector<pair<string, int>> topStocks = system.getTopNStocks(3);

  cout << "Top 3 Trending Stocks in the Last 1 Hour:" << endl;
  for (auto& stock : topStocks) {
    cout << stock.first << " - " << stock.second << " shares traded" << endl;
  }

  return 0;
}

