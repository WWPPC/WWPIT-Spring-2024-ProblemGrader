#include <bits/stdc++.h>
using namespace std;
int randint(int a, int b){
    return rand()%(b-a+1)+a;
}

// const int BUF_SZ = 5e6;
// inline namespace Output {
// char buf[BUF_SZ];
// int pos;

// void flush_out() {
// 	fwrite(buf, 1, pos, stdout);
// 	pos = 0;
// }

// void write_char(char c) {
// 	if (pos == BUF_SZ) { flush_out(); }
// 	buf[pos++] = c;
// }

// void write_int(int x) {
// 	static char num_buf[12];
// 	if (x < 0) {
// 		write_char('-');
// 		x *= -1;
// 	}
// 	int len = 0;
// 	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
// 	write_char((char)('0' + x));
// 	while (len) { write_char(num_buf[--len]); }
// }

// // auto-flush output when program exits
// void init_output() { assert(atexit(flush_out) == 0); }
// }  // namespace Output

int nums[1001][1001];
int main(int argc, char* argv[]){
    assert(argc == 3);
    int subtask = stoi(argv[1]);
    srand(stoi(argv[2]));
    // init_output();
    int mn = subtask == 1 ? 100 : 1000;
    int m = randint(mn-5, mn), n = randint(mn-5, mn);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nums[i][j] = i+1;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n-1; i++) {
            swap(nums[i][j], nums[i + 1 + randint(0, n-i-2)][j]);
        }
    }
    cout << n << ' ' << m << '\n';
    // write_int(n);
    // write_char(' ');
    // write_int(m);
    // write_char('\n');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << nums[i][j];
            // write_int(nums[i][j]);
            if(j != m-1) cout << ' ';//write_char(' ');
        }
        cout << '\n';
        // write_char('\n');
    }
}