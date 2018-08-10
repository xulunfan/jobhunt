class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        if(prices.size()==2){
            return max(0,prices[1]-prices[0]);
        }
        vector<int>ans(prices.size());
        ans[0]=0;
        ans[1]=max(0,prices[1]-prices[0]);
        for(int i=2;i<prices.size();i++){
            ans[i]=ans[i-1];
            if(prices[0]<prices[i]) ans[i]=max(ans[i],prices[i]-prices[0]);
            if(prices[1]<prices[i]) ans[i]=max(ans[i],prices[i]-prices[1]);
            for(int j=2;j<i;j++){
                if(prices[j]<prices[i]){
                    int tmp=ans[j-2]+(prices[i]-prices[j]);
                    ans[i]=std::max(ans[i],tmp);
                }
            }
        }
        return ans[prices.size()-1];
    }
};
