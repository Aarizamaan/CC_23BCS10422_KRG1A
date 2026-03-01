#include <bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0;   // use long long to avoid overflow

    // Iterate through all 32 bits
    for(int i = 0; i < 32; i++) {
        long long set = 0;
        long long unset = 0;

        for(int j = 0; j < n; j++) {
            if(arr[j] & (1 << i))
                set++;
            else
                unset++;
        }

        sum += 2LL * set * unset;
    }

    return sum;
}

int main() {
    vector<int> arr = {15, 10, 12};
    cout << totalHammingDistance(arr) << endl;
    return 0;
}