//hung.nguyen@student.tut.fi - student id: 272585
//sanghun.2.lee@student.tut.fi - student id: 272571
#include "splitter.hh"
#include "market.hh"
#include "mainrun.hh"

using namespace std;

int main()
{
    market m;
    if(m.inputRead()){
          mainRun(m);
    }
    return 0;
}
