#pragma once

#include "Math.h"

#include <unordered_map>
#include <vector>
#include <string>

// BFS
struct GraphNode
{
  // pointers to adjacent nodes
  int m_CsvIndex; // stores index for csv vector
  int m_NodeIndex;
  Vector2 m_Position;
  std::vector<GraphNode*> m_Adjacent;
};
struct Graph
{
  std::vector<GraphNode*> m_Nodes;
};
using NodeToParentMap = std::unordered_map<const GraphNode*, const GraphNode*>;

// GBFS
struct WeightedEdge
{

};
struct GBFSScratch
{
  const WeightedEdge* m_ParentEdige = nullptr;
  float m_Heuristic = 0.0f;
  bool m_InOpenSet = false;
  bool m_InClosedSet = false;
};
using GBFSMap = std::unordered_map<const GraphNode*, GBFSScratch>;

// A*
struct AStarScratch
{
  const WeightedEdge* m_ParentEdge = nullptr;
  float m_Heuristic = 0.0f;
  float m_ActualFromStart = 0.0f;
  bool m_InOpenSet = false;
  bool m_InClosedSet = false;
};
using AStarMap = std::vector<const GraphNode*, AStarScratch>;

// used to prevent actors from passing through barriers
class Map
{
public:
  enum Mode {E_BFS, E_GBFS, E_ASTAR};
private:
  Mode m_Mode;
  int m_Rows;
  int m_Cols;
  int m_CellWidth;
  int m_CellHeight;
  std::vector<int> m_Csv;

  std::unordered_map<int, int> mapCsvToNodeIndex;

  Graph m_Graph;

  bool LoadCsv(std::string fileName);
  void BuildGraph();
  Vector2 GetPositionFromCsvIndex(int index);
  Vector2 GetPositionFromCsvIndexCentered(int index);
  int ConvertPositionto1Dindex(Vector2 pos);
  int ConvertCsvToNodeIndex(int csvIndex);

  bool BFS(const Graph& graph, const GraphNode* start, const GraphNode* goal, NodeToParentMap& outMap);
  bool GBFS(const Graph& graph, const GraphNode* start, const GraphNode* goal, GBFSMap& outMap);
  bool AStar();

  float GetRand(int min, int max) const;

public:
  Map(std::string fileName);
  bool CollidesWithBarrier(Vector2 pos, float width, float height);
  std::vector<int> GetCsv() const;
  Vector2 GetRandomOpenPosition() const;
  void SetMode(Mode mode);
  void GetPath(Vector2 from, Vector2 to, std::vector<Vector2>& path);

  // todo remove
  void GetPathTest(Vector2 from, Vector2 to, std::vector<Vector2>& path);
};
