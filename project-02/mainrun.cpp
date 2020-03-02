//hung.nguyen@student.tut.fi - student id: 272585
//sanghun.2.lee@student.tut.fi - student id: 272571
#include <iostream>
#include "market.hh"
#include "mainrun.hh"
#include "splitter.hh"


void mainRun(market m){

    while(1){
        string line;
        cout<<"product search> ";
        getline(cin,line);
        if(line == "quit" ){        
            break;
        }else if(line == "chains"){
            m.getChains();
        }else{
            vector<string> vec  = split(line,' ');
            if(vec.at(0) == "cheapest"){
                if(vec.size() != 2){
                    cout<<"Error: require 1 parameter after \"cheapest\"."<<endl;
                }else{
                    m.getCheapest(vec.at(1));
                }
            }else if(vec.at(0) =="stores"){
                if(vec.size() != 2){
                    cout<<"Error: require 1 parameter after \"stores\"."<<endl;
                }else{
                    m.getChainStores(vec.at(1));
                }
            }else if(vec.at(0) == "selection") {
                if(vec.size() != 3){
                    cout<<"Error: require 2 parameters after \"selection\"."<<endl;
                }else{
                    m.getStoreProducts(vec.at(1),vec.at(2));
                }
            }else{
                cout<<"Error: unknown command."<<endl;
            }
        }
    }
}
