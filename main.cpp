#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
list<int> R;
map<int,list < pair <int, int> > > G;


void PrintGraph (map<int,list < pair <int, int> > > G)
{
    int key;
    list < pair <int, int> > val;
    for( auto const& x : G )
    {
        cout << x.first  << " : ";       
        for( auto const& i : x.second )
            cout  << i.first << " , " << i.second  << "; " ;    
        cout << std::endl ;
    }


}

void GetGraph()
{
    string strR;
    getline(cin, strR);
    istringstream is( strR );
    int n;
    int b = 0;
    while( is >> n ) {
        R.push_back(n);
        b++;
    }
    R.sort(); 
    int v1,v2,w;
    map<int,list < pair <int, int> > >::iterator it;
    while(cin >> v1 >> v2 >> w)
    {
        
        it = G.find(v1);
        if (it != G.end())
            G[v1].push_back(make_pair(v2,w));
        else 
        {
            list < pair <int, int> > novo;
            novo.push_back(make_pair(v2,w));
            G[v1] = novo; 
        }
    }

}

int main (int argc, char** argv)
{
    GetGraph();
    PrintGraph(G);


    return 0;
}