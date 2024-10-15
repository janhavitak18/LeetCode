class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if (s1[0] != s2[0] || s2[0] != s3[0] || s1[0] != s3[0])
            return -1;
        int i = 0, j = 0, k = 0;
        while (i < a && j < b && k < c) 
        {
            if (s1[i] != s2[i] || s2[i] != s3[i] || s1[i] != s3[i])
                break;
            i++;
            j++;
            k++;
        }
        return a - i + b - j + c - k;
    }
};
