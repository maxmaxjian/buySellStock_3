#include <iostream>
#include <vector>
#include <algorithm>

class solution {
  public:
    int maxProfit(const std::vector<int> & prices) {
        // solution 1
        // // one transaction
        // int maxOne = maxOneTransaction(prices, 0, prices.size());
        // std::cout << "max one = " << maxOne << std::endl;

        // // two transactions
        // std::vector<int> twos;
        // for (size_t i = 1; i < prices.size()-1; i++)
        //     twos.push_back(maxOneTransaction(prices, 0, i)+maxOneTransaction(prices, i, prices.size()));
        // std::cout << "max two = " << *std::max_element(twos.begin(), twos.end()) << std::endl;
        
        // // max of one and two transactions
        // return std::max(maxOne, *std::max_element(twos.begin(), twos.end()));

        
        // solution 2
        std::vector<int> trans;
        for (size_t i = 0; i <= prices.size(); i++)
            trans.push_back(maxOneTransaction(prices, 0, i)+maxOneTransaction(prices, i, prices.size()));
        return *std::max_element(trans.begin(), trans.end());
    }

  private:
    int maxOneTransaction(const std::vector<int> & prices, size_t begin, size_t end) {
        int result = 0;
        for (size_t i = begin; i < end; i++) {
            std::vector<int> temp;
            std::transform(prices.begin()+i, prices.begin()+end, std::inserter(temp, temp.begin()),
                           [&](int num){
                               return num-prices[i];
                           });
            auto it = std::max_element(temp.begin(), temp.end());
            result = *it>result ? *it : result;
        }
        return result;
    }
};

int main() {
    std::vector<int> prices{1,4,5,7,6,3,2,9};

    solution soln;
    int maxProfit = soln.maxProfit(prices);
    std::cout << "The maximium profit that can be gained by at most two transactions is:\n"
              << maxProfit << std::endl;
}
