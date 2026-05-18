class Solution {
public:
    bool closeStrings(string word1, string word2) {      
        vector<int> w1Freq (26,0), w2Freq(26,0);
        set<char> w1,w2;
        for(char c:word1){
            w1Freq[c-'a']++;
            w1.insert(c);
        }
        for(char c:word2){
            w2Freq[c-'a']++;
            w2.insert(c);
        }
        sort(w1Freq.begin(),w1Freq.end());
        sort(w2Freq.begin(),w2Freq.end());
        return (w1 == w2) && (w1Freq == w2Freq); 
    }
};

/*
Looked up example solution and this one is pretty smart
You basically get the requency of the letters in 2 sepreate vectors
you make sure they have the same letters used
you sort the vectors
now compare the number of occurences and if any are off they are not alike
otherwise true.
class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
};



*/