class Solution {
    // nlogn의 시간복잡도로 topk를 선정해야함
    // 빈도수 확인 
    public int[] topKFrequent(int[] nums, int k) {
        // arr[n] -> 빈도수 n인 숫자 목록 배열
        ArrayList<Integer>[] arr = new ArrayList[nums.length + 1];
        // 숫자 : 빈도수
        Map<Integer, Integer> frqMap = new HashMap<Integer, Integer>();

        // 빈도 해시맵 초기화
        for(int i : nums){
            frqMap.put(i, frqMap.getOrDefault(i, 0) + 1);
        }

        // 빈도수를 index로 하는 배열 초기화
        for(int key : frqMap.keySet()){
            int frq = frqMap.get(key);
            if(arr[frq] == null){
                arr[frq] = new ArrayList<>();
            }
            arr[frq].add(key);
        }
        
        // 빈도수 index배열을 뒤에서부터 조회하며 ans배열을 k개 채운다
        int[] ans = new int[k];
        int index = 0;
        for(int frq = arr.length - 1; frq >= 0; frq--){
            // 배열이 null이 아니고
            if(arr[frq] == null) continue;
            // It is guaranteed that the answer is unique -> 같은 인덱스에서 경우의 수 없음
            for(int i : arr[frq]){
                ans[index++] = i;
            }

            if(index == k){
                return ans;
            }
        }
        return ans;
    }
}