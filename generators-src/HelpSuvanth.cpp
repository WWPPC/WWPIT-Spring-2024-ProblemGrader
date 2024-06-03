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

void write_ll(long long x){
    static char num_buf[20];
    if(x<0){
        write_char('-');
        x*=-1;
    }
    int len = 0;
    for(; x>=10; x/=10) num_buf[len++] = (char)('0'+(x%10));
    write_char((char)('0'+x));
    while(len) write_char(num_buf[--len]);
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output
void gen1(int t, long long l, long long r, int sub, int file) {
    write_int(t);
    write_char('\n');
    while(t--) {
        long long a = rand()*(long long)rand()%(r-l+1)+l;
        long long b = rand()*(long long)rand()%(r-l+1)+l;
        if (a > b) swap(a, b);
        write_ll(a);
        write_char(' ');
        write_ll(b);
        write_char('\n');
    }
}

void gen2(int t, long long r, int sub, int file) {
    write_ll(t);
    write_char('\n');
    while (t--) {
        long long a = rand()*(long long)rand()%r + 1;
        write_ll(a);
        write_char(' ');
        write_ll(a);
        write_char('\n');
    }
}
int main(int argc, char* argv[]){
    assert(argc == 3);
    int subtask = stoi(argv[1]);
    srand(stoi(argv[2]));
    init_output();
    if(subtask == 2)
        gen1(100000, 1, 1e18, 2, 1);
    else
        //subtask 1
        gen2(100000, 1e18, 1, 1);
}