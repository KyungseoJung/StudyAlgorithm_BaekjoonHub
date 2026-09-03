using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long needPrice = 0;
    for(int i=1; i <= count; i++)
    {
        needPrice += price * i;
    }
    
    if(money >= needPrice)
    {
        answer = 0;
    }
    else
    {
        answer = needPrice - money;
    }

    return answer;
}