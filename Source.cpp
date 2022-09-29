#include <string>
#include <iostream>
#include "encryption.h"
#include "consoleAsk.h"
#include <stdlib.h>

using namespace std;

void Encryptor() {
	while (true)
	{
		bool Debug;
		string in;
		char v[1];
		cout << "Would you like to start in debug mode? ('y' 'n') *very complicated, documentation must be read before use" << endl << "   ";
		cin >> in;

		int p1 = 8;
		int p2 = 12;
		int displace = 0;
		int depth = 0;

		if (in == "y") {
			cout << endl << "Multiplier 1 (default 8)" << endl << "   ";
			cin >> p1;

			cout << endl << "Multiplier 2 (default 12)" << endl << "   ";
			cin >> p2;

			cout << endl << "Displacement (default 0) <0 - 94>" << endl << "   ";
			cin >> displace;

			cout << endl << "Depth (default 2)" << endl << "   ";
			cin >> depth;

			cout << endl << endl;
		}

		if (cin.fail())
		{
			cout << "fatal error" << endl << "-rebooting";
			ResetCin();
			continue;
		}

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
				cout << endl << "*enter the seed you want to use" << endl << "   ";
				cin >> seed;

				if (!cin || seed > 9024 || seed < 0)
				{
					ResetCin();
					cout << "*Err: please enter a valid seed (0 - 94)" << endl << endl;
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

			string out = Input;
			string check = Input;

			out = encryptString(Input, seed, decode, depth, p1, p2, displace);
			check = encryptString(out, seed, !decode, depth, p1, p2, displace);

			if (Input == check)
			{
				cout << endl << "*Encryption was a success:" << endl << "   Out: " << out << endl << endl << endl;
			}
			else
			{
				cout << "*Err: Undefined sequence inputted" << endl << "*Restarting" << endl << endl << endl;
			}
		}
	}
}

int main() {

	Encryptor();

	return 0;
}