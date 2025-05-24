class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        vector<pair<int,int>> meets;

        for(int i=0;i<start.size();i++){
            meets.push_back({end[i],start[i]});
        }

        sort(meets.begin(),meets.end());

        int count=1;
        int lastMeet=meets[0].first;

        for(int i=1;i<meets.size();i++){
            if(lastMeet<meets[i].second) {count++; lastMeet=meets[i].first;}
        }

        return count;
    }
};