/*
*Approach 1:
*word < word + "~"
*prefix + "~" helps you find the upper bound, '~' is one option, any character after 'z' should be also working such as '{'.
*/
class SearchSuggestionSystem {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {

    List<List<String>> res = new ArrayList<>();
    if (products == null || searchWord == null) {
      return res;
    }

    Arrays.sort(products);
    List<String> proList = Arrays.asList(products);
    TreeMap<String, Integer> proToIndex = new TreeMap<>();
    for (int i = 0; i < products.length; i++) {
      proToIndex.put(products[i], i);
    }

    String key = "";
    for (char c : searchWord.toCharArray()) {
      key = key + c;
      String ceil = proToIndex.cellingKey(key);
      String floor = proToIndex.floorKey(key + "~"); // can find key
      if (cell == null || floor == null) {
        break;
      }

      res.add(proList.subList(proToIndex.get(ceil), Math.min(proToIndex.get(ceil) + 3, proToIndex.get(floor) + 1)));
    }

    while (res.size() < searchWord.length()) {
      res.add(new Array<String>());
    }

    return res;
    }
}


/*
*Approach #2 Tire Tree
*/

class Solution {
    private class TrieNode {
        boolean end = false;
        String str = null;
        int count = 0;
        TrieNode[] children = new TrieNode[26];
    }

    private class Trie {
        TrieNode root = new TrieNode();
        public void insert(String[] products) {
            for (String str : products) {
                insertWord(str);
            }
        }

        public void insertWord(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                if (node.children[c - 'a'] == null) {
                    node.children[c - 'a'] = new TrieNode();
                }
                node = node.children[c - 'a'];
            }
            if (node.end != true) {
                node.end = true;
                node.str = word;
            }
            node.count++;
        }

        public List<List<String>> searchWord(String word) {
            List<List<String>> result = new ArrayList<>();
            for (int i = 1; i <= word.length(); i++) {
                result.add(search(word.substring(0, i)));
            }
            return result;
        }

        private List<String> search(String pattern) {
            List<String> result = new ArrayList<>();
            TrieNode node = root;
            for (char c : pattern.toCharArray()) {
                if (node.children[c - 'a'] == null) {
                    return result;
                }
                node = node.children[c - 'a'];
            }

            Solution(node, result);
            return result;
        }

        private void Solution(TrieNode root, List<String> result) {
            if (root.end) {
                for (int i = 0; i < root.count; i++) {
                    result.add(root.str);
                    if (result.size() == 3) {
                        return;
                    }
                }
            }

            for (TrieNode node : root.children) {
                if (node != null) {
                    Solution(node, result);
                }
                if (result.size() == 3) {
                    return;
                }
            }

        }
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Trie trie = new Trie();
        trie.insert(products);
        return trie.searchWord(searchWord);
    }
}