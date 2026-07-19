class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up=0,down=matrix.size()-1;
        int right=matrix[0].size()-1;

        while(up<down){
            int mid1=up+(down-up)/2;
            if(matrix[mid1][right]<target){
                up=mid1+1;
            }
            // else if(matrix[mid1][0]==target) return true;
            else{
                down=mid1;
            }




        }

        int left=0;
        if (target < matrix[up][0] || target > matrix[up][right]) return false;
        while(left<=right){
            int mid2=left+(right-left)/2;
            if (matrix[up][mid2] == target)
                return true;
            else if (matrix[up][mid2] < target)
                left = mid2 + 1;
            else
                right = mid2 - 1;
        }

        return false;
    }

};