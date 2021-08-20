import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        for (int i = 0; i < candies.length; i += 1) {
            if (candies[i] > max){
                max = candies[i];
            }
        }
        List<Boolean> result = new ArrayList<Boolean>();
        for (int i = 0; i < candies.length; i += 1) {
            if (candies[i] + extraCandies >= max) {
                result.add(true);
            }
            else {
                result.add(false);
            }
        }
        return result;
    }
}