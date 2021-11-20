class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0; 
        unordered_set <string> words (wordList.begin(), wordList.end());
        queue <string> q;
        q.push(beginWord);
        
        string currWord, nextWord;
        int ans = 1;
        while (!q.empty()) {
            int currSize = q.size();
            while (currSize--) {
                currWord = q.front();
                q.pop();
                words.erase(currWord);
                for (int i=0; i<currWord.size(); i++) {
                    char original = currWord[i];
                    for (int j=0; j<26; j++) {
                        currWord[i] = 'a' + j;
                        if (currWord == endWord) return ans+1;
                        if (words.find(currWord)!=words.end()) q.push(currWord);
                    }
                    currWord[i] = original;
                }
            }
            ans++;
        }
        return 0;
    }
};