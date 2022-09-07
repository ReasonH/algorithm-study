import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring(" "));
    }

    public static int lengthOfLongestSubstring(String s) {
        Set<Integer> longest = new HashSet<>();
        Set<Integer> localLongest = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            int characterDigit = s.charAt(i);
            if (!localLongest.contains(characterDigit)) {
                localLongest.add(characterDigit);
            } else {
                if (longest.size() < localLongest.size()) {
                    longest = localLongest;
                }
                localLongest = new HashSet<>();
                localLongest.add(characterDigit);
            }
        }


        return longest.size();
    }
}
