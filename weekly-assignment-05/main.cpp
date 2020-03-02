#include <iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;

bool IsEExists(vector<string>_e, string e){
    if(_e.size()==0){
        cout<<"Event named, "<<e<<" doesn't exist. Creating new one."<<endl;
        return false;
    }else{
        for(unsigned int i=0; i<_e.size(); i++){
            if(_e[i].compare(e)!=0){
                cout<<"Event named, "<<e<<" doesn't exist. Creating new one."<<endl;
                return false;
            }
        }
        cout<<"blah"<<endl;
        return true;
    }
}


int main()
{
    vector<string> events;
    map<int, map<int, string>> details;
    string _name;
    string _event;
    int _pos;
    int e_num;
                                                               //name of the event
    while(true){
        cout<<"Type name of the event"<<endl;
        cin>>_event;
                                                               //check existance
        if(IsEExists(events, _event)==false){
            events.push_back(_event);
            e_num=events.size();
        }else{
            e_num = IsEExists(events, _event);
        }
        while(true){
        //position
        cout<<"Type the position of participant"<<endl;
        cin>>_pos;
        //check existance of the pos
        if(details[e_num][_pos].empty()){
            break;
        }
        }
        cout<<"Type the name of participant"<<endl;         //certain pos is empty
        cin>>_name;
        details[e_num][_pos]=_name;

        cout<<"--------------------------------"<<endl;
        cout<<"    Event    | Pos |    Name    "<<endl;
        cout<<"--------------------------------"<<endl;
        for(unsigned int i=0; i<events.size()+1; i++){
            for(unsigned int j=0; j<details[i].size(); j++){
                cout<<events.at(i)<<"  "<<j<<"  "<<details[i][j]<<endl;
            }
        }
        cout<<"--------------------------------"<<endl;
    }
}

