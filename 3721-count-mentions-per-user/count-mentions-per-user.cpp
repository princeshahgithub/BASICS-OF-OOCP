class Solution {
private:
    vector<string> splitString(string str){
        stringstream ss(str);
        string s;
        vector<string> v;
        while(getline(ss, s, ' ')){
            v.push_back(s);
        }
        return v;
    }    

public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size();
        vector<int> mentions(numberOfUsers, 0), status(numberOfUsers, 1);
        sort(events.begin(), events.end(), [&](vector<string>& s1, vector<string>& s2){
            int ts1 = stoi(s1[1]), ts2 = stoi(s2[1]);
            if(ts1 == ts2) return s1[0] > s2[0];
            return ts1 < ts2;
        });
        set<pair<int, int>> st; //{online time, user id}
        for(auto x : events){
            if(x[0] == "MESSAGE"){
                while(!st.empty()){
                    auto [t, id] = *st.begin();
                    if(t > stoi(x[1])) break;
                    status[id] = 1;
                    st.erase(st.begin());
                }
                if(x[2] == "ALL"){
                    for(int i = 0; i < numberOfUsers; i++){
                        mentions[i]++;
                    }
                }
                else if(x[2] == "HERE"){
                    for(int i = 0; i < numberOfUsers; i++){
                        if(status[i] == 1) mentions[i]++;
                    }
                }
                else{
                    vector<string> mentionIds = splitString(x[2]);
                    for(auto id : mentionIds){
                        mentions[stoi(id.substr(2))]++;
                    }
                }
            }
            else{
                int id = stoi(x[2]), ts = stoi(x[1]);
                status[id] = 0;
                for(auto [t, Id] : st){
                    if(Id == id) st.erase({t, Id});
                }
                st.insert({ts + 60, id});
            }
        }
        return mentions;
    }
};