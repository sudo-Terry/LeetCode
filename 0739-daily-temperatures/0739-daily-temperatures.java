class Solution {
    // index마다 대소비교 -> N*N 인데 1 <= temperatures.length <= 10^5 
    // 시간복잡도가 10^10이니 터짐 (보통 1억이 마지노선)
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] ans = new int[n];

        // 어떤 정보가 언제 쓸모 없어지는가
        // 임의의 인덱스에서 과거를 바라보며 갱신
        // 갱신은 LIFO
        Stack<Integer> stk = new Stack<Integer>();
        for(int i = 0; i < n; i++){
            int curr = temperatures[i];
            while (!stk.isEmpty() && temperatures[stk.peek()] < curr) {
                // 정답을 찾았으니 스택에서 빼기
                int prevIndex = stk.pop(); 
                // 기다린 일수
                ans[prevIndex] = i - prevIndex; 
            }
            
            // 스택에 보류
            stk.push(i);
        }
        return ans;
    }
}