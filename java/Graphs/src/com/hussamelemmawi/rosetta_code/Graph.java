package com.hussamelemmawi.rosetta_code;

import java.util.HashMap;
import java.util.Map;
import java.util.NavigableSet;
import java.util.TreeSet;

public class Graph {
    private final Map<String, Vertex> graph; // mapping of vertex names to Vertex objects, built from a set of Edges

    /** One edge of the graph (only used by Graph constructor) */
    public static class Edge {
        public final String v1, v2;
        public final int dist;

        public Edge(String v1, String v2, int dist) {
            this.v1 = v1;
            this.v2 = v2;
            this.dist = dist;
        }
    }

    /** One vertex of the graph, complete with mappings to neighbouring vertices */
    public static class Vertex implements Comparable<Vertex> {
        public final String name;
        public int dist = Integer.MAX_VALUE; // MAX_VALUE assumed to be infinity
        public Vertex previous = null;
        public final Map<Vertex, Integer> neighbours = new HashMap<>();

        public Vertex(String name) {
            this.name = name;
        }

        private void printPath() {
            if (this == this.previous) {
                System.out.printf("%s", this.name);
            } else if (this.previous == null) {
                System.out.printf("%s(unreached)", this.name);
            } else {
                this.previous.printPath();
                System.out.printf(" -> %s(%d)", this.name, this.dist);
            }
        }

        @Override
        public int compareTo(Vertex other) {
            if (dist == other.dist) {
                return name.compareTo(other.name);
            }

            return Integer.compare(dist, other.dist);
        }

        @Override
        public String toString() {
            return "(" + name + ", " + dist + ")";
        }
    }

    /** Builds a graph from a set of edges */
    public Graph(Edge[] edges) {
        graph = new HashMap<>(edges.length);

        for (Edge e: edges) {
            if (!graph.containsKey(e.v1)) graph.put(e.v1, new Vertex(e.v1));
            if (!graph.containsKey(e.v2)) graph.put(e.v2, new Vertex(e.v2));
        }

        for (Edge e: edges) {
            graph.get(e.v1).neighbours.put(graph.get(e.v2), e.dist);
            //graph.get(e.v2).neighbours.put(graph.get(e.v1), e.dist); // also do this for an undirected graph
        }
    }

    /** Runs dijkstra using a specified source vertex */
    public void dijkstra(String startName) {
        if (!graph.containsKey(startName)) {
            System.err.printf("Graph doesn't contain start vertex \"%s\"\n", startName);
            return;
        }

        final Vertex source = graph.get(startName);
        NavigableSet<Vertex> queue = new TreeSet<>();

        for (Vertex v: graph.values()) {
            v.previous = v == source ? source: null;
            v.dist = v == source ? 0: Integer.MAX_VALUE;
            queue.add(v);
        }

        dijkstra(queue);
    }

    /** Implementation of dijkstra's algorithm using a binary heap. */
    private void dijkstra(NavigableSet<Vertex> queue) {
        Vertex u, v;

        while (!queue.isEmpty()) {
            u = queue.pollFirst();

            if (u.dist == Integer.MAX_VALUE) break;

            for (Map.Entry<Vertex, Integer> entry: u.neighbours.entrySet()) {
                v = entry.getKey(); // the vertex

                final int alternateDist = u.dist + entry.getValue();
                if (alternateDist < v.dist) {
                    queue.remove(v);
                    v.dist = alternateDist;
                    v.previous = u;
                    queue.add(v);
                }
            }
        }
    }

    public void prim(String startName) {
        if (!graph.containsKey(startName)) {
            System.err.printf("Graph doesn't contain start vertex \"%s\"\n", startName);
            return;
        }

        final Vertex source = graph.get(startName);
        NavigableSet<Vertex> queue = new TreeSet<>();

        for (Vertex v: graph.values()) {
            v.previous = v == source ? source: null;
            v.dist = v == source ? 0: Integer.MAX_VALUE;
            queue.add(v);
        }

        prim(queue);
    }

    private void prim(NavigableSet<Vertex> queue) {
        Vertex u, v;

        while (!queue.isEmpty()) {
            u = queue.pollFirst();

            if (u.dist == Integer.MAX_VALUE) break;

            for (Map.Entry<Vertex, Integer> entry: u.neighbours.entrySet()) {
                v = entry.getKey(); // the vertex

                final int alternateDist = u.dist + entry.getValue();
                if (alternateDist < v.dist) {
                    queue.remove(v);
                    v.dist = alternateDist;
                    v.previous = u;
                    queue.add(v);
                }
            }
        }
    }

    /** Prints a path from the source to the specified vertex */
    public void printPath(String endName) {
        if (!graph.containsKey(endName)) {
            System.err.printf("Graph doesn't contain end vertex \"%s\"\n", endName);
            return;
        }

        graph.get(endName).printPath();
        System.out.println();
    }

    /** Prints the path from the source to every vertex (output order is not guaranteed) */
    public void printAllPaths() {
        for (Vertex v: graph.values()) {
            v.printPath();
            System.out.println();
        }
    }
}

