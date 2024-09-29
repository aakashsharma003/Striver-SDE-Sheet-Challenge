class Solution {
public:
    int countOfSubstrings(string s, int k) {
        if (s.size() < 5)
            return 0;
        int ans = 0;
        for (int j = 0; j < s.size(); j++) {
            int a = 0, e = 0, i = 0, o = 0, u = 0;
            int c = 0;

            for (int len = j; len < s.size(); len++) {
                char ch = s[len];
                switch (ch) {
                case 'a':
                    a++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'i':
                    i++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'u':
                    u++;
                    break;
                default:
                    c++;
                    break;
                }

                if (a && e && i && o && u && c == k)
                    ans++;

            }
        }
        return ans;

    }
};