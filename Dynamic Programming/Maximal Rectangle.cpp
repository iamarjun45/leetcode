class Solution {
    int maximumHistogramArea(int heights[],int cols){
        stack<int> s;
        int max_area=0;
        for(int i=0;i<cols;i++){
            if(s.empty() || heights[i]>=heights[s.top()])
                s.push(i);
            else{
               while((!s.empty()) && heights[i]<heights[s.top()]){
                   int currHeight=heights[s.top()];
                   s.pop();
                   max_area=max(max_area,(s.empty()? (currHeight*i) : (currHeight*(i-s.top()-1))));
               }
                s.push(i);
            }
        }
        while(!s.empty()){
            int currHeight=heights[s.top()];
            s.pop();
            max_area=max(max_area,(s.empty()? (currHeight*cols): (currHeight*(cols-s.top()-1))));
        }
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        if(rows==0)
            return 0;
        int cols=matrix[0].size();
        int heights[cols];
        for(int i=0;i<cols;i++) heights[i]=0;
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            ans=max(ans,maximumHistogramArea(heights,cols));
        }
        return ans;
    }
};

