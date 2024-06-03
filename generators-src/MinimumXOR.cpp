#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> genTree(int n){
    double p = 20;
    vector<int> ord(n);
    for(int i = 0; i<n; i++) ord[i] = i;
    for(int i = 0; i<n-1; i++)
        swap(ord[i],ord[i+rand()%(n-i-1)]);
    vector<pair<int,int>> all(n-1);
    for(int i = 1; i<n; i++) all[i-1] = {ord[i-(int)(pow((double)rand()/(double)(RAND_MAX),p)*i)-1],ord[i]};
    for(int i = 0; i<n-2; i++)
        swap(all[i],all[i+rand()%(n-i-1)]);
    vector<pair<int,int>> v;
    for(int i = 0; i<n-1; i++)
        v.push_back({all[i].first+1,all[i].second+1});
    return v;
}
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

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output
int main(int argc, char* argv[]){
    assert(argc == 3);
    int subtask = stoi(argv[1]);
    srand(stoi(argv[2]));
    int n = subtask == 1 ? 1000 : 1e5;
    bool hasCycle = subtask == 1 || subtask == 4;
    bool queryAfter = subtask == 3;
    int q = randint(1, subtask == 1 ? min(2000,n*n) : min(1000000LL, (long long)n*n));
    vector<vector<int>> q1, q2;
    init_output();
    write_int(n);
    write_char(' ');
    write_int(q);
    write_char('\n');
    if(hasCycle){
        for(int i = 0; i<q; i++){
            int a = randint(1,n);
            int b = randint(1,n);
            q1.push_back({a,b,rand()});
        }
    }else{
        auto tree = genTree(n);
        for(auto& a: tree)
            q1.push_back({a.first,a.second,rand()});
    }
    for(int i = 0; i<q; i++){
        int a = randint(1,n);
        int b = randint(1,n);
        q2.push_back({a,b});
    }
    if(queryAfter){
        int change = randint(max(1,q-(int)q2.size()),min(q,(int)q1.size()));
        for(int i = 0; i<change; i++){
            write_char('1');
            write_char(' ');
            write_int(q1[i][0]);
            write_char(' ');
            write_int(q1[i][1]);
            write_char(' ');
            write_int(q1[i][2]);
            write_char('\n');
        }
        for(int i = 0; i<q-change; i++){
            write_char('2');
            write_char(' ');
            write_int(q2[i][0]);
            write_char(' ');
            write_int(q2[i][1]);
            write_char('\n');
        }
    }else{
        int p1 = 0, p2 = 0;
        for(int i = 0; i<q; i++){
            if(p1 != q1.size() && (p2 == q2.size() || randint(0,1) == 0)){
                write_char('1');
                write_char(' ');
                write_int(q1[p1][0]);
                write_char(' ');
                write_int(q1[p1][1]);
                write_char(' ');
                write_int(q1[p1][2]);
                write_char('\n');
                p1++;
            }else{
                write_char('2');
                write_char(' ');
                write_int(q2[p2][0]);
                write_char(' ');
                write_int(q2[p2][1]);
                write_char('\n');
                p2++;
            }
        }
    }
}