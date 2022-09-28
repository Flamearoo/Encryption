#include <string>
#include <iostream>
#include "encryption.h"
#include <stdlib.h>

using namespace std;

void ResetCin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
	while (true)
	{
		bool done;

		int seed = 0;
		string decodeS;
		bool decode = false;
		string Input;

		done = true;
		while (done)
		{
			cout << "*enter the seed you want to use" << endl << "   ";
			cin >> seed;

			if (!cin)
			{
				ResetCin();
				cout << "*Err: please enter a valid seed (0 - 9024)" << endl << endl;
				continue;
			}
			else
			{
				done = false;
			}
		}

		done = true;
		while (done)
		{
			cout << endl << "*would you like to decode ('d') or encode ('e')" << endl << "   ";
			cin >> decodeS;

			if (decodeS == "d")
			{
				decode = true;
				done = false;
			}
			else if (decodeS == "e")
			{
				decode = false;
				done = false;
			}
			else
			{
				ResetCin();
				cout << "*Err: please enter either 'd' or 'e'" << endl << endl;
				continue;
			}
		}
		done = true;
		while (done)
		{
			cout << endl << "*enter the string you want to encrypt" << endl << "   ";
			cin.ignore();
			getline(cin, Input);

			if (!cin)
			{
				ResetCin();
				cout << "*Err: please enter a valid input" << endl << endl;
				continue;
			}
			else
			{
				done = false;
			}
		}

		string dec = Input;
		string enc = Input;

		for (int i = 0; i < Input.size(); i++)
		{
			dec = segregateString(dec, dec.size() - i - 1, seed, true);
		}
		for (int i = 0; i < Input.size(); i++)
		{
			enc = segregateString(enc, i, seed, false);
		}

		string out = Input;
		string check = Input;
		if (decode)
		{
			out = dec;
			check = dec;
			for (int i = 0; i < Input.size(); i++)
			{
				check = segregateString(check, i, seed, false);
			}
		}
		else
		{
			out = enc;
			check = enc;
			for (int i = 0; i < Input.size(); i++)
			{
				check = segregateString(check, check.size() - i - 1, seed, true);
			}
		}

		if (Input == check)
		{
			cout << endl << "*Encryption was a success:" << endl << "   Out: " << out << endl << endl << endl;
		}
		else
		{
			ResetCin();
			cout << "*Err: Undefined sequence inputted" << endl << "*Restarting" << endl << endl << endl;
		}

	}

	return 0;
}