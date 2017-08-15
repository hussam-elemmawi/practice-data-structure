package com.hussamelemmawi;

public class Main {

  public static void main(String[] args) {
    UndirectedGraph undirectedGraph = new UndirectedGraph(GraphType.UNDIRECTED);

    undirectedGraph.appendVertex(new Vertex('A')); // index 0
    undirectedGraph.appendVertex(new Vertex('B')); // index 1
    undirectedGraph.appendVertex(new Vertex('C')); // index 2
    undirectedGraph.appendVertex(new Vertex('D')); // index 3

    undirectedGraph.connectVertices(0, 1); // connect A with B
    Vertex v0 = undirectedGraph.vertices.get(0);
    Vertex v2 = undirectedGraph.vertices.get(2);
    undirectedGraph.connectVertices(v2, v0); // connect A with C

    undirectedGraph.printGraph();

    undirectedGraph.printEdgesCount();
    undirectedGraph.DFS();

    undirectedGraph.CCs();

    undirectedGraph.connectVertices(2, 3); // connect C with D

    undirectedGraph.DFSPrePostVisit();
  }
}
