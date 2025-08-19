#include <iostream>
#include <vector>

using namespace std;
int main()
{
  ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> x(M);
    for (int i = 0; i < M; ++i) cin >> x[i];

    int ans = 0;
    // 왼쪽 끝
    ans = max(ans, x[0]);
    // 사이 간격
    for (int i = 1; i < M; ++i) {
        int gap = x[i] - x[i-1];
        ans = max(ans, (gap + 1) / 2); // ceil(gap/2)
    }
    // 오른쪽 끝
    ans = max(ans, N - x.back());

    cout << ans << '\n';
    return 0;

}