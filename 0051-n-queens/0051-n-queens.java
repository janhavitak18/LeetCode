class Solution {
    private List<List<String>> list = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        int[][] places = new int[n][n];
        helper(places, n, 0);
        return list;
    }

    private void helper(int[][] nums, int n, int r) {
        if (r >= n) {
            fillPattern(nums);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(r, i, nums)) {
                nums[r][i] = 1;
                helper(nums, n, r + 1);
                nums[r][i] = 0;
            }
        }
    }

    private boolean isValid(int r, int c, int[][] nums) {
        for (int i = r - 1; i >= 0; i--) {
            if (nums[i][c] == 1)
                return false;
        }

        for (int i = r - 1, j = c + 1; i >= 0 && j < nums.length; i--, j++) {
            if (nums[i][j] == 1)
                return false;
        }

        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (nums[i][j] == 1)
                return false;
        }

        return true;
    }

    private void fillPattern(int[][] nums) {
        List<String> l = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < nums.length; j++) {
                if (nums[i][j] == 1)
                    sb.append("Q");
                else
                    sb.append(".");
            }
            l.add(sb.toString());
        }
        list.add(l);
    }
}

// class Solution {
// public List<List<String>> solveNQueens(int n) {
// int [][] places = new int[n][n];
// helper(places, n , 0);
// return list;
// }
// private void helper(int[][]nums, int n , int r){
// if(r>=n){
// fillPateren(nums);
// return;
// }
// for(int i = 0 ; i<n; i++){
// if(isValid(r,i,nums)){
// helper(nums, n , r+1);
// nums[r][i] =0;
// }
// }
// }
// private boolean isValid(int r, int c; int[][]nums){

// for(int i = r-1; i>=0; i--){
// if(nums[i][c] == 1) return false;

// }

// for(int i = r-1, j= c+1; i>= 0 && j<nums.lenght; i--, j++){
// if(nums[i][j] == 1) return false;
// }
// for(int i = r-1, j=c-1; i>0&& j>=0; i--; j--){
// if(nums[i][j] == 1) return false;
// }
// return true;
// }
// private void fillPattern(int [][] nums){
// List<String> l = new Arraylist<>();
// for(int i = 0; i<nums.lenght; i++){
// StringBuilder sb= new StringBuilder ();
// for(int j = 0; j = nums.lenght; j++){
// if(nums[i][j] == 1) sb.append("Q")
// else sb.append(".");

// }
// l.add(sb.toString);
// }
// list.add(l);
// }
// }