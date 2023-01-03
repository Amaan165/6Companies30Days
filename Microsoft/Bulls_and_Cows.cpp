class Solution {
public:
    string getHint(string s, string g) {
	int smp[10] = {0};
        int gmp[10] = {0};
	int A = 0, B = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == g[i]) A++;

            else
            {
                (smp[g[i] - '0'] > 0) ? smp[g[i] - '0']--, B++ : gmp[g[i] - '0']++;
                (gmp[s[i] - '0'] > 0) ? gmp[s[i] - '0']--, B++ : smp[s[i] - '0']++; 
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
