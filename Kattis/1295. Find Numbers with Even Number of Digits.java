class Solution {
    public int findNumbers(int[] nums) {
        int countNum = 0;
        for (int i = 0; i < nums.length; i += 1) {
            int countDigit = 1;
            while (nums[i] >= 10) {
                countDigit += 1;
                nums[i] /= 10;
            }
            if (countDigit % 2 == 0) {
                countNum += 1;
            }
        }
        return countNum;
    }
}