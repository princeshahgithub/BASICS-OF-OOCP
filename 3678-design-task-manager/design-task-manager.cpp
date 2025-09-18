class TaskManager {
public:

    priority_queue<pair<int,int>> pq;
    map<int,pair<int,int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it: tasks)
        {
            int userid = it[0]; int taskid = it[1]; int priority = it[2];
            pq.push({priority,taskid});
            mp[taskid]={userid,priority};
        }

        cout << pq.top().first << " " << pq.top().second;
    }
    
    void add(int userId, int taskId, int priority) {

        pq.push({priority,taskId});
        mp[taskId] = {userId,priority};
    }
    
    void edit(int taskId, int newPriority) {

        mp[taskId].second=newPriority;
        pq.push({newPriority,taskId});
        
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
        
    }
    
    int execTop() {
        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            int priority = it.first; int taskid = it.second;
            
            if(mp.find(taskid)!=mp.end() && mp[taskid].second==priority) //not a stale entry
            {
                int userid = mp[taskid].first;
                mp.erase(taskid);
                return userid;
            }
            
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */