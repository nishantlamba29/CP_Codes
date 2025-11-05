#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int n;
vector<vector<int>> adj;
vector<int> A, sub, used;
ll answer = 0;

// Fenwick (BIT) that maintains both a count and the sum of “g‑values”
struct Fenwick {
    int N;
    vector<ll> cnt, sum;
    Fenwick() : N(0) {}
    Fenwick(int n): N(n), cnt(n+1,0), sum(n+1,0) {}
    void init(int n){
        N = n;
        cnt.assign(n+1,0);
        sum.assign(n+1,0);
    }
    // add count += c and sum += s at index i
    void update(int i, ll c, ll s){
        for(; i<=N; i+=i&-i){
            cnt[i] = (cnt[i] + c) % MOD;
            sum[i] = (sum[i] + s) % MOD;
        }
    }
    // prefix [1..i]
    pair<ll,ll> query(int i){
        ll c=0, s=0;
        for(; i>0; i-=i&-i){
            c = (c + cnt[i]) % MOD;
            s = (s + sum[i]) % MOD;
        }
        return {c, s};
    }
};

// 1) compute subtree sizes
int dfs_size(int u, int p){
    sub[u] = 1;
    for(int v: adj[u]) if(v!=p && !used[v]){
        sub[u] += dfs_size(v,u);
    }
    return sub[u];
}

// 2) find centroid of the current component
int find_centroid(int u, int p, int sz){
    for(int v: adj[u]) if(v!=p && !used[v]){
        if(sub[v]*2 > sz)
            return find_centroid(v, u, sz);
    }
    return u;
}

// gather (max_on_path, min_on_path) from centroid→u
void collect(int u, int p, int curMax, int curMin, vector<pair<int,int>> &vec){
    curMax = max(curMax, A[u]);
    curMin = min(curMin, A[u]);
    vec.emplace_back(curMax, curMin);
    for(int v: adj[u]) if(v!=p && !used[v]){
        collect(v, u, curMax, curMin, vec);
    }
}

void process_centroid(int c){
    used[c] = 1;

    // 1. For each neighbor-subtree, collect its (max,min)-pairs
    vector<vector<pair<int,int>>> allVecs;
    vector<int> allMins;
    allMins.push_back(A[c]);               // include the centroid itself

    for(int v: adj[c]) if(!used[v]){
        vector<pair<int,int>> vec;
        collect(v, c, A[c], A[c], vec);
        allVecs.push_back(move(vec));
        for(auto &pr: allVecs.back())
            allMins.push_back(pr.second);
    }

    // 2. Coordinate-compress the “min” values
    sort(allMins.begin(), allMins.end());
    allMins.erase(unique(allMins.begin(), allMins.end()), allMins.end());
    auto idxOf = [&](int x){
        return int(lower_bound(allMins.begin(), allMins.end(), x)
                          - allMins.begin()) + 1;
    };
    int M = allMins.size();

    // 3. Build a single list of “events” = (max, min, subtree_id)
    //    subtree_id = -1 for the centroid itself; 0..k-1 for each neighbor
    struct E { int mx, mn, sid; };
    vector<E> events;
    events.push_back({ A[c], A[c], -1 });
    for(int i=0; i<(int)allVecs.size(); i++){
        for(auto &pr: allVecs[i]){
            events.push_back({ pr.first, pr.second, i });
        }
    }
    sort(events.begin(), events.end(),
         [](auto &a, auto &b){ return a.mx < b.mx; });

    // 4. One global Fenwick for “everything so far”
    Fenwick fenwAll;  fenwAll.init(M);
    ll totalCount = 0;

    // 5. One Fenwick _per subtree_ to subtract “intra‑subtree” pairs
    vector<Fenwick> fenwSub(allVecs.size());
    for(auto &f: fenwSub) f.init(M);
    vector<ll> subCount(allVecs.size(), 0);

    // 6. Sweep through events in ascending order of mx
    for(auto &e: events){
        ll Mcur = e.mx;
        ll mcur = e.mn;
        int sid  = e.sid;
        int idx  = idxOf(mcur);

        if(totalCount > 0){
            // query against all “previous” items
            auto [cnt_le, sum_le] = fenwAll.query(idx);
            ll cnt_gt = (totalCount - cnt_le + MOD) % MOD;

            // case1: those with prev_min <= mcur
            //    f = Mcur, g = prev_min, so → Mcur * sum_le
            ll addAll = (Mcur % MOD) * (sum_le % MOD) % MOD;

            // case2: those with prev_min > mcur
            //    f = Mcur, g = mcur, so → Mcur * mcur * cnt_gt
            addAll = (addAll
                      + (Mcur % MOD) * (mcur % MOD) % MOD * cnt_gt % MOD)
                     % MOD;

            // subtract the same contribution from within the same subtree
            ll addSub = 0;
            if(sid >= 0){
                auto [cs_le, ss_le] = fenwSub[sid].query(idx);
                ll cs_gt = (subCount[sid] - cs_le + MOD) % MOD;
                addSub = ( (Mcur%MOD)*(ss_le%MOD) %MOD
                           + (Mcur%MOD)*(mcur%MOD)%MOD * cs_gt %MOD )
                         % MOD;
            }

            answer = (answer + addAll - addSub + MOD) % MOD;
        }

        // now add this event into our Fenwicks
        fenwAll.update(idx, 1, mcur);
        totalCount++;
        if(sid >= 0){
            fenwSub[sid].update(idx, 1, mcur);
            subCount[sid]++;
        }
    }

    // 7. Recurse on each disconnected piece
    for(int v: adj[c]) if(!used[v]){
        int sz = dfs_size(v, c);
        int cent = find_centroid(v, c, sz);
        process_centroid(cent);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n, {});
    A.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0, u, v; i < n-1; i++){
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sub .assign(n, 0);
    used.assign(n, 0);

    int sz   = dfs_size(0, -1);
    int root = find_centroid(0, -1, sz);
    process_centroid(root);

    cout << answer % MOD << "\n";
    return 0;
}
