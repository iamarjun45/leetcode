class Solution {
    double DistanceFromAllPoints(vector<vector<int>>& positions,vector<double>& mean){
        double sum=0;
        for(auto x:positions){
            // Euclidean Distance = [(x)^2 + (y)^2]^(1/2)
            sum=sum+sqrt(pow(x[0]-mean[0],2)+pow(x[1]-mean[1],2));
        }
        return sum;
    }
    double DistanceFromAllPoints(vector<vector<int>>& positions,vector<int>& mean){
        double sum=0;
        for(auto x:positions){
            // Euclidean Distance = [(x)^2 + (y)^2]^(1/2)
            sum=sum+sqrt(pow(x[0]-mean[0],2)+pow(x[1]-mean[1],2));
        }
        return sum;
    }
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        // Base Case
        if(positions.size()<=1)
            return 0;
        double ans=DBL_MAX;
        int n=positions.size();
        // 1. Let us assume that centeriod is the geometric median
        vector<double> centeroid(2,0);
        for(auto x:positions){
            centeroid[0]+=x[0];
            centeroid[1]+=x[1];
        }
        centeroid[0]=centeroid[0]/n;
        centeroid[1]=centeroid[1]/n;
        ans=min(ans,DistanceFromAllPoints(positions,centeroid));
        // 2. Suppose if any point is the geometric median
        for(auto x:positions){
            double check=DistanceFromAllPoints(positions,x);
            if(check<ans){
                ans=check;
                centeroid[0]=x[0];
                centeroid[1]=x[1];
            }
        }
        // 3. There is no standard method to calculate median.
        // We need to search our point through approximation.
        // Less the lower_limit, better the approximation is.
        // Approximation given in question is 10^(-5)
        double lower_limit=1e-5;
        // Start searching the point 100 units, away from the current point in all directions
        double test_distance=100;
        // Search in all directions
        double x[4]={1.0, 0.0, -1.0, 0.0}; // Right, Down, Left, Up 
        double y[4]={0.0, -1.0, 0.0, 1.0};
        while(test_distance>lower_limit){
            bool found=false;
            for(int i=0;i<4;i++){
                vector<double> checkPoint(2,0);
                checkPoint[0]=centeroid[0]+test_distance*x[i];
                checkPoint[1]=centeroid[1]+test_distance*y[i];
                double check=DistanceFromAllPoints(positions,checkPoint);
                if(check<ans){
                    ans=check;
                    centeroid[0]=checkPoint[0];
                    centeroid[1]=checkPoint[1];
                    found=true;
                    break;
                }
            }
            // No point in all direction is better
            // Let check a more closer point
            if(!found){
                test_distance/=2;
            }
        }
        return ans;
    }
};
