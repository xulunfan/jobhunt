class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1) return 1;
        int a[101]={0};
        vector<int>v;
        v.push_back(1);
        while(v.size()<n){
            vector<int>b;
            for(int i=0;i<primes.size();i++){
                b.push_back(primes[i]*v[a[i]]);
            }
            int result=b[0];
            
            for(int i=0;i<b.size();i++) result=min(result,b[i]);
            v.push_back(result);
            for(int i=0;i<b.size();i++){
                if(result==b[i]) a[i]++;
            }            
        }
        return v[n-1];
    }
};
