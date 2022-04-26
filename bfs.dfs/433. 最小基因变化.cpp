class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size() == 0) return -1;
        unordered_set<string> uset;
        for (auto& it : bank) {
            uset.insert(it);
        }
        unordered_map<string, int> umap;
        umap[start] = 0;
        //*****队列中只会有两层的信息
        queue<string> que;
        que.push(start);
        char ch[4] = {'A', 'C', 'G', 'T'};
        while (!que.empty()) {
            string str = que.front();
            que.pop();
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    string tmp = str;
                    if(tmp[i] == ch[j]) continue;
                    tmp[i] = ch[j];
                    //不在基因库直接跳过
                    if(uset.find(tmp) == uset.end()) continue;
                    //在基因库且为结束字符串返回结果
                    if(tmp == end) return umap[str] + 1;
                    //只有不在map中需要处理，在map中说明前面处理过
                    if(umap.find(tmp) == umap.end()) {
                        umap[tmp] = umap[str] + 1;
                        //入队，基因变化n次的入队，基因变化n-2次的全部处理过，在map中
                        que.push(tmp);
                    }
                }
            }
        }
        return -1;
    }
};