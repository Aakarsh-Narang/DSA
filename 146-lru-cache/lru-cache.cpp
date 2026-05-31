class LRUCache {
public:
    struct Node{
        Node* prev;
        Node* next;
        int key, value;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = next = NULL;
        }
    };

    // Global variables
    int cap;
    Node* head; // Most Recently used
    Node* tail; // Least Recently used
    unordered_map<int, Node*> mp;  // Map to store addresses of the Keys

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        // Initial Connection
        head->next = tail;
        tail->prev = head;
    }

    // Adds a node to the Head  (Head -- 1st Node -- ..... -- Tail)
    void addNode(int key, int val){
        Node* temp = new Node(key, val);

        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;

        mp[key] = temp;
        if(mp.size() > cap) 
            deleteNode(tail->prev); // Least Recently used
    }

    void deleteNode(Node* temp){
        int key = temp->key;

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        mp.erase(key);
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* temp = mp[key];
            int val = temp->value;

            // Maintain Recency
            deleteNode(temp);
            addNode(key, val);

            return temp->value;
        }

        return -1;   
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->value = value;
            // Maintain Recency
            get(key);
        }
        else{
            addNode(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */