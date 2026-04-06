#include <iostream>
#include <string>

using namespace std;
int main()
{
	string N;
	cin >> N;

	int intN;
	intN = stoi(N);

	string sentence = "1";
	// 일단 1부터 N까지의 숫자를 나열한 문장을 만들기
	for (int i = 2; i <= intN; i++)
	{
		sentence += to_string(i);
	}

	// 그 문장을 검사하기
	bool find = false;
	//cout << "길이: " << sentence.length() << "\n";
	for (int i = 0; i < sentence.length(); i++)
	{
		//cout << "for문\n";
		if (sentence[i] == N[0])
		{
			find = true;
			//cout << "체크1\n";
			for (int j = 1; j < N.length(); j++)
			{
				//cout << "체크2\n";
				if ( (i+j < sentence.length()) && (sentence[i + j] != N[j]))
				{
					find = false;
				}
			}

			if (find == true)
			{
				//cout << "찾았다! : " << i + 1;
				cout << i + 1;
				break;	// for문 통과
			}

		}
	}

	//cout << sentence;
}