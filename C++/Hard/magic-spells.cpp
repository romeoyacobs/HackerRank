#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    if (spell != nullptr)
    {
        if (auto p = dynamic_cast<Fireball*>(spell)) {
            p->revealFirepower();
        } else if (auto p = dynamic_cast<Frostbite*>(spell)) {
            p->revealFrostpower();
        } else if (auto p = dynamic_cast<Waterbolt*>(spell)) {
            p->revealWaterpower();
        } else if (auto p = dynamic_cast<Thunderstorm*>(spell)) {
            p->revealThunderpower();
        } else {
            auto str1 = spell->revealScrollName();
            auto str2 = SpellJournal::read();

            auto m = str1.size() + 1;
            auto n = str2.size() + 1;

            vector<vector<int>>C(m, vector<int>(n));
            for (int i = 0; i < m; ++i)
            {
                C[i][0] = 0;
            }
            for (int j = 0; j < n; ++j) {
                C[0][j] = 0;
            }

            for (int i = 1; i < m; ++i)
            {
                for (int j = 1; j < n; ++j)
                {
                    if (str1[i-1] == str2[j-1])
                    {
                        C[i][j] = C[i-1][j-1] + 1;
                    }
                    else
                    {
                        C[i][j] = max(C[i][j-1], C[i-1][j]);
                    }
                }
            }

            printf("%d\n", C[m-1][n-1]);
        }
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}