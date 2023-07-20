class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int num_4groups = 0;
        unordered_map<int, int> seats;

        for(const auto& vec: reservedSeats)
            seats[vec[0] - 1] = seats[vec[0] - 1] | (1 << (vec[1] - 1));
        
        for(auto [row, seat]: seats){
            int is_mid   = ((0b0001111000 & seat) == 0);
            int is_right = ((0b0000011110 & seat) == 0);
            int is_left  = ((0b0111100000 & seat) == 0);
            num_4groups += max(is_mid, is_right + is_left);
        }

        num_4groups += (n - seats.size()) * 2; // empty row

        return num_4groups;
    }
};