package com.hussamelemmawi;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * Created by hussamelemmawi on 16/08/17.
 */
public class DirectedGraph extends Graph {

  private ArrayList<ArrayList<Vertex>> SCCs;

  public DirectedGraph() {
    super(GraphType.DIRECTED);
    SCCs = new ArrayList<>();
  }

  @Override
  void appendVertex(Vertex vertex) {
    vertices.add(vertex);
  }

  @Override
  void connectVertices(Vertex src, Vertex dest) {
    if (!src.equals(dest)) {
      for (Vertex v : vertices) {
        if (v.equals(src) && v.connectToVertex(dest)) {
          ++edgesCount;
          dest.increamentIncomingEdgesCount();
        }
      }
    }
  }

  @Override
  void connectVertices(int src, int dest) {
    if (src != dest && src >= 0 && src < vertices.size() && dest >= 0 && dest < vertices.size()) {
      getVertex(this, src).connectToVertex(getVertex(this, dest));
      getVertex(this, dest).increamentIncomingEdgesCount();
      ++edgesCount;
    }
  }

  @Override
  void connectVertices(Object srcValue, Object destValue) {
    if (srcValue != destValue && srcValue != null && destValue != null) {
      getVertex(this, srcValue).connectToVertex(getVertex(this, destValue));
      getVertex(this, destValue).increamentIncomingEdgesCount();
      ++edgesCount;
    }
  }

  @Override
  void disconnectVertices(Vertex src, Vertex dest) {
    if (!src.equals(dest)) {
      for (Vertex v : vertices) {
        if (v.equals(src) && v.disconnectFromVertex(dest)) {
          --edgesCount;
          dest.decreamentIncomingEdgesCount();
        }
      }
    }
  }

  @Override
  void disconnectVertices(int src, int dest) {
    if (src != dest && src >= 0 && src < vertices.size() && dest >= 0 && dest < vertices.size()) {
      getVertex(this, src).disconnectFromVertex(getVertex(this, dest));
      getVertex(this, dest).decreamentIncomingEdgesCount();
      --edgesCount;
    }
  }

  @Override
  void printEdgesCount() {
    System.out.println("Graph has: " + edgesCount + " (s)");
  }

  @Override
  protected DirectedGraph clone() {
    DirectedGraph graph = new DirectedGraph();
    for (Vertex v : vertices) {
      graph.appendVertex(v);
    }
    return graph;
  }

  private DirectedGraph reverse(DirectedGraph g) {
    DirectedGraph reversedGraph = g.clone();
    for (Vertex v : reversedGraph.vertices) v.setVisited(false);
    for (Vertex v: reversedGraph.vertices) {
      for (int j = 0; j < v.getAdjacentList().size(); ++j)
        if (!v.getAdjacentList().get(j).isVisited()) {
          connectVertices(v.getAdjacentList().get(j), v);
          disconnectVertices(v, v.getAdjacentList().get(j));
          // todo Graph should have list of Edges (as list of vertices) so we can store info for each edge.
        }
      v.setVisited(true);
    }
    return reversedGraph;
  }

  void SCCs() {
    DirectedGraph reversedGraph = reverse(this);

    System.out.println("REVERSED GRAPH");
    reversedGraph.printGraphEdges();

    for (Vertex v : reversedGraph.vertices) v.setVisited(false);
    int SCC_counter = 1;
    for (Vertex v : reversedGraph.vertices) {
      exploreFor_SCCs(v, SCC_counter);
      ++SCC_counter;
      println();
    }
  }

  private void exploreFor_SCCs(Vertex v, int SCC_count) {
    try {
      SCCs.get(SCC_count - 1);
    } catch (IndexOutOfBoundsException e) {
      System.out.println("Connected Comp. #" + (SCC_count));
      SCCs.add(SCC_count - 1, new ArrayList<>());
    }
    SCCs.get(SCC_count - 1).add(v);
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
