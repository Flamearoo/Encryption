#ifndef ENCRYPTION_H
#define ENCRYPTION_H

using namespace std;

int conInt(char in) {
	return static_cast<int>(in) - 32;
}	

char conChar(int in) {
	return char(in + 32);
}

int convertInt(string Input) {
	return 95 * (conInt(Input.at(0))) + (conInt(Input.at(1)));
}

string convertString(int Input) {
	string Out = "  ";
	Out.at(0) = conChar(floor((float)Input / (float)95));
	Out.at(1) = conChar(Input - (95 * floor((float)Input / (float)95)));
	return Out;
}

int encodeNumber(int Input, int seed) {
	float cap = 9025;
	float out = (547 * Input) + (53 * seed);
	return out - (cap * floor(out / cap));
}

int decodeNumber(int Input, int seed) {
	float cap = 9025;
	float out = 33 * (Input - (53 * seed));
	return out - (cap * floor(out / cap));
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
