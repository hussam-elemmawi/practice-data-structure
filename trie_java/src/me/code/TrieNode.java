package me.code;

import java.util.*;

public class TrieNode {
    Character c;
    boolean isWord;
    Map<Character, TrieNode> children;

    @Override
    public String toString() {
        return "" + c + ", " + isWord;
    }

    public TrieNode() {
        children = new HashMap<>();
    }

    public TrieNode(Character c, boolean isWord) {
        children = new HashMap<>();
        this.c = c;
        this.isWord = isWord;
    }

    public void add(String word) {
        if (0 == word.length()) return;

        Character character = word.charAt(0);
        TrieNode child = children.get(character);

        if (child == null) {
            child = new TrieNode(character, 1 == word.length());
            children.put(character, child);
        }
        child.add(word.substring(1));
    }

    public boolean containsWord(String word) {
        if (word == null || word.length() == 0) return true;

        Character character = word.charAt(0);
        TrieNode child = children.get(character);
        if (word.length() == 1) {
            return child != null && child.isWord;
        }

        return child != null && child.containsWord(word.substring(1));
    }

    public boolean containsPrefix(String word) {
        if (word == null || word.length() == 0) return true;

        Character character = word.charAt(0);
        TrieNode child = children.get(character);
        if (word.length() == 1) {
            return child != null;
        }

        return child != null && child.containsPrefix(word.substring(1));
    }

    public List<String> nextPrefixes(String prefix) {
        if (!containsPrefix(prefix)) return Collections.emptyList();

        TrieNode lastTrieNode = traverseTill(prefix);
        StringBuilder sb = new StringBuilder(prefix);
        List<String> result = new ArrayList<>();
        for (TrieNode child: lastTrieNode.children.values()) {
            dfs(child, sb, result);
        }
        return result;
    }

    private TrieNode traverseTill(String prefix) {
        if (prefix == null || prefix.length() == 0) return this;

        Character character = prefix.charAt(0);
        TrieNode child = children.get(character);
        if (prefix.length() == 1) {
            return child;
        }

        return child.traverseTill(prefix.substring(1));
    }

    private void dfs(TrieNode node, StringBuilder sb, List<String> result) {
        result.add(sb.append(node.c).toString());
        if (node.children.size() > 0) {
            for (TrieNode child: node.children.values()) {
                dfs(child, new StringBuilder(sb), result);
            }
        }
    }
}
