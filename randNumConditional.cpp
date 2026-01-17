/* Your program should then generate this number of events. For each 
event, you should generate a random number between 1 and 6. 
If the number now generated is 1, then the first team has scored a goal. If it 
is 2, then the second team has scored a goal.
 If the number is 3, the first team has committed an offside, and if it is a 4 
then the second team has committed an offside.
 If the number is 5, the first team gets a penalty, and if it is 6, the second 
team gets a penalty. To decide the outcome of the penalty, your program 
should generate another random number between 1 and 4. If this number 
is 1, the team scores from the penalty, if it is 2, they miss the penalty, a 3 
means they get a yellow card, and a 4 means a red card for the team. 
For each event generated, your program should output a statement giving 
a commentary on that event, such as “Team 1 scored a goal”. At the end 
of the program, you should print out the final score of the game. At the 
start of your main function seed the random number generator with the 
current time using the command srand(time(NULL));*/
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

//Function to generate random integer in range (min, max)
int getRandomNumber(int min, int max) {
    static mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int main() {
    int team1Score = 0;
    int team2Score = 0;

    // Number of events in the game (1-15)
    int numberOfEvents = getRandomNumber(1, 15);

    cout << "Number of events in the game: " << numberOfEvents << endl << endl;

    for (int i = 1; i <= numberOfEvents; ++i) {
        int event = getRandomNumber(1, 6);
        cout << "Event " << i << ": ";

        switch (event) {
            case 1:
                team1Score++;
                cout << "Team 1 scored a goal!" << endl;
                break;
            case 2:
                team2Score++;
                cout << "Team 2 scored a goal!" << endl;
                break;
            case 3:
                cout << "Team 1 committed an offside." << endl;
                break;
            case 4:
                cout << "Team 2 committed an offside." << endl;
                break;
            case 5: {
                cout << "Team 1 gets a penalty! ";
                int penaltyOutcome = getRandomNumber(1, 4);
                switch (penaltyOutcome) {
                    case 1:
                        team1Score++;
                        cout << "They score from the penalty!" << endl;
                        break;
                    case 2:
                        cout << "They miss the penalty." << endl;
                        break;
                    case 3:
                        cout << "They receive a yellow card." << endl;
                        break;
                    case 4:
                        cout << "They receive a red card!" << endl;
                        break;
                }
                break;
            }
            case 6: {
                cout << "Team 2 gets a penalty! ";
                int penaltyOutcome = getRandomNumber(1, 4);
                switch (penaltyOutcome) {
                    case 1:
                        team2Score++;
                        cout << "They score from the penalty!" << endl;
                        break;
                    case 2:
                        cout << "They miss the penalty." << endl;
                        break;
                    case 3:
                        cout << "They receive a yellow card." << endl;
                        break;
                    case 4:
                        cout << "They receive a red card!" << endl;
                        break;
                }
                break;
            }
          }
          }

    cout << "\n Final Score **" << endl;
    cout << "Team 1: " << team1Score << endl;
    cout << "Team 2: " << team2Score << endl;

    if (team1Score > team2Score) {
        cout << "Team 1 wins!" << endl;
    } else if (team2Score > team1Score) {
        cout << "Team 2 wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

 return 0;
}
