struct node{
    int u,v,w;
    node(int u1,int v1,int w1){
        u = u1;
        v = v1;
        w = w1;
    }
};

int findpar(int a, vector<int>&p){
    if(p[a] == a){
        return a;
    }
    return p[a] = findpar(p[a] , p);
}
void uni(int a,int b,vector<int>&p,vector<int>&r){
    a = findpar(a,p);
    b = findpar(b,p);
    if(r[a] > r[b]){
        p[b] = a;
    }
    else if(r[b] > r[a]){
        p[a] = b;
    }
    else{
        p[a] = b;
        r[b]++;
    }
}
bool comp(node a,node b){
    return a.w < b.w;
}
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<node>v;
    int n = g_to.size();
    for(int i=0;i<n;i++){
        v.push_back(node(g_from[i],g_to[i],g_weight[i]));
    }
    sort(v.begin(),v.end(),comp);
    vector<int>p(n+1),r(n+1,0);
    for(int i=1;i<=n;i++){
        p[i] = i;
    }
    int c = 0;
    vector<pair<int,int>>mst;
    for(auto x: v){
        if(findpar(x.u , p) != findpar(x.v , p)){
            c += x.w;
            mst.push_back({x.u,x.v});
            uni(x.u , x.v , p ,r);
        }
    }
    return c;
}
