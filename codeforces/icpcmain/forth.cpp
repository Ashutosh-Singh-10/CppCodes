#include <iostream>
#include <string>

using namespace std;

int find_current_player_turn(int N, int K, string& history) {
    int current_player = 1;
    int direction = 1;  

    for (char card : history) {
        if (card == 'U') {
            current_player = (current_player + direction - 1+N) % N + 1;
        } 
        else if (card == 'S') {
            current_player = (current_player + 2 * direction - 1+N) % N + 1;
        } 
        else if (card == 'R') {
            direction *= -1;
            current_player = (current_player + direction - 1+N) % N + 1;
            
        }
    }

    return current_player;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, K;
        cin >> N >> K;

        string history;
        cin >> history;

        int result = find_current_player_turn(N, K, history);
        cout << result << endl;
    }

    return 0;
}