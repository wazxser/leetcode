#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
using namespace std;
#define INF 99999

//dijks，单源最短路径，复杂度O(n2)，权值必须为正，邻接矩阵存储图，visit数组记录已访问过的点
//dis数组记录从源点到各点的最短距离
//每次寻找
//用memset初始化二维数组时，会Runtime error

int m[110][110];
int visit[110];
int dis[110];

void dijks(int n, int s){
    int minn, temp;
    visit[s] = 1;
    for(int i = 1; i <= n; i++){
        dis[i] = m[s][i];
    }

    for(int i = 0; i < n; i++){
        minn = INF;
        for(int j = 1; j <= n; j++){
            if(!visit[j] && dis[j] < minn){
                temp = j;
                minn = dis[j];
            }
        }

        visit[temp] = 1;
        for(int j = 1; j <= n; j++){
            if(!visit[j] && dis[temp] + m[temp][j] < dis[j])
                dis[j] = dis[temp] + m[temp][j];
        }
    }
}

int main(){
    int n, mm, a, b, w;
    while(~scanf("%d %d", &n, &mm) && n+mm){
//        memset(m, INF, sizeof(m));
        memset(visit, 0, sizeof(visit));
        memset(dis, 0, sizeof(dis));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                m[i][j] = INF;
            }
        }

        for(int i = 1; i <= mm; i++){
            scanf("%d %d %d", &a, &b, &w);
            m[a][b] = w;
            m[b][a] = w;
        }

        dijks(n, 1);
        printf("%d\n", dis[n]);
    }

    return 0;
}
