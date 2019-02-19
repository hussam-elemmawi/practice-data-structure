package me.code;

public class Main {

    public static void main(String[] args) {
        TrieNode root = new TrieNode();

        root.add("all");
        root.add("allocate");
        root.add("no");
        root.add("noise");
        root.add("nope");

        System.out.println("is no a word? " + root.containsWord("no"));
        System.out.println("is bad a word? " + root.containsWord("bad"));
        System.out.println("is allow a word? " + root.containsWord("allow"));
        System.out.println("is all a word? " + root.containsWord("all"));
        System.out.println();
        System.out.println("is all a prefix? " + root.containsPrefix("all"));
        System.out.println("is allow a prefix? " + root.containsPrefix("allow"));
        System.out.println("is allo a prefix? " + root.containsPrefix("allo"));
        System.out.println("is noi a prefix? " + root.containsPrefix("noi"));

        System.out.println();

        for (String prefix : root.nextPrefixes("no"))
            System.out.println(prefix);
    }
}
