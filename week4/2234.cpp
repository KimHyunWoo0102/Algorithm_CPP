#include<bits/stdc++.h>

using namespace std;

int arr[54][54], visited[54][54], room_id[54][54];
// 서(1), 북(2), 동(4), 남(8)
int direction[] = { 1, 2, 4, 8 }; 
int dy[] = { 0, -1, 0, 1 }, dx[] = { -1, 0, 1, 0 };

int r, c;

int cnt = 0;
int max_room = 0;
int tmp = 0;
vector<int> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	room_id[y][x] = cnt;
	tmp++;

	for (int i = 0; i < 4; i++) {
		if ((arr[y][x] & direction[i])) continue;

		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx]) continue;

		dfs(ny, nx);
	}
}

int main() {
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> c >> r;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	// 1. 각 방의 ID를 부여하고 크기를 계산
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == 0) {
				tmp = 0;
				dfs(i, j);
				v.push_back(tmp);
				cnt++; // dfs 호출 후 cnt를 증가시켜 다음 방의 ID로 사용
			}
		}
	}
    
    // 이 부분이 수정된 핵심 로직입니다.
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			for (int k = 0; k < 4; k++) {
				// 현재 칸(y,x)에 k 방향으로 벽이 있다면
				if ((arr[y][x] & direction[k])) {
					int ny = y + dy[k];
					int nx = x + dx[k];

					// 맵 범위를 벗어나는지 확인
					if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

					// 벽 너머가 다른 방일 경우에만 합친다
					if (room_id[y][x] != room_id[ny][nx]) {
						int combined_size = v[room_id[y][x]] + v[room_id[ny][nx]];
						max_room = max(max_room, combined_size);
					}
				}
			}
		}
	}

	sort(v.begin(), v.end());
	cout << cnt << '\n';
	cout << v.back() << '\n';
	cout << max_room << '\n';
	
	return 0;
}