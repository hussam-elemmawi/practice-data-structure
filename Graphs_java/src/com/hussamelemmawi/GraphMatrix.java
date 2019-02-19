package com.hussamelemmawi;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Stack;

public class GraphMatrix {
    private HashMap<Vertex, HashSet<Vertex>> graph;


    public GraphMatrix() {
        graph = new HashMap<>();
    }

    public void addVertex(Vertex v) {
        graph.put(v, new HashSet<>());
    }

    public Vertex getVertex(Vertex v) {
        return graph.containsKey(v) ? v: null;
    }

    public Vertex getVertex(Object value) {
        for (Vertex v : graph.keySet()) {
            if (v.getValue() == value) return v;
        }
        return null;
    }

    public void connect(Vertex src, Vertex dest) {
        if (src == null || dest == null) return;
        if (src.equals(dest)) return;
        if (graph.get(src).contains(dest) && !graph.get(dest).contains(src)) return;
        if (!graph.get(src).contains(dest) && graph.get(dest).contains(src)) return;

        graph.get(src).add(dest);
        graph.get(dest).add(src);
    }

    public void disconnect(Vertex src, Vertex dest) {
        if (src == null || dest == null) return;
        if (src.equals(dest)) return;

        graph.get(src).remove(dest);
        graph.get(dest).remove(src);
    }

    public void dfs() {
        for (Vertex vertex : graph.keySet()) {
            vertex.setVisited(false);
        }

        for (Vertex vertex : graph.keySet()) {
            if (!vertex.isVisited()) {
                dfs(vertex);
                System.out.println();
            }
        }
        System.out.println();
    }

    private void dfs(Vertex v) {
        v.setVisited(true);
        System.out.print(v.getValue());

        for (Vertex u : graph.get(v)) {
            if (!u.isVisited()) {
                System.out.print(" -- ");
                dfs(u);
            }
        }
    }

    public void dfs_iterative() {
        for (Vertex vertex : graph.keySet()) {
            vertex.setVisited(false);
        }

        Stack<Vertex> stack = new Stack<>();

        for (Vertex vertex: graph.keySet()) {
            if (!vertex.isVisited()) {
                stack.push(vertex);

                while(!stack.isEmpty()) {
                    Vertex v = stack.pop();
                    if (!v.isVisited()) {
                        v.setVisited(true);
                        System.out.print(v.getValue());

                        for (Vertex u: graph.get(v)) {
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
        for (Vertex vertex : graph.keySet()) {
            vertex.setVisited(false);
        }

        LinkedList<Vertex> queue = new LinkedList<>();

        for (Vertex vertex: graph.keySet()) {
            if (!vertex.isVisited()) {
                queue.addLast(vertex);

                while (!queue.isEmpty()) {
                    Vertex v = queue.getFirst();
                    queue.remove(0);

                    if (!v.isVisited()) {
                        v.setVisited(true);
                        System.out.print(v.getValue() + " -- ");

                        for (Vertex u: graph.get(v)) {
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
