#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

int profit(vector<int> & prices){
    int profit = 0;

    int n = prices.size();
    int minPrice = prices[0];

    for (int i = 1; i < n;i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        profit = max(profit, prices[i] - minPrice);
    }
    cout << profit << endl;
    return profit;
}

int main () {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    profit(prices);
    return 0;
}