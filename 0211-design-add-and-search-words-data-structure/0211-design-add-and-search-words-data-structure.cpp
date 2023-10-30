class TrieNode {
public:
    bool isEnd = false;
    map<char, TrieNode*> children;
    ~TrieNode(){
        for (auto [c, ptr] : children) delete ptr;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();    
    }
    
    void addWord(string word) {
        auto cursor = root;
        for(auto ch: word){
            if(cursor->children.count(ch) == 0)
                cursor->children[ch] = new TrieNode();
            cursor = cursor->children[ch];
        }
        cursor->isEnd = true;
    }
    
    bool search(string word) {
        return inner_search(root, word);
    }

private:
    bool inner_search(TrieNode* node, string word) {
        // Base case
        if(word == "") return node->isEnd; // found existed string

        // Recursive case
        bool res = false;
        auto tgt_ch = word[0];
        string substr = word.substr(1, word.size() - 1);

        if(tgt_ch == '.'){
            for(auto [ch, next_node]: node->children){
                res |= inner_search(next_node, substr);
            }
            
        } else if (node->children.count(tgt_ch)) 
            res = inner_search(node->children[tgt_ch], substr);

        return res; 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */