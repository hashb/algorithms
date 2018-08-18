#pragma once
#include <vector>

namespace skiena {
    template<typename T>
    class priority_queue {
        priority_queue();
        ~priority_queue();
        void insert();
        T extract();

        private:
            void heapify_up();
            void heapify_down();
    };
}