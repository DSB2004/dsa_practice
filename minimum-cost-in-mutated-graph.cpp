#include<iostream>
#include <queue>
#include<vector>


using namespace std;

using _pair=pair<int,int>;


class Solution{
    public:
    int solution(int n,vector<int> list){
        vector<int> dis(n+1,INT_MAX);

        priority_queue<_pair,vector<_pair>,greater<_pair>> pq;

        pq.push({0,1});
        dis[1]=0;

        while(!pq.empty()){
            auto [_d,_n]=pq.top();
            pq.pop();
            int node_val=list[_n];
            for(int j=_n+1;j<n;j++){
                if(j==_n+1){
                    if(dis[j]>_d+1){
                        dis[j]=_d+1;
                        pq.push({_d+1,j});
                    }
                }else{
                    if(list[j]%list[_n]==0&& dis[j]>list[_n]){
                        dis[j]=list[_n];
                        pq.push({list[_n],j});
                        list[j]++;
                    }
                }
            }
        }
        return dis[n];
    }
};


int main() {
    Solution sol;

    // Test Case 1: Minimum input (n = 2)
    {
        vector<int> list = {0, 1};  // start at index 1, goal is index 1
        cout << "Test 1 (n=2): " << sol.solution(list.size(), list) << " (Expected: 0)" << endl;
    }

    // Test Case 2: Only move forward (no valid jumps)
    {
        vector<int> list = {0, 5, 7, 9, 11};  // all list[j] % list[i] != 0
        cout << "Test 2 (forward only): " << sol.solution(list.size(), list) << " (Expected: 3)" << endl;
    }

    // Test Case 3: All elements are multiples of list[1]
    {
        vector<int> list = {0, 2, 4, 6, 8, 10};  // should allow jump from 1 to all
        cout << "Test 3 (full jump): " << sol.solution(list.size(), list) << " (Expected: depends, likely 2)" << endl;
    }

    // Test Case 4: list[j] becomes un-jumpable due to list[j]++ mutation
    {
        vector<int> list = {0, 2, 4, 6, 8};  // after jump, list[j]++
        cout << "Test 4 (mutating jumps): " << sol.solution(list.size(), list) << " (Expected: depends)" << endl;
    }

    // Test Case 5: Large list with uniform values
    {
        vector<int> list(1000, 2);
        list[0] = 0;
        list[1] = 2;
        cout << "Test 5 (large uniform): " << sol.solution(list.size(), list) << " (Expected: should run fast)" << endl;
    }

    // Test Case 6: No possible jumps, must walk to end
    {
        vector<int> list = {0, 3, 5, 7, 11, 13, 17};  // primes, no list[j] % list[i] == 0
        cout << "Test 6 (no jumps): " << sol.solution(list.size(), list) << " (Expected: 5)" << endl;
    }

    // Test Case 7: Path with cheaper jumps than walks
    {
        vector<int> list = {0, 1, 2, 4, 8};  // can jump: 1->2->4->8
        cout << "Test 7 (cheapest jumps): " << sol.solution(list.size(), list) << " (Expected: likely 1)" << endl;
    }

    return 0;
}
