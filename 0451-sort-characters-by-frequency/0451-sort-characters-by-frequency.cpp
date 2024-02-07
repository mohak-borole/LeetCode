class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> map;
        for(char ch : s) {
            map[ch]++;
        }
        
        auto comparator = [&] (char a , char b) {
            if(map[a] == map[b])
                return a<b;
            return map[a] > map[b];
        };
        
        sort(s.begin() , s.end() , comparator);
        return s;
    }
};