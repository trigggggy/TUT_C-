//hung.nguyen@student.tut.fi - student id: 272585
//sanghun.2.lee@student.tut.fi - student id: 272571
#ifndef CLASS_HH
#define CLASS_HH
#include <map>
using namespace std;

using products = map<string,double>;
using stores = map<string,products>;
using chains = map<string, stores>;
class market{
public:
    market();
    bool inputRead() const;
    void getChains() const;
    void getChainStores(string chainName) const;
    void getCheapest(string productName) const;
    void getStoreProducts(string chainName, string storeName) const;


private:
    chains chains1;
    bool inputRead_;
};
#endif // CLASS_HH
