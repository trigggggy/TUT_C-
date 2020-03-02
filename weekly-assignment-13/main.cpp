#include <iostream>
#include <regex>

using namespace std;

int main() {
    regex reg(
       "([0-3][0-9]+)"
        "[/]*"
        "([0-1][0-9]+)"
        "[/]*"
        "([0-2][0-9][0-9][0-9]+)"
    );
    smatch result;
    string line;
    while ( cout << "Input int: " and getline(cin, line) ) {
        if ( regex_match(line, result, reg) ) {
            cout << result.str(3) << "-" << result.str(2) << "-" << result.str(1) << endl;
        } else {
            cout << "Wrong, try again!" << endl;
        }
    }
}
