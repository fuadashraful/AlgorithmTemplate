//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
struct Trie {
    Trie *next[26];
    int cnt;

    Trie(){
        cnt = 0;
        for(int i=0;i<26;++i){
            next[i] = nullptr;
        }
    }
};

class Solution {
public:

    Trie* head = new Trie();
    
    void insert(string &s){
        int n = s.size();

        Trie* now = head;

        for(char ch:s) {
            int idx = ch - 'a';

            if(!now->next[idx]) {
                now->next[idx] = new Trie();
            }

            now = now->next[idx];
            now->cnt++;
        }

        return;
    }

    int getScore(string& s) {
        Trie* now = head;

        int sum = 0;

        for(char ch: s) {
            int idx =ch - 'a';
            now=now->next[idx];
            sum+=now->cnt;
        }

        return sum;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for(string s: words) {
            insert(s);
        }

        vector<int>res;

        for(string s: words) {
            int r = getScore(s);
            res.push_back(r);
        }

        return res;
    }
};
