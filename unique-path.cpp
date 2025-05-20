class Solution {
    // brute force
    public:
        int helper(int x,int y,int m,int y){
            if(x>m-1 || y>n-1){
                return 0;
            } // outside the boundary
            else if(x==m-1 && y==n-1){ 
                return 1;
            } // inside
            else{
                return helper(x+1,y,m,n)+helper(x,y+1,m,n); 
            } // move right or bottom
        }   


        int uniquePaths(int m, int n) {
            return helper(0,0,m,n);
        }

    // using dynamic programming 

        int helper(int x,int y,int m,int n,vector<vector<int>>&ref){
            if(x>m-1||y>n-1){
                return 0;
            }
            if(ref[x][y]!=-1){
                return ref[x][y];
            }
            if(x==m-1 && y==n-1){ 
                ref[x][y]=1;
                return 1;
            }
            ref[x][y] = helper(x + 1, y, m, n, ref) + helper(x, y + 1, m, n, ref);
            return ref[x][y];
        }   
    
    
        int uniquePaths(int m, int n) {
            vector<vector<int>> ref(m, vector<int>(n, -1));
            return helper(0,0,m,n,ref);
        }
        
    };