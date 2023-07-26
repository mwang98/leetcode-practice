class Solution {
public:
    string str;
    int INIT_PART = 16;
    int min_partitions = 16;
    unordered_set<string> power5 {"11110100001001", "110000110101", "1001110001",
                                  "1111101", "11001", "101", "1"};

    void backtrack(int i = 0, int n_part = 0){
        // Base case
        if(i == str.size()){
            min_partitions = min(min_partitions, n_part); 
            return;
        } else if(str[i] == '0') return; // leading zero

        // Recursive case
        for(int j = i + 1 ; j <= str.size() ; ++j){
            if(power5.count(str.substr(i, j - i))){
                cout << str.substr(i, j - i) << endl;
                backtrack(j, n_part + 1);
            }
        }
    }
    int minimumBeautifulSubstrings(string s) {
        str = s;
        backtrack();

        return min_partitions == INIT_PART ? -1 : min_partitions;
    }
};