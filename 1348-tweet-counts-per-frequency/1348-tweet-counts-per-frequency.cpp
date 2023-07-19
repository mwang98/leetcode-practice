class TweetCounts {
    unordered_map<string, multiset<int>> record;
    unordered_map<string, int> mapping;
public:
    TweetCounts() {
        mapping["minute"] = 60;
        mapping["hour"] = 3600;
        mapping["day"] = 86400;
    }
    
    void recordTweet(string tweetName, int time) {
        record[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ret;
        auto step = mapping[freq];
        const auto& tweets = record[tweetName];
        
        int start = startTime, end = min(start + step, endTime + 1);
        auto curr_it = tweets.begin();

        while(start < endTime + 1){
            auto start_it = lower_bound(curr_it, tweets.end(), start);
            auto end_it = lower_bound(start_it, tweets.end(), end);
            ret.push_back(distance(start_it, end_it));

            curr_it = end_it;
            start = end;
            end = min(end + step, endTime + 1);
        }

        return ret;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */