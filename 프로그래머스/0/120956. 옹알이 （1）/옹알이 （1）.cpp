#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector <string> words = { "aya", "ye", "woo", "ma" };

    int ele;
    bool same = true;
    for (int i = 0; i < babbling.size(); i++)
    {
        //cout << i << "번째 babbling 검사 \n";

        ele = 0;
        while (true)
        {
            for (int j = 0; j < words.size(); j++)
            {
                //cout << j << "번째 단어인 " << words[j] << "와 비교 \n";

                same = true;
                for (int k = 0; k < words[j].length(); k++)
                {
                    if (babbling[i].length() <= k + ele)
                    {
                        same = false;
                        break;
                    }

                    if (babbling[i][k + ele] != words[j][k])   // babbling의 i번째 단어와 words의 j번째 단어가 동일하지 않다면, same = false; (반면, 모든 알파벳이 동일하다면 same = true로 남음)
                    {
                        same = false;
                    } 
                }

                if (same == true)
                {
                    ele += words[j].length();
                    break;  // for문 하나 벗어나기
                }

            }

            if (same == false)   // 끝까지 맞는 단어가 하나도 없었다면 애초에 발음할 수 없는 단어임
            {
                //cout << i << "번째 babbling은 발음 불가능 XXXXX \n";
                break;
            }
            else if (ele == babbling[i].length()) // 모든 단어를 발음하는 데 성공했다면
            {
                answer += 1;
                //cout << i << "번째 babbling은 발음 가능 ***** \n";
                break;
            }
        }
    }
    return answer;
}
