class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int one = 0;
        int two = 0;
        for(int i : arr){
            one = (i ^ one) & ~two;
            two = (i ^ two) & ~one;
        }
        return one;
    }
};