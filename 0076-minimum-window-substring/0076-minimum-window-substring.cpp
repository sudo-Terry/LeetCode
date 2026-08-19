class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> target(128, 0);
        for (char c : t) {
            target[c]++;
        }

        int remaining = t.length();
        int left = 0, min_len = INT_MAX, start_idx = 0;

        // 윈도우 오른쪽 이동 -> 문자 카운트 줄이기
        for (int right = 0; right < s.length(); ++right) {
            // 필요한 문자면 -1
            if (target[s[right]] > 0) {
                remaining--;
            }
            target[s[right]]--;

            // 윈도우 축소
            while (remaining == 0) {
                int current_len = right - left + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    start_idx = left;
                }

                // 왼쪽을 당겨 윈도우 줄이기
                target[s[left]]++;
                // 필요했던거면 다시 증가
                if (target[s[left]] > 0) {
                    remaining++;
                }
                left++;
            }
        }

        return (min_len == INT_MAX) ? "" : s.substr(start_idx, min_len);
    }
};
