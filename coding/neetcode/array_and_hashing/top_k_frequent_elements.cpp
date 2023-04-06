// Problem - 

// Solutions

// Approach 1 - Map, Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        map<int, int>::iterator itr;

        vector<pair<int, int>> vec;
        vector<int> result;

        // iterate array
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // iterate map
        for (itr = mp.begin(); itr != mp.end(); itr++) {
            vec.push_back(make_pair(itr->second, itr->first));
        }

        // sort
        sort(vec.begin(), vec.end());

        // iterate backwards K
        for (int i = vec.size()-1; i >= 0; i--) {
            if (k == 0) break;
            result.push_back(vec[i].second);
            k--;
        }
        return result;
    }
};
// Time complexity - O(n*logn + k)
// Space complexity - O(n+k)
// Auxiliary space - O(n+k)


// Approach 2 - Priority_queue using min-heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> result;
        
        // priority queue using min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // iterate array
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // iterate map & push in pq
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            pq.push({itr->second, itr->first});

            if (pq.size() > k) {
                pq.pop();
            }

        }
        
        // pop top K elements and add to vector
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
// Time complexity - O(n*logk)
// Space complexity - O(n+k)
// Auxiliary space - O(n+k)