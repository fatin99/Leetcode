class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int count = 0;
        for (int i = 0; i < startTime.length; i += 1) {
            if ((startTime[i] <= queryTime) && (endTime[i] >= queryTime)) {
                count += 1;
            }
        }
        return count;
    }
}