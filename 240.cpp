class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int row=0;
        int col=n-1;
        while(row<m && col>=0){
            int mid=mat[row][col];
            if(target==mid){
                return true;
            }else if(target>mid){
                row++;
            }else col--;
        }
        return false;
    }
};
