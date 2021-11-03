#include <iostream>

using namespace std;


string cycl(string str) {
	string ans;
	int len = str.length();
	ans += str[len - 1];
	for (int i = 0; i < len - 1; i++) {
		ans += str[i];
	}
	return ans;
}

int main() {
	string str;
	cin >> str;
	int len = str.length(), count = 0;
	if (len == 1) {
		cout << str;
	}
	else if (len == 2) {
		cout << str << endl;
		cout << cycl(str) << endl;
	}
	else if (len == 3) {
		cout << str << endl;
		cout << cycl(str) << endl;
		cout << cycl(cycl(str)) << endl;
		str = string{ str[1] } + string{ str[0] } + string{ str[2] };
		cout << str << endl;
		cout << cycl(str) << endl;
		cout << cycl(cycl(str)) << endl;
	}
	else {
		string str_copy = str;
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (count <= 20) {
					cout << str_copy << endl;
					count++;
				}
				else { exit(0);	}
				str_copy = cycl(str_copy);
			}
			str_copy = string{ str[i] } + str.substr(1, i - 1) + string{ str[0] } + str.substr(i + 1, len - i - 1);

		}
		for (int j = 0; j < len; j++) {
			if (count <= 20) {
				cout << str_copy << endl;
				count++;
			}
			else { exit(0); }
			str_copy = cycl(str_copy);
		}
	}
	return 0;
}