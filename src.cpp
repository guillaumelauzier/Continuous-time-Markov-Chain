#include <iostream>
#include <random>
using namespace std;

const int N = 2; // Number of states
const int T = 10; // Total time

double transitionRates[N][N] = {
    {-1, 2},
    {1, -3}
};

int main() {
    int currentState = 0; // Initial state
    double time = 0; // Current time
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);
    while (time < T) {
        // Find the rate of transition from the current state
        double rate = 0;
        for (int i = 0; i < N; i++) {
            rate += transitionRates[currentState][i];
        }
        // Generate a random time interval
        double dt = -log(distribution(generator)) / rate;
        time += dt;
        // Update the state
        if (time > T) {
            break;
        }
        double cummulativeProbability = 0;
        double randomNumber = distribution(generator);
        for (int i = 0; i < N; i++) {
            cummulativeProbability += transitionRates[currentState][i] / rate;
            if (randomNumber < cummulativeProbability) {
                currentState = i;
                break;
            }
        }
    }
    // Print the final state
    cout << "Final state: " << currentState << endl;
return 0;
}
