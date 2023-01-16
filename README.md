# Continuous-time-Markov-Chain

A Continuous-time Markov Chain is a type of Markov Chain where the time between transitions is modeled by a probability distribution, rather than being fixed. The probability of transitioning from one state to another in a continuous-time Markov chain is given by the following formula:

P(X(t+dt) = j | X(t) = i) = λ_i * dt + o(dt)

where λ_i is the rate of transition from state i to state j, dt is a small time interval and o(dt) is an infinitesimal term.

In C++, a continuous-time Markov Chain can be simulated using the Gillespie algorithm, which is a stochastic algorithm that simulates the transitions of the chain. The algorithm works by randomly selecting the next transition based on the transition rates, and updating the time accordingly.

Here is an example of how to simulate a continuous-time Markov Chain in C++ using the Gillespie algorithm:

```
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
```

This code defines a continuous-time Markov Chain with 2 states and a total time of 10. Using the Gillespie algorithm, the code simulates the transitions of the chain by randomly selecting the next transition based on the transition rates, and updating the time accordingly. The final state after the simulation is printed at the end.

It's important to note that the transition rate matrix should have negative values on the diagonal, and positive values on the off-diagonal entries, as this represents the rate at which the chain is leaving one state and entering another.

