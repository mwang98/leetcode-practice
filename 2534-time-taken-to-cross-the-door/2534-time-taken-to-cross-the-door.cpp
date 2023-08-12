enum State {
    Enter = 0,
    Exit = 1,
    None = 2,
};
class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        vector<int> ret(arrival.size());
        queue<pair<int, int>> enter, exit;
        int timer = 0;
        State prev_state = State::None;

        for(int i = 0 ; i < arrival.size() ; ++i){
            if(state[i]) exit.push({i, arrival[i]});
            else enter.push({i, arrival[i]});
        }

        while(!enter.empty() && !exit.empty()){
            auto [in_idx, in_time] = enter.front();
            auto [ot_idx, ot_time] = exit.front();
            if(in_time > timer && ot_time > timer){
                timer = min(in_time, ot_time);
                prev_state = State::None;
            } else if(in_time <= timer && ot_time <= timer){
                if(prev_state == State::None || prev_state == State::Exit){
                    ret[ot_idx] = timer++;
                    prev_state = State::Exit;
                    exit.pop();
                } else{
                    ret[in_idx] = timer++;
                    prev_state = State::Enter;
                    enter.pop();
                }
            } else if(in_time <= timer){
                ret[in_idx] = timer++;
                prev_state = State::Enter;
                enter.pop();
            } else{ // ou_time <= timer
                ret[ot_idx] = timer++;
                prev_state = State::Exit;
                exit.pop();
            }
        }

        while(!enter.empty()){
            auto [in_idx, in_time] = enter.front();
            ret[in_idx] = max(timer, in_time);
            timer = ret[in_idx] + 1;
            enter.pop();
        }

        while(!exit.empty()){
            auto [ot_idx, ot_time] = exit.front();
            ret[ot_idx] = max(timer, ot_time);
            timer = ret[ot_idx] + 1;
            exit.pop();
        }

        return ret;
    }
};