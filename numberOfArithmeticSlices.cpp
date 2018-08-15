class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        if(A.size()==3){
            if(A[0]-A[1]==A[1]-A[2]) return 1;
            return 0;
        }
        int end=A.size()-1;
        int p=0,cnt=0;
        if(end>1){
            p=end-1,cnt=0;
            while(p-1>=0&&A[end]-A[end-1]==A[p]-A[p-1]){cnt++;p--;}
        }
        A.pop_back();
        return numberOfArithmeticSlices(A)+cnt;
    }
};
