#include <string>
#include <vector>

#include <algorithm>    // sort 함수 사용하기 위함

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    sort(array.begin(), array.end());
    int num = (array.size() + 1) /2 - 1;
    
    answer = array[num];
    return answer;
}