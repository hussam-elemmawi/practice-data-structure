package com.hussamelemmawi;

import com.hussamelemmawi.rosetta_code.Graph;
public class Main {

    public static void main(String[] args) {

//        undirectedGraph();
//
//        directedGraph();
//
//        graphByAdjacentListDFS();
//
//        graphByAdjacentListDFS_iterative();
//
//        graphMatrixDfs();
//
//        graphMatrixDfs_iterative();
//
//        graphByAdjacentListBFS();
//
//        graphMatrixBFS();

        dijkstraRosettaCode();
    }

    static void undirectedGraph() {
        UndirectedGraph undirectedGraph = new UndirectedGraph();

        undirectedGraph.appendVertex(new Vertex('A')); // index 0
        undirectedGraph.appendVertex(new Vertex('B')); // index 1
        undirectedGraph.appendVertex(new Vertex('C')); // index 2
        undirectedGraph.appendVertex(new Vertex('D')); // index 3

        undirectedGraph.connectVertices('A', 'B'); // connect A with B
        Vertex v0 = undirectedGraph.getVertex(undirectedGraph, 'A');
        Vertex v2 = undirectedGraph.getVertex(undirectedGraph, 'C');
        undirectedGraph.connectVertices(v2, v0); // connect A with C

        undirectedGraph.printGraph();

        undirectedGraph.printEdgesCount();
        undirectedGraph.DFS();

        undirectedGraph.CCs();

        undirectedGraph.connectVertices('C', 'D'); // connect C with D

        undirectedGraph.DFSPrePostVisit();
    }

    static void directedGraph() {
        DirectedGraph directedGraph = new DirectedGraph();
        directedGraph.appendVertex(new Vertex('A')); // index 0
        directedGraph.appendVertex(new Vertex('B')); // index 1
        directedGraph.appendVertex(new Vertex('C')); // index 2
        directedGraph.appendVertex(new Vertex('D')); // index 3
        directedGraph.appendVertex(new Vertex('E')); // index 4
        directedGraph.appendVertex(new Vertex('F')); // index 5

        directedGraph.connectVertices('A', 'B'); // A -> B
        directedGraph.connectVertices('B', 'C'); // B -> C
        directedGraph.connectVertices('C', 'A'); // C -> A
        directedGraph.connectVertices('C', 'D'); // C -> D
        directedGraph.connectVertices('D', 'B'); // D -> B
        directedGraph.connectVertices('C', 'A'); // C -> A
        directedGraph.connectVertices('A', 'C'); // A -> C

        directedGraph.printGraphEdges();

        directedGraph.SCCs();
    }

    static void graphByAdjacentListDFS() {
        GraphAdjacentList graphAdjacentList = new GraphAdjacentList();
        graphAdjacentList.addVertex(new Vertex(5));
        graphAdjacentList.addVertex(new Vertex(3));
        graphAdjacentList.addVertex(new Vertex(7));
        graphAdjacentList.addVertex(new Vertex(1));
        graphAdjacentList.addVertex(new Vertex(9));

        Vertex v = graphAdjacentList.getVertex(5);
        Vertex u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u); // 5 -- 3

        v = graphAdjacentList.getVertex(5);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.connect(v, u); // 5 -- 7

        v = graphAdjacentList.getVertex(1);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.connect(v, u); // 1 -- 7

        graphAdjacentList.dfs();

        v = graphAdjacentList.getVertex(5);
        u = graphAdjacentList.getVertex(3);
        graphAdjacentList.disconnect(v, u);

        graphAdjacentList.dfs();

        v = graphAdjacentList.getVertex(9);
        u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u);

        graphAdjacentList.dfs();

        v = graphAdjacentList.getVertex(5);
        u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u);

        graphAdjacentList.dfs();
    }

    static void graphByAdjacentListDFS_iterative() {
        GraphAdjacentList graphAdjacentList = new GraphAdjacentList();
        graphAdjacentList.addVertex(new Vertex(5));
        graphAdjacentList.addVertex(new Vertex(3));
        graphAdjacentList.addVertex(new Vertex(7));
        graphAdjacentList.addVertex(new Vertex(1));
        graphAdjacentList.addVertex(new Vertex(9));

        Vertex v = graphAdjacentList.getVertex(5);
        Vertex u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u); // 5 -- 3

        v = graphAdjacentList.getVertex(5);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.connect(v, u); // 5 -- 7

        v = graphAdjacentList.getVertex(1);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.connect(v, u); // 1 -- 7

        graphAdjacentList.dfs_iterative();

        v = graphAdjacentList.getVertex(5);
        u = graphAdjacentList.getVertex(3);
        graphAdjacentList.disconnect(v, u);

        graphAdjacentList.dfs_iterative();

        v = graphAdjacentList.getVertex(9);
        u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u);

        graphAdjacentList.dfs_iterative();

        v = graphAdjacentList.getVertex(5);
        u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u);

        graphAdjacentList.dfs_iterative();
    }

    static void graphMatrixDfs() {
        GraphMatrix graphMatrix = new GraphMatrix();

        graphMatrix.addVertex(new Vertex(5));
        graphMatrix.addVertex(new Vertex(3));
        graphMatrix.addVertex(new Vertex(7));
        graphMatrix.addVertex(new Vertex(1));
        graphMatrix.addVertex(new Vertex(9));

        Vertex v = graphMatrix.getVertex(5);
        Vertex u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u); // 5 -- 3

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(7);
        graphMatrix.connect(v, u); // 5 -- 7

        v = graphMatrix.getVertex(1);
        u = graphMatrix.getVertex(7);
        graphMatrix.connect(v, u); // 1 -- 7

        graphMatrix.dfs();

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(3);
        graphMatrix.disconnect(v, u);

        graphMatrix.dfs();

        v = graphMatrix.getVertex(9);
        u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u);

        graphMatrix.dfs();

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u);

        graphMatrix.dfs();
    }

    static void graphMatrixDfs_iterative() {
        GraphMatrix graphMatrix = new GraphMatrix();

        graphMatrix.addVertex(new Vertex(5));
        graphMatrix.addVertex(new Vertex(3));
        graphMatrix.addVertex(new Vertex(7));
        graphMatrix.addVertex(new Vertex(1));
        graphMatrix.addVertex(new Vertex(9));

        Vertex v = graphMatrix.getVertex(5);
        Vertex u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u); // 5 -- 3

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(7);
        graphMatrix.connect(v, u); // 5 -- 7

        v = graphMatrix.getVertex(1);
        u = graphMatrix.getVertex(7);
        graphMatrix.connect(v, u); // 1 -- 7

        graphMatrix.dfs_iterative();

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(3);
        graphMatrix.disconnect(v, u); // break 5 -/- 3

        graphMatrix.dfs_iterative();

        v = graphMatrix.getVertex(9);
        u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u); // 9 -- 3

        graphMatrix.dfs_iterative();

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u); // 5 -- 3

        graphMatrix.dfs_iterative();

        v = graphMatrix.getVertex(5);
        u = graphMatrix.getVertex(1);
        graphMatrix.connect(v, u); // 5 -- 1

        graphMatrix.dfs_iterative();
    }

    static void graphByAdjacentListBFS() {
        GraphAdjacentList graphAdjacentList = new GraphAdjacentList();
        graphAdjacentList.addVertex(new Vertex(5));
        graphAdjacentList.addVertex(new Vertex(3));
        graphAdjacentList.addVertex(new Vertex(7));
        graphAdjacentList.addVertex(new Vertex(1));
        graphAdjacentList.addVertex(new Vertex(9));

        Vertex v = graphAdjacentList.getVertex(1);
        Vertex u = graphAdjacentList.getVertex(3);
        graphAdjacentList.connect(v, u); // 1 -- 3

        v = graphAdjacentList.getVertex(1);
        u = graphAdjacentList.getVertex(5);
        graphAdjacentList.connect(v, u); // 1 -- 5

        v = graphAdjacentList.getVertex(1);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.connect(v, u); // 1 -- 7

        graphAdjacentList.bfs();

        v = graphAdjacentList.getVertex(1);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.disconnect(v, u);

        graphAdjacentList.bfs();

        v = graphAdjacentList.getVertex(1);
        u = graphAdjacentList.getVertex(7);
        graphAdjacentList.connect(v, u); // 1 -- 7

        graphAdjacentList.bfs();

        v = graphAdjacentList.getVertex(7);
        u = graphAdjacentList.getVertex(9);
        graphAdjacentList.connect(v, u); // 7 -- 9

        graphAdjacentList.bfs();
    }

    static void graphMatrixBFS() {
        GraphMatrix graphMatrix = new GraphMatrix();

        graphMatrix.addVertex(new Vertex(5));
        graphMatrix.addVertex(new Vertex(3));
        graphMatrix.addVertex(new Vertex(7));
        graphMatrix.addVertex(new Vertex(1));
        graphMatrix.addVertex(new Vertex(9));

        Vertex v = graphMatrix.getVertex(1);
        Vertex u = graphMatrix.getVertex(3);
        graphMatrix.connect(v, u); // 1 -- 3

        v = graphMatrix.getVertex(1);
        u = graphMatrix.getVertex(5);
        graphMatrix.connect(v, u); // 1 -- 5

        v = graphMatrix.getVertex(1);
        u = graphMatrix.getVertex(7);
        graphMatrix.connect(v, u); // 1 -- 7

        graphMatrix.bfs();

        v = graphMatrix.getVertex(1);
        u = graphMatrix.getVertex(7);
        graphMatrix.disconnect(v, u);

        graphMatrix.bfs();

        v = graphMatrix.getVertex(1);
        u = graphMatrix.getVertex(7);
        graphMatrix.connect(v, u); // 1 -- 7

        graphMatrix.bfs();

        v = graphMatrix.getVertex(7);
        u = graphMatrix.getVertex(9);
        graphMatrix.connect(v, u); // 7 -- 9

        graphMatrix.bfs();
    }

    private static final Graph.Edge[] GRAPH = {
            new Graph.Edge("a", "b", 7),
            new Graph.Edge("a", "c", 9),
            new Graph.Edge("a", "f", 14),
            new Graph.Edge("b", "c", 10),
            new Graph.Edge("b", "d", 15),
            new Graph.Edge("c", "d", 11),
            new Graph.Edge("c", "f", 2),
            new Graph.Edge("d", "e", 6),
            new Graph.Edge("e", "f", 9),
    };
    private static final String START = "f";
    private static final String END = "e";

    static void dijkstraRosettaCode() {
        Graph g = new Graph(GRAPH);
        g.dijkstra(START);
//        g.printPath(END);
        g.printAllPaths();
    }
}
