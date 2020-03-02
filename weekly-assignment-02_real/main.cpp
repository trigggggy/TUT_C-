// The purpose on this example is to demonstrate
// how the private part of a class can be comletely
// redesigned hwile the public interface stays the same.
// Although, two methods fetch_hour and fetch_minutes
// were added to the public interface, but they are
// unrelated to the fact that the original three
// methods are the same.

#include <iostream>
#include <iomanip>

using namespace std;


class Clock {
  public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    int difference(int time);
    int return_time_by_minutes();

    int fetch_hour() const;
    int fetch_minutes() const;

  private:
    // Minutes since the previous midnight.
    int minutes_since_midnight_;
};


int main() {
    string time1;
    string time_;
    string hours;
    string minutes;
    string hours_;
    string minutes_;

    cout<<"Enter the first time: "<<endl;
    cin>> time1;
    hours = time1.substr(0,time1.find("."));
    minutes = time1.substr(time1.find(".")+1);
    if (stoi(hours)>=24 || stoi(minutes)>60){
        cout<<"Invalid input. Enter the first time: "<<endl;
        cin>> time1;
        hours = time1.substr(0,time1.find("."));
        minutes = time1.substr(time1.find(".")+1);
    }else{
        cout<<"Enter the second time: "<<endl;
        cin>> time_;
        hours_ = time_.substr(0,time1.find("."));
        minutes_ = time_.substr(time1.find(".")+1);
            if (stoi(hours_)>=24 || stoi(minutes_)>60){
                cout<<"Invalid Input. Enter the second time: "<<endl;
                cin>> time_;
                hours_ = time_.substr(0,time1.find("."));
                minutes_ = time_.substr(time1.find(".")+1);
        }else{
    Clock Time(stoi(hours), stoi(minutes));
    Clock Time2(stoi(hours_), stoi(minutes_));

    cout << Time2.difference(Time.return_time_by_minutes()) << endl;
                }
            }

}


Clock::Clock(int hour, int minute):
    minutes_since_midnight_(60 * hour + minute) {
}
int Clock::difference(int time){
    return minutes_since_midnight_ - time ;

}

int Clock::return_time_by_minutes(){
    return minutes_since_midnight_;
}

void Clock::tick_tock() {
    ++minutes_since_midnight_;

    if ( minutes_since_midnight_ >= 24 * 60 ) {
        minutes_since_midnight_ = 0;
    }
}


int Clock::fetch_hour() const {
    // When you divide an integer by an integer
    // the result is a rounded down integer.
    return minutes_since_midnight_ / 60;
}


int Clock::fetch_minutes() const {
    return minutes_since_midnight_ % 60;
}


void Clock::print() const {
    // Notice how print-method doesn't need to know what
    // variables are hidden in the private section of the class.
    // It utilizes the helper methods fetch_hour and fetch_minutes
    // to figure out the time.  The good point of this is that
    // if we change the implementation (private part) of the class
    // print-method can stay the same.

    cout << setfill('0') << setw(2) << fetch_hour()
         << "."
         << setw(2) << fetch_minutes()
         << endl;
}
