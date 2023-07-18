class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        /* Solved by boolean algebra
        Example:
            arr1 = [A], arr2 = [a, b]
            Aa ^ Ab = Aa(Ab)' + (Aa)'Ab
                    = Aa(A'+b') + Ab(A'+a')
                    = A(ab'+a'b)
                    = A(a ^ b)
            =>
            arr1 = [A, B], arr2 = [a, b]
            Answer = (A ^ B)(a ^ b)
        */
        int xor_1 = 0, xor_2 = 0;

        for(auto num: arr1) xor_1 = xor_1 ^ num;
        for(auto num: arr2) xor_2 = xor_2 ^ num;

        return xor_1 & xor_2;
    }
};