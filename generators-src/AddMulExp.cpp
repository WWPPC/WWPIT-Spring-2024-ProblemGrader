#include <bits/stdc++.h>
using namespace std;

int randint(int a, int b){
    return rand()%(b-a+1)+a;
}

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
int main(int argc, char* argv[]){
    assert(argc == 3);
    int subtask = stoi(argv[1]);
    srand(stoi(argv[2]));
    init_output();
    //subtasks 1 and 2 should be MANUAL
    int t = subtask==3?200:1e5;
    long long e18 = 1e18;
    t = randint(t-5, t);
    write_int(t);
    write_char('\n');
    while (t--) {
        long long n = rand()*(long long)rand()%e18 + 1;
        long long x = rand()*(long long)rand()%e18 + 1;
        int m = randint(1, 1e9);
        write_ll(n);
        write_char(' ');
        write_ll(x);
        write_char(' ');
        write_int(m);
        write_char('\n');
    }
}