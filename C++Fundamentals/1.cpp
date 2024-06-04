# include<cstdio>
# include<cstdlib>
int nodes[150];
int main(){
    int n,m;
    scanf(" %d%d", &n, &m);
    for(int i=1; i <= n -1; i++) nodes[i]=i + 1;
    nodes[n] = 1;
    int now = 1, prev = 1;
    while((n--) > 1){
        for(int i = 1; i < m; i++){
        prev = now; now = nodes[now];
        }
        printf("%d ", now);
        nodes[prev] = nodes[now];
        now = nodes[prev];
    }
    printf("%d", now);
    return 0;
}