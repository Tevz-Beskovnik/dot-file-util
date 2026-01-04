#include "nob.h"
#include "src/dot_util.h"
#include <string>
#include <vector>

using namespace dot;

int main (int argc, char *argv[]) {
    REBUILD_SELF_AND_WATCH(argc, argv, "./src/dot_util.cpp");

    graph_t graph(graph_type_t::digraph, "example");

    node_style_t style;
    style.color = "black";
    style.fill = "white";
    style.shape = dot::circle;

    node_style_t style_o;
    style_o.color = "black";
    style_o.fill = "#FF0000";
    style_o.shape = dot::circle;

    node_style_t style_i;
    style_i.color = "black";
    style_i.fill = "#0000FF";
    style_i.shape = dot::record;

    node_style_t style_t;
    style_t.color = "black";
    style_t.fill = "#FFFF00";
    style_t.shape = dot::circle;

    std::vector<std::string> data = { "5", "7", "1" };

    graph.add_node(node_t::create_managed("4", &style));
    graph.add_node(node_t::create_managed("2", &style_o));
    graph.add_node(node_t::create_managed("10", &style));
    graph.add_node(node_t::create_managed("6", &style_t));
    graph.add_node(node_t::create_managed("8", &style_t));
    graph.add_node(node_t::create_managed("22", &style));
    graph.add_node(multy_node_t::create_managed("1", data, &style_i));

    graph.add_connection("\"1\":f0", "4");
    graph.add_connection("\"1\":f1", "10");
    graph.add_connection("\"1\":f2", "2");
    graph.add_connection("\"1\":f3", "22");
    graph.add_connection("4", "6");
    graph.add_connection("8", "1");
    graph.add_connection("22", "8");
    graph.add_connection("10", "2");
    graph.add_connection("2", "8");

    graph.display();
    
    return 0;
}
