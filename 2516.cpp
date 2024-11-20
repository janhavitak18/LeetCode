class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

    // Count total occurrences of 'a', 'b', and 'c' in the string
    vector<int> total_count(3, 0);
    for (char c : s) {
        total_count[c - 'a']++;
    }

    // If any character has fewer than k occurrences, return -1
    for (int count : total_count) {
        if (count < k) return -1;
    }

    // Calculate the needed counts to retain for each character
    vector<int> needed(3);
    for (int i = 0; i < 3; ++i) {
        needed[i] = total_count[i] - k;
    }

    // Sliding window approach
    vector<int> current_count(3, 0);
    int left = 0, max_length = 0;

    for (int right = 0; right < n; ++right) {
        current_count[s[right] - 'a']++;

        // Shrink the window if any character exceeds its "needed" count
        while (current_count[0] > needed[0] || current_count[1] > needed[1] || current_count[2] > needed[2]) {
            current_count[s[left] - 'a']--;
            left++;
        }

        // Update the maximum length of the valid subarray
        max_length = max(max_length, right - left + 1);
    }

    // The minimum minutes needed
    return n - max_length;
    }
};
