#ifndef ENCRYPTION_H
#define ENCRYPTION_H

using namespace std;

int conInt(char in) {
	return static_cast<int>(in) - 32;
}	

char conChar(int in) {
	return char(in + 32);
}

int Wrap(int in, int cap) {
	return in - cap * floor((float)in / (float)cap);
}

string encrypt(string Input, int seed, bool Decode) {
	int a = conInt(Input.at(0));
	int b = conInt(Input.at(1));
	int o = NULL;
	if (Decode)
	{
		o = Wrap(12 * (b - (a * seed)), 95);
	}
	else
	{
		o = Wrap((8 * b) + (a * seed), 95);
	}
	string out = "  ";
	out.at(0) = conChar(a);
	out.at(1) = conChar(o);
	return out;
}

string segregateString(string Input, int place, int seed, bool Decode) {
	string in;
	if (place == Input.size() - 1)
	{
		in = string(1, Input.at(place)) + string(1, Input.at(0));
	}
	else
	{
		in = string(1, Input.at(place)) + string(1, Input.at(place + 1));
	}

	in = encrypt(in, seed, Decode);
	string out = Input;

	if (place == Input.size() - 1)
	{
		out.at(place) = in.at(0);
		out.at(0) = in.at(1);
	}
	else
	{
		out.at(place) = in.at(0);
		out.at(place + 1) = in.at(1);
	}

	return out;
}

string encryptString(string Input, int seed, bool decode, int depth) {
	string out = Input;
	for (int i = 0; i < depth; i++)
	{
		if (decode)
		{
			for (int i = 0; i < Input.size(); i++)
			{
				out = segregateString(out, out.size() - i - 1, seed, true);
			}
		}
		else
		{
			for (int i = 0; i < Input.size(); i++)
			{
				out = segregateString(out, i, seed, false);
			}
		}
	}
	return out;
}

#endif ENCRYPTION_H
