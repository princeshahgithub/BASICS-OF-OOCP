#define ll long long
class Solution {
public:
    string rotate(string& s, ll b) {
        return s.substr(s.size() - b) + s.substr(0, s.size() - b);
    }
    
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        string ans = s;
        while (!q.empty()) {
            string temp = q.front();
            q.pop();
            if (vis.count(temp)) continue;
            vis.insert(temp);
            ans = min(ans, temp);
            //  Try rotate
            q.push(rotate(temp, b));
            //  Try add
            for (ll i = 1; i < temp.length(); i += 2) {
                temp[i] = ((temp[i] - '0') + a) % 10 + '0'; //  Mod 10 to cycle back
            }
            q.push(temp);
        }
        return ans;
    }
};