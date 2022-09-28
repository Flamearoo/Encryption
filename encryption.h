#ifndef ENCRYPTION_H
#define ENCRYPTION_H

using namespace std;

int convertInt(string Input) {
	return 256 * ((int)Input.at(0)) + ((int)Input.at(1));
}

string convertString(int Input) {
	string Out = "  ";
	Out.at(0) = (char)(int)floor((float)Input / (float)256);
	Out.at(1) = (char)(int)(Input - 256 * floor((float)Input / (float)256));
	return Out;
}

int encodeNumber(int Input, int seed) {
	int cap = 65536;
	int out = (481 * Input) + (53 * seed);
	return out - (cap * floor((float)out / (float)cap));
}

int decodeNumber(int Input, int seed) {
	int cap = 65536;
	int out = (545) * (Input - (53 * seed));
	return out - (cap * floor((float)out / (float)cap));
}

string encrypt(string Input, int seed, bool Decode) {
	int val = convertInt(Input);
	if (Decode)
	{
		val = decodeNumber(val, seed);
	}
	else
	{
		val = encodeNumber(val, seed);
	}
	return convertString(val);
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

#endif ENCRYPTION_H
