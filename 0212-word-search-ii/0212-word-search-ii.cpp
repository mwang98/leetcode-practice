class TrieNode {
    public:
        string word = "";
        TrieNode* children[26];
        TrieNode() {
            memset(children, 0, sizeof(children));
        }
        ~TrieNode(){
            for (int i = 0 ; i < 26 ; ++i){
                if(children[i]) delete children[i];
            }
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Define variables
        TrieNode* root = new TrieNode();
        vector<string> res;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n_rows = board.size(), n_cols = board[0].size();

        // Build Trie over `words` (trie.insert)
        for(const auto& word: words){
            auto cursor = root;
            for(auto ch: word){
                if(cursor->children[ch - 'a'] == 0)
                    cursor->children[ch - 'a'] = new TrieNode();
                cursor = cursor->children[ch - 'a'];
            }
            cursor->word = word;
        }


        // Backtrack: `node` is used to traverse Trie like `index` for 1-D data structure
        function<void(int, int, TrieNode*)> backtrack = 
        [&](int x, int y, TrieNode* node) -> void {
            // Base case
            auto ch = board[x][y];
            if(ch == '#') return; // visited cell
            if(node->children[ch - 'a'] == 0) return; // ch not found in Trie

            // Recursive case
            board[x][y] = '#';
            node = node->children[ch - 'a'];

            if(!node->word.empty()) { // a word found!
                res.push_back(node->word);
                node->word = "";
            }
            for(auto [dx, dy]: directions){
                auto nx = x + dx, ny = y + dy;
                if(!(0 <= nx && nx < n_rows && 0 <= ny && ny < n_cols)) continue;
                backtrack(nx, ny, node);
            }
            board[x][y] = ch;
        };

        for(int i = 0 ; i < n_rows ; ++i){
            for(int j = 0 ; j < n_cols ; ++j){
                backtrack(i, j, root);
            }
        }
        return res;
    }
};