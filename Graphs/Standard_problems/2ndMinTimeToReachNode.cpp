int secondMinimum(int V, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> adj(V + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
        vector<int> dist(V+1, 0), freq(V+1, 0);

        pq.push(make_pair(0, 1));
        freq[1]++;

        while (!pq.empty())
        {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();

            int val = d/change;

            if(val % 2 != 0) d += ((val + 1)*change) - d;
            
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i);
                if(dist[v] != d + time and freq[v] < 2) {
                    dist[v] = d + time;
                    freq[v]++;
                    pq.push({d+time, v});
                }
            }
        }


        return dist[V];
    }
