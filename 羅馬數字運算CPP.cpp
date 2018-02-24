#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int ROMtoNUM(string);
int RtoN(char);
string NUMtoROM(int);
int priority(char);

int main() {
	string input_f, input_s, output;
	int in_f, in_s, out;
	
	while (cin >> input_f >> input_s){
		in_f = 0;
		in_s = 0;
		out = 0;
		
		if (input_f == "#" || input_s == "#") break;
		
		if (input_f == "ZERO") in_f = 0;
		else in_f = ROMtoNUM(input_f);
		if (input_s == "ZERO") in_s = 0;
		else in_s = ROMtoNUM(input_s);
		
		out = (in_f >= in_s) ? in_f - in_s : in_s - in_f;
		output = NUMtoROM(out);
		
		cout << output << endl;
	}

} 

int ROMtoNUM(string input) {
	int result = 0, tmp = 0;
	tmp = RtoN(input[0]);
	
	for (int i=1; i<input.length(); i++) {
		if (priority(input[i-1]) > priority(input[i])) {
			result += tmp;
			tmp = RtoN(input[i]);
		} else if (priority(input[i-1]) == priority(input[i])) {
			tmp += RtoN(input[i]);
		} else {
			result += RtoN(input[i]) - tmp;
			tmp = 0;
		}
	}
	
	result += tmp;
	return result;
}

int RtoN(char word) {
	switch(word) {
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			return 0;
			break;
	}
}

int priority(char word) {
	switch(word) {
		case 'I':
			return 1;
			break;
		case 'V':
			return 2;
			break;
		case 'X':
			return 3;
			break;
		case 'L':
			return 4;
			break;
		case 'C':
			return 5;
			break;
		case 'D':
			return 6;
			break;
		case 'M':
			return 7;
			break;
		default:
			return 0;
			break;
	}
}

string NUMtoROM(int o) {
	int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string word[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	string result = "";
	int idx = 0;
	
	if (o == 0) return "ZERO";
	
	while (o > 0) {
		while (o >= num[idx]) {
			o -= num[idx];
			result = result + word[idx];
		}
		
		idx++;
	}
	
	return result;
}
