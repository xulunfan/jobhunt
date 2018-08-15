class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        if(n==4) return 4;   
        if(n==5) return 5;   
        vector<int>a={1,2,3,4,5};
        int i=2,j=1,k=1;
        while(a.size()<=1690){
            int x=a[i]*2,y=a[j]*3,z=a[k]*5,w=min(min(x,y),z);
            a.push_back(w);
            if(x==w) i++;
            if(y==w) j++;
            if(z==w) k++;
        }
        return a[n-1];
    }
};
