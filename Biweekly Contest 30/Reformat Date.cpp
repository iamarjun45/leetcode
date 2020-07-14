class Solution {
public:
    string reformatDate(string date) {
        int n=date.size();
        vector<string> months({"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"});
        // Year is always the last four letters
        string year=date.substr(n-4);
        // Month is of 3 letters and start from (n-8)
        string mon=date.substr(n-8,3);
        // Search for the month number
        string month;
        for(int i=0;i<months.size();i++){
            if(months[i]==mon){
                month=to_string(i+1);
            }
        }
        // Day always start from 0th index, can be of length 1 or 2
        string day;
        int i=0;
        while(date[i]>='0' && date[i]<='9'){
            day=day+date[i];
            i++;
        }
        if(month.size()==1)
            month='0'+month;
        if(day.size()==1)
            day='0'+day;
        // Printing format
        return year+"-"+month+"-"+day;
    }
};
