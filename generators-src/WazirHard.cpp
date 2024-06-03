#include <bits/stdc++.h>
using namespace std;
const int BUF_SZ = 5e6;
inline namespace Output {
char buf[BUF_SZ];
int pos;

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
    int subtask = stoi(argv[1]);
    srand(stoi(argv[2]));
    int t = subtask == 1 ? 2e5:1e6;
    int lim = 1e9;
    init_output();
    write_int(t);
    write_char('\n');
    while(t--){
        for(int i = 0; i<4; i++){
            write_int(rand()%lim);
            write_char(' ');
        }
        write_char('\n');
    }
}