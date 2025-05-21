// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<int> row(n, 0);
//         vector<int> col(m, 0);


//         // int col [m] ={0};
//         // int row [n] = {0};
//         for (int i = 0,  i< n , i++){
//             for(int j = 0, j <m , j++){
//                 if(matrix[i][j]==0){
//                     row[i] = 1;
//                     col[j] =1;

//                 }
//             }
//         }
//         for(int i  = 0, i<n , i++){
//             for (int j =0 j< m, j++) {
//                 if(row[i] || col [j]){
//                     matrix[i][j] =0;
//                 }
//             }
//         }
//         return matrix;
//     }
// };



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return; 

        int n = matrix.size();       
        int m = matrix[0].size();    
        vector<int> row(n, 0);       
        vector<int> col(m, 0);      

        
        for (int i = 0; i < n; i++) {         
            for (int j = 0; j < m; j++) {     
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

       
        for (int i = 0; i < n; i++) {         
            for (int j = 0; j < m; j++) {     
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
