class Solution {
public:
    int furthestDistanceFromOrigin(string m) {
        
        int c=0;
        int l=0;
        int r=0;
    int maxm=0;
        for(int i=0;i<m.length();i++){
            if(m[i]=='L') l++;
            else if(m[i]=='R') r++;
            else c++;
        }
          return maxm=max(l+c-r,r+c-l);
        
    }
};