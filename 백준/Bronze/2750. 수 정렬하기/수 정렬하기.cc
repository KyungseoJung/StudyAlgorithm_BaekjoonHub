#include <iostream>

int main()
{
    int input[1000];
    int output[1000];

    int num;    // 입력할 숫자 개수
    std::cin >> num;

    for (int i = 0; i < num; i++)
    {
        std::cin >> input[i];
    }

    int ele = 0;
    int min;
    int checkMin = -99999;   // 이미 체크한 element
    while (ele <= (num - 1))
    {
        min = 99999;
        for (int j = 0; j < num; j++)
        {
            //std::cout << "input[" << j << "]: " << input[j] << "| min: " << min << "| checkMin: " << checkMin << "\n";
            if ((input[j] < min) && (input[j] > checkMin))
            {
                min = input[j];
            }
        }

        output[ele] = min;
        checkMin = min;
        ele++;
    }

    for (int i = 0; i < num; i++)
    {
        std::cout << output[i] << "\n";
    }
    return 0;
}