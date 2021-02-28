class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 1;//记录转化的步骤数；
        unordered_set<string> hash(wordList.begin(),wordList.end());//将字典中的单词加入到hash表中方便查询；
        unordered_set<string> visited;//用于记录字典中的单词是否被访问过；
        if (wordList.size() == 0 || hash.find(endWord) == hash.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 1;i<=n;i++) {
                string s = q.front();
                q.pop();

                for (int j = 0;j<s.size();j++) {
                    char c = s[j];
                    for(int k = 0;k<26;k++) {
                        if ('a' + k == c) {
                            continue;
                        } 
                        s[j] = char('a' + k);

                        if (s == endWord) {
                            step++;
                            return step;
                        } else {
                            if (hash.find(s)!=hash.end()&&visited.find(s) == visited.end()) {
                                q.push(s);
                                visited.insert(s);
                            }
                        }
                    }
                    s[j] = c;//将查询的单词还原到原始值，即不改变wordList字典中的单词
                }
            }
            step++;
        }
        return 0;
    }
};