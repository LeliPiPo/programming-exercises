/*  9. The following problem is sometimes called “The Monty Hall Game Show 
Problem.” You are a contestant on a game show and have won a shot at the 
grand prize. Before you are three closed doors. Behind one door is a brand 
new car. Behind the other two doors are consolation prizes. The location 
of the prizes is randomly selected. The game show host asks you to select a 
door, and you pick one. However, before revealing the contents behind your 
door, the game show host reveals one of the other doors with a consolation 
prize. At this point, the game show host asks if you would like to stick with 
your original choice or switch your choice to the other closed door. What 
choice should you make to optimize your chances of winning the car? Does 
it matter whether you stick with your original choice or switch doors?
 Write a simulation program to solve the game show problem. Your program 
should make 10,000 simulated runs through the problem, randomly 
selecting locations for the prize, and then counting the number of times the 
car was won when sticking with the original choice, and counting the number 
of times the car was won when switching doors. Output the estimated 
probability of winning for both strategies. Be sure that your program exactly 
simulates the process of selecting the door, revealing one, and then switching. 
Do not make assumptions about the actual solution (for example, simply 
assuming that there is a 1/3 or 1/2 chance of getting the prize).*/

#include <iostream>
#include <random> //new version of crandom
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3); //for picking doors

    int stickWins = 0, switchWins = 0;
    int simulations = 10000;

    for (int i = 0; i < simulations; ++i) {
        int carDoor = dist(gen);
        int playerPick = dist(gen);

        //determine host options
        int hostOptions[2];
        int count = 0;
        for (int door = 1; door <= 3; ++door) {
            if (door != playerPick && door != carDoor) {
                hostOptions[count++] = door;
            }
        }

        //host picks a door to open
        uniform_int_distribution<> hostDist(0, count - 1);
        int hostOpens = hostOptions[hostDist(gen)];

        //player sticks or switches
        int switchPick;
        for (int door = 1; door <= 3; ++door) {
            if (door != playerPick && door != hostOpens) {
                switchPick = door;  //only one door left
                break;
            }
        }

        if (playerPick == carDoor) ++stickWins;
        if (switchPick == carDoor) ++switchWins;
    }

    cout << "After " << simulations << " simulations:\n";
    cout << "Wins by sticking: " << stickWins << " (" << (stickWins * 100.0 / simulations) << "%)\n";
    cout << "Wins by switching: " << switchWins << " (" << (switchWins * 100.0 / simulations) << "%)\n";

    return 0;
}
