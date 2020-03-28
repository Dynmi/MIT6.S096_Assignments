#include <bits/stdc++.h>
using namespace std;


class State {
  size_t _node;
  double _dist;
public:
  State( size_t aNode, double aDist ) : _node{aNode}, _dist{aDist} {}
  inline size_t node()const { return _node; }
  inline double dist()const { return _dist; }
};
 
class AdjacencyList {
  std::vector< std::vector< State>  > _adj;
  AdjacencyList() = delete;
public:
  AdjacencyList( std::istream &input );
  inline size_t size() const { return _adj.size(); }
  inline const vector& adj(size_t node )  const { return _adj[node]; }
  void print();
};
 
inline bool operator<( const State &a, const State &b ) {
  return a.dist() > b.dist();
}
 
AdjacencyList::AdjacencyList( std::istream &input ) : _adj{} {
  size_t nNodes; size_t nEdges; input >> nNodes >> nEdges;
  _adj.resize( nNodes );
 
  for( size_t e = 0; e < nEdges; ++e ) {
    size_t v, w; double weight;
    input >> v >> w >> weight;
    // Add this edge to both the v and w lists
    _adj[v].push_back( State{ w, weight } );
    _adj[w].push_back( State{ v, weight } );
  }
}
 
void AdjacencyList::print() {
  for( size_t i = 0; i < _adj.size(); ++i ) {
    std::cout << i << ": ";
    for( auto state : _adj[i] ) {
      std::cout << "(" << state.node() << ", " << state.dist() << ") ";
    }
    std::cout << "\n";
  }
}
 
double prim( const AdjacencyList &adj ) {
  std::unordered_map<int, bool> visited;
  std::priority_queue<State> pq;
 
  pq.push( State{ 0, 0.0 } );
  double weight = 0.0;
 
  while( visited.size() < adj.size() ) {
    auto top = pq.top(); pq.pop();
 
    if( visited.count( top.node() ) == 0 ) {
      visited[top.node()] = true;
      weight += top.dist();
 
      for( auto vertex : adj.adj( top.node() ) ) {
        pq.push( vertex );
      }
    }
  }
 
  return weight;
}
 
int main() {
  std::ifstream input{ "mst.in" };
  std::ofstream output{ "mst.out" };
 
  if( input.is_open() ) {
    auto adj = AdjacencyList{ input };
    output << std::fixed << std::setprecision( 8 );
    output << prim( adj ) << "\n";
  } else {
    std::cerr << "Could not open mst.in\n";
    return 1;
  }

  return 0;
}

