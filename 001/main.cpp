#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    long long prefixSum = 0;
    long long minVal = LLONG_MAX, maxVal = LLONG_MIN;
    

    for (int j = 0; j < N; j++){
        prefixSum += A[j];

        long long cur = A[j] - (j + 1);
        minVal = min(minVal, cur);
        maxVal = max(maxVal, cur);
        
        int day = j + 1; 
        long long youngest = day + minVal;
        long long oldest   = day + maxVal;
        
        
        double totalAge = prefixSum + (day * (day - 1LL)) / 2.0;
        double average = totalAge / day;
        
        cout << youngest << " " << oldest << " " << fixed << setprecision(4) << average << "\n";
    }
    
    return 0;
}
