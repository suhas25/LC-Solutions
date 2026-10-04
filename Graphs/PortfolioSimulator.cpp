#include <cmath>
#include <cstdio>
#include <queue>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 private:
  struct Constituent { //could be stock or a nested portfolio
    string name;
    double shares;
  };

  struct AffectedPortfolio {
    string portfolioName;
    double shares;
  };

  // portfolio name -> direct constituents
  unordered_map<string, vector<Constituent>> portfolioGraph;
  // constituent -> portfolios containing it
  unordered_map<string, vector<string>> parentPortfolioGraph;
  unordered_map<string, vector<AffectedPortfolio>> affectedPortfolios; //<stock -> list{portfolios}

  //trackers
  unordered_set<string> portfolioNameSet;
  unordered_set<string> stockNameSet;
  unordered_map<string, double> stockPrices; //tracks stock prices
  unordered_map<string, double> portfolioPrices; //tracks portfolio prices

  unordered_map<string, unordered_map<string, double>> stockWeights;
  unordered_map<string, unordered_set<string>> requiredStocks;   //Portfolio -> set<stocks>

  unordered_map<string, int> missingPortfolioPricesMap; // missing prices count for a portfolio
  unordered_map<string, bool> portfolioPriceKnown;

  vector<string> topologicalSort() {
    unordered_map<string, int> indegree;
    for (const string& portfolio : portfolioNameSet) {
      indegree[portfolio] =static_cast<int>(portfolioGraph[portfolio].size());
    }

    for (const string& stock : stockNameSet) {
      indegree[stock] = 0;
    }

    queue<string> processQueue;

    for (const auto& [name, degree] : indegree) {
      if (degree == 0) {
        processQueue.push(name);
      }
    }

    vector<string> order;
    order.reserve(indegree.size());

    while (!processQueue.empty()) {
      string current = processQueue.front();
      processQueue.pop();

      order.push_back(current);

      for (const string& parent : parentPortfolioGraph[current]) {
        --indegree[parent];

        if (indegree[parent] == 0) {
          processQueue.push(parent);
        }
      }
    }

    const int totalNames =static_cast<int>(portfolioNameSet.size() + stockNameSet.size());

    if (static_cast<int>(order.size()) != totalNames) {
      throw invalid_argument(
          "Portfolio definitions contain a cycle"
      );
    }

    return order;
  }

  void flattenGraph(const vector<string>& order) {
    for (const string& portfolio : order) {

      if (!portfolioNameSet.count(portfolio)) {
        continue;
      }

      for (const Constituent& constituent :portfolioGraph[portfolio]) {
        const string& child = constituent.name;
        const double shares = constituent.shares;

        if (stockNameSet.count(child))
        {
          requiredStocks[portfolio].insert(child);
          stockWeights[portfolio][child] += shares;
        }
        else //constituent is a portfolio
        {
          for (const string& stock :requiredStocks[child])
          {
            requiredStocks[portfolio].insert(stock);
          }

          for (const auto& [stock, childStockShares] : stockWeights[child])
          {
            stockWeights[portfolio][stock] += shares * childStockShares;
          }
        }
      }
    }


    for (const string& portfolio : order) {
      if (!portfolioNameSet.count(portfolio)) {
        continue;
      }

      for (const string& stock : requiredStocks[portfolio]) {
        double shares = stockWeights[portfolio][stock];
        affectedPortfolios[stock].push_back({portfolio,shares});
      }

      missingPortfolioPricesMap[portfolio] =static_cast<int>(requiredStocks[portfolio].size());
      portfolioPrices[portfolio] = 0.0;
      portfolioPriceKnown[portfolio] = missingPortfolioPricesMap[portfolio] == 0;
    }
  }

  void buildGraph(
      const vector<pair<string, string>>& portfolioRows
  ) {
    string currentPortfolio;

    for (const auto& [name, shares] : portfolioRows) {
      if (shares.empty()) {
        portfolioNameSet.insert(name);
      }
    }

    for (const auto& [name, sharesText] : portfolioRows) {
      if (sharesText.empty()) {
        currentPortfolio = name;
        portfolioGraph[currentPortfolio];
        continue;
      }

      if (currentPortfolio.empty()) {
        throw invalid_argument(
            "Constituent appears before a portfolio definition"
        );
      }

      double shares = stod(sharesText);

      portfolioGraph[currentPortfolio].push_back({name,shares});

      parentPortfolioGraph[name].push_back(currentPortfolio);

      if (!portfolioNameSet.count(name)) {
        stockNameSet.insert(name);
      }
    }

    for (const string& portfolio : portfolioNameSet) {
      stockNameSet.erase(portfolio);
    }

    vector<string> order = topologicalSort();
    flattenGraph(order);
  }

 public:
  vector<pair<string, double>> calculatePortfolioPrices(
      const vector<pair<string, string>>& portfolioRows,
      const vector<pair<string, double>>& priceRows
  ) {

    buildGraph(portfolioRows);

    vector<pair<string, double>> output;

    for (const auto& [stock, newPrice] : priceRows) {
      output.push_back({stock, newPrice});

      bool firstPrice = !stockPrices.count(stock);

      double oldPrice =
          firstPrice ? 0.0 : stockPrices[stock];

      double priceChange = newPrice - oldPrice;

      stockPrices[stock] = newPrice;

      for (const AffectedPortfolio& affected :affectedPortfolios[stock]) {
        const string& portfolio = affected.portfolioName;

        double oldPortfolioPrice = portfolioPrices[portfolio];

        portfolioPrices[portfolio] += affected.shares * priceChange;

        if (firstPrice)
          --missingPortfolioPricesMap[portfolio];

        bool wasKnown = portfolioPriceKnown[portfolio];

        bool isPortfolioKnown = missingPortfolioPricesMap[portfolio] == 0;

        portfolioPriceKnown[portfolio] = isPortfolioKnown;

        bool fullyDiscovered = wasKnown || isPortfolioKnown;

        bool priceChanged =  portfolioPrices[portfolio] != oldPortfolioPrice;

        if (fullyDiscovered && priceChanged)
          output.push_back({portfolio,portfolioPrices[portfolio]});
      }
    }

    return output;
  }
};

string formatPrice(double value) {
  if (isfinite(value) && value == floor(value) && fabs(value) < 9e15) {
    return to_string(static_cast<long long>(value)) + ".0";
  }

  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%.15g", value);
  return buffer;
}

int main() {
  Solution solution;

  vector<pair<string, string>> portfolios = {
      {"TECH", ""},
      {"AAPL", "100"},
      {"MSFT", "200"},
      {"NVDA", "300"},

      {"AUTOS", ""},
      {"FORD", "100"},
      {"TSLA", "200"},
      {"BMW", "200"},

      {"INDUSTRIALS", ""},
      {"TECH", "2"},
      {"AUTOS", "3"}
  };

  vector<pair<string, double>> prices = {
      {"AAPL", 173},
      {"MSFT", 425},
      {"NVDA", 880},
      {"AAPL", 174},
      {"FORD", 200},
      {"TSLA", 300.33},
      {"BMW", 400},
  };

  auto result =
      solution.calculatePortfolioPrices(portfolios, prices);

  for (const auto& [name, price] : result) {
    cout << name << "," << formatPrice(price) << '\n';
  }
}