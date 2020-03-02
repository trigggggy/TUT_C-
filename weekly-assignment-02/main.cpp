#include <iostream>
#include <iomanip>

using namespace std;


class TimeCalc {
    public:
        void calc(float _first, float _last);
        bool check(float tim);
        int diff;
    private:
        int hour;
        int min;
        int hour_;
        int min_;



};


int main() {
    float first=0.00;
    float last=0.00;
    TimeCalc Time;
    cout<<"enter the beginning of the time form of 'hour'.'min'"<<endl;
    cin>>first;
    while(!Time.check(first)){
        cout<<"wrong value";
        cout<<"enter the beginning of the time form of 'hour'.'min'"<<endl;
        cin>>first;
    }
    cout<<"enter the final time form of 'hour'.'min'";
        cin>>last;
    while(!Time.check(last)){
        cout<<"wrong value";
        cout<<"enter the final of the time form of 'hour'.'min'"<<endl;
        cin>>last;
    }
    Time.calc(first, last);
    cout<<Time.diff<<endl;

}

bool TimeCalc::check(float tim){
    int hr;
    float m;
    hr = tim/1;
    m = (tim-hr)*100;
    int _m = m/1;
    int val_m = m-_m;
cout<<hr<< "and" << val_m<<endl;
    if(hr<=24 && m-_m>=0 && m<=60 && tim>0){
    return true;
}else{
        return false;
    }

}

void TimeCalc::calc(float first_, float last_){
    hour = first_/1;
    (hour==0)? hour=24:hour=(int)hour;
    min = (first_-hour)*100;
    hour_ = last_/1;
    (hour_==0)? hour_=24:hour_=(int)hour_;
    min_ = (last_-hour_)*100;

    diff = min_+hour_*60-min-hour*60;
}

/*
void TimeCalc::calc(){
    string delimiter=".";
    int i;
    size_t pos = 0;
    string token;
    while ((pos = first_.find(delimiter)) != std::string::npos) {
        token = first_.substr(0, pos);
        _time[i]=stoi(token);
        i++;
        first_.erase(0, pos + delimiter.length());
    }
        int min_ = stoi(first_);
    _total = _time[0] * 60;
        cout<<_total<<endl;
    _total += min_;
    cout<<_total<<endl;


}
*/
