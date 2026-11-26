class Solution {
public:
    bool canAliceWin(int n) {
        int remstones = 10;
        while(n > 0)
        {
            if(n < remstones)
                return false;
            n -= remstones;
            --remstones;
            if(n < remstones)
                return true;
            n -= remstones;
            --remstones;
        }
        return false;
    }
};