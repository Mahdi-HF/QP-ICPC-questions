#include <bits/stdc++.h>
using namespace std;
#define not_found 1500

int search_set(vector < pair<string,int> > vect, string name) {
    for (auto it = vect.begin(); it != vect.end() ; it++) {
        pair <string,int> pr = *it;
        string st = pr.first;
        int num = pr.second;
        if (name == st)
            return num;
    }
    return not_found;
}

int main(){
    string str;
    vector < pair <string, int> > vect;
    while(getline(cin, str)) {
        // cout << str << endl;
        auto pos = str.find(" ");
        string inst = str.substr(0,pos);
        str = str.substr(pos+1);

        if (inst == "def") {
            auto pos2 = str.find(" ");
            string name = str.substr(0, pos2);
            str = str.substr(pos2 + 1);
            int num = stoi(str);

            if(search_set(vect, name) == not_found)
                vect.push_back(make_pair(name, num));
            else {
                for (auto it = vect.begin(); it != vect.end() ; it++) {
                    pair <string,int> pr = *it;
                    string st = pr.first;
                    if (name == st){
                        vect.erase(it);
                        vect.push_back(make_pair(name, num));
                    }
                }
            }
        }
        else if (inst == "calc")
        {
            int res = 0;
            string new_oper = "+";
            cout << str << " ";
            for (int i = 0;1; i++) {
                auto pos3 = str.find(" ");
                string name = str.substr(0, pos3);
                string oper = new_oper;
                new_oper = str.substr(pos3+1, 1);
                // cout << new_oper << endl;
                if (new_oper != "=") str = str.substr(pos3 + 3);
                // cout << "name is: " << name << endl;
                if (oper == "+"){
                    int number = search_set(vect, name);
                    // cout << res << " the number is:" << number << endl;
                    if (number != not_found)
                        res += number;
                    else {
                        cout << "unknown" << endl;
                        break;
                    }
                }
                if (oper == "-") {
                    int number = search_set(vect, name);
                    if (number != not_found)
                        res -= number;
                    else {
                        cout << "unknown" << endl;
                        break;
                    }
                }
                if (new_oper == "=") {
                    // cout << res << endl;
                    int flag = 0;
                    for(auto it = vect.begin(); it != vect.end(); it++) {
                        pair<string, int> pr = *it;
                        if(pr.second == res){
                            cout << pr.first << endl;
                            flag = 1;
                        }
                    }
                    if (flag == 0) cout << "unknown" << endl;
                    break;
                }
            }
        }
        else if (inst == "clear") {
            // for (auto it = vect.begin(); it != vect.end(); it++) {
            //     pair<string, int> pr = *it;
            //     cout << pr.first << "  " << pr.second << endl;
            // }
            vect.clear();
        }
    }
    return 0;
}