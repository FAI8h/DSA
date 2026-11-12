#include <iostream>
#include <vector>

using namespace std;

int profit(vector<int> &prices){
    int minPrice = prices[0];
    int profit = 0;
    for (int i = 0; i < prices.size(); i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        profit = max(profit, prices[i] - minPrice);
    }
    cout << profit;
    return profit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    profit(prices);
    cout << '\n';
    return 0;
}