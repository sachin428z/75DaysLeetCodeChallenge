class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& time:times) {
            int u=time[0],v=time[1],w=time[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        while(!pq.empty()) {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();


            for(auto& [nbr,wt]: adj[node]) {
                if(dist[nbr]>time+wt) {
                    dist[nbr]=time+wt;
                    pq.push({dist[nbr],nbr});

                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX?-1:ans;
    }
};