vector<int> MinimumCoins(int n)
{
    vector<int> coins={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> result;
    int i=coins.size()-1;
    while(i>=0&&n-coins[i]<0)i--;
    while(i>=0&&n>0){
        if(i>=0&&n-coins[i]<0)i--;
        else {
            n-=coins[i];
            result.push_back(coins[i]);
        }

    }
    return result;
} 