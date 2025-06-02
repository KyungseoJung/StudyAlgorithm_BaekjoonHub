#include <iostream>

int main()
{
	//int numTime[8];	// 각 숫자 버튼을 눌렀을 때 소요되는 시간 저장
	//// 1을 걸려면 총 2초 필요. 그 이후부터는 2 + (n-1)*1 초 필요함.

	//// numTime[0] <=> n=2임을 의미함.

	//for (int i = 0; i < 8; i++)
	//{
	//	numTime[i] = 2 + (i + 2 - 1);
	//}


	// 각 알파벳 문자를 숫자그룹으로 만들어주기
	std::string callNum[10];
	callNum[2] = "ABC";
	callNum[3] = "DEF";
	callNum[4] = "GHI";
	callNum[5] = "JKL";
	callNum[6] = "MNO";
	callNum[7] = "PQRS";
	callNum[8] = "TUV";
	callNum[9] = "WXYZ";
	//callNum[10] 

	
	// 테스트 예제 입력
	std::string word;
	std::cin >> word;

	int time = 0;

	for (int i=0; i < word.length(); i++)
	{
		// 입력한 단어 중 i번째 문자에 대해서 검사
		for (int j = 2; j < 10; j++)
		{
			//std::cout << "callNum[" << j << "] 의 데이터는 총 " << callNum[j].length() << " 개" << "\n";

			for (int k = 0; k < callNum[j].length(); k++)
			{

				//std::cout << "그 안의 데이터는 " << k << "개~" << "\n";
				if (word[i] == callNum[j][k])
				{

					time += 2 + (j - 1);
					//break;
				}
			}
		}
	}

	std::cout << time;

}


	//std::cout << S[num - 1];
	//std::cout << S.at(num-1);
	//https://m.blog.naver.com/dorergiverny/223046924132
