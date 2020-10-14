class Solution {
    public int jump(int[] input1) {
        int n=input1.length;
	if(n==1)
		return 0;
	int reached=0;
	int current=0;
	int ans=0;
	for(int i=0;i<n-1;i++){
		if(i+input1[i]>reached)
			reached=i+input1[i];
		if(current==i){
			current=reached;
			ans++;
		}
	}
	return ans;
    }
}
