class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Since the number of piles is even, Alice can choose on her first move whether to collect all even-indexed piles or all odd-indexed piles.
        // She first computes:
        // - evenSum = sum of stones at even indices
        // - oddSum = sum of stones at odd indices
        // Alice chooses the parity with the larger total on her first move and, thereafter, always picks the end corresponding to that parity.
        // Bob is forced to take piles from the opposite parity.
        // Since the total number of stones is odd, evenSum ≠ oddSum, so one parity has a strictly larger sum.
        // Therefore, Alice can always guarantee collecting the larger parity sum and always wins.
        return 1;
    }
};