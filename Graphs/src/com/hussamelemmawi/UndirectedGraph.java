package com.hussamelemmawi;

import java.util.ArrayList;

/**
 * Created by hussamelemmawi on 14/08/17.
 */

public class UndirectedGraph extends Graph {

  private ArrayList<ArrayList<Vertex>> CCs;

  public UndirectedGraph(GraphType graphType) {
    super(graphType);
    this.CCs = new ArrayList<>();
  }

  @Override
  void appendVertex(Vertex vertex) {
    vertices.add(vertex);
  }

  @Override
  void connectVertices(Vertex src, Vertex dest) {
    if (!src.equals(dest))
      for (Vertex v : vertices) {
        if (v.equals(src) && v.connectToVertex(dest))
          ++edgesCount;
        if (v.equals(dest) && v.connectToVertex(src))
          ++edgesCount;
      }
  }

  @Override
  void connectVertices(int src, int dest) {
    if (src != dest) {
      if (vertices.get(src).connectToVertex(vertices.get(dest))) ++edgesCount;
      if (vertices.get(dest).connectToVertex(vertices.get(src))) ++edgesCount;
    }
  }

  @Override
  void disConnectVertices(Vertex src, Vertex dest) {
    if (!src.equals(dest))
      for (Vertex v : vertices) {
        if (v.equals(src) && v.disconnectFromVertex(dest))
          --edgesCount;
        if (v.equals(dest) && v.disconnectFromVertex(src))
          --edgesCount;
      }
  }

  @Override
  void disConnectVertices(int src, int dest) {
    if (src != dest) {
      if (vertices.get(src).disconnectFromVertex(vertices.get(dest))) --edgesCount;
      if (vertices.get(dest).disconnectFromVertex(vertices.get(src))) --edgesCount;
    }
  }

  void CCs() {
    DFS_for_CCs();
  }

  private void DFS_for_CCs() {
    for (Vertex v : vertices) v.setVisited(false);
    int SCC_count = 1;
    for (Vertex v : vertices) {
      if (!v.isVisited()) {
        println();
        exploreFor_CCs(v, SCC_count);
        ++SCC_count;
      }
    }
    println();
  }

  private void exploreFor_CCs(Vertex v, int SCC_count) {
    try {
      CCs.get(SCC_count - 1);
    } catch (IndexOutOfBoundsException e) {
      System.out.println("Connected Comp. #" + (SCC_count));
      CCs.add(SCC_count - 1, new ArrayList<>());
    }
    CCs.get(SCC_count - 1).add(v);
    v.setVisited(true);
    v.setCC_num(SCC_count);
    printVertex(v);
    for (Vertex u : v.getAdjacentList()) {
      if (!u.isVisited()) {
        explore(u);
      }
    }
  }
}
