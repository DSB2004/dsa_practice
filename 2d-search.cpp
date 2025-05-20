class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i = 0;
        int j = row - 1;

        while (i <= j) {
            int mid = (i + j) / 2;
            
            if (matrix[mid][col - 1] == target) {
                return true;
            } else if (matrix[mid][col - 1] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        
        if (i >= row) return false;  // No valid row found
        
        int rowToSearch = i;  // Now `i` is the row where the target could exist
        int left = 0;
        int right = col - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (matrix[rowToSearch][mid] == target) {
                return true;
            } else if (matrix[rowToSearch][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};
