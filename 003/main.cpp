#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    // Tumpukan (stack) untuk menyimpan buah bit,
    // di mana index 0 adalah bagian bawah dan index terakhir adalah puncak.
    vector<int> stack;
    stack.reserve(N);
    
    // pos[x] menyimpan indeks dari buah bit bernomor x dalam tumpukan.
    vector<int> pos(N + 1, 0);
    
    // Simulasi proses pemanenan
    for (int i = 1; i <= N; i++){
        // Letakkan buah bit i di atas tumpukan.
        stack.push_back(i);
        pos[i] = stack.size() - 1;
        
        // Dapatkan nilai A_i (ingat: array A 0-indexed)
        int target = A[i - 1];
        int swapIndex = pos[target]; // posisi buah bit dengan nomor target
        int topIndex = stack.size() - 1; // posisi buah bit yang baru ditambahkan
        
        // Lakukan pertukaran jika diperlukan
        if (swapIndex != topIndex) {
            swap(stack[swapIndex], stack[topIndex]);
            pos[stack[swapIndex]] = swapIndex;
            pos[stack[topIndex]] = topIndex;
        }
    }
    
    // Cetak tumpukan dari bawah ke atas
    for (int i = 0; i < N; i++){
        cout << stack[i] << " ";
    }
    return 0;
}
