/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maxChunksToSorted(vector<int>& arr) {
        /* Monotonic stack 
        Maintain increasing stack (>=)
        Pop: elements > num
        Push: max(num, max(popped elements))
        */
        vector<int> mono_stack;

        for (const auto& val: arr){
            if (mono_stack.empty() || val >= mono_stack.back())
                mono_stack.push_back(val);
            else{
                auto largest = mono_stack.back();
                while(!mono_stack.empty() && val < mono_stack.back())
                    mono_stack.pop_back();
                mono_stack.push_back(largest);
            }
        }

        return mono_stack.size();
    }
};
// @lc code=end
