class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto sort_second_value = [](const vector<int> a, const vector<int> b){
            return a[1] < b[1];
        };
        auto print = [](const vector<int> a) {printf("[%d,%d]\n",a[0],a[1]);};

        sort(intervals.begin(), intervals.end(),sort_second_value);

        int size = intervals.size(),count = 0;

        array<int,2> a,b;
        a[0] = intervals[0][0];
        a[1] = intervals[0][1];
        

        for(int i = 1; i < size; i++){
            b[0] = intervals[i][0];
            b[1] = intervals[i][1];
            if(b[1] > a[1] && b[0] >= a[1]){
                count++;
                a[0] = b[0];
                a[1] = b[1];
                continue;
            }

        }
        
        

        for_each(intervals.begin(), intervals.end(), print);
        return size - count - 1;
    }
};


        