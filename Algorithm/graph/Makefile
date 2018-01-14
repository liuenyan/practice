.PHONY: clean, mrproper
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

all: test_graph test_symbol_graph degree_of_seperation test_directed_dfs \
	test_topological test_kosaraju_scc test_lazy_prim_mst test_prim_mst \
	test_kruskal_mst test_dijkstra_sp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test_graph: test_graph.o graph.o depth_first_search.o depth_first_paths.o \
	breadth_first_paths.o connected_components.o cycle.o two_color.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_symbol_graph: test_symbol_graph.o symbol_graph.o graph.o
	$(CXX) $(CXXFLAGS) -o $@ $+

degree_of_seperation: degree_of_seperation.o symbol_graph.o graph.o \
	breadth_first_paths.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_directed_dfs: test_directed_dfs.o directed_dfs.o digraph.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_topological: test_topological.o digraph.o directed_cycle.o \
	depth_first_order.o topological.o symbol_digraph.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_kosaraju_scc: test_kosaraju_scc.o kosaraju_scc.o depth_first_order.o \
	digraph.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_lazy_prim_mst: test_lazy_prim_mst.o edge_weighted_graph.o edge.o \
	lazy_prim_mst.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_prim_mst: test_prim_mst.o edge_weighted_graph.o edge.o prim_mst.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_kruskal_mst:test_kruskal_mst.o kruskal_mst.o union_find.o \
	edge.o edge_weighted_graph.o
	$(CXX) $(CXXFLAGS) -o $@ $+

test_dijkstra_sp: test_dijkstra_sp.o dijkstra_sp.o edge_weighted_digraph.o \
	directed_edge.o
	$(CXX) $(CXXFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f test_graph test_symbol_graph degree_of_seperation test_directed_dfs \
	test_topological test_kosaraju_scc test_lazy_prim_mst test_prim_mst \
	test_kruskal_mst test_dijkstra_sp
