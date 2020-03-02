//sanghun.2.lee@student.tut.fi - student id: 272571

#include <iostream>
#include <regex>

using namespace std;

int INIT_SIZE = 0;

class Stack {
    public:
        Stack();
       ~Stack();
        void cmd(string str);
    private:
        string **array_;            //2d array for the chores
        int *used_space_;           //simple array to received the space used for the array.
        void E(string);             //Hanlding Error
        void add(string, regex);    //Add chores function
        void init(string, regex);   //Initializing list
        void print(string);         //Printing out chores
        void next(string);          //Load next chores
        void erase(string, regex);  //Erase chores
        void quit(string);          //quit program

        string **tmp_arr;            //2d array for the chores
        //regex isnum;

};
Stack::Stack(): array_(new string*[INIT_SIZE]), used_space_(new int[INIT_SIZE]), tmp_arr(new string*[INIT_SIZE]) {

    //initializing 2d array
    for(int i = 0; i < INIT_SIZE; ++i) {
        array_[i] = new string[0];
    }

    for(int i = 0; i < INIT_SIZE; ++i) {
        tmp_arr[i] = new string[0];
    }

}
//print error message
void Stack::E(string msg){

    //printing error
    cout<<"Error: "<<msg<<"."<<endl;
}

//basis of command
void Stack::cmd(string str){

        //regex to analyze where it's number or not
        regex isnum(
            "([[:digit:]]+)"
            );
        string val;
        string cmd_n;
        string::size_type mark1 = 0;
        string::size_type mark2 = 0;

        //spliting command and detail
        mark1 = str.find(' ',mark2);
        cmd_n = str.substr(mark2,mark1 - mark2);
        if(str.size()<=mark1){
            val="";
        }else{
            val=str.substr(mark1+1, str.size());
        }

        //command lists
        if(!cmd_n.compare("init")){
            init(val, isnum);
        }else if(!cmd_n.compare("add")){
            if(INIT_SIZE==0){                                                  //If the list is not initialized, then show the error message.
                E("Chores list is not initialized");
            }else{
            add(val, isnum);
            }
        }else if(!cmd_n.compare("print")){
            if(INIT_SIZE==0){
                E("Chores list is not initialized");
            }else{
            print(val);
            }
        }else if(!cmd_n.compare("next")){
            if(INIT_SIZE==0){
                E("Chores list is not initialized");
            }else{
            next(val);
            }
        }else if(!cmd_n.compare("erase")){
            if(INIT_SIZE==0){
                E("Chores list is not initialized");
            }else{
            erase(val, isnum);
            }
        }else if(!cmd_n.compare("quit")){
            quit(val);
        }else{
            E("Command doesn't exist");
        }
}

void Stack::init(string s, regex isnum){

    smatch result;
    if(!s.compare("")){
        E("the number of priority levels is missing");
    }else{
        if(regex_match(s, result, isnum)){
            if(stoi(s)>0){
            INIT_SIZE = stoi(s);
            cout<<"New priority list with levels 1-"<<s<<" initialized."<<endl;

            used_space_=new int[INIT_SIZE];

            array_=new string*[INIT_SIZE];
            for(int i = 0; i < INIT_SIZE; ++i) {
                array_[i] = new string[0];

                used_space_[i]=0;
            }

            }else{
                E("value must be greater than 0");
            }
        }else{
            E("the number of priority levels must be an integer greater than 0");
        }
    }
}

void Stack::add(string s, regex isnum){

    smatch result;
        string val;
        string tmp_n;
        int pri_n;
        string::size_type mark1 = 0;
        string::size_type mark2 = 0;
        if(!s.compare("")){
            E("priority level and chore description are missing");
        }else{
            mark1 = s.find(' ',mark2);
            tmp_n = s.substr(mark2,mark1 - mark2);

            if(regex_match(tmp_n, result, isnum)){
            pri_n = stoi(tmp_n)-1;

                if(s.size()<=mark1){
                    E("chore description is missing");
                }else{
                    if(pri_n<0 || pri_n+1>INIT_SIZE){
                        E("Priority level must be an integer between 1-"+to_string(INIT_SIZE));
                    }else{
                        //cout<<pri_n<<endl;
                        tmp_arr=new string*[INIT_SIZE]; //row create

                        for(int i = 0; i < INIT_SIZE; i++) {
                            int sizer = used_space_[i];
                            if(i==pri_n){
                                tmp_arr[i] = new string[sizer+1];
                            }else{
                                tmp_arr[i] = new string[sizer];
                            }
                            //cout<<i<<" : "<<sizer<<endl;
                        }

                        for(int i =0; i< INIT_SIZE;i++){
                            for(int j=0;j<used_space_[i]; j++){
                                tmp_arr[i][j] = array_[i][j];
                            }
                        }

                        //delete array
                        for(int i = 0; i < INIT_SIZE; ++i) {
                            delete [] array_[i];
                        }
                        delete [] array_;

                        //renew array slots
                        array_ = tmp_arr;

                        //receive the description
                        val = s.substr(mark1+1, s.size());

                        //add new value
                        array_[pri_n][used_space_[pri_n]] = val;
                        cout<<"New chore added to priority level "<<pri_n+1<<"."<<endl;
                        used_space_[pri_n]+=1;
                    }
                }
            }else{
                E("priority number doesn't exist");
            }
        }
}

//print the list
void Stack::print(string s){
    if(!s.compare("")){
        int a = INIT_SIZE;
        int num = 1;
        while(a>=0){
            if(used_space_[a-1]>0){
                cout<<"Priority level "<< a <<":"<<endl;
                for(int j=0; j< used_space_[a-1]; j++){
                        cout<<"  "<< to_string(num) <<". "<< array_[a-1][j] <<endl;
                        num++;
                }
            }
           --a;
        }
    }else{
        E("extra text after print command");
    }
}

void Stack::next(string s){
    int cnt=0;
    int num = 0;
    int tmp_size=0;
    int row=0;
    int b=INIT_SIZE;
    string* tmp;

    if(!s.compare("")){

        for(int i=0; i<INIT_SIZE; i++){
            tmp_size += used_space_[i];
        }
    tmp = new string[tmp_size];

        while(b>=0){
            if(used_space_[b-1]>0){
                for(int j=0; j< used_space_[b-1]; j++){
                    tmp[cnt] = array_[b-1][j];
                    ++cnt;
                }
            }
            b--;
        }

    if(tmp_size<1){
        cout<<"--- no chores left ---"<<endl;
    }else{
        cout<<tmp[0]<<endl;
        //check the val
        for(int t=0; t<INIT_SIZE; t++){
            for(int k=0; k<used_space_[t]; k++){
                if(tmp[num]==array_[t][k]){
                    row=t;
                    break;
                }
            }
        }

        //renew the array
        tmp_arr=new string*[INIT_SIZE]; //row create
        for(int i = 0; i < INIT_SIZE; i++) {
            if(i==row && used_space_[i]>0){
                tmp_arr[i] = new string[used_space_[i]-1];
            }else{
                tmp_arr[i] = new string[used_space_[i]];
            }
        }
        used_space_[row]-=1;
        for(int i =0; i< INIT_SIZE;i++){
            for(int j=0;j<used_space_[i]; j++){
                if(row==i){
                    tmp_arr[i][j] = array_[i][j+1];
                }else{
                    tmp_arr[i][j] = array_[i][j];
                }
            }
        }


        //delete array
        for(int tt = 0; tt < INIT_SIZE; ++tt) {
            delete [] array_[tt];
        }
        delete [] array_;
        //renew array slots
        array_ = tmp_arr;
        }
    }else{
        E("extra text after next command");
    }

}

//erase
void Stack::erase(string s, regex isnum){
    int cnt=0;
    int tmp_size=0;
    int row=0;
    int col=0;
    bool there_is = false;
    smatch result;

    if(!s.compare("")){
        E("no");
    }else{
        int num = stoi(s);
    if(regex_match(s, result, isnum)){                                                                       //regex
        for(int i=0; i<INIT_SIZE; i++){
            tmp_size += used_space_[i];
        }
        int b=tmp_size;
        string tmp[tmp_size];
        while(b>0){
            if(used_space_[b]!=0){
                for(int j=0; j< used_space_[b]; j++){
                    tmp[cnt] = array_[b][j];
                    cnt++;
                }
            }
            b--;
        }
        if(num-1<0){
            E("the running number must be greater than 0");
        }else if(num-1>INIT_SIZE){
            E("there is no such chore");
        }else{

            //check the val
            for(int t=0; t<INIT_SIZE; t++){
                for(int k=0; k<used_space_[t]; k++){
                    if(!tmp[num-1].compare(array_[t][k])){
                        row=t;
                        col=k;
                        there_is=true;
                        break;
                    }
                }
            }
            if(there_is){
                //renew the array
                tmp_arr=new string*[INIT_SIZE]; //row create
                for(int i = 0; i < INIT_SIZE; i++) {
                    if(i==row){
                        tmp_arr[i] = new string[used_space_[i]-1];
                    }else{
                        tmp_arr[i] = new string[used_space_[i]];
                    }
                }

                for(int i =0; i< INIT_SIZE;i++){
                    for(int j=0;j<used_space_[i]; j++){
                        if(row==i){
                            if(j!=col){
                                tmp_arr[i][j] = array_[i][j];
                            }
                        }else{
                        tmp_arr[i][j] = array_[i][j];
                        }
                    }
                }
                used_space_[row]-=1;

                //delete array
                for(int i = 0; i < INIT_SIZE; ++i) {
                    delete [] array_[i];
                }
                delete [] array_;

                //renew array slots
                array_ = tmp_arr;
            }
            else{
                E("there is no such chore");
            }
        }
    }else{                                      //regex not found
        E("the running number is missing");
    }

    }
}

//quit program
void Stack::quit(string s){
    if(!s.compare("")){
    exit(0);
    }else{
        E("extra text after quit command");
    }
}

Stack::~Stack(){
    for(int i = 0; i < INIT_SIZE; ++i) {
        delete [] array_[i];
        delete [] tmp_arr[i];
    }
    delete [] array_;
    delete [] tmp_arr;
    delete [] used_space_;
}

int main()
{
    Stack s;
    string a;
    while(cout<<"chores> " && getline(cin, a)){
        s.cmd(a);
    }
}
