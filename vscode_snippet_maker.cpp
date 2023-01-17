#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name, prefix, code, description;
    ofstream file("snippet.txt");

    cout << "Enter snippet name: ";
    getline(cin, name);

    cout << "Enter prefix: ";
    getline(cin, prefix);

    file << "\"" << name << "\": {\n";
    file << "\t\"prefix\": \"" << prefix << "\",\n";
    file << "\t\"body\": [\n";

    while (true) {
        cout << "Enter code (Enter 0 to end): ";
        getline(cin, code);

        if (code == "0") {
            break;
        }

        file << "\t\t\"" << code << "\",\n";
    }

    cout << "Enter description (Enter 0 for default): ";
    getline(cin, description);
    if (description == "0") {
        description = "The snippet has no description";
    }
    file << "\t],\n";
    file << "\t\"description\": \"" << description << "\"\n";
    file << "}\n";

    file.close();

    cout << "Snippet saved to snippet.txt" << endl;

    return 0;
}
