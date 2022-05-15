#include <vector>
#include <string>
#include <iostream>

using namespace std;

//a minta.txt be van példa amit belehet másolni ha nem akarja begépelni

int main() {
    vector<pair<string, string>> rules;
    string rule, key, value;
    int i;
    string start = "S#";
    string result = "";

    cout << "Addja meg a szabályokat, ha bevitte az öszes szabályt akkor írjon 'stop'-ot:\n";
    // ebbe a blokba történik a szabajok felvétele
    while(cin>>rule) {
        if(rule == "stop")  // leallírja a bekérést 
            break;
        key = value = "";
        i = 0;
        while(rule[i] != '-') {   // ball oldal
            key += rule[i];
            i++;
        }
        i += 2;
        while(i < rule.size()) { // jobb oldal a szabálynak
            value += rule[i];
            i++;
        }
        rules.push_back(pair<string, string>(key, value));
    }
// idáig tart, illetve jobb és bal oldal felvétele

    cout << "\nSzabályok:\n";
    for(i = 0; i < rules.size(); i++)
        cout << rules[i].first << "->" << rules[i].second << "  Sorszám: " << i+1 << '\n'; // ki iratjuk a felvett szabájokat indexel együtt, ami levezetésnél kell
    
    cout << "\nAdja meg a vizsgálandó szót: ";
    string word;
    cin >> word; // meg adjuk a keresendő szót
    word += "#"; //  a szó végére '#' helyezünk, mely jelzi annak végét majd
    
    while (start[0] != '#'){   // addig megyünk amíg elnem érjük a szö végét jelölő szimbolumot
        if(start[0] == word[0]){
            start.erase(start.begin()); 
            word.erase(word.begin());
            continue;
        }
// ebben a blokkban törtéénik a vizsgálat
        for(i = 0; i < rules.size(); i++) { 
            if(rules[i].first[0] == start[0]) // a baloldala a szabalynak
                if(rules[i].second[0] == word[0]) { // jobb oldala a szabálynak kerűl vizsgálatra
                    start.replace(start.begin(), start.begin()+1, rules[i].second); // ha megegyezik a szabályokbol az a keresett szó első karaktere elkezdi 'cserélgeti'
                    result += to_string(i+1); // hogy mely szabályokkal vezethető le itt tároljuk el az indexeiket 
                }
        }
    }

    cout << "Ezen szabályok alkalmazásával lehet levezetni a szót: " << result << '\n';
}