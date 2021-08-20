class Solution {
    public int numJewelsInStones(String J, String S) {
        char count = 0;
        char[] jewels = J.toCharArray();
        char[] stones = S.toCharArray();
        for (int i = 0; i < stones.length; i += 1) {
            for (int j = 0; j < jewels.length; j += 1) {
                if (stones[i] == jewels[j]) {
                    count += 1;
                }
            }
        }
        return count;
    }
}