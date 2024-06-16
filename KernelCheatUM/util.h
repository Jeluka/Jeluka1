#pragma once
#define _CRT_SECURE_NO_WARNINGS


#define patch_shell   xor_w(L"\\SoftwareDistribution\\Download\\")

string random_string()
{
	srand((unsigned int)time((time_t*)0));
	string str = xor_a("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890");
	string newstr;
	int pos;
	while (newstr.size() != 32)
	{
		pos = ((rand() % (str.size() + 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}
