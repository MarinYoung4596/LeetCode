#ifndef _INTERNAL_SORT_H_
#define _INTERNAL_SORT_H_

#include "util.h"
#include <vector>

/**
 * @brief: 仅为原理实现，不做异常输入检查
 *
 */

/**
 * @brief: 重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定排序
 */
template<typename Type>
void bubble_sort(std::vector<Type> &a, int left, int right) {
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j < right; j++) {
            if (a[i] > a[j])
                std::swap(a[i], a[j]);
        }
    }
}


/**
 * @brief 每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
 * 直到全部待排序的数据元素排完。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 不稳定排序
 */
template<typename Type>
void select_sort(std::vector<Type> &a, int left, int right) {
    for (int i = left; i < right; i++) {
        int min_pos = i;
        for (int j = i + 1; j < right; j++) {
            if (a[min_pos] > a[j]) {
                min_pos = j;
            }
        }
        if (i != min_pos) {
            std::swap(a[i], a[min_pos]);
        }
    }
}

/**
 * @brief: 每步将一个待排序的纪录，按其关键值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 不稳定排序
 */
template<typename Type>
void insert_sort(std::vector<Type> &a, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        //如果a[j]前一个数据a[j-1] > a[j]，就交换a[j]和a[j-1]，再j--直到a[j-1] <= a[j]
        for (int j = i - 1;
                j >= 0 && a[j] > a[j + 1];
                --j) {
            std::swap(a[j], a[j + 1]);
        }
    }
}


/**
 * @brief: 通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
 * 然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(logN)
 * 不稳定排序
 * https://en.wikipedia.org/wiki/Quicksort
 */
template <typename Type>
int partition(std::vector<Type> &v, int begin, int end) {
    int pivot = v[end]; // 以最后一个元素为基准
    int i = begin;
    for (auto j = begin; j < end; ++j) { // 从前往后扫描
        if (v[j] < pivot) { // 遇到比pivot小的元素, 挪到前面去
            // 这里i可以理解为比pivot小的元素总数(相对于所有v而言)
            std::swap(v[i], v[j]);     //  <
            ++i;
        }
    }
    std::swap(v[i], v[end]); // 循环执行完,下标<i的所有元素都比pivot小, swap之后, 即实现了partition的目标
    return i;
}

template<typename Type>
void quick_sort(std::vector<Type> &a, int left, int right) {
    if (left >= right) {        // do not sort 0 or 1 element
        return;
    }
    int k = partition(a, left, right);
    quick_sort(a, left, k - 1);
    quick_sort(a, k + 1, right);
}

/**
 * @brief 采用分治法.将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(N)
 * 稳定排序
 * https://en.wikipedia.org/wiki/Merge_sort
 */
template <typename Type>
void merge(Type a[], Type tmp[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = 0;
    while (i < mid && j < right) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i < mid) {
        tmp[k++] = a[i++];
    }
    while (j < right) {
        tmp[k++] = a[j++];
    }

    for (i = 0; i < k; i++) {
        a[left + i] = tmp[i];
    }
}

template <typename Type>
void merge_sort(Type a[], Type tmp[], int left, int right) {
    if (right - left < 2) {
        return;
    }
    int mid = (left + right) / 2;

    merge_sort(a, tmp, left, mid);
    merge_sort(a, tmp, mid, right);

    merge(a, tmp, left, mid, right);
}


/**
 * @brief 把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
 * 随着增量逐渐减少，每组包含的关键词越来越多，
 * 当增量减至1时，整个文件恰被分成一组，算法终止.
 * 时间复杂度：O(n^1.5)
 * 空间复杂度：O(1)
 * 不稳定排序
 * https://en.wikipedia.org/wiki/Shellsort
 */
template <typename Type>
void ins_sort_2(std::vector<Type> &a, int start, int incr) {
    int n = a.size();
    for (int i = start + incr; i < n; i += incr) {
        for (int j = i; j >= incr; j -= incr) {
            if (a[j] < a[j - incr]) {
                std::swap(a[j], a[j - incr]);
            }
        }
    }
}

template <typename Type>
void shell_sort(std::vector<Type> &a) {
    int n = a.size();
    for (int i = n / 2; i > 2; i /= 2) {
        for (int j = 0; j < i; j++) {
            ins_sort_2(a, j, i);
        }
    }
    ins_sort_2(a, 0, 1);
}


/**
 * @brief 利用堆的性质：子节点的键值总是小于（或大于）它的父节点
 * 时间复杂度：O(NlogN);
 * 空间复杂度：O(1);
 * 不稳定排序
 * https://en.wikipedia.org/wiki/Heapsort
 */
template <typename Type>
void heap_adjust(std::vector<Type> &v, int start, int end) {
    auto left = 2 * start;
    auto right = left + 1;
    auto largest = start;          // 建最大堆，取左右子树的最大值，同时判断左右子树是否存在
    if (left <= end && v[largest] < v[left]) {
        largest = left;
    }
    if (right <= end && v[largest] < v[right]) {
        largest = right;
    }
    if (largest != start) {
        std::swap(v[start], v[largest]); // 将当前结点与左右子树中的大者交换
        heap_adjust(v, largest, end); // 再对其中不满足堆条件的子树执行adjust操作（另外一棵树肯定满足条件）
    }
}

template <typename Type>
inline void build_heap(std::vector<Type> &v) {
    // (start is assigned the index in 'a' of the last parent node)
    // (the last element in a 0-based array is at index count-1; find the parent of that element)
    int start = (v.size() - 1) / 2; // 最后一个元素的父节点
    while (start >= 0) {
        //(sift down the node at index 'start' to the proper place such that all nodes below the start index are in heap order)
        heap_adjust(v, start, v.size());
        // (go to the next parent node)
        --start;
    }
    // (after sifting down the root all nodes/elements are in heap order)
}

template <typename Type>
void heap_sort(std::vector<Type> &v) {
    // (Build the heap in array a so that largest value is at the root)
    build_heap(v);
    int end = v.size() - 1;
    while (end > 0) { // 从最后一个元素开始调整序列
        //  (v[0] is the root and largest value. The swap moves it in front of the sorted elements.)
        std::swap(v[end], v[0]); // 交换堆顶元素和堆中最后一个元素，相当于pop堆顶
        --end;
        heap_adjust(v, 0, end); // 调整堆
    }
}


#endif // _INTERNAL_SORT_H_
