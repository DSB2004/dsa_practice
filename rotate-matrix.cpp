class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first calcuate the transpose of matrix
        
        int n=matrix.size();

       for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }

        // then reverse each row
        
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
};