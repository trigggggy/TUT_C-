//hung.nguyen@student.tut.fi - student id: 272585
//sanghun.2.lee@student.tut.fi - student id: 272571
#include <vector>
#include <string>
#include <iostream>
#include "splitter.hh"

using namespace std;

/*split input file line into seperate string and store them into
 *a vector which is returned by the function.
 */
vector<string> split(const string& stringToSplit_,char regex){

    vector<string> fields;
    string::size_type strCount=0;
    string::size_type mark1=0;
    string::size_type mark2=0;

    while(1){
        mark2 = stringToSplit_.find(regex,mark1);
        if(mark2 == string::npos){
            fields.push_back(stringToSplit_.substr(mark1));
            break;
        }

        strCount = mark2 - mark1;
        if(strCount !=0){
            fields.push_back(stringToSplit_.substr(mark1,strCount));
        }
        while(stringToSplit_.at(mark2) == regex){
            if(mark2==stringToSplit_.size() -1){
                break;
            }
            mark2++;
        }
        if(mark2==stringToSplit_.size() -1){
            if(stringToSplit_.at(mark2) == regex)   break;
            fields.push_back(stringToSplit_.substr(mark2,1));
            break;
        }
        mark1 = mark2;
    }
    return fields;
}
