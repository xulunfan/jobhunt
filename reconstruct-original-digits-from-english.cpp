class Solution {
public:
    string originalDigits(string s) {
        int a[128]{},b[128]{};
        string result;
        for(auto c:s)++a[c];
        b['0']=a['z'];
        b['2']=a['w'];
        b['4']=a['u'];
        b['6']=a['x'];
        b['8']=a['g'];
        b['1']=a['o']-b['0']-b['2']-b['4'];
        b['3']=a['r']-b['0']-b['4'];
        b['5']=a['f']-b['4'];
        b['7']=a['s']-b['6'];
        b['9']=a['i']-b['5']-b['6']-b['8'];
        for(int i=0;i<=9;++i){
            result+=string(b['0'+i],'0'+i);
        }
        return result;
    }
};
