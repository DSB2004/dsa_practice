#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double result=0.0;
    int cur_weight=0;
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (double)a.second / a.first > (double)b.second / b.first;
    });



     for (auto item : items) {
        if (cur_weight + item.first <= w) {
            cur_weight += item.first;
            result += item.second;
        } else {
            int remaining = w - cur_weight;
            result += (double)remaining * (double)item.second / (double)item.first;
            break;  
        }
    }

    return result;

    
}