class Solution {
public:
    map<string, int> mappa = {
        {"electronics", 1},
        {"grocery", 2},
        {"pharmacy", 3},
        {"restaurant", 4}
    };
    bool isAlnum(string s){
        for(char c: s)
            if(!isalnum(c) and c != '_')
                return false;
        return true;
    }
    typedef pair<int, string> pis;
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        priority_queue<pis, vector<pis>, greater<>> pq;
        int n = businessLine.size();
        for(int i = 0;i<n;i++){
            if(isActive[i] and !code[i].empty() and isAlnum(code[i]) and mappa.count(businessLine[i]))
                pq.push({mappa[businessLine[i]], code[i]});
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};