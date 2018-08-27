#pragma once

#include <iostream>
#include <vector>
#include <memory>

struct Node {
    int val;
    int weight;
    std::unique_ptr<Node> children;
};