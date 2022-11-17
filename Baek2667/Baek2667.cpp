#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N; //첫 줄에서 받는 지도의 크기
int aptMap[25][25]; //N의 최대 크기가 25기에 25x25 배열을 선언
bool visited[25][25]; //방문 여부

int blockCnt = 0; //단지 수
pair<int, int> p;
queue<pair<int, int> > q; //아파트의 위치를 좌표형태로 저장
vector<int> aptCnt; //각 단지마다 개수 저장

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; //상하좌우를 탐색하기 위한 x, y 값

void bfs(){
	while(!q.empty()){ //모든 아파트에 방문할동안 반복
		int x = q.front().first; 
		int y = q.front().second; //q는 x.y값을 저장한 큐이므로 first값은 x, second는 y
		blockCnt++; 
		q.pop(); //추가 연산 진행 후 해당 x,y값은 pop

		for(int i = 0; i < 4; i++){ //상하좌우를 탐색해야하므로 반복 4번
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(aptMap[nx][ny] == 1){ //해당 위치에 아파트가 있다면
				p = make_pair(nx, ny);
                q.push(p);  //q에 해당 좌표값을 넣고
				visited[nx][ny] = true; //방문을 true로 만들기
			}
		}
	}
	aptCnt.push_back(blockCnt);
}

void solve(){
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(aptMap[i][j] ==1 && visited[i][j] == false){
                blockCnt++; //아파트가 있고, 방문하지 않았다면 카운트 올리기
                p = make_pair(i, j);
                q.push(p);
                visited[i][j]=true;
                bfs();
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        string tmp;
        cin >> tmp; //tmp값으로 지도 정보를 받아
        for(int j = 0 ; j< N; j++){
            aptMap[i][j] = tmp[j]-'0'; //지도를 2차원 배열 형태로 나타냄
        }
    }
    solve();
    sort(aptCnt.begin(), aptCnt.end()); // 문제 조건 오름차순 출력
    cout << blockCnt << '\n';
    for(int i =0 ; i< aptCnt.size(); i++)
    {
        cout << aptCnt[i] << '\n';
    }
}
