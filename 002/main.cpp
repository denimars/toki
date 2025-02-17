#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    // Jika ada dua bebek dengan tinggi yang sama, tidak mungkin tersusun secara strict ascending
    if(A == B || B == C || A == C) {
        cout << -1;
        return 0;
    }

    int swaps = 0;
    // Hitung jumlah inversi yang merupakan banyaknya pertukaran adjacent minimal
    if(A > B) swaps++;
    if(A > C) swaps++;
    if(B > C) swaps++;

    cout << swaps;
    return 0;
}