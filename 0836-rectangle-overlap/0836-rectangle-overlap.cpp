class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        return !(rec1[2] <= rec2[0] ||  //LEFT
                 rec1[3] <= rec2[1] ||  //BOTTOM
                 rec1[1] >= rec2[3] ||  //TOP
                 rec1[0] >= rec2[2] //RIGHT
                 );
        
    }
};