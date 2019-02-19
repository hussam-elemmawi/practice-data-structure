package com.hussamelemmawi;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class GraphAdjacentList {
    private HashSet<Vertex> graph;

    public GraphAdjacentList() {
        graph = new HashSet<>();
    }

    public void addVertex(Vertex v) {
        graph.add(v);
    }

    public Vertex getVertex(Vertex v) {
        return graph.contains(v) ? v : null;
    }

    public Vertex getVertex(Object value) {
        for (Vertex v : graph) {
            if (v.getValue() == value) return v;
        }
        return null;
    }

    public void connect(Vertex src, Vertex dest) {
        if (src == null || dest == null) return;
        if (src.equals(dest)) return;
        if (src.getAdjacentList().contains(dest) && !dest.getAdjacentList().contains(src)) return;
        if (!src.getAdjacentList().contains(dest) && dest.getAdjacentList().contains(src)) return;

        src.getAdjacentList().add(dest);
        dest.getAdjacentList().add(src);
    }

    public void disconnect(Vertex src, Vertex dest) {
        if (src == null || dest == null) return;
        if (src.equals(dest)) return;

        src.getAdjacentList().remove(dest);
        dest.getAdjacentList().remove(src);
    }

    public void dfs() {
        for (Vertex vertex : graph) { // for each vertex in graph
            vertex.setVisited(false); // set as not visited yet
        }

        for (Vertex vertex : graph) { // for each vertex in graph
            if (!vertex.isVisited()) {
                dfs(vertex);
                System.out.println();
            }
        }

        System.out.println();
    }

    private void dfs(Vertex vertex) {
        System.out.print(vertex.getValue());
        vertex.setVisited(true);

        for (Vertex u : vertex.getAdjacentList()) {
            if (!u.isVisited()) {
                System.out.print(" -- ");
                dfs(u);
            }
        }
    }

    public void dfs_iterative() {
        for (Vertex vertex : graph) { // for each vertex in graph
            vertex.setVisited(false); // set as not visited yet
        }

        Stack<Vertex> stack = new Stack<>();

        for (Vertex vertex : graph) { // for each vertex in graph
            if (!vertex.isVisited()) {
                stack.push(vertex);

                while (!stack.isEmpty()) {
                    Vertex v = stack.pop();
                    if (!v.isVisited()) {
                        v.setVisited(true);

                        System.out.print(v.getValue());

                        for (Vertex u : v.getAdjacentList()) {
                            if (!u.isVisited()) {
                                System.out.print(" -- ");
                                stack.push(u);
                            }
                        }
                    }
                }

                System.out.println();
            }
        }
        System.out.println();
    }

    public void bfs() {
        for (Vertex vertex : graph) { // for each vertex in graph
            vertex.setVisited(false); // set as not visited yet
        }

        LinkedList<Vertex> queue = new LinkedList<>();

        for (Vertex vertex: graph) {
            if (!vertex.isVisited()) {
                queue.addLast(vertex);

                while (!queue.isEmpty()) {
                    Vertex v = queue.getFirst(); // note: get don't include remove operation
                    queue.remove(0); // remove first element

                    if (!v.isVisited()) {
                        v.setVisited(true);
                        System.out.print(v.getValue() + " -- ");

                        for (Vertex u: v.getAdjacentList()) {
                            if (!u.isVisited()) {
                                queue.addLast(u);
                            }
                        }
                    }
                }
                System.out.println();
            }
        }
        System.out.println();
    }
}
