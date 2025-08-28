#include <iostream>
#include <cstdio>

using namespace std;

// 시간을 분으로 바꾸는 함수
int toMinutes(int h, int m) {
    return h * 60 + m;
}

int main() {
    int n;
    scanf("%d", &n);

    int s1 = 0, s2 = 0; // 현재 점수
    int ret1 = 0, ret2 = 0; // 각 팀이 이긴 총 시간 (분)
    int prev_time = 0; // 직전 골이 터진 시간 (00:00에서 시작)

    for (int i = 0; i < n; i++) {
        int t, h, m;
        scanf("%d %d:%d", &t, &h, &m);

        int current_time = toMinutes(h, m);

        // 이전 이벤트부터 현재 이벤트까지의 시간 동안, 누가 이기고 있었는지 확인하고 시간 추가
        if (s1 > s2) {
            ret1 += (current_time - prev_time);
        } else if (s2 > s1) {
            ret2 += (current_time - prev_time);
        }

        // 현재 점수 업데이트
        if (t == 1) s1++;
        else s2++;
        
        // 다음 계산을 위해 현재 시간을 '이전 시간'으로 저장
        prev_time = current_time;
    }

    // 마지막 골 이후 ~ 경기 끝(48:00)까지의 시간 계산
    int end_time = toMinutes(48, 0);
    if (s1 > s2) {
        ret1 += (end_time - prev_time);
    } else if (s2 > s1) {
        ret2 += (end_time - prev_time);
    }

    // 최종 누적된 '분'을 HH:MM 형식으로 출력
    printf("%02d:%02d\n", ret1 / 60, ret1 % 60);
    printf("%02d:%02d\n", ret2 / 60, ret2 % 60);

    return 0;
}