#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void clear();
void populate(string input);

int main() {
	string input;
	string finalIn = "";
	string gifsicle = "gifsicle --no-background -S 1600x900 --colors 256 -d 3 ";
	int xpos;
	int ypos;
	int max;
	
	cout << "Type in the GIFs you want to put together:" << endl;
	cin >> input;
	
	while (input.compare("end") != 0) {
		xpos = 100 * (rand() % 12 + 1) + 10 * (rand() % 10 + 1) - 100 * (rand() % 20) % 2;
		ypos = 100 * (rand() % 6 + 1) + 10 * (rand() % 10 + 1) - 100 * (rand() % 20) % 3;
		input = " -p " + to_string(xpos) + "," + to_string(ypos) + " " + input;
		finalIn = finalIn + input;
		cin >> input;
	}
	

	gifsicle = gifsicle + finalIn;
	gifsicle = gifsicle + " > allgifs.gif";
	
	const char *compile = gifsicle.c_str();

	system(compile);

	const char *run = "gifview -a -bg allgifs.gif";

	system(run);
}
