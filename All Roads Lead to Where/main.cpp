#include <iostream>
#include <string>
#include <vector>

using namespace std;

class city{
public:
    string name;
    city* parent;
    vector<city*> child;
};

vector<city*> cityvec(0);

int invec(string str)
{
    for(int i = 0; i < cityvec.size(); i++)
        if(cityvec[i]->name == str) return i;
    return -1;
}

void pathtoRome(int ind, vector<string>& utoR)
{
    city* trav = cityvec[ind];
    while(1)
    {
        utoR.push_back(trav->name);
        if(trav->name == "Rome")
            return;
        trav = trav->parent;
    }
}

void findlca(vector<string> utoR, vector<string> vtoR, int& lca1, int& lca2)
{
    int uind = utoR.size()-1;
    int vind = vtoR.size()-1;
    while(1)
    {
        if(utoR[uind] != vtoR[vind])
        {
            lca1 = uind+1;
            lca2 = vind+1;
            return;
        }
        uind--;
        vind--;
    }
}

int main(){
    int n;
    cin >> n;
    while(n--)
    {
        int c, q;
        cin >> c >> q;

        while(c--)
        {
            string u, v;
            cin >> u >> v;
            int iu = invec(u);
            int iv = invec(v);
            if(iu == -1 && iv == -1)
            {
                city* temp1 = new city;
                city* temp2 = new city;
                temp1->name = u;
                temp1->parent = nullptr;
                temp1->child.push_back(temp2);
                temp2->name = v;
                temp2->parent = temp1;
                cityvec.push_back(temp1);
                cityvec.push_back(temp2);
            }
            else if(iu == -1 && iv != -1)
            {
                city* temp1 = new city;
                temp1->name = u;
                temp1->parent = nullptr;
                temp1->child.push_back(cityvec[iv]);
                cityvec[iv]->parent = temp1;
                cityvec.push_back(temp1);
            }
            else if(iu != -1 && iv == -1)
            {
                city* temp2 = new city;
                temp2->name = v;
                temp2->parent = cityvec[iu];
                cityvec[iu]->child.push_back(temp2);
                cityvec.push_back(temp2);
            }
            else if(iu != -1 && iv != -1)
            {
                cityvec[iu]->child.push_back(cityvec[iu]);
                cityvec[iv]->parent = cityvec[iu];
            }
        }
//        for(int i = 0; i < cityvec.size(); i++)
//        {
//            if(cityvec[i]->parent)
//            {
//                cout << cityvec[i]->name << ' ';
//                cout << cityvec[i]->parent->name << endl;
//            }
//        }
        while(q--)
        {
            string u, v;
            cin >> u >> v;
            int iu = invec(u);
            int iv = invec(v);
            vector<string> utoR(0);
            vector<string> vtoR(0);
            pathtoRome(iu, utoR);
            pathtoRome(iv, vtoR);

            int lcau, lcav;
            findlca(utoR, vtoR, lcau, lcav);

            for(int i = 0; i <= lcau; i++)
                cout << utoR[i][0];
            for(int i = lcav-1; i >= 0; i--)
                cout << vtoR[i][0];
            cout << endl;
        }
        if(n) cout << endl;
    }

    return 0;
}
