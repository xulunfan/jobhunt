class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int a[101]={0};
        vector<int>v;
        v.push_back(1);
        while(v.size()<n){
            int result=INT_MAX;      
            for(int i=0;i<primes.size();i++) result=min(result,primes[i]*v[a[i]]);
            v.push_back(result);
            for(int i=0;i<primes.size();i++){
                if(result==primes[i]*v[a[i]]) a[i]++;
            }            
        }
        return v[n-1];
    }
};
