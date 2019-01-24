package com.hussamelemmawi;

import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by hussamelemmawi on 14/08/17.
 */

abstract class Graph {
  private final GraphType graphType;
  protected HashSet<Vertex> vertices;
  int edgesCount;
  private int clock;

  Graph(GraphType graphType) {
    this.graphType = graphType;
    vertices = new HashSet<>();
    edgesCount = 0;
    clock = 0;
  }

  abstract void appendVertex(Vertex vertex);

  abstract void connectVertices(Vertex src, Vertex dest);

  abstract void connectVertices(Object srcValue, Object destValue);

  abstract void connectVertices(int src, int dest);

  abstract void disconnectVertices(Vertex src, Vertex dest);

  abstract void disconnectVertices(int src, int dest);

  abstract void printEdgesCount();

  void DFS() {
    for (Vertex v : vertices) v.setVisited(false);
    for (Vertex v : vertices) {
      if (!v.isVisited()) {
        println();
        explore(v);
      }
    }
    println();
  }

  void explore(Vertex v) {
    v.setVisited(true);
    printVertex(v);
    for (Vertex u : v.getAdjacentList()) {
      if (!u.isVisited()) {
        explore(u);
      }
    }
  }

  void DFSPrePostVisit() {
    for (Vertex v : vertices) v.setVisited(false);
    for (Vertex v : vertices) {
      if (!v.isVisited()) {
        explorePrePostVisit(v);
      }
    }
    println();
    printGraphDetailed();
  }

  private void explorePrePostVisit(Vertex v) {
    v.setVisited(true);
    v.preVisit(this);
    for (Vertex u : v.getAdjacentList()) {
      if (!u.isVisited()) {
        explorePrePostVisit(u);
      }
    }
    v.postVisit(this);
  }

  int getClock() {
    return clock;
  }

  void tickClock() {
    ++clock;
  }

  void printGraph() {
    for (Vertex v : vertices) {
      System.out.println(v.getValue());
    }
  }

  void printGraphEdges() {
    for (Vertex v : vertices) {
      for (Vertex u: v.getAdjacentList()) {
        System.out.println(v.getValue() + " -> " + u.getValue());
      }
    }
  }

  void printGraphDetailed() {
    for (Vertex v : vertices) {
      System.out.println(
        v.getValue() + ", pre: " + v.getPreVisit() + ", post: " + v.getPostVisit()
      );
    }
  }

  Vertex getVertex(Graph g, Object value) {
    for (Vertex v: g.vertices) {
      if (v.getValue().equals(value)) {
        return v;
      }
    }
    return null;
  }

  void println() {
    System.out.println();
  }

  void printVertex(Vertex v) {
    System.out.print(v.getValue() + "\t");
  }
}
