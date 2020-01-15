// Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1


class WordDistance {
    private HashMap<String, List<Integer>> map;
    
    public WordDistance(String[] words) {
        map = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            String s = words[i];
            if (!map.containsKey(s)) map.put(s, new ArrayList<Integer>());
            map.get(s).add(i);
        }
    }
    
    public int shortest(String word1, String word2) {
        int res = Integer.MAX_VALUE;
        List<Integer> l1 = map.get(word1);
        List<Integer> l2 = map.get(word2);
        
        int i1 = 0, i2 = 0;
        
        while (i1 < l1.size() && i2 < l2.size()) {
            if (l1.get(i1) < l2.get(i2)) {
                res = Math.min(res, l2.get(i2) - l1.get(i1));
                i1 += 1;
            } else {
                res = Math.min(res, l1.get(i1) - l2.get(i2));
                i2 += 1;
            }
        }
        
        return res;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
