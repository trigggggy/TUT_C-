// The purpose on this example is to demonstrate
// how the private part of a class can be comletely
// redesigned while the public interface stays the same.
// Although, two methods fetch_hour and fetch_minutes
// were added to the public interface, but they are
// unrelated to the fact that the original three
// methods are the same.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Org_clock {
  public:
    Org_clock(vector<int> collection);
void print();
  private:
vector<int> sanghun;
};

class Clock {
  public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    int organizer();
    int fetch_hour() const;
    int fetch() const;
    int fetch_minutes() const;
    vector< vector<int> > collection;

  private:
    // Minutes since the previous midnight.
    int minutes_since_midnight_;
    vector<int> clock;
};


int main() {
int nclock;
int hour;
int min;
int i=0;
    vector<int> coll;
    vector<int> part;
cout<<"How many clocks do you want to make?"<<endl;
cin >> nclock;
for(i=0; i <= nclock; i++){
cout<< i+1 <<"'th Clock, enter hour"<<endl;
cin >> hour;
cout<< i+1 <<"'th Clock, enter minute"<<endl;
cin >> min;
Clock time(hour, min);
coll.push_back(time.fetch());
}
cout<<coll[1]<<endl;
Org_clock clockie(coll);
clockie.print();


}


Clock::Clock(int hour, int minute):
    minutes_since_midnight_(60 * hour + minute) {
}
Org_clock::Org_clock(vector<int> sets):
sanghun(sets){}

void Org_clock::print(){
    sort(sanghun.begin(), sanghun.end());
    for (int j=0; j < sanghun.size(); j++){
        cout<< j+1 << "Clock : " << sanghun[j] / 60<< ":" << sanghun[j] % 60 <<endl;
    }
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
int Clock::fetch() const {
    return minutes_since_midnight_;
}


int Clock::fetch_minutes() const {
    return minutes_since_midnight_ % 60;
}

int Clock::organizer() {
clock.push_back(fetch_hour());
clock.push_back(fetch_minutes());
collection.push_back(clock);


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
