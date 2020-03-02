#include <iostream>
#include<string>

using namespace std;
bool is_palindrome (const string & str, string::size_type i = 0);
bool is_palindrome (const string & str, string::size_type i) {
    if (str.empty ()) {
        return true;
    }

    if(i <= str.size()/2) {
        if(str.at(i) != str.at(str.size()-1-i)) {
            return false;
        }
        i++;
        return is_palindrome(str, i);
    }

    return true;
}

int main()
{
    string str;
    cin>>str;
    if(is_palindrome(str)){
    cout << "true"<< endl;
}else{
        cout<<"false"<<endl;
    }
    return 0;
}
