class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_length = s.size(), words_size = words.size(), word_length = words[0].size();
        if (s_length < word_length*words_size) return {};
        vector<int> ans;
        unordered_map<string, int> word;
        for (string tmp:words){
            word[tmp]++;
        }
        vector<unordered_map<string, int>> wins(word_length);
        for (int i=0; i<word_length && i+word_length*words_size <= s_length; i++){
            for (int j=i; j<i+word_length*words_size; j+= word_length){
                string tmp = s.substr(j, word_length);
                wins[i][tmp]++;
                if (wins[i] == word) ans.push_back(i);
            }
        }
        for (int i = word_length; i + word_length * (words_size-1) <s_length; i++){
            int win_place = i%word_length;
            string front = s.substr(i-word_length, word_length);
            string back = s.substr(i+word_length*(words_size-1), word_length);
            wins[win_place][front]--;
            if (wins[win_place][front] == 0) wins[win_place].erase(front);
            wins[win_place][back]++;
            if (wins[win_place] == word) ans.push_back(i);
        }
        return ans;
    }
};
