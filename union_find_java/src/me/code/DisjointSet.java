package me.code;

import java.util.HashMap;
import java.util.Map;

public class DisjointSet<D> {
    private Map<D, Node> map;

    private class Node<D> {
        D data;
        int rank;
        Node<D> parent;

        @Override
        public String toString() {
            return "[node: " + data + ", rank: " + rank + ", parent: " + parent.data + "]";
        }
    }

    public DisjointSet() {
        map = new HashMap<>();
    }

    public void makeSet(D val) {
        Node<D> node = new Node();
        node.data = val;
        node.parent = node;
        node.rank = 0;
        map.put(val, node);
    }

    public void union(D val1, D val2) {
        Node<D> node1 = map.get(val1);
        Node<D> node2 = map.get(val2);

        if (node1 == null || node2 == null) return;

        Node<D> root1 = findSet(node1);
        Node<D> root2 = findSet(node2);

        if (root1.equals(root2)) {
            return;
        }

        if (root1.rank >= root2.rank) {
            root1.rank = (root1.rank == root2.rank) ? root1.rank + 1 : root1.rank;
            root2.parent = root1;
        } else {
            root1.parent = root2;
        }
    }

    // get the root node of a set
    public Node findSet(D val) {
        return findSet(map.get(val));
    }

    public Node findSet(Node<D> node) {
        if (node == null) return node;

        Node<D> parent = node.parent;
        if (parent.equals(node)) { // we reached the root
            return parent;
        }

        node.parent = findSet(node.parent);
        return node.parent;
    }

    public static void main(String args[]) {
        DisjointSet<Integer> ds = new DisjointSet<>();
        ds.makeSet(1);
        ds.makeSet(2);
        ds.makeSet(3);
        ds.makeSet(4);
        ds.makeSet(5);
        ds.makeSet(6);
        ds.makeSet(7);

        ds.union(1, 2);
        ds.union(2, 3);
        ds.union(4, 5);
        ds.union(6, 7);
        ds.union(5, 6);
        ds.union(3, 7);

        System.out.println(ds.findSet(1));
        System.out.println(ds.findSet(2));
        System.out.println(ds.findSet(3));
        System.out.println(ds.findSet(4));
        System.out.println(ds.findSet(5));
        System.out.println(ds.findSet(6));
        System.out.println(ds.findSet(7));
    }

}

