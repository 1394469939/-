#include<stdio.h>
#include<stdlib.h>
int main()
{
	int e[101][101], dis[101], visited[101];
	int i, j, n, m, t1, t2, t3, u, v, min;
	int inf = 0x3f3f3f3f;
	//while (1)//这边考虑的是多组输入问题
	//{
		scanf("%d %d", &n, &m);//n表示路口个数，m表示路的条数 
		//if (n == 0 && m == 0)break;//如果是0 0就直接退出，这道题可以不考虑
		for (i = 1; i <= n; i++)//初始化 
		{
			for (j = 1; j <= n; j++)
			{
				if (i == j) e[i][j] = 0;
				else  e[i][j] = inf;
			}
		}
		for (i = 1; i <= m; i++)//输入边 
		{
			scanf("%d %d %d", &t1, &t2, &t3);
			e[t1][t2] = t3;//路口t1 到路口 t2 的路程 
		}
		for (i = 1; i <= n; i++)//源点到各个顶点的初始路程 
			dis[i] = e[1][i];//这边定义为根据题意第一个点，可自由定义
		for (i = 1; i <= n; i++)//book数组初始化 
			visited[i] = 0;
		visited[1] = 1;//这边源点定义为1，也可以自由定义
		for (i = 1; i <= n - 1; i++)
		{
			min = inf;
			for (j = 1; j <= n; j++)//找离源点（即点1）最近的点 
			{
				if (visited[j] == 0 && dis[j] < min)
				{
					min = dis[j];
					u = j;
				}
			}
			visited[u] = 1;//标记已经确定过 ,就放入visited数组
			for (v = 1; v <= n; v++)
			{
				if (e[u][v] < inf)//对所有以点v 为起点的边进行松弛 
				{
					if (dis[v] > dis[u] + e[u][v])
						dis[v] = dis[u] + e[u][v];
				}
			}
		}
		printf("%d\n", dis[n]);//这边n便是最后一个点，也可以任意输出数组中的值即为到这个点的最短距离
	//}
	return 0;
}