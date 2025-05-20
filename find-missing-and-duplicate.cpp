

class Solution {

    // using hashmap
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int>ref((grid.size()*grid.size())+1,0);
            vector<int>result(2);
            for(auto n:grid){
                for(auto m:n){
                    ref[m]++;
                }
            }
            for(int i=0;i<ref.size();i++){
                if(ref[i]==0){
                    result[1]=i;
                }
                else if(ref[i]==2){
                    result[0]=i;
                }
            }
            return result;

        }
    // using math intuition 

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int x,y;
        // x is duplicate no and y is missing number
        long long  sum=0;
        long long sumsq=0;

        long long n=grid.size()*grid.size();

        // x-y = sum of all grid ele - sum of n natural number
        // x^2 - y^2 = sum of sq of all grid ele - sum of sq of n natural number
        
        for(auto row:grid){
            for(auto ele:row){
                sum+=static_cast<long long>(ele);
                sumsq+=static_cast<long long>(ele*ele);
            }
        }


        long long s=(n*(n+1))/2; // sum of first natural number
        long long sq=(n*(n+1)*(2*n+1))/6; // sum of sq of first n natural number
        
        y=(sumsq-sq-((sum-s)*(sum-s)))/(2*(sum-s));
        x=y+sum-s;
        return vector<int>{x, y}; 
        

    }
    };