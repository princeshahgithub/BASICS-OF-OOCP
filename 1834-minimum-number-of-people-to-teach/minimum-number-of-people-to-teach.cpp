class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> userLanguages(m + 1);
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                userLanguages[i + 1].insert(lang);
            }
        }
        
        unordered_set<int> problematicUsers;
        vector<pair<int, int>> problematicPairs;
        for (auto& f : friendships) {
            int u = f[0];
            int v = f[1];
            
            bool canCommunicate = false;
            for (int lang : userLanguages[u]) {
                if (userLanguages[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            if (!canCommunicate) {
                problematicUsers.insert(u);
                problematicUsers.insert(v);
                problematicPairs.emplace_back(u, v);
            }
        }
        
        unordered_map<int, int> langCount;
        for (int user : problematicUsers) {
            for (int lang : userLanguages[user]) {
                langCount[lang]++;
            }
        }
        
        int maxKnown = 0;
        for (auto& [lang, count] : langCount) {
            maxKnown = max(maxKnown, count);
        }
        
        return problematicUsers.size() - maxKnown;
    }
};