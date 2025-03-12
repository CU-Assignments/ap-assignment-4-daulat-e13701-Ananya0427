#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], i, 0}); 
        }

        int count = 0, result = 0;
        while (count < k) {
            auto top = minHeap.top();
            minHeap.pop();
            result = top[0];
            int row = top[1], col = top[2];

            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
            count++;
        }

        return result;
    }
};
