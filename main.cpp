#include <iostream>
#include <iomanip>
using namespace std;


class GameMange{
private:
    string player1;
    string player2;
    int pl1_wins = 0;
    int pl2_wins = 0;
    int coins = 0;
    int turn = 1;

public:
    int get_coins(){
        return coins;
    }

    void print_info(){
        cout << "Player: " << player1 << " number wins: " << pl1_wins << "\n";
        cout << "Player: " << player2 << " number wins: " << pl2_wins << "\n";
    }

    void add_players(string &pl1, string &pl2){
        player1 = pl1;
        player2 = pl2;
    }

    void reset_game(){
        coins = 0;
        turn = 1;
    }

    bool check_win(){
        if (coins >= 100){
            return true;
        }
        else{
            return false;
        }
    }

    void add_play(int num_coins){
        coins += num_coins;
        if(not check_win()){
            turn++;
        }
    }

    string get_turn(){
        if (turn % 2 == 0){
            return player2;
        }
            return player1;
    }

    void add_win(){
        if (get_turn() == player1){
            pl1_wins++;
        }
        else{
            pl2_wins++;
        }}
};


class FrontEnd{
private:
    GameMange mange;
    static void start_menu(){
        cout << setw(30) << "Welcome to 100 game!!\n";
        cout << "Players add coins trying to reach 100 coins\n";
        cout << setw(35) <<"players can add from 1-10 coins\n";
        cout << setw(41) << "player who gets to 100 coins first wins\n";
    }

    void get_players_menu(){
        string player1, player2;
        cout << "\nEnter player 1 name:"; cin >> player1;
        cout << "Enter player 2 name:"; cin >> player2;
        mange.add_players(player1, player2);
    }

    void print_coins_turn(){
        cout << "\nCoins = " << mange.get_coins();
        cout << "\nPlayer " << mange.get_turn() << " turn\n";
    }

    void take_coins(){
        int coins;
        while (true){
            cout << "Enter coins from (1-10):"; cin >> coins;
            if (0 < coins && coins < 11) {
                mange.add_play(coins);
                return;
            }
            cout << "Invalid input! please try again.\n";

        }
    }

    void winner_menu(){
        string player = mange.get_turn();
        cout << "\nPlayer " << player << " has won!!\n";
        mange.add_win();
    }

    int game_menu(){
        cout <<"\n  **Game menu**\n";
        cout << "1) start another game\n"
                "2) print game score\n"
                "3) Exit game\n"
                "Enter choice from (1-3):";
        int choice;
        cin >> choice; cout << endl;
        if (0 < choice && choice < 4){
            return choice;
        }
        else {
            cout << "Invalid choice!!";
            return game_menu();
        }
    }

public:
    void run(){
        start_menu();
        get_players_menu();

        while (true){
            print_coins_turn();
            take_coins();

            if(mange.check_win()) {
                winner_menu();
                mange.reset_game();

                int choice;
                do {
                    choice = game_menu();
                    if (choice == 1)
                        continue;
                    else if (choice == 2)
                        mange.print_info();
                    else
                        return;
                } while (choice == 2);
            }
        }

    }
};

int main(){
    FrontEnd game;
    game.run();
}
