class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int n : nums) {
            minHeap.push(n);
            maxHeap.push(n);

            if (minHeap.size() > 3) minHeap.pop();
            if (maxHeap.size() > 3) maxHeap.pop();
        }

        // minHeap contains 3 largest: extract in ascending order
        int a = minHeap.top(); minHeap.pop();
        int b = minHeap.top(); minHeap.pop();
        int c = minHeap.top(); minHeap.pop();

        // maxHeap contains 3 smallest: extract in descending order
        int x = maxHeap.top(); maxHeap.pop();
        int y = maxHeap.top(); maxHeap.pop();
        int z = maxHeap.top(); maxHeap.pop();

        int sum1 = a * b * c;
        int sum2 = y * z * c;
        
        return max(sum1, sum2);
    }
};