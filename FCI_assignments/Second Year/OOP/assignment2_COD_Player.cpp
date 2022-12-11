#include <bits/stdc++.h>
using namespace std;

class COD_Player {
private:
    string name;
    int id;
    int level;
    string user_name;
    string password;
    int shots;

    static int total_alive_players;
    static int total_died_players;
public:
    COD_Player() {
        total_alive_players++;

        int shots = 0;
    }

    COD_Player(string name, int id, int level,string user_name, string password) {
        this->name = name;
        this->id = id;
        this->level = level;
        this->user_name = user_name;
        this->password = password;

        this->shots = 0;
        total_alive_players++;
    }


    void fire() {
        this->shots++;

        total_alive_players--, total_died_players++;

        cout << "Someone was killed!\n";
    }

    static int get_alive() {
        return total_alive_players;
    }
    static int get_dead() {
        return total_died_players;
    }

    ~COD_Player() {
        cout << "the player is died and removed from the server\n";
        total_died_players++;
    }
};


int COD_Player::total_alive_players = 0;
int COD_Player::total_died_players = 0;

int main() {
    COD_Player* player1 = new COD_Player("hussein", 10, 1,"hussein_hany", "mypassword");
    cout << "Alive : " << player1->get_alive() << " Dead : " << player1->get_dead() << endl;

    COD_Player player2;

    player2.fire();
    cout << "Alive : " << player1->get_alive() << " Dead : " << player1->get_dead() << endl;
    return 0;
}