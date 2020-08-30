#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <X11/Xlib.h>

using namespace std;

void clear();
void populate(string input);

int main() {
	string input;
	string finalIn = "";
	//get display resolution
	Display* d = XOpenDisplay(NULL);
	Screen*  s = DefaultScreenOfDisplay(d);
	int swidth = s->width;
	int sheight = s->height;
	//make initial gifsicle command using screen width and height
	string gifsicle = "gifsicle --no-background -S " + to_string(swidth) + "x" + to_string(sheight) + " --colors 256 -d 3 ";
	int xpos;
	int ypos;

	//output contents of gifs directory to file using bash command
	const char* list_gifs = "rm gifs.txt && ls gifs >> gifs.txt";
	system(list_gifs);
	ifstream gifs_file("gifs.txt");

	if (gifs_file.is_open()) {
		while (getline(gifs_file,input)) {
			xpos = rand() % swidth + 25;
			ypos = rand() % sheight + 25;
			input = " -p " + to_string(xpos) + "," + to_string(ypos) + " gifs/" + input;
			finalIn = finalIn + input;
		}
		gifs_file.close();
	} else {
		cout << "can't open gifs.txt" << endl;
	}

	//remove previous allgifs.gif
	const char* clear_gifs = "rm allgifs.gif";
	system(clear_gifs);

	// put together final version of gifsicle command
	gifsicle = gifsicle + finalIn;
	gifsicle = gifsicle + " > allgifs.gif";

	const char* compile = gifsicle.c_str();

	system(compile);

	const char* run = "gifview -a -bg allgifs.gif";

	system(run);
}
