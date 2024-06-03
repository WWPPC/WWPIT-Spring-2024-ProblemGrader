#include <bits/stdc++.h>
#include "../jngen.h"
using namespace std;
const int BUF_SZ = 5e6;
inline namespace Output {
char buf[BUF_SZ];
int pos;

int randint(int a, int b){
    return rand()%(b-a+1)+a;
}

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) { flush_out(); }
	buf[pos++] = c;
}

void write_int(int x) {
	static char num_buf[12];
	if (x < 0) {
		write_char('-');
		x *= -1;
	}
	int len = 0;
	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
	write_char((char)('0' + x));
	while (len) { write_char(num_buf[--len]); }
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output
int main(int argc, char* argv[]){
    assert(argc == 3);
    registerGen(argc, argv); //jngen
    int subtask = stoi(argv[1]);
    srand(stoi(argv[2]));
    int maxl = subtask == 1 ? 1:1e9;
    int n = randint(1e5-10, 1e5);
    init_output();
    write_int(n);
    write_char('\n');
    jngen::Array arr = Array::randomUnique(2*n, 1e9).sorted();
    for (int i = 0; i < 2*n; i++) {
        write_int(randint(1, maxl));
        write_char(' ');
        write_int(arr[i]);
        write_char('\n');
    }
}