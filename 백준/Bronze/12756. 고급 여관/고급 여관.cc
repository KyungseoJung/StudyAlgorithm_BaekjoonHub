#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int A_attack, A_life;
	int B_attack, B_life;

	cin >> A_attack >> A_life >> B_attack >> B_life;

	while (true)
	{

		if ((A_life <= 0) && (B_life <= 0))
		{
			cout << "DRAW";
			return 0;
		}
		else if (A_life <= 0)
		{
			cout << "PLAYER B";
			return 0;
		}
		else if (B_life <= 0)
		{
			cout << "PLAYER A";
			return 0;
		}
		A_life -= B_attack;
		B_life -= A_attack;

	}
}