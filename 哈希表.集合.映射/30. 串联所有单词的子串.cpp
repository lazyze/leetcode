class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        getmap(words);
        int wlen = words[0].size(); //单词长度
        int wnum = words.size();    //单词个数
        int total = wlen * wnum;    //子串长度
        int len = s.size(); //字符串长度
        vector<int> ans;
        for (int i = 0; i < wlen; i++) {
            //以i为起点的子串长度小于total终止循环
            if (i + total > len) break;
            unordered_map<string, int> cmap;
            int cur = i;
            //讲长度为total的子串分割存入map中
            for (int j = 0; j < wnum; j++) {
                cmap[s.substr(cur, wlen)]++;
                cur += wlen;
            }
            //记录子串的起点和终点，每次往后遍历一个wlen长度,
            //循环结束条件即终点位置大于len,超出字符串位置
            for (int begin = i, end = i + total; end <= len; begin += wlen, end += wlen) {
                if(equal(cmap, recd)) ans.push_back(begin);
                cmap[s.substr(begin, wlen)]--;
                cmap[s.substr(end, wlen)]++;
            }
        }
        return ans;
    }

    void getmap(vector<string>& words) {
        for (auto& it : words) {
            recd[it]++;
        }
    }

    bool equal(unordered_map<string, int>& a,unordered_map<string, int>& b) {
        for (auto& it : a) {
            if(b[it.first] != it.second) return false;
        }
        for (auto& it : b) {
            if(a[it.first] != it.second) return false;
        }
        return true;
    }
private:
    unordered_map<string, int> recd;
};