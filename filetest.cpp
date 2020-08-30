#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string str = "";
	string hold;

	ifstream gifs_file("test.txt");
	
	if (gifs_file.is_open()) {
		while (getline(gifs_file,hold)) {
			str = str + hold;
		}

		gifs_file.close();
	} else {
		cout << "can't open";
	}

	cout << str << endl;
	
	return 0;
}
