#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// unsigned int is a type you can use to store and manipulate
// natural numbers (ℕ) in C++ programs.  In other words
// whole numbers that are ≥ 0.
const unsigned int SPLIT_ERROR = 0;

class Splitter {
  public:
    Splitter(const string& string_to_split = "");
    void set_string_to_split(const string& string_to_split);
    unsigned int split(char separator, bool ignore_empty = false);
    unsigned int number_of_fields() const;
    string fetch_field(unsigned int field_index) const;

  private:
    string original;
     vector<string> splitted;
};

Splitter::Splitter(const string& string_to_split):
    original(string_to_split), splitted({}){
}
void Splitter::set_string_to_split(const string&){

}
unsigned int Splitter::split(char separator, bool ignore_empty){
    splitted.clear();
    string::size_type start_pos = 0;
    string field_content;
    while (true){
        string::size_type split_pos = original.find(separator, start_pos);
        if(split_pos==string::npos){
            break;
        }
        field_content = original.substr(start_pos, split_pos-start_pos);
        start_pos=split_pos+1;
        if (ignore_empty == true){
            remove(field_content.begin(), field_content.end(), ' ');
                    splitted.push_back(field_content);
        }
        else{
        splitted.push_back(field_content);
        }
    }
    //field_content = original.substr();
    splitted.push_back(field_content);
    return splitted.size();
    //size_t n = count(s.begin(), s.end(), separator);
    //for(int i = 0; i<n; i++){
    //        .substr(0,time1.find("."));
    //}

}
unsigned int Splitter::number_of_fields()const{
    return splitted.size();
}

string Splitter::fetch_field(unsigned int field_index)const{
    return splitted.at(field_index);
}

int main()
{
    Splitter obj("Helo, i,       am     , sanghun, qwer1, qwer");
    obj.split(',', true);

    cout << obj.fetch_field(5) <<"and "<< obj.number_of_fields() << endl;
    return 0;
}
