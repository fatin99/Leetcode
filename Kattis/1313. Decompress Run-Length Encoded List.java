import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < nums.length - 1; i += 2) {
            for (int j = 0; j < nums[i]; j += 1) {
                result.add(nums[i + 1]);
            }
        }
        int[] resultArray = new int[result.size()];
        for (int i=0; i < resultArray.length; i += 1) {
            resultArray[i] = result.get(i).intValue();
        }
        return resultArray;    
    }
}