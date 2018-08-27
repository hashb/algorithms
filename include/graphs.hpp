#pragma once

#include <iostream>
#include <vector>
#include <memory>

namespace skiena {
    struct Node {
        int val;
        int weight;
        std::unique_ptr<Node> children;
    };
}


