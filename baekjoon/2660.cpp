#include <iostream>
#include <vector>

using namespace std;

int n; // n : 회원의 수
int score[51];
vector <int> V[51];

int dist[51][51]; //dist[x][y] : x에서 y까지 가는 최소 간선 수

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> n;

	for (int i = 1; i <= n; i++)//init
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)continue;
			else dist[i][j] = 1000000000;
		}	
	}

	int x, y;
	while (true)
	{
		cin >> x >> y;

		if (x == y)break;

		dist[x][y] = 1;
		dist[y][x] = 1;//간선의 가중치는 1
	}

	for (int t = 1; t <= n ;t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][t] + dist[t][j]) {
					// i-j 직접가는 것보다 i-k, k-i 거쳐서 가는 것이 더 이득일때 최소비용을 갱신
					dist[i][j] = dist[i][t] + dist[t][j];
				}
			}
		}
	}//만약 dist[i][j] 값에 1000000000값이 남아있다면 j점은 아무 점과도 연결되지 않은 것

	int score[51];
	int member = -1;
	for (int i = 1; i <= n; i++)
	{
		int m = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] > m) m = dist[i][j];
		}
		score[i] = m;
		if (member > m || member == -1) member = m;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == member) cnt++;
	}

	cout << member << " " << cnt << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == member) cout << i << " ";
	}

	return 0;
}
