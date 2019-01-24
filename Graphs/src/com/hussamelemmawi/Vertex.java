package com.hussamelemmawi;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by hussamelemmawi on 14/08/17.
 */

public class Vertex {
  private Object value;
  private ArrayList<Vertex> adjacentList;
  private boolean visited;
  private int CC_num;
  private int preVisit;
  private int postVisit;
  private int incomingEdgesCount;

  Vertex(Object value) {
    this.value = value;
    adjacentList = new ArrayList<>();
    visited = false;
    incomingEdgesCount = 0;
  }

  boolean connectToVertex(Vertex vertex) {
    for (Vertex v : adjacentList) {
      if (v.equals(vertex)) return false;
    }
    return adjacentList.add(vertex);
  }

  boolean disconnectFromVertex(Vertex vertex) {
    return adjacentList.remove(vertex);
  }

  Object getValue() {
    return value;
  }

  public void setValue(Object value) {
    this.value = value;
  }

  ArrayList<Vertex> getAdjacentList() {
    return adjacentList;
  }

  public void setAdjacentList(ArrayList<Vertex> adjacentList) {
    this.adjacentList = adjacentList;
  }

  boolean isVisited() {
    return visited;
  }

  void setVisited(boolean visited) {
    this.visited = visited;
  }

  public int getCC_num() {
    return CC_num;
  }

  void setCC_num(int CC_num) {
    this.CC_num = CC_num;
  }

  int getPreVisit() {
    return preVisit;
  }

  int getPostVisit() {
    return postVisit;
  }

  void preVisit(Graph g) {
    g.tickClock();
    preVisit = g.getClock();
  }

  void postVisit(Graph g) {
    g.tickClock();
    postVisit = g.getClock();
  }

  void increamentIncomingEdgesCount() {
    ++incomingEdgesCount;
  }

  void decreamentIncomingEdgesCount() {
    --incomingEdgesCount;
  }

  boolean isSink() {
    return incomingEdgesCount == 0;
  }

  boolean isDisconnectedFromGraph() {
    return isSink() && adjacentList.isEmpty();
  }

  @Override
  public boolean equals(Object obj) {
    return this.value == ((Vertex) obj).value;
  }
}
