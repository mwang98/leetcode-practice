class TrieNode {
    public:
        bool is_end = false;
        unordered_map<char, TrieNode*> children;
};

class StreamChecker {
public:
    TrieNode* root;
    string stream = "";
    StreamChecker(vector<string>& words) {
        // TC: O(WK) where W = word length, K = # of words
        // SC: O(WK)
        // Create root 
        root = new TrieNode();

        // Build trie on top of words
        auto insert = [&](const auto& w) -> void {
            auto cursor = root;
            for(auto ch: w){
                if(cursor->children.count(ch) == 0)
                    cursor->children[ch] = new TrieNode();
                cursor = cursor->children[ch];
            }
            cursor->is_end = true;
        };

        for(auto w: words) {
            // Reverse word
            reverse(w.begin(), w.end());
            insert(w);
        }
    }
    
    bool query(char letter) {
        // TC: O(W + Q) where Q = # of query calls so far 
        // SC: O(1)
        stream.push_back(letter);

        // Traverse trie
        auto cursor = root;
        for(int i = stream.size() - 1 ; i >= 0 ; --i){
            auto ch = stream[i];
            if(cursor->children.count(ch) == 0) return false; // suffix not found
            cursor = cursor->children[ch];
            if(cursor->is_end) return true; // one suffix found
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */