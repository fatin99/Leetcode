import java.util.ArrayList;
import java.util.List;

class Solution {
    public String defangIPaddr(String address) {
        String output = address.replace(".", "[.]");
        return output;
    }
}