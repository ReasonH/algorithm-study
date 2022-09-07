package medium;

import java.util.HashMap;
import java.util.Map;

public class LongestSubString {

    public int lengthOfLongestSubstring(String s) {
        int answer = 0;
        int start = 0;
        int end = 0;
        Map<Integer, Integer> indexes = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            int character = s.charAt(i);
            if (indexes.containsKey(character) && indexes.get(character) >= start) {
                start = indexes.get(character) + 1;
            }
            end = i;
            answer = Math.max(answer, end - start + 1);
            indexes.put(character, i);
        }

        return answer;
    }
}