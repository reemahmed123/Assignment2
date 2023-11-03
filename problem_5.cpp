#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Player {
    string name;
    int score;
};

// Comparator function used to sort players by score in descending order
bool compareByScore(const Player& player1, const Player& player2)
{
    return player1.score > player2.score;
}

int main() {
    vector<Player> players;
    const int MAX_PLAYERS = 10;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a player and score\n";
        cout << "2. Print top 10 names and scores\n";
        cout << "3. Check player's highest score\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int score;
                cout << "Enter player name: ";
                cin >> name;
                cout << "Enter score: ";
                cin >> score;

                Player player;
                player.name = name;
                player.score = score;

                if (players.size() < MAX_PLAYERS) {
                    players.push_back(player);
                } else {
                    // Find the player with the smallest score
                    auto minPlayer = min_element(players.begin(), players.end(),
                        [](const Player& player1, const Player& player2) {
                            return player1.score < player2.score;
                        });

                    // Replace the player with the smallest score
                    *minPlayer = player;
                }

                  cout << "Player added!\n";
                break;
            }

            case 2: {
                // Sort the players by score in descending order
                std::sort(players.begin(), players.end(), compareByScore);

                 cout << "Top 10 names and scores:\n";
                for (int i = 0; i < players.size(); ++i) {
                     cout << players[i].name << " " << players[i].score << "\n";
                }
                break;
            }

            case 3: {
                 string playerName;
                 cout << "Enter player name: ";
                 cin >> playerName;

                bool found = false;
                int highestScore = 0;

                for (const Player& player : players) {
                    if (player.name == playerName) {
                        found = true;
                        if (player.score > highestScore) {
                            highestScore = player.score;
                        }
                    }
                }

                if (found) {
                    cout << "Player's highest score: " << highestScore << "\n";
                } else {
                    cout << "Player not found or not in the top 10.\n";
                }
                break;
            }

            case4:{
                 cout << "Exiting the program.\n";
                return 0;
            }

            default:
                    cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "\n";
    }
}