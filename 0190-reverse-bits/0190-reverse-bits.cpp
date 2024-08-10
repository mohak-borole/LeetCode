class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int power = 1;
        for(int i = 0 ; i<32 ; i++){
            uint32_t lsb = n%2;
            n = n/2;
            res = res << 1 | lsb;
        }
        
        return res;
    }
};