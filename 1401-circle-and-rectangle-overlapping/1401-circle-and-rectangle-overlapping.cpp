class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {

        if(xc >= x1 && xc <= x2 && yc >= y1 && yc <= y2){
            return true;
        }

        for(int i=x1; i<=x2; i++){

            double d11 = 1.0 * ((i-xc) * (i - xc) + (y1 - yc)*(y1 - yc));
            double d22 = 1.0 * ((i-xc) * (i - xc) + (y2 - yc)*(y2 - yc));
            double d1 = sqrt(d11);
            double d2 = sqrt(d22);

            if(d1 <= r || d2 <= r) return 1;
        }
        for(int i=y1; i<=y2; i++){

            double d11 = 1.0 * ((x1-xc) * (x1 - xc) + (i - yc)*(i - yc));
            double d22 = 1.0 * ((x2-xc) * (x2 - xc) + (i - yc)*(i - yc));
            double d1 = sqrt(d11);
            double d2 = sqrt(d22);

            if(d1 <= r || d2 <= r) return 1;
        }

        return 0;
    }
};