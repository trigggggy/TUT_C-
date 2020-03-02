#include <iostream>
#include <map>
#include<string>

using namespace std;


int count_names(const map<string, string>& phonebook, char initial_letter, map<string, string>::const_iterator iter, int cnt) {
    if(iter == phonebook.end()){
        return cnt;
    }else{
        cnt++;
        iter++;
        return count_names(phonebook, initial_letter, iter, cnt);
    }
}


int main()
{
map<string, string> phonebook;
phonebook["Sanghun"]="1111111";
phonebook["Sanghuni"]="111111";
phonebook["Sanghunii"]="11111";
phonebook["Sanghuniii"]="1111";
phonebook["Sanghuniiii"]="111";
phonebook["Sanghuniiiii"]="11";
int numi;
map<string, string>::const_iterator iter = phonebook.begin();
numi = count_names(phonebook, 'S',iter , 0);
cout<<"Number : "<<numi<<endl;

}
