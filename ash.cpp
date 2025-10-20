#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

using namespace std;

vector<string> paths = {"/bin"}; 

void printError() {
    const char* error_message = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message));
}

int main() {
    string input;

    while (true) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));

        cout << "ash " << cwd << " > ";
        if (!getline(cin, input)) {
            cout << "\nAggie Shell - TaliahLilly" << endl;
            exit(0);
        }

        if (input.empty()) continue;

        stringstream ss(input);
        vector<string> args;
        string arg;
        while (ss >> arg) args.push_back(arg);
        if (args.empty()) continue;

        string command = args[0];


        if (command == "exit") {
            if (args.size() != 1) {
                printError();
                continue;
            }
            cout << "Aggie Shell - TaliahLilly" << endl;
            exit(0);
        }

        else if (command == "cd") {
            if (args.size() != 2) {
                printError();
                continue;
            }
            if (chdir(args[1].c_str()) != 0) {
                printError();
            }
        }

        else if (command == "path") {
            paths.clear();
            for (size_t i = 1; i < args.size(); ++i) {
                paths.push_back(args[i]);
            }
        }

        else {
            printError();
        }
    }

    return 0;
}
