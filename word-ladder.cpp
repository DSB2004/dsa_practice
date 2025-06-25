
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> wordSet(wordList.begin(), wordList.end());
            if (wordSet.find(endWord) == wordSet.end()) return 0;
            queue<string> _queue;
            string curr = beginWord;
            _queue.push(curr);

            int result = 1;
            while(!_queue.empty()){
                int sz = _queue.size();
                for (int i = 0; i <sz; i++) {
                    string front = _queue.front();
                    _queue.pop();
                    if(front==endWord) return result;
                    for (int i = 0; i < front.size();i++){
                        string temp = front;
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (temp[i] == c) continue;
                            temp[i] = c;
                            if(wordSet.find(temp)!=wordSet.end()){
                                _queue.push(temp);
                                wordSet.erase(temp);
                            }
                    }
                }
                result++;
            }}
            return 0;
            }
        
    }; 