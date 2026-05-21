/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int isLeaf(vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
        int sum = 0;
        for(int i = x1; i<=x2; i++){
            for(int j = y1; j<=y2; j++){
                sum += grid[i][j];
            }
        }
        if(sum == 0) return 0;  // Leaf with all 0s
        if(sum == (x2-x1+1)*(y2-y1+1)) return 1;    // Leaf with all 1s
        return -1;  //Not a leaf
    }
    Node* build(vector<vector<int>>& grid, int x1, int x2, int y1, int y2){
        int value = isLeaf(grid, x1, y1, x2, y2);
        Node* root = new Node();
        
        if(value != -1){
            root->val = value;
            root->isLeaf = true;
            return root;
        }

        int xmid = (x1+x2)/2;  //x1 -> xmid & xmid+1 -> x2
        int ymid = (y1+y2)/2;

        root->topLeft = build(grid, x1, xmid, y1, ymid);
        root->bottomLeft = build(grid, xmid+1, x2, y1, ymid);
        root->topRight = build(grid, x1, xmid, ymid+1, y2);
        root->bottomRight = build(grid, xmid+1, x2, ymid+1, y2);

        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, n-1, 0, n-1);
    }
};