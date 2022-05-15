#include <vector>
#include <string>
#include <iostream>

using namespace std;


//a minta.txt be van példa amit belehet másolni ha nem akarja begépelni
int main() {
    vector<pair<string, string>> rules;
    vector<pair<pair<char, char>, int>> talalkozasok;
    string rule, key, value, szabaly_betuk;
    int i;
    string start = "S#";
    string result = "";
    std::size_t found;
// ebben a blokban történik a szabályok felvétele
    cout << "Addja meg a szabályokat, ha megadtamindet akkor írjin 'stop'-ot a bevitel megszakitására:\n";
    while(cin>>rule) {
        if(rule == "stop") // megállítja a bevitelt
            break;
        key = value = "";
        i = 0;
        while(rule[i] != '-') { // bal oldala 
            key += rule[i];
            i++;
        }
        i += 2;
        while(i < rule.size()) { // jobb oldala
            value += rule[i];
            i++;
        }
        found = szabaly_betuk.find(key); 
        if(found == std::string::npos)
            szabaly_betuk += key;
        rules.push_back(pair<string, string>(key, value)); // felvétel egy map -be, azér esett erra a választás mert kulcs érték párokat lehet benne tárolni
    }
// idáig tart ez a blokk

    for(i = 0; i < rules.size(); i++) {
        if(islower(rules[i].second[0])) {// a találkozások lekezelése
            talalkozasok.push_back(pair<pair<char, char>, int>(pair<char, char>(rules[i].first[0], rules[i].second[0]), i)); 
            for(int j = 0; j < rules.size(); j++) {
                if(rules[j].second[0] == rules[i].first[0]) {
                    talalkozasok.push_back(pair<pair<char, char>, int>(pair<char, char>(rules[j].first[0], rules[i].second[0]), j));
                }
            }
        }
    }

//ebben a blokban a táblázat szimulálása történik
    bool van = false, talalt = true;
    while(talalt){ // amíg igaz addig 
        talalt = false;
        for(i = 0; i < talalkozasok.size(); i++){ // végig megyünk a talalkozasok map -en, mindenegyes elemére
            for(int j = 0; j < rules.size(); j++) { // megnézzük azonbelűl mindeneggyes szabályt
                van = false; // találathoz szükséges vaáltozó
                if(rules[j].second[0] == talalkozasok[i].first.first) {
                    for(int k = 0; k < talalkozasok.size(); k++) {
                        if(talalkozasok[k].first.first == rules[j].first[0] && talalkozasok[k].first.second == talalkozasok[i].first.second) 
                            van = true; 
                    }
                    if(!van){
                        talalkozasok.push_back(pair<pair<char, char>, int>(pair<char, char>(rules[j].first[0], talalkozasok[i].first.second), j));
                        talalt = true;
                    }
                }
            }
        }
    }

    for(i = 0; i < talalkozasok.size(); i++){  // a mellékelt minta.jpg be látható a kiíratás 
        cout << talalkozasok[i].first.first << '+' << talalkozasok[i].first.second << '=' << talalkozasok[i].second << '\n'; // kiíratás
    }
// idáig tart a táblázat

    cout << "\nSzabályok:\n";
    for(i = 0; i < rules.size(); i++)
        cout << rules[i].first << "->" << rules[i].second << "  Sorszám: " << i+1 << '\n';
    
    cout << "\nAdja meg a vizsgálandó szót: "; 
    string word;
    cin >> word;
    word += "#"; // szó végét jelző szimbolúm
    
    while (start[0] != '#' || word[0] != '#'){ // adíg megy amíg nem egyenlő a szó végét jelölő '#' szimbólummal
        talalt = false;
        if(start[0] == word[0]){
            start.erase(start.begin());
            word.erase(word.begin());
            result += "pop ";
            continue;
        }
// ebben a blokkban vizsgáljuk meg a levezetés menetét 
// végig megyünk a táblázaton 
        for(i = 0; i < talalkozasok.size(); i++) {
            if(talalkozasok[i].first.second == word[0] && talalkozasok[i].first.first == start[0]) {
                start.replace(start.begin(), start.begin()+1, rules[talalkozasok[i].second].second);
                cout << word << '\n';
                result += '(' + rules[talalkozasok[i].second].second + ", " + to_string(talalkozasok[i].second+1) + ") "; // kigyűjtjük a lépéseket ezeket ha accept be jutottunk felhasználjuk
                talalt = true;
            }
        }
        if(!talalt) {
            cout << "A szó nem levezethető.";
            return 0;
        }
    }

    cout << "A szó az alábbi szabályok alkalmazásával vezethető le: " << result << '\n'; // és végűl itt kiíratjuk
}