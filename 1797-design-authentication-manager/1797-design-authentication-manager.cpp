class AuthenticationManager {
public:
    int TTL; // time to live
    unordered_map<string, int> tokens; // tokenId -> exp time
    multimap<int, string> time2tokens; // exp time -> tokenId

    AuthenticationManager(int timeToLive) {
        TTL = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        // O(logn)
        tokens[tokenId] = currentTime + TTL;
        time2tokens.insert({currentTime + TTL, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        // O(logn)
        if(tokens.count(tokenId) == 0) return;
        if(tokens[tokenId] <= currentTime) tokens.erase(tokenId);
        else generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        // O(logn)
        auto end_it = time2tokens.upper_bound(currentTime);

        // Remove expired tokens in hash map
        for(auto it = time2tokens.begin() ; it != end_it ; ++it){
            if(tokens.count(it->second) && tokens[it->second] == it->first) 
                tokens.erase(it->second);
        }
 
        time2tokens.erase(time2tokens.begin(), end_it);

        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */