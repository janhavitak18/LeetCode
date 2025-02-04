class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int k = 0;
        bool a = false;
        for(int i  = n-1;  i > 0; i--){
            if(arr[i]>arr[i-1]){
                k = i -1;
                a = true;
                break;
            }
        }
        if(a==false){
            sort(arr.begin(), arr.end());
            return;
        }
        int min = INT_MAX;
        int index = 0;
        for(int i = n-1; i>k; i--){
            if(arr[i] < min && arr[i] > arr[k]){
                min = arr[i];
                index = i;

            }
        }
        swap(arr[k], arr[index]);

        reverse(arr.begin()+k+1, arr.end());
    }
};