class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap to store the count and character as pairs
        priority_queue<pair<int, char>> pq;

        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while (!pq.empty()) {
            auto [currCount, currChar] = pq.top();
            pq.pop();

            // If the last two characters in the result are the same as currChar, we need to skip it
            if (result.length() >= 2 && result[result.length() - 1] == currChar && result[result.length() - 2] == currChar) {
                if (pq.empty()) {
                    break;
                }

                // Use the next largest frequency character
                auto [nextCount, nextChar] = pq.top();
                pq.pop();

                result.push_back(nextChar);
                nextCount--;

                if (nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }

                // Push the current character back to the heap
                pq.push({currCount, currChar});
            } else {
                // Use the current character
                result.push_back(currChar);
                currCount--;

                if (currCount > 0) {
                    pq.push({currCount, currChar});
                }
            }
        }

        return result;
    }
};
