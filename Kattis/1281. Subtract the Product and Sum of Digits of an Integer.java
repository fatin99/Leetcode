import java.util.ArrayList;
import java.util.List;

class Solution {
    public static int subtractProductAndSum(int n) {
        List<Integer> digits = new ArrayList<Integer>();
        while (n >= 10) {
            digits.add(n % 10);
            n /= 10;
        }
        digits.add(n % 10);
        int sum = 0;
        int product = 1;
        for (int i = 0; i < digits.size(); i += 1) {
            sum += digits.get(i);
            System.out.println("sum: " + sum);
            product *= digits.get(i);
            System.out.println("product: " +product);
        }
        return product - sum;
    }

    public static void main(String[] args) {
        System.out.println("result: " + subtractProductAndSum(10225));
    }
}