#include <iostream>

int main()
{
	int num=0;
	std::cin >> num;

	int member, findMember;	//각 숫자 각각들, 찾으려는 숫자
	int arr[100];

	for (int i = 0; i < num; i++)
	{
		std::cin >> member;
		arr[i] = member;
	}

	std::cin >> findMember;	// 찾으려는 숫자 입력 받음
	int count=0;	// 찾으려는 숫자의 개수 카운팅
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == findMember)
			count += 1;
	}

	std::cout << count;
    
    return 0;
}