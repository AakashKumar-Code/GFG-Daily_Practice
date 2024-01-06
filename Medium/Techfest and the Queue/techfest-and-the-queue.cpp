//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    unordered_map<int, int>mpp;
    vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

void solve(int num, const vector<int>& primes) {
    for (int prime : primes) {
        while (num % prime == 0) {
            mpp[prime]++;
            num /= prime;
        }
    }

    if (num > 1) {
        mpp[num]++;
    }
}

int sumOfPowers(int a, int b) {
    int limit = sqrt(b);
    vector<int> primes = generatePrimes(limit);

    for (int i = a; i <= b; i++) {
        solve(i, primes);
    }

    int sum = 0;
    for (auto &it : mpp) {
        sum += it.second;
    }

    return sum;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends