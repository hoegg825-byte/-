class Solution {
public:
    int romanToInt(string s) {
        int i=0;
        while (i+1<s.size()){
            string tmp = s.substr(i, 2);
            if (tmp == "IV") s.replace(i, 2, "a");
            else if (tmp == "IX") s.replace(i, 2, "b");
            else if (tmp == "XL") s.replace(i, 2, "c");
            else if (tmp == "XC") s.replace(i, 2, "d");
            else if (tmp == "CD") s.replace(i, 2, "e");
            else if (tmp == "CM") s.replace(i, 2, "f");
            i++;
        }
        int res = 0;
        for (int i = 0; i < s.length(); i++) res += getValue(s[i]);
        return res;
    }
        int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            case 'a': return 4;
            case 'b': return 9;
            case 'c': return 40;
            case 'd': return 90;
            case 'e': return 400;
            case 'f': return 900;
        }
        return 0;
    }

};
