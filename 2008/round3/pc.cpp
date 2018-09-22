#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define MAX_V 20005
//flow template with dinic弧優化
using namespace std;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
bool used[MAX_V];
void add_edge(int from,int to,int cap){
        G[from].push_back((edge){to,cap,G[to].size()});
        G[to].push_back((edge){from,0,G[from].size()-1});
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++){
			edge&e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
        if(v==t)return f;
        used[v]=true;
        for(int &i=iter[v];i<G[v].size();i++){
                edge &e=G[v][i];
                if(e.cap>0&&level[v]<level[e.to]){
                        int d=dfs(e.to,t,min(f,e.cap));
                        if(d>0){
                                e.cap-=d;
                                G[e.to][e.rev].cap+=d;
                                return d;
                        }
                }
        }
        return 0;
}
int max_flow(int s,int t){
        int flow=0;
        while(true){
		bfs(s);
		if(level[t]<0)return flow;
                memset(iter,0,sizeof(iter));
                int f;
		while((f=dfs(s,t,2147483647))>0){flow+=f;}
        }
}
int n,m;
char table[85][85];
void solve(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin >> table[i][j];
	}
	int num=0;
	int s=m*n,t=s+1;
	int dx[4]={-1,-1,1,1};
	int dy[4]={0,-1,0,-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(table[i][j]=='.'){
				num++;
				if(j%2==0){
					add_edge(s,m*i+j,1);
					//cout << s << " " << m*i+j << endl;
				}else{
					add_edge(m*i+j,t,1);
					//cout << m*i+j << " " << t << endl;
				}
				for(int k=0;k<4;k++){
					if(j+dx[k]<m&&j+dx[k]>=0&&i+dy[k]<n&&i+dy[k]>=0&&table[i+dy[k]][j+dx[k]]=='.'){
						if(j%2==0){
							add_edge(m*i+j,m*(i+dy[k])+(j+dx[k]),1);
							//cout << m*i+j << " " << m*(i+dy[k])+(j+dx[k]) << endl;
						}else{
							add_edge(m*(i+dy[k])+(j+dx[k]),m*i+j,1);
							//cout << m*(i+dy[k])+(j+dx[k]) << " " << m*i+j << endl;
						}
					}
				}
			}
		}
	}
	printf("%d\n",num-max_flow(s,t));
	memset(level,0,sizeof(level));
        memset(iter,0,sizeof(iter));
        memset(used,0,sizeof(used));
        for(int i=0;i<MAX_V;i++)G[i].clear();
}
int main(){
        int T;
        scanf("%d",&T);
        for(int iii=1;iii<=T;iii++){
                printf("Case #%d: ",iii);
                solve();
        }
        return 0;
}

