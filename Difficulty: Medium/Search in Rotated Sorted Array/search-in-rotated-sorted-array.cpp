//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
    int n = arr.size();
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == key) {
            return mid;  // If key is found at mid, return mid
        }
        if (arr[lo] <= arr[mid]) {  // Left half is sorted
            if (arr[lo] <= key && key < arr[mid]) {
                hi = mid - 1;  // Key is in the left half
            } else {
                lo = mid + 1;  // Key is in the right half
            }
        } else {  // Right half is sorted
            if (arr[mid] < key && key <= arr[hi]) {
                lo = mid + 1;  // Key is in the right half
            } else {
                hi = mid - 1;  // Key is in the left half
            }
        }
    }
    return -1;  // Key not found
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends