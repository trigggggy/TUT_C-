//hung.nguyen@student.tut.fi - student id: 272585
//sanghun.2.lee@student.tut.fi - student id: 272571
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "splitter.hh"
#include "market.hh"

/*The input file is read in the constructor of the 'market' class
 * in the class, there is a map of chains and a boolean value to tell
 * if the input file is read successfully.
 */
market::market(){
    inputRead_ = true;
    ifstream inputFile("products.txt");
    if(!inputFile){
        cout<<"Error: the input file can not be read."<<endl;
        inputRead_ = false;
    }
    else{
        string line;
        while(getline(inputFile,line)){
            if(line.find(' ') != string::npos){
                cout<<"Error: the input file can not be read."<<endl;
                inputRead_ = false;
                break;
            }
            vector<string> vec = split(line,';');
            if(vec.size() != 4){
                cout<<"Error: the input file can not be read."<<endl;
                inputRead_ = false;
                break;

            }
            double d = stod(vec.at(3));
            chains1[vec.at(0)][vec.at(1)][vec.at(2)] = d;
        }
        inputFile.close();
    }
}

/*return the boolean value: true if the input file is read successfully
 *and false otherwise.
 */
bool market::inputRead() const{
    return inputRead_;
}

/*print out all the chains available in the input file
 */
void market::getChains() const{
    for(auto chain : chains1){
        cout<<chain.first<<endl;
    }
}

/*print out all the stores of the chain whose name is passed as the string
 * parameter for the function
 */
void market::getChainStores(string chainName) const{
    bool found = false;
    for(auto chain : chains1){
        if(chain.first == chainName){
            found = true;
            for(auto store: chain.second){
                cout<<store.first<<endl;
            }
        }
    }
    if(!found)  cout<<"Error: chain not found."<<endl;
}

/*print out all the chain-stores where the cheapest price of a product is found.
 *The function takes the name of the product as the string parameter
 */
void market::getCheapest(string productName)const{
    double cheapest = numeric_limits<double>::max();
    bool foundProduct = false;
    for(auto chain: chains1){
        for(auto store: chain.second){
            for(auto product: store.second){
                if(product.first == productName){
                    foundProduct = true;
                    if(product.second < cheapest){
                        cheapest = product.second;

                    }
                }
            }
        }
    }
    if(!foundProduct)  cout<<"This product is not available anywhere."<<endl;
    else{
        cout<<fixed<<setprecision(2)<<cheapest<<endl;

        for(auto chain: chains1){
            for(auto store: chain.second){
                for(auto product: store.second){
                    if(product.first == productName){
                        if(product.second  == cheapest){
                            cout<<chain.first<<" "<<store.first<<endl;
                        }
                    }
                }
            }
        }
    }
}

/*print out all the products of a store of a chain. the function takes the name of the
 * chain and the store as string-parameters
 */
void market::getStoreProducts(string chainName, string storeName) const{
    bool foundChain = false;
    bool foundStore = false;
    for(auto chain : chains1){
        if(chain.first==chainName){
            foundChain = true;
            for(auto store:chain.second){
                if(store.first == storeName){
                    foundStore = true;
                    for(auto product : store.second){
                        cout<<product.first<<" "<<fixed<<setprecision(2)<<product.second<<endl;
                    }
                }
            }
        }
    }
    if(!foundChain) cout<<"Error: chain not found."<<endl;
    else{
        if(!foundStore) cout<<"Error: store not found."<<endl;
    }
}
