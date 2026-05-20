#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    vector <vector <int>> arr1(N, vector <int> (M));
    vector <vector <int>> arr2(N, vector <int> (M));
    vector <vector <int>> arr3(N, vector <int> (M));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> arr2[i][j];
        }
    }

    // arr3 얻기 ------------
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr1[i][j] == arr2[i][j])
            {
                arr3[i][j] = 0;
            }
            else
            {
                arr3[i][j] = 1;
            }
        }
    }
    // 출력 ------------
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout << arr3[i][j] << " " ;
        }
        cout << "\n";
    }
    return 0;
}