class Solution {
public:
    int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<int> q;
        queue<int> delay_q;

        q.push(1);
        delay_q.push(1);
        int n_ppl = 1; // # of people know the secret
        int n_delay_ppl = 1; // # of people know the secret but cannot tell others

        for(int i = 1 ; i < n ; ++i){
            if(q.size() == forget){
                auto ppl = q.front();
                q.pop();
                n_ppl = (n_ppl - ppl + MOD) % MOD;
            }
            if(delay_q.size() == delay){
                auto ppl = delay_q.front();
                delay_q.pop();
                n_delay_ppl = (n_delay_ppl - ppl + MOD) % MOD;
            }

            auto new_ppl = (n_ppl - n_delay_ppl + MOD) % MOD;
            q.push(new_ppl);
            delay_q.push(new_ppl);

            n_ppl = (n_ppl + new_ppl) % MOD;
            n_delay_ppl = (n_delay_ppl + new_ppl) % MOD;
        } 

        return n_ppl;
    }
};