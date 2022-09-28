#include <iostream>
#include "encryption.h"

using namespace std;

void ResetCin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
	while (true)
	{
		int seed;
		string decodeS;
		bool decode;
		string Input;

		cout << "enter the seed you want to use" << endl;
		cin >> seed;

		if (!cin)
		{
			ResetCin();
			cout << "please enter a valid seed" << endl << endl;
			continue;
		}

		cout << "would you like to decode ('d') or encode ('e')" << endl;
		cin >> decodeS;

		if (decodeS == "d")
		{
			decode = true;
		}
		else if (decodeS == "e")
		{
			decode = false;
		}
		else
		{
			ResetCin();
			cout << "please enter either 'd' or 'e'" << endl << endl;
			continue;
		}

		cout << "enter the string you want to encrypt" << endl;
		cin >> Input;

		if (!cin)
		{
			ResetCin();
			cout << "please enter a valid input" << endl << endl;
			continue;
		}

		if (decode)
		{
			for (int i = 0; i < Input.size(); i++)
			{
				Input = segregateString(Input, Input.size() - i - 1, seed, true);
			}
		}
		else
		{
			for (int i = 0; i < Input.size(); i++)
			{
				Input = segregateString(Input, i, seed, false);
			}
		}

		cout << Input << endl << endl;
	}

	return 0;
}