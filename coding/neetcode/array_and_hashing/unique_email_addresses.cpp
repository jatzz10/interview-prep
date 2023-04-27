// Problem - https://leetcode.com/problems/unique-email-addresses

// Solutions
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (int i = 0; i < emails.size(); i++) {
            string s = "";
            bool shouldCharBeIgnored = false, domain = false;

            for (int j = 0; j < emails[i].size(); j++) {
                if (emails[i][j] == '@') {
                    shouldCharBeIgnored = false;
                    domain = true;
                }
                
                if (emails[i][j] == '+' && domain == false) {
                    shouldCharBeIgnored = true;
                }
                
                if (shouldCharBeIgnored == true) {
                    continue;
                }

                if (emails[i][j] == '.' and domain == false) {
                    continue;
                }

                s += emails[i][j];
            }

            uniqueEmails.insert(s);
        }

        return uniqueEmails.size();
    }
};