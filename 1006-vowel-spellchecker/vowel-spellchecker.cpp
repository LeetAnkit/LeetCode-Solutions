class Solution {
public:
    string toLowercase(const string &word) {
        string res = word;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string devowel(const string &word) {
        string res = word;
        for (char &c : res) {
            char lower = tolower(c);
            if (lower=='a' || lower=='e' || lower=='i' || lower=='o' || lower=='u') {
                c = '*';
            } else {
                c = lower;
            }
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords;  
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;

        // Preprocess wordlist
        for (string &ele : wordlist) {
            exactWords.insert(ele);
            string lower = toLowercase(ele);
            string vow = devowel(ele);

            if (!caseMap.count(lower)) caseMap[lower] = ele;
            if (!vowelMap.count(vow)) vowelMap[vow] = ele;
        }

        vector<string> result;
        for (string &q : queries) {
            if (exactWords.count(q)) {
                result.push_back(q);  // exact match
            } else {
                string lower = toLowercase(q);
                string vow = devowel(q);

                if (caseMap.count(lower)) {
                    result.push_back(caseMap[lower]);  // case-insensitive match
                } else if (vowelMap.count(vow)) {
                    result.push_back(vowelMap[vow]);  // vowel-error match
                } else {
                    result.push_back("");  // no match
                }
            }
        }
        return result;
    }
};
