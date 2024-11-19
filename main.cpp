#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct problem {
    std::string id;
    std::string specialitate;
    int durata;
    bool rezolvat = false;
};

struct doctor {
    std::string id;
    std::string specialitate;
    int timpdelucru = 8;

};

int main() {
    ifstream inFile("input4_bonus.txt");
    int no_problems, no_doctors;
    inFile >> no_problems;
    std::vector<problem> probleme(no_problems);

    for (int i = 0; i < no_problems; i++) {
        inFile >> probleme[i].id;
        inFile >> probleme[i].specialitate;
        inFile >> probleme[i].durata;
    }
    inFile >> no_doctors;
    std::vector<doctor> doctori(no_doctors);

    for (int i = 0; i < no_doctors; i++) {
        inFile >> doctori[i].id;
        inFile >> doctori[i].specialitate;
    }
    for (auto& iter : doctori) {

        std::vector<string> rezolvate;
        int problemerezolvate = 0;
        for (auto& iter2 : probleme) {
            std::vector<string> afecrez;
            if (!iter2.rezolvat && (iter.specialitate == iter2.specialitate) && (iter2.durata <= iter.timpdelucru)) {
                iter.timpdelucru = iter.timpdelucru - iter2.durata;
                iter2.rezolvat = true;
                problemerezolvate++;
                rezolvate.push_back(iter2.id);


            }
            if (iter.timpdelucru == 0)
                break;
        }
        cout << iter.id << " " << problemerezolvate << " ";
        for (int i = 0; i < rezolvate.size(); ++i) {
            cout << rezolvate[i] << " ";

        }
        cout << endl;

    }
    return 0;
}
/*problema de dinainte de bonus
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct problem {
    std::string id;
    std::string specialitate;
};

struct doctor {
    std::string id;
    std::string specialitate;
};

int main() {
    ifstream inFile("input.txt");
    int no_problems, no_doctors;
    inFile >> no_problems;
    std::vector<problem> probleme(no_problems);

    for (int i = 0; i < no_problems; i++) {
        inFile >> probleme[i].id;
        inFile >> probleme[i].specialitate;
    }

    inFile >> no_doctors;
    std::vector<doctor> doctori(no_doctors);

    for (int i = 0; i < no_doctors; i++) {
        inFile >> doctori[i].id;
        inFile >> doctori[i].specialitate;
    }

    for (auto problemiter : probleme) {
        bool accepted = false;
        

        for (auto it = doctori.begin(); it != doctori.end(); ++it) {
            if (problemiter.specialitate == it->specialitate) {

                std::cout << it->id << " " << problemiter.id << endl;
                accepted = true;
                doctori.erase(it);
                break;
            }
        }

    }

    return 0;
}

*/





