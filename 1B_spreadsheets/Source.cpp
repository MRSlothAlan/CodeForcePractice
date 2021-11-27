#pragma warning(disable : 4996)
#include <cstdio>
#include <cstring>
#include <cstdio>
/*
technique to learn : 
-> use recursion for the number conversion, radix 26.
-> use gets_s, then sscanf_s() -> check format
*/
void g(const int x) {

	if (x) {
		g((x - 1) / 26);
		putchar((x - 1) % 26 + 65);
	}
}

int main()
{
	int n, x, y;
	scanf_s("%d\n", &n);
	char str[64];
	while (n--)
	{
		gets_s(str);
		// return the fields which are successfully assigned.
		if (sscanf_s(str, "R%dC%d", &x, &y) == 2)
		{
			g(y);
			printf("%d\n", x);
		}
		else {
			char *p = str;
			int temp = 0;
			for (; *p > 64; ++p)
			{
				temp = temp * 26 + *p - 64;
			}
			printf("R%sC%d\n", p, temp);
		}
	}
	return 0;
}


/*
your way to write code... so-called.
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> vec_name;
vector<int> vec_num;
const int MAX = 1e6 + 1000;
char s[MAX];

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		scanf("%s", &s);
		int len = strlen(s);
		vec_name.clear();
		vec_num.clear();
		string tmp_str = "";
		string tmp_num = "";
		// make good use of sscanf, no need to reinvent the old stuff, unless needed.
		for (int i = 0; i < len; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (tmp_str.length() > 0) {
					vec_name.push_back(tmp_str);
					tmp_str = "";
				}
				tmp_num += s[i];
			}
			else {
				if (tmp_num.length() > 0) {
					vec_num.push_back(stoi(tmp_num));
					tmp_num = "";
				}
				tmp_str += s[i];
			}
			if (tmp_num.length() > 0) {
				vec_num.push_back(stoi(tmp_num));
			}
		}
		if (vec_num.size() > 1 && vec_name.size() > 1) {
			// to CR

		}
		else {

		}
	}
	return 0;
}
*/

/*
1 -> A,
2 -> B,
3 -> C,
26 -> Z,
27 -> AA
28 -> AB
52 -> AZ
53 -> BA
54 -> BB, BC, BD... BZ, CA...
ZZ -> AAA
cell name -> column + row.
or, use RXCY.

Let each letter representation of column number be associated 
with integer in radix-26, 
where 'A' = 0, 'B' = 1 ... 'Z'=25. 
Then, when converting letter representation to 
decimal representation, 
we take associated integer and add one plus quantity of 
valid all letter representations which are shorter than 
letter representation being converted. 
When converting from decimal representation to letter representation, 
we have to decide how many letters do we need. Easiest way to do this is to subtract one from number, then quantity of letter representation having length 1, then 2, then 3, and so on, until next subtraction would have produced negative result. At that point, the reduced number is the one which must be written using defined association with fixed number  of digits, with leading zeroes (i.e. 'A's) as needed.

		// wait, cant do that
		if (s[0] == 'R') {
			int i = 0;
			for (; i < len && s[i] != 'C'; i++) {
				tmp_num += s[i];
			}
			vec_num.push_back(stoi(tmp_num));
			i++;
			for (; i < len; i++) {

			}
		}
*/