#include <iostream>
#include <iomanip>

using namespace std;
int arr_1[10];
int arr_2[10];
int arr_ans[10];

void cmp(int a, int b, int &c) {
    asm(
            ".intel_syntax noprefix         \n"
            "mov eax, %1                    \n"
            "mov ebx, %2                    \n"
            "cmp eax, ebx                   \n"
            "ja abo                         \n"
            "jb bel                         \n"
            "abo:\n mov %0, eax \n jmp sk   \n"
            "bel:\n mov %0, ebx             \n"
            "sk: .att_syntax                \n"
            : "=r" (c)
            : "r" (a), "r" (b)
            : "cc"
        );
} 

int main() {
    for (int i = 0; i < 10; i++) {
        arr_1[i] = rand() % 11;
        arr_2[i] = rand() % 11;
        cmp(arr_1[i], arr_2[i], arr_ans[i]);
        cout << arr_1[i] << setw(5) << arr_2[i] << setw(5) << arr_ans[i] << endl;
    }
}
