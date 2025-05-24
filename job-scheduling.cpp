
#include<vector>
#include<algorithm>
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // sort on profit
    sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] > b[2];  // descending order
    });

    // get the max unit allowed 

    int maxTime=INT_MIN;
    int count=0;
    int maxProfit=0;
    for(auto job:jobs){
        maxTIme=max(maxTIme,job[1]);
    }


    vector<int>taken=new vector(maxTime,0);

    for(auto job:jobs){
        //  trying for max deadline possible to min
        for(int i=job[1]-1;i>=0;i--){
            if(taken[i]==0){
                taken[i]=1;
                count++;
                maxProfit+=job[2];
                break;
            }
        }
    }


    vector<int>result;
    result.push_back(count);
    result.push_back(maxProfit);
    return result;

}