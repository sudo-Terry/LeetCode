class RandomizedSet {
    private ArrayList<Integer> nums;
    private HashMap<Integer, Integer> map;

    private Random rand;

    public RandomizedSet() {
        nums = new ArrayList<>();
        map = new HashMap<>();
        
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)){
            return false;
        }

        nums.add(val);
        map.put(val, nums.size() - 1);

        return true;
    }
    
    public boolean remove(int val) {
        if(!map.containsKey(val)){
            return false;
        }
        
        int valIdx = map.get(val); // 제거할 값 인덱스
        int lastVal = nums.get(nums.size() - 1);
        
        nums.set(valIdx, lastVal); // 제거할 곳에 배열 마지막 값 넣기
        map.put(lastVal, valIdx); 
        
        nums.remove(nums.size() - 1); // 배열 마지막 값 제거
        map.remove(val); // 해시 제거
        
        return true;
    }
    
    public int getRandom() {
        int randNum = rand.nextInt(nums.size());

        return nums.get(randNum);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */