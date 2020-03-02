//email address: hung.nguyen@student.tut.fi - student id: 272585
//email address: sanghun.2.lee@student.tut.fi - student id: 272571



#include <iostream>
#include <string>
#include <vector>


using namespace std;

//Splitter to split the date string to int-type components.
//Return a vector of integers based on the input string.
vector<int> Splitter(const string& strToSplit){
    vector<int> vector;
    int tempInt;
    string tempString;
    string::size_type mark1 = 0;
    string::size_type mark2 = 0;
    while(1){
        mark1 = strToSplit.find('-',mark2);
        if(mark1 == string::npos){
            tempString = strToSplit.substr(mark2);
            tempInt = stoi(tempString);
            vector.push_back(tempInt);
            break;
        }
        tempString = strToSplit.substr(mark2,mark1 - mark2);
        tempInt = stoi(tempString);
        vector.push_back(tempInt);
        mark2 = mark1+1;
    }
    return vector;
}

//Helper function to check if a character is a number.
//Return true if the char variable is a number and vice versa.
bool isANumber(char c){
    if(c>='0' && c<='9'){
        return true;
    }return false;
}

//function to check if the input string s a valid date string with type: day-month-year.
//Return true if the string is of form day-month-year and vice versa.
bool isStringValid(string str){
    if(str.size() == 10){
        if(str.at(2) == '-' && str.at(5)=='-' && isANumber(str.at(0)) && isANumber(str.at(1)) && isANumber(str.at(3))
                && isANumber(str.at(4)) && isANumber(str.at(6)) && isANumber(str.at(7)) && isANumber(str.at(8)) && isANumber(str.at(9))){
            return true;
        }
    }else if(str.size() == 8){
        if(str.at(1)=='-' && str.at(3) == '-' && isANumber(str.at(0)) && isANumber(str.at(2)) && isANumber(str.at(4))
                && isANumber(str.at(5)) && isANumber(str.at(6)) && isANumber(str.at(7))){
            return true;
        }
    }else if(str.size() == 9){
        if(str.at(1) == '-' && str.at(4) == '-' && isANumber(str.at(0))&& isANumber(str.at(2))&& isANumber(str.at(3))&& isANumber(str.at(5))&& isANumber(str.at(6))&& isANumber(str.at(7))&& isANumber(str.at(8))){
            return true;
        }
        if(str.at(2) == '-' && str.at(4)=='-' && isANumber(str.at(0))&& isANumber(str.at(1))&& isANumber(str.at(3))&& isANumber(str.at(5))&& isANumber(str.at(6))&& isANumber(str.at(7))&& isANumber(str.at(8))){
            return true;
        }
    }
    return false;
}

class date{
public:
    date(string date);
    date(int day, int month, int year);
    bool isValid()const;
    void print()const;
    void print2()const;
    void moveToNextDate();
    void moveToLastDate();
    string getWeekday()const;
    int getDay()const;
    int getMonth()const;
    int getYear()const;

private:
    int day_;
    int month_;
    int year_;

};

//function to get week day of the current date.
//Return a string from "Monday" to "Sunday"
string date::getWeekday() const {
    // The formula for calculating a julian day number is ripped from:
    // https://en.wikipedia.org/wiki/Julian_day
    int Y = year_;
    int M = month_;
    int D =day_;
    int julian_day_number =
            (1461 * (Y + 4800 + (M - 14)/12))/4
            + (367 * (M - 2 - 12 * ((M - 14)/12)))/12
            - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075;

    int weekday_number = julian_day_number % 7;

    switch ( weekday_number ) {
    case 0:
        return "Monday";
    case 1:
        return "Tuesday";
    case 2:
        return "Wednesday";
    case 3:
        return "Thursday";
    case 4:
        return "Friday";
    case 5:
        return "Saturday";
    case 6:
        return "Sunday";
    default:
        return "?????";
    }
}

//Constructor for input as a string
date::date(string date){
    vector<int> vector = Splitter(date);
    //vector is only used to store integers from the Splitter
    day_ = vector.at(0);
    month_ = vector.at(1);
    year_ = vector.at(2);
}

//Constructor for input as 3 different int: day, month, year
date::date(int day, int month, int year):
    day_(day),month_(month),year_(year){}

//function to check if a date is valid.
//return true if the date is a valid date and vice versa.
bool date::isValid()const{
    if(year_ >= 1800){
        if(month_==1 || month_==3 || month_==5 || month_==7|| month_==8 || month_==10 ||
                month_==12){
            if(day_ <= 31 && day_> 0)  return true;

        }else if(month_ ==4|| month_ ==6 || month_==9||month_==11){
            if(day_ <= 30 && day_>0)  return true;


        }else if(month_ == 2){
            if(year_ % 4 == 0){
                if(year_ %100 != 0){
                    if(day_ <= 29 && day_>0)  return true;
                }else if(year_ %400 == 0){
                    if(day_ <= 29 && day_> 0)  return true;
                }

            }else{
                if(day_<=28 && day_>0)    return true;
            }
        }

        return false;
    }
    return false;
}

//print out the current date.
void date::print() const{
    cout<<"Day is "<<day_<<"\nMonth is "<<month_<<"\nYear is "<<year_<<"\nWeekday is "<<getWeekday()<<endl;
}

//another print function to print out the date object.
//because the next and previous dates are printed differently from the input date.
void date::print2() const{
    cout<<getWeekday()<<" "<<day_<<"."<<month_<<"."<<year_<<endl;
}

//increment the current date object to the next date.
void date::moveToNextDate(){

    int nextDay = day_+1;
    int monthNextDay = month_;
    int yearNextDay = year_;
    date tempDate = date(nextDay,month_,year_);
    if(!tempDate.isValid()){
        nextDay =1;
        monthNextDay = month_+1;
        tempDate = date(nextDay,monthNextDay,year_);
        if(!tempDate.isValid()){
            monthNextDay =1;
            yearNextDay = year_ +1;
        }
    }
    day_=nextDay;
    month_=monthNextDay;
    year_=yearNextDay;
}


//decrement the current date object to the previous date.
void date::moveToLastDate(){
    int lastDay = day_ -1;
    int monthLastDay = month_;
    int yearLastDay = year_;
    date tempDate = date(lastDay,month_,year_);
    if(!tempDate.isValid()){
        if(month_ ==1){
            monthLastDay = 12;
            yearLastDay = year_-1;
            lastDay = 31;
            tempDate = date(lastDay,monthLastDay,yearLastDay);
        }else{
            monthLastDay = month_ -1;
            lastDay =31;
            while(1){
                tempDate = date(lastDay,monthLastDay,yearLastDay);
                if(tempDate.isValid())  break;
                lastDay--;
            }
        }
    }
    day_ = lastDay;
    month_ = monthLastDay;
    year_ = yearLastDay;
}

//get the day number of the date object.
int date::getDay()const{
    return day_;
}

//get the month number of the date object.
int date::getMonth()const{
    return month_;
}

//get the year number of the date object.
int date::getYear()const{
    return year_;
}


int main(){
    string input;
    while(1){
        cout<<"Input a date in day-month-year format: ";
        getline(cin, input);
        if(input == "quit"){
            cout<<"\nTest program ending, goodbye!\n"<<endl;
            break;
        }


        cout<<"--- TEST OUTPUT BEGIN"<<endl;
        if(!isStringValid(input)){
            cout<<"Error: this is not a valid date!"<<endl;
        }else{
            date d1 = date(input);
            if(d1.isValid()){
                cout<<"The date is a valid date."<<endl;
                d1.print();
                d1.moveToLastDate();
                cout<<"The previous date was: ";
                d1.print2();
                d1.moveToNextDate();
                d1.moveToNextDate();
                cout<<"The next date will be: ";
                d1.print2();
            }else{
                cout<<"Error: this is not a valid date"<<endl;
            }
        }

        cout<<"--- TEST OUTPUT END\n"<<endl;
    }

    return 0;
}
