class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> bigRec = rectangles[0];
        int area = 0;
        unordered_set<string> corners; 
        pair<unordered_set<string>::iterator, bool> r;
        for(vector<int> rec: rectangles)
        {
            if(bigRec[0] + bigRec[1] > rec[0] + rec[1])
                bigRec[0] =rec[0]; bigRec[1] = rec[1];
            
            if(bigRec[2] + bigRec[3] < rec[2] + rec[3])
                bigRec[2] = rec[2]; bigRec[3] = rec[3];
            
            for(int i = 0; i < 4; i++)
            {
                r = corners.insert(to_string(rec[(i>>1) * 2]) + "," + to_string(rec[(i & 1) * 2 + 1]));
                if(!r.second) corners.erase(r.first);
            }

            area +=  (rec[2] -  rec[0]) *  (rec[3] -  rec[1]);
        }
        
        if(corners.size() != 4) 
            return false;

        for(int i = 0; i < 4; i++)
            if(corners.find(to_string(bigRec[(i>>1) * 2]) + "," + to_string(bigRec[(i & 1) * 2 + 1])) == corners.end())
               return false;
        
        return (area == (bigRec[2] - bigRec[0]) *  (bigRec[3] - bigRec[1]));
    }
};
