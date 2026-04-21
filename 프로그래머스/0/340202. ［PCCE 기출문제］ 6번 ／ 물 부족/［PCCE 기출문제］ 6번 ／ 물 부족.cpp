#include <string>
#include <vector>

using namespace std;

int solution(int storage, int usage, vector<int> change) {
    int total_usage = 0;
    for(int i=0; i<change.size(); i++){
        usage = usage * (100 + change[i]) / 100;  // 이번달 사용한 양을 새로 계산하는 것 같음
        total_usage += usage;
        if(total_usage > storage){
            return i;
        }
    }
    return -1;
}