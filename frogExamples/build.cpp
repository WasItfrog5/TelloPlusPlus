#include <iostream>
#include <string>
#include <cstdlib>

//this is modified file i use mostly for building .cpp files, i wont explain anything here except that i recommend modifying this file
//however you like, and then putting it in folder where your .cpp files are and put the folder in path
//so that you can just open cmd and do "build yes main yes" so that it compiles it and makes main.exe and opens it
//it opens the name of file in your path so if you dont wanna set that path just delete the opening function

int main(int argc, char* argv[]) {
	std::string a;
	std::string name;
	std::string open;
	if (argc > 1) {
		a = argv[1];
		name = argv[2];
		open = argv[3];
	}
	else {
		std::cout << "yes or no? y for yes" << std::endl;
		std::cin >> a;
		std::cout << "name of app" << std::endl;
		std::cin >> name;
		std::cout << "should open after building or no? y for yes" << std::endl;
		std::cin >> open;
	}
	if (a == "y" || a == "Y" || a == "yes") {
		std::string command = "g++ -o "+ name +  " main.cpp -lFrogTello";
		system(command.c_str());
	}
	if (open == "y" || open == "Y" || open == "yes") {
		std::string command = name;
		system(command.c_str());
	}
}