class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        while(index < bits.size()){
            if(index == bits.size()-1) return true;
            if(bits[index] == 0){
                index++;
            }else{
                index += 2;
            }
        }
        return false;
    }
};