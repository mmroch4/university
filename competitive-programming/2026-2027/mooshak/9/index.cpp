#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

int N, K;

multiset<int> lower;
multiset<int> higher;
vector<int> values;

long long lowerSum = 0;
long long higherSum = 0;

int getSize(multiset<int>& m) {
    return (int)m.size();
}

void add(int i) {
    int value = values[i];
    
    if (value >= *lower.rbegin()) {
        higher.insert(value);
        higherSum += value;
    }
    else {
        lower.insert(value);
        lowerSum += value;
    }
}

void rebalance() {
    int diff = getSize(higher) - getSize(lower);

    if (diff == 0 || diff == -1) {
        return;
    }
    else if (diff == -2) {
        auto it = --lower.end();
        lowerSum -= *it;
        higherSum += *it;
        higher.insert(*it);
        lower.erase(it);
        return;
    }
    else if (diff == 1 || diff == 2) {
        auto it = higher.begin();
        higherSum -= *it;
        lowerSum += *it;
        lower.insert(*it);
        higher.erase(it);
        return;
    }
    else {
        throw invalid_argument("A DIFERENÇA É MAIOR DO QUE |2|: " + to_string(diff));
    }
}

long long getCost() {
    int median = *lower.rbegin();
    return getSize(lower) * median - lowerSum + higherSum - getSize(higher) * median;
}

void remove(int i) {
    auto it = lower.find(values[i]);
    bool isHigher = false;
    
    if (it == lower.end()) {
        it = higher.find(values[i]);
        isHigher = true;
    }

    if (isHigher && it == higher.end()) {
        throw invalid_argument("O VALOR NAO EXISTE EM NENHUM DOS DOIS SETS: " + to_string(values[i]) + "  -  " + to_string(i));
    }

    if (isHigher) {
        higherSum -= *it;
        higher.erase(it);
    }
    else {
        lowerSum -= *it;
        lower.erase(it);
    }
}

int main() {
    cin >> N >> K;

    values.resize(N);

    for (int i = 0; i < N; i++) cin >> values[i];

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            cout << 0 << " ";
        }

        cout << "\n";

        return 0;
    }

    lower.insert(values[0]);
    lowerSum += values[0];

    for (int i = 1; i < K; i++) {
        add(i);

        rebalance();
    }

    cout << getCost() << " ";

    for (int i = K; i < N; i++) {

        // cout << "reading index: " << i << "\n";
        remove(i - K);

        rebalance();

        add(i);

        rebalance();

        cout << getCost() << " ";
    }

    cout << "\n";
}