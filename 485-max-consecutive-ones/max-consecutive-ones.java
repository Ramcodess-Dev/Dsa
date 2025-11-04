class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxfreq=0;
        int freq=0;
        for(int val:nums){
            if(val==1)freq++;
            else freq=0;       
            maxfreq=Math.max(freq,maxfreq);
        }
        return maxfreq;
    }
}