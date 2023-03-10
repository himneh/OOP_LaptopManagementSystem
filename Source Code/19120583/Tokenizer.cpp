#include "Tokenizer.h"

vector<string> Tokenizer::split(string haystack, string  needle) {
	vector<string> result;

	int startPos = 0;
	size_t foundPos = 0;
	while (true) {
		foundPos = haystack.find(needle, startPos);

		if (foundPos != string::npos) {
			string token = haystack.substr(startPos, foundPos - startPos);
			result.push_back(token);
			startPos = foundPos + needle.length();
		}
		else {
			string token = haystack.substr(startPos, haystack.length() - startPos);
			result.push_back(token);
			break;
		}
	}
	return result;
}