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
    int mx = stoi(argv[1]) == 1 ? 5e3:2e5;
    srand(stoi(argv[2]));
	init_output();
	int n = rand()%10+mx-9;
	int q = rand()%10+mx-9;
	write_int(n);
	write_char(' ');
	write_int(q);
	write_char('\n');
	for(int i = 0; i<n; i++){
		write_int(rand()%mx+1);
		write_char(' ');
	}
	write_char('\n');
	while(q--) if(rand()&1){
		write_char('1');
		write_char(' ');
		write_int(rand()%n+1);
		write_char(' ');
		write_int(rand()%mx+1);
		write_char('\n');
	}else{
		write_char('2');
		write_char(' ');
		int l = rand()%n+1;
		int r = rand()%n+1;
		if(l > r) swap(l,r);
		write_int(l);
		write_char(' ');
		write_int(r);
		write_char(' ');
		write_int(rand()%mx+1);
		write_char('\n');
	}
}