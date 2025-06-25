
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int sumOfGoodArray(vector<int> &array,int k){
    map<int, int> ref;
    for(auto n:array){
        ref[n]++;
    }

    int result = 0;
    for(auto no:ref){
        if(no.second<=k && no.first>0)
            result += (no.first * no.second);
            
    }

    return result;
}
void runTest(const vector<int>& array, int k, int expected, int testNumber) {
    int observed = sumOfGoodArray(const_cast<vector<int>&>(array), k);
    cout << "Test " << testNumber << ": ";
    if (observed == expected) {
        cout << "✅ Passed";
    } else {
        cout << "❌ Failed";
    }
    cout << " | Observed: " << observed << " | Expected: " << expected << endl;
}

int main() {
    runTest({1, 2, 2, 3, 3, 3}, 2, 5, 1);              // 1 + 2*2 = 5
    runTest({-1, 0, 1, 1, 2, 2, 3}, 1, 3, 2);          // Only 3 is valid
    runTest({4, 4, 4, 4}, 2, 0, 3);                    // All exceed k
    runTest({-1, -2, -3, -3}, 2, 0, 4);                // All negative
    runTest({0, 0, 0, 1, 2}, 2, 3, 5);                 // 1 + 2
    runTest({5, 5, 2}, 2, 12, 6);                      // 5*2 + 2
    runTest({1, 1, 1, 2, 2, 3}, 100, 10, 7);           // All included
    runTest({0, 0, 0}, 1, 0, 8);                       // Only zeros
      runTest({}, 2, 0, 9);                              // Empty input
    runTest({7, 7, 7, 7, 7}, 5, 35, 10);               // All within k
    runTest({7, 7, 7, 7, 7}, 3, 0, 11);                // Exceeds k
    runTest({-10, -10, -10, 1000}, 1, 1000, 12);       // Only 1000
    runTest({-10, -5, 0, 3, 4, 4}, 2, 11, 13);         // 3 + 4*2 = 11
    runTest({1, 2, 3, 4, 5, 6}, 1, 21, 14);            // All unique
    runTest({1, 1, 2, 2, 3, 3}, 1, 0, 15);             // All exceed k=1
    runTest({1, 2, 2, 3, 3, 3}, 3, 14, 16);            // 1 + 2*2 + 3*3 = 14
    runTest({-100, -50, 100, 50, 50}, 2, 200, 17);     // 100 + 50*2
    runTest({1000000}, 1, 1000000, 18);                // Large single value

    return 0;
}