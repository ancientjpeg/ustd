/**
 * @file pathfind.h
 * @author Jackson Kaplan (JwyattK@gmail.com)
 * @date 2025-06-09
 * Copyright (c) 2025. All rights reserved.
 */

#ifndef USTD_PATHFIND_H_
#define USTD_PATHFIND_H_

#include <algorithm>
#include <map>
#include <vector>

template <typename Node, typename NodeGetter>
std::pair<size_t, std::vector<Node *>> find_path(const Node  *start_node,
                                                 const Node  *end_node,
                                                 NodeGetter &&node_getter)
{
  std::map<size_t, Node *>           unvisited;
  std::unordered_map<Node *, size_t> visited;

  while (start_node != end_node) {
    for (const Node *node : node_getter(start_node)) {
    }

    if (unvisited.empty()) {
      break;
    }

    start_node = unvisited.begin()->second;
  }
}

template <typename Node>
std::pair<size_t, std::vector<Node *>> find_path(const Node *start_node,
                                                 const Node *end_node)

{

  find_path(start_node,
            end_node,
            [](const Node *node) -> std::vector<const Node *> {
              std::vector<const Node *> nodes;
              std::transform(node->begin(),
                             node->end(),
                             std::back_inserter(nodes),
                             [](const Node *n) { return n; });
              return nodes;
            });
}

#endif
