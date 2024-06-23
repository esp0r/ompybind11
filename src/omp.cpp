#include <pybind11/pybind11.h>
#include <omp.h>

namespace py = pybind11;

int sum_thread_ids() {
    int sum = 0;
    #pragma omp parallel shared(sum)
    {
        #pragma omp critical
        sum += omp_get_thread_num();
    }
    return sum;
}

PYBIND11_MODULE(ompybind11, m) {
    m.def("sum_thread_ids", &sum_thread_ids, "Sum the thread IDs");
}